#include "Element.h"

Element::Element(QRectF rectangle, qreal weight, qreal elasticity, qreal acceleration) :
    color(255, 127, 80),
    Thing(rectangle, weight, elasticity, 0, 0, acceleration)
{
}

void Element::advance(int step) {

    if (!step)
        return;

    updateStateY();
    updateStateX();

    Manifold m = {0.0, 0.0, 0.0, NULL};

    if (doesCollide(&m)) {
        qreal rvX = m.second_object->getVelocityX() - this->getVelocityX();
        qreal rvY = m.second_object->getVelocityY() - this->getVelocityY();

        qreal vetAlongNormal = m.normal_x * rvX + m.normal_y * rvY;

        if (vetAlongNormal > 0.0)
          return;

        qreal min_elasticity = std::min(this->getElasticity(), m.second_object->getElasticity());
        qreal j = -(1 + min_elasticity) * vetAlongNormal;

        j /= this->getInvWeight() + m.second_object->getInvWeight();

        std::cout << "This (" << this->getAccelerationY() << ") " << "- " << this->getVelocityY() << std::endl;
        std::cout << "Element (" << m.second_object->getAccelerationY() << ") " << "- " << m.second_object->getVelocityY() << std::endl;

        this->setVelocityX(this->getVelocityX() - this->getInvWeight() * j * m.normal_x);
        this->setVelocityY(this->getVelocityY() - this->getInvWeight() * j * m.normal_y);

        m.second_object->setVelocityX(m.second_object->getVelocityX() + this->getInvWeight() * j * m.normal_x);
        m.second_object->setVelocityY(m.second_object->getVelocityY() + this->getInvWeight() * j * m.normal_y);

        std::cout << "penetration= " << m.penetration << std::endl;
        setY(y() - m.penetration*.2 + this->getVelocityY() * 100 / 100);
    }
}

void Element::updateStateY(void) {

    //accelerationY += 0;
    this->setVelocityY(this->getVelocityY() + this->getAccelerationY() / 100);
    setY(scenePos().y() + this->getVelocityY() * 100 / 100);
}

void Element::updateStateX(void) {

    //accelerationX += 0;
    this->setVelocityX(this->getVelocityX() + this->getAccelerationX() / 100);
    setX(scenePos().x() + this->getVelocityX() * 100 / 100);
}

bool Element::doesCollide(Manifold * m) {

    collidingItemsList = scene()->collidingItems(this);

    if (collidingItemsList.isEmpty()) {
        return false;

    } else {

        std::cout << "Colliding Items:  " << "Something!" << std::endl;

        QGraphicsRectItem * rectB = dynamic_cast<QGraphicsRectItem*>(collidingItemsList.first());
        m->second_object = dynamic_cast<Thing*>(collidingItemsList.first());

        /* Manifold calculation */

        // Vector between two colliding objects AB
        QPointF AB = rectB->mapToScene(rectB->rect().center()) - this->mapToScene(this->rect().center());

        QPointF this_y = this->scenePos();
        QPointF this_center = this->mapToScene(this->rect().center());

        QPointF other_yP= rectB->mapToScene(rectB->rect().topLeft());
        QPointF other_center = rectB->mapToScene(rectB->rect().center());

        // x overlap between two colliding objects
        qreal overlap_x = std::min<qreal>(mapToScene(rect().topLeft()).x() + rect().width(), rectB->mapToScene(rectB->rect().topLeft()).x() + rectB->rect().width()) - std::max<qreal>(mapToScene(rect().topLeft()).x(), rectB->mapToScene(rectB->rect().topLeft()).x());

        if (overlap_x > 0) {
            // y overlap between two colliding objects
            qreal overlap_y = std::min<qreal>(mapToScene(rect().topLeft()).y() + rect().height(), rectB->mapToScene(rectB->rect().topLeft()).y() + rectB->rect().height()) - std::max<qreal>(mapToScene(rect().topLeft()).y(), rectB->mapToScene(rectB->rect().topLeft()).y());

            if (overlap_y > 0) {
                if (overlap_y > overlap_x) {
                    if (AB.x() < 0) {
                        m->normal_x = -1;
                        m->normal_y = 0;
                    } else {
                        m->normal_x = 1;
                        m->normal_y = 0;
                    }
                    m->penetration = overlap_x;
                    return true;
                } else {
                    if (AB.y() < 0) {
                        m->normal_x = 0;
                        m->normal_y = -1;
                    } else {
                        m->normal_x = 0;
                        m->normal_y = 1;
                    }
                    m->penetration = overlap_y;
                    return true;
                }
            }

        }
        /* ******************** */
        return false;
    }
}

void Element::paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget) {
    painter->fillRect(this->boundingRect(), color);
}

QRectF Element::boundingRect() const {
    return this->rect();
}
