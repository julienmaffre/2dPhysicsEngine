#ifndef DECOR_H
#define DECOR_H

#include <QGraphicsItem>
#include <QPainter>
#include <QColor>
#include <iostream>

#include "Thing.h"

class Decor : public Thing
{
public:
    Decor(QRectF rect);

    void paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget);

    void setVelocityX(const qreal &value);
    void setVelocityY(const qreal &value);

private:

    QColor color;

    qreal width;
    qreal height;
};

#endif // DECOR_H
