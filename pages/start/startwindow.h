#ifndef STARTWINDOW_H
#define STARTWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QMovie>
#include "./pages/index/indexwindow.h"

namespace Ui {
class StartWindow;
}

class StartWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit StartWindow(QWidget *parent = nullptr);
    ~StartWindow();

private:
    Ui::StartWindow *ui;
    QTimer *timer;
    QMovie *movie;
    IndexWindow *mainwindow;

private slots:
    void enterNewScreen();
};

#endif // STARTWINDOW_H
