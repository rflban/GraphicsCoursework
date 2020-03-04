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

void Presenter::rotateCamera(double deltaT, double deltaP)
{
    scene->rotateCamera(deltaT, deltaP);
}

