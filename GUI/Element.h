#ifndef ELEMENT_H
#define ELEMENT_H

#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QPainter>
#include <QColor>
#include <iostream>
#include <QtMath>
#include <time.h>

#include "Thing.h"

#define SIMULATION_STEP (33.0) // simulation step in milliseconds
#define EPSILON_VELOCITY (0.01)

typedef struct {
    qreal penetration;
    qreal normal_x;
    qreal normal_y;
    Thing* second_object;
} Manifold;

class Element : public Thing
{
public:
    Element(QRectF rectangle, qreal weight, qreal elasticity, qreal acceleration);

    bool doesCollide(Manifold *m);

    void updateStateX(void);
    void updateStateY(void);

    void advance(int step);

    void paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget);

    QRectF boundingRect() const;

private:
    QColor color;

    QList<QGraphicsItem *> collidingItemsList;

};

#endif // ELEMENT_H
