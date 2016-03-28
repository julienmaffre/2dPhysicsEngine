#ifndef ELEMENT_H
#define ELEMENT_H

#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QPainter>
#include <QColor>
#include <iostream>
#include <QtMath>
#include <time.h>

#include "physicsengine/Object2d.h"

typedef struct {
    qreal penetration;
    qreal normal_x;
    qreal normal_y;
    Object2d* second_object;
} Manifold;


class Element : public Object2d
{
public:
    Element(QRectF rectangle, QColor color, qreal weight, qreal elasticity, qreal acceleration);

    void paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget);

    QRectF boundingRect() const;

    void advance(int step);

    QList<Manifold *> detectCollidingObjects(void);

    void updateStateX(void);

    void updateStateY(void);

    void adjustPosition(Manifold* collidingObjectManifold);
    
private:
    QColor color;

    QList<QGraphicsItem *> collidingItemsList;
};

#endif // ELEMENT_H
