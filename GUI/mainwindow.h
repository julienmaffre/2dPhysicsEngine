#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDesktopWidget>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(float widthPct, float heightPct, QWidget *parent = 0);
    ~MainWindow();

    int getWidth() const;
    void setWidth(int value);

    int getHeight() const;
    void setHeight(int value);

private:
    Ui::MainWindow *ui;
    int width;
    int height;
};

#endif // MAINWINDOW_H
