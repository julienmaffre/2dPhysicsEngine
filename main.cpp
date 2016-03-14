#include "GUI/Element.h"
#include "GUI/Decor.h"
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

    QRectF * mainRect = new QRectF(0, -100, 50, 50);
    Element * element1 = new Element(*mainRect, 1, .8, 10);

    QRectF * mainRect2 = new QRectF(0, 100, 50, 50);
    Element * element2 = new Element(*mainRect2, 1, .4, 10);

    QRectF * mainRect3 = new QRectF(-100, 100, 50, 25);
    Element * element3 = new Element(*mainRect3, 10, .7, 10);

    QRectF * mainRect4 = new QRectF(-100, -100, 25, 25);
    Element * element4 = new Element(*mainRect4, 10, .7, 10);

    QRectF * bottomLine = new QRectF(-200, 200, 400, 10);
    Decor * bottomObject = new Decor(*bottomLine);

    QRectF * rightLine = new QRectF(200, -190, 10, 400);
    Decor * rightObject = new Decor(*rightLine);

    QRectF * leftLine = new QRectF(-200, -190, 10, 400);
    Decor * leftObject = new Decor(*leftLine);

    scene.addItem(element1);
//    scene.addItem(element2);
//    scene.addItem(element3);
//    scene.addItem(element4);
    scene.addItem(rightObject);
    scene.addItem(bottomObject);
    scene.addItem(leftObject);


    QGraphicsView view(&scene);
    view.setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);

    view.resize(700, 700);
    view.show();

    QTimer timer;
    QObject::connect(&timer, SIGNAL(timeout()), &scene, SLOT(advance()));
    timer.start(10);

    return a.exec();
}
