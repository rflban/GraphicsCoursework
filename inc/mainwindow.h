#ifndef GCW_MAINWINDOW_H_
#define GCW_MAINWINDOW_H_

#include <QMainWindow>

#include "View.h"

namespace Ui
{
class MainWindow;
}

class MainWindow : public QMainWindow, public View
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    virtual ~MainWindow();

private:
    Ui::MainWindow *ui;

};

#endif // GCW_MAINWINDOW_H_

