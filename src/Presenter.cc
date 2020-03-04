#include "Presenter.h"

#include "View.h"
#include "InputBuffer.h"

#include "Scene.h"

#include <QDebug>

Presenter::Presenter(Scene *scene) :
    scene(scene)
{
}

void Presenter::setView(View *view)
{
    this->view = view;
}

void Presenter::renderFrame()
{
    InputBuffer *buffer = view->getInputBuffer();

    scene->render(*buffer);

    qDebug() << "frame rendering";

    view->updateOutputBuffer();

    delete buffer;
}

void Presenter::scaleCamera(double rx, double ry, double rz)
{
    scene->scaleCamera(rx, ry, rz);
}

void Presenter::rotateCamera(double ax, double ay, double az)
{
    scene->rotateCamera(ax, ay, az);
}

void Presenter::translateCamera(double dx, double dy, double dz)
{
    scene->translateCamera(dx, dy, dz);
}

