#include "StaticScenery.h"

StaticScenery::StaticScenery(QRectF rect):
    color(200, 200, 200),
    Object2d(rect, 0, 1, 0, 0, 0)
{
}

void StaticScenery::paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget) {
    painter->fillRect(this->boundingRect(), color);

}

void StaticScenery::setPosX(const qreal &value) {
    return;
}

void StaticScenery::setPosY(const qreal &value) {
    return;
}

void StaticScenery::setVelocityX(const qreal &value) {
    this->velocityX = 0;
}

void StaticScenery::setVelocityY(const qreal &value) {
    this->velocityY = 0;
}
