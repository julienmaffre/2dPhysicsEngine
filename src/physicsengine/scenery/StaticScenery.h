#ifndef STATICSCENERY_H
#define STATICSCENERY_H

#include <QGraphicsItem>
#include <QPainter>
#include <QColor>
#include <iostream>

#include "physicsengine/Object2d.h"

class StaticScenery : public Object2d
{
public:
    StaticScenery(QRectF rect);

    void paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget);

    void setPosX(const qreal &value);
    void setPosY(const qreal &value);

    void setVelocityX(const qreal &value);
    void setVelocityY(const qreal &value);

private:

    QColor color;

    qreal width;
    qreal height;
};

#endif // STATICSCENERY_H
