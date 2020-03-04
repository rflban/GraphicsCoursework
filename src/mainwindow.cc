#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "QImageBuffer.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),

    ui(new Ui::MainWindow),
    frameTimer(new QTimer)
{
    ui->setupUi(this);

    connect(frameTimer, SIGNAL(timeout()), this, SLOT(requestFrame()));
    frameTimer->start(1000 / 24);
}

MainWindow::~MainWindow()
{
    delete frameTimer;
    delete ui;
}

void MainWindow::requestFrame()
{
    frameRequested();
}

void MainWindow::updateOutputBuffer()
{
    ui->display->updateOutputBuffer();
}

InputBuffer *MainWindow::getInputBuffer()
{
    return new QImageBuffer(&ui->display->getInputBuffer(),
                            ui->display->width(),
                            ui->display->height());
}

