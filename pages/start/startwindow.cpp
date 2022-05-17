#include "startwindow.h"
#include "ui_startwindow.h"
#include "./pages/index/indexwindow.h"

StartWindow::StartWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::StartWindow)
{
    ui->setupUi(this);
    //设置无边框
    this->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowMinimizeButtonHint);
    movie = new QMovie(":/public/start/start_up.gif");
    ui->labelStart->setMovie(movie);
    movie->start();
    mainwindow = new IndexWindow;

    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(enterNewScreen()));
    timer->start(500);
}

StartWindow::~StartWindow()
{
    delete ui;
}

void StartWindow::enterNewScreen()
{
    movie->stop();
    mainwindow->show();
    this->close();
}
