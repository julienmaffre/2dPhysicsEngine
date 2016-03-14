#include "Thing.h"

Thing::Thing(QRectF rectangle, qreal weight, qreal elasticity, qreal velocity_x, qreal velocity_y, qreal acceleration) :
    QGraphicsRectItem(rectangle),
    weight(weight),
    velocityX(velocity_x),
    velocityY(velocity_y),
    accelerationX(5),
    accelerationY(acceleration),
    elasticity(elasticity)
{

}

qreal Thing::getWeight() const
{
    return weight;
}

void Thing::setVelocityX(const qreal &value)
{
    velocityX = value;
}

void Thing::setVelocityY(const qreal &value)
{
    velocityY = value;
}

qreal Thing::getAccelerationX() const
{
    return accelerationX;
}

qreal Thing::getAccelerationY() const
{
    return accelerationY;
}

qreal Thing::getElasticity() const
{
    return elasticity;
}

qreal Thing::getInvWeight() const
{
    if (weight == 0) {
        return 0;
    } else {
        return 1/weight;
    }
}

qreal Thing::getVelocityY() const
{
    return velocityY;
}

qreal Thing::getVelocityX() const
{
    return velocityX;
}
