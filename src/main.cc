#include <QApplication>

#include "mainwindow.h"
#include "Presenter.h"
#include "Scene.h"

int qt_main(int argc, char **argv, Presenter &p);

int main(int argc, char **argv)
{
    Scene scene;
    Presenter presenter(&scene);

    return qt_main(argc, argv, presenter);
}

int qt_main(int argc, char **argv, Presenter &p)
{
    QApplication app(argc, argv);
    MainWindow w;

    p.setView(&w);
    w.attach(&p);

    w.show();

    return app.exec();
}

