#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QInputEvent>
#include <cmath>

#include "QImageBuffer.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),

    ui(new Ui::MainWindow),
    frameTimer(new QTimer)
{
    ui->setupUi(this);

    ui->particleSlider->setRange(100, 30000);
    ui->particleSlider->setTickInterval(1);
    ui->particleSlider->setSliderPosition(25000);
    connect(ui->particleSlider, SIGNAL(valueChanged(int)), this, SLOT(modifyParticle()));

    ui->velocitySlider->setRange(20000, 25000);
    ui->velocitySlider->setTickInterval(1);
    ui->velocitySlider->setSliderPosition(22500);
    connect(ui->velocitySlider, SIGNAL(valueChanged(int)), this, SLOT(modifyVelocity()));

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

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    int key = event->key();

    double step = M_PI / 120;
    double ratio = 1.05;

    if (key == Qt::Key_Equal)
    {
        cameraScalingRequested(1/ratio, 1/ratio, 1/ratio);
    }
    if (key == Qt::Key_Minus)
    {
        cameraScalingRequested(ratio, ratio, ratio);
    }
    if (key == Qt::Key_W)
    {
        cameraRotationRequested(0, 0, +step);
    }
    if (key == Qt::Key_S)
    {
        cameraRotationRequested(0, 0, -step);
    }
    if (key == Qt::Key_D)
    {
        cameraRotationRequested(0, +step, 0);
    }
    if (key == Qt::Key_A)
    {
        cameraRotationRequested(0, -step, 0);
    }
    if (key == Qt::Key_E)
    {
        cameraRotationRequested(+step, 0, 0);
    }
    if (key == Qt::Key_Q)
    {
        cameraRotationRequested(-step, 0, 0);
    }
}

void MainWindow::modifyVelocity()
{
    velocityModified(ui->velocitySlider->sliderPosition());
}

void MainWindow::modifyParticle()
{
    particleModified(ui->particleSlider->sliderPosition());
}

