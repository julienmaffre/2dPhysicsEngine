#include "Element.h"

Element::Element(QRectF rectangle, QColor color, qreal weight, qreal elasticity, qreal acceleration) :
    color(color),
    Object2d(rectangle, weight, elasticity, 0, 0, acceleration)
{}

void Element::paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget) {
    painter->fillRect(this->boundingRect(), this->color);
}

QRectF Element::boundingRect() const {
    return this->rect();
}

void Element::advance(int step) {

    if (!step)
        return;

    /* Update x and y state based on gravity laws */
    updateStateY();
    updateStateX();

    /* Detect and resolve collisions with other objects */
    QList<Manifold *> listOfCollidingObjects = detectCollidingObjects();

    while (!listOfCollidingObjects.isEmpty()) {
        Manifold * secondObjectManifold = listOfCollidingObjects.takeFirst();

        /* Calculate relative velocity between two colliding objects */
        qreal rv_x = secondObjectManifold->second_object->getVelocityX() - this->getVelocityX();
        qreal rv_y = secondObjectManifold->second_object->getVelocityY() - this->getVelocityY();

        /* Calculate velocity along normal direction */
        qreal vetAlongNormal = secondObjectManifold->normal_x * rv_x + secondObjectManifold->normal_y * rv_y;

        if (vetAlongNormal <= 0.0) {

            qreal minElasticity = std::min(this->getElasticity(), secondObjectManifold->second_object->getElasticity());
            qreal j = -(1 + minElasticity) * vetAlongNormal;
            j /= this->getInvWeight() + secondObjectManifold->second_object->getInvWeight();

            this->setVelocityX(this->getVelocityX() - this->getInvWeight() * j * secondObjectManifold->normal_x);
            this->setVelocityY(this->getVelocityY() - this->getInvWeight() * j * secondObjectManifold->normal_y);

            secondObjectManifold->second_object->setVelocityX(secondObjectManifold->second_object->getVelocityX() + secondObjectManifold->second_object->getInvWeight() * j * secondObjectManifold->normal_x);
            secondObjectManifold->second_object->setVelocityY(secondObjectManifold->second_object->getVelocityY() + secondObjectManifold->second_object->getInvWeight() * j * secondObjectManifold->normal_y);

            adjustPosition(secondObjectManifold);
        }
    }

}

void Element::updateStateY(void) {
    //accelerationY += 0;
    this->setVelocityY(this->getVelocityY() + this->getAccelerationY() / 100);
    setPosY(scenePos().y() + this->getVelocityY() * 10 / 100);
}

void Element::updateStateX(void) {
    //accelerationX += 0;
    this->setVelocityX(this->getVelocityX() + this->getAccelerationX() / 100);
    setPosX(scenePos().x() + this->getVelocityX() * 10 / 100);
}

void Element::adjustPosition(Manifold* collidingObjectManifold) {
    const qreal percent = .5;
    const qreal slop = .05;
    qreal correction_x = std::max<qreal>(collidingObjectManifold->penetration, slop) / (this->getInvWeight() + collidingObjectManifold->second_object->getInvWeight()) * percent * collidingObjectManifold->normal_x;
    qreal correction_y = std::max<qreal>(collidingObjectManifold->penetration, slop) / (this->getInvWeight() + collidingObjectManifold->second_object->getInvWeight()) * percent * collidingObjectManifold->normal_y;

    setPosX(x() - this->getInvWeight() * correction_x);
    setPosY(y() - this->getInvWeight() * correction_y);
}

QList<Manifold *> Element::detectCollidingObjects(void) {

    collidingItemsList = scene()->collidingItems(this);

    QList<Manifold *> mList = * new QList<Manifold *>();
    for (int j = 0; j < collidingItemsList.size(); j++) {
        mList.append(new Manifold());
    }
    int i = 0;

    // While detect colliding items
    while (!collidingItemsList.isEmpty()) {

        // Pop the first item from the list
        QGraphicsRectItem * rectB = dynamic_cast<QGraphicsRectItem*>(collidingItemsList.takeFirst());

        mList[i]->second_object = dynamic_cast<Object2d*>(rectB);

        // Vector between two colliding objects A and B
        QPointF dist_AB = rectB->mapToScene(rectB->rect().center()) - this->mapToScene(this->rect().center());

        // x overlap between two colliding objects
        qreal overlap_x = std::min<qreal>(mapToScene(rect().topLeft()).x() + rect().width(), rectB->mapToScene(rectB->rect().topLeft()).x() + rectB->rect().width()) - std::max<qreal>(mapToScene(rect().topLeft()).x(), rectB->mapToScene(rectB->rect().topLeft()).x());

        if (overlap_x > 0) {
            // y overlap between two colliding objects
            qreal overlap_y = std::min<qreal>(mapToScene(rect().topLeft()).y() + rect().height(), rectB->mapToScene(rectB->rect().topLeft()).y() + rectB->rect().height()) - std::max<qreal>(mapToScene(rect().topLeft()).y(), rectB->mapToScene(rectB->rect().topLeft()).y());

            if (overlap_y > 0) {
                if (overlap_y > overlap_x) {
                    if (dist_AB.x() < 0) {
                        mList[i]->normal_x = -1;
                        mList[i]->normal_y = 0;
                    } else {
                        mList[i]->normal_x = 1;
                        mList[i]->normal_y = 0;
                    }
                    mList[i]->penetration = overlap_x;
                } else {
                    if (dist_AB.y() < 0) {
                        mList[i]->normal_x = 0;
                        mList[i]->normal_y = -1;
                    } else {
                        mList[i]->normal_x = 0;
                        mList[i]->normal_y = 1;
                    }
                    mList[i]->penetration = overlap_y;
                }
            }
        }
        ++i;
    }
    return mList;
}
