#ifndef GCW_MAINWINDOW_H_
#define GCW_MAINWINDOW_H_

#include <QMainWindow>
#include <QTimer>

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

    void updateOutputBuffer() override;
    InputBuffer *getInputBuffer() override;

protected:
    void keyPressEvent(QKeyEvent *) override;

private:
    Ui::MainWindow *ui;
    QTimer *frameTimer;

private slots:
    void requestFrame();

    void modifyVelocity();
    void modifyParticle();
};

#endif // GCW_MAINWINDOW_H_

