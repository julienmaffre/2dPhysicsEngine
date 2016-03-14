#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(float widthPct, float heightPct, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    QDesktopWidget dw;

    ui->setupUi(this);
    width = dw.width()*widthPct;
    height = dw.height()*heightPct;
    this->setFixedSize(width,height);
}

MainWindow::~MainWindow()
{
    delete ui;
}

int MainWindow::getWidth() const
{
    return width;
}

void MainWindow::setWidth(int value)
{
    width = value;
}

int MainWindow::getHeight() const
{
    return height;
}

void MainWindow::setHeight(int value)
{
    height = value;
}
