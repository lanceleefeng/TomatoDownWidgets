
#include <QBoxLayout>
#include <QVBoxLayout>
#include <QHBoxLayout>

#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QBoxLayout *layout = new QVBoxLayout;

    // 不应该继承QMainWindow
    //QWidget::setLayout: Attempting to set QLayout "" on MainWindow "", which already has a layout
    setLayout(layout);
}

MainWindow::~MainWindow()
{
    
}
