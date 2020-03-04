#include <QApplication>

#include "mainwindow.h"
#include "Presenter.h"

int qt_main(int argc, char **argv, Presenter &p);

int main(int argc, char **argv)
{
    Presenter presenter;

    return qt_main(argc, argv, presenter);
}

int qt_main(int argc, char **argv, Presenter &p)
{
    QApplication app(argc, argv);

    MainWindow w;
    p.addView(&w);

    w.show();

    return app.exec();
}

