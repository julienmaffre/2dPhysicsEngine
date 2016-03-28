#ifndef OBJECT2D_H
#define OBJECT2D_H

#include <QGraphicsItem>

class Object2d : public QGraphicsRectItem
{
public:
    Object2d(QRectF rectangle, qreal weight, qreal elasticity, qreal velocity_x, qreal velocity_y, qreal acceleration);

    qreal getInvWeight() const;
    qreal getWeight() const;

    virtual void setPosX(const qreal &value);
    virtual void setPosY(const qreal &value);

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

#endif // OBJECT2D_H
