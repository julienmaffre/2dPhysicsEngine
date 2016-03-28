#include "src/physicsengine/objects/Element.h"
#include "src/physicsengine/scenery/StaticScenery.h"
#include <iostream>

#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QGraphicsScene scene;
    scene.setSceneRect(-300, -300, 600, 600);

    scene.setItemIndexMethod(QGraphicsScene::NoIndex);

    /* Create loads of objects with different attribute */
    qreal y_gravity = 10;

    QRectF * mainRect = new QRectF(0, -100, 50, 50);
    Element * element1 = new Element(*mainRect, Qt::blue, 10, .2, y_gravity);

    QRectF * mainRect2 = new QRectF(0, 100, 50, 50);
    Element * element2 = new Element(*mainRect2, Qt::red, 10, .2, y_gravity);

    QRectF * mainRect3 = new QRectF(-100, 100, 50, 25);
    Element * element3 = new Element(*mainRect3, Qt::black, 5, .7, y_gravity);

    QRectF * mainRect4 = new QRectF(-100, -100, 25, 25);
    Element * element4 = new Element(*mainRect4, Qt::yellow, 1, 1, y_gravity);

    QRectF * mainRect5 = new QRectF(-50, -100, 25, 25);
    Element * element5 = new Element(*mainRect5, Qt::magenta, 1, 1, y_gravity);

    QRectF * mainRect6 = new QRectF(-100, -50, 25, 25);
    Element * element6 = new Element(*mainRect6, Qt::gray, 1, 1, y_gravity);

    QRectF * mainRect7 = new QRectF(-50, -50, 25, 25);
    Element * element7 = new Element(*mainRect7, Qt::darkGreen, 1, 1, y_gravity);

    QRectF * mainRect8 = new QRectF(0, -50, 25, 25);
    Element * element8 = new Element(*mainRect8, Qt::lightGray, 1, 1, y_gravity);

    QRectF * bottomLine = new QRectF(-200, 200, 400, 10);
    StaticScenery * bottomObject = new StaticScenery(*bottomLine);

    QRectF * rightLine = new QRectF(200, -190, 10, 400);
    StaticScenery * rightObject = new StaticScenery(*rightLine);

    QRectF * leftLine = new QRectF(-200, -190, 10, 400);
    StaticScenery * leftObject = new StaticScenery(*leftLine);

    scene.addItem(element1);
    scene.addItem(element2);
    scene.addItem(element3);
    scene.addItem(element4);
    scene.addItem(element5);
    scene.addItem(element6);
    scene.addItem(element7);
    scene.addItem(element8);
    scene.addItem(rightObject);
    scene.addItem(bottomObject);
    scene.addItem(leftObject);
    /****************/

    QGraphicsView view(&scene);
    view.setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);

    view.resize(1000, 700);
    view.show();

    QTimer timer;
    QObject::connect(&timer, SIGNAL(timeout()), &scene, SLOT(advance()));
    timer.start(10);

    return a.exec();
}
