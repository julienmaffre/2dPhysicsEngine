#include "Decor.h"

Decor::Decor(QRectF rect):
    color(200, 200, 200),
    Thing(rect, 0, 1, 0, 0, 0)
{
}

void Decor::paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget) {
    painter->fillRect(this->boundingRect(), color);

}

void Decor::setVelocityX(const qreal &value) {
    this->velocityX = 0;
}

void Decor::setVelocityY(const qreal &value) {
    this->velocityY = 0;
}
