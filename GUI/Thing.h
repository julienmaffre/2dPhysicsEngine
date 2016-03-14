#ifndef THING_H
#define THING_H

#include <QGraphicsItem>

class Thing : public QGraphicsRectItem
{
public:
    Thing(QRectF rectangle, qreal weight, qreal elasticity, qreal velocity_x, qreal velocity_y, qreal acceleration);

    qreal getInvWeight() const;
    qreal getWeight() const;

    qreal getVelocityX() const;
    qreal getVelocityY() const;

    virtual void setVelocityX(const qreal &value);
    virtual void setVelocityY(const qreal &value);

    qreal getAccelerationX() const;
    qreal getAccelerationY() const;

    qreal getElasticity() const;

protected:
    qreal weight;

    qreal accelerationX;
    qreal accelerationY;
    qreal velocityX;
    qreal velocityY;

    qreal elasticity;
};

#endif // THING_H
