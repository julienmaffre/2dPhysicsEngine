#include "Object2d.h"

Object2d::Object2d(QRectF rectangle, qreal weight, qreal elasticity, qreal velocity_x, qreal velocity_y, qreal acceleration) :
    QGraphicsRectItem(rectangle),
    weight(weight),
    velocityX(velocity_x),
    velocityY(velocity_y),
    accelerationX(5),
    accelerationY(acceleration),
    elasticity(elasticity)
{}

qreal Object2d::getWeight() const
{
    return weight;
}

void Object2d::setPosX(const qreal &value) {
    this->setX(value);
}

void Object2d::setPosY(const qreal &value) {
    this->setY(value);
}

void Object2d::setVelocityX(const qreal &value)
{
    velocityX = value;
}

void Object2d::setVelocityY(const qreal &value)
{
    velocityY = value;
}

qreal Object2d::getAccelerationX() const
{
    return accelerationX;
}

qreal Object2d::getAccelerationY() const
{
    return accelerationY;
}

qreal Object2d::getElasticity() const
{
    return elasticity;
}

qreal Object2d::getInvWeight() const
{
    if (weight == 0) {
        return 0;
    } else {
        return 1/weight;
    }
}

qreal Object2d::getVelocityY() const
{
    return velocityY;
}

qreal Object2d::getVelocityX() const
{
    return velocityX;
}
