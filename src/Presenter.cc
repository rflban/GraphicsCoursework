#include "Presenter.h"

#include "View.h"
#include "InputBuffer.h"

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

    for (int i = 0; i < buffer->width(); i++)
    {
        for (int j = 0; j < buffer->height(); j++)
            buffer->setPixel(i, j, 255, 0, 0);
    }

    qDebug() << "frame rendering";

    view->updateOutputBuffer();

    delete buffer;
}

