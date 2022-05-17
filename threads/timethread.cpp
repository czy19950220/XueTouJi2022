#include "timethread.h"

TimeThread::TimeThread(QObject *parent) : QObject(parent)
{
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(getCurrentData()));
}

void TimeThread::startGetTime(){
    timer->start(100);
    qDebug()<<"timer启动";
}


void TimeThread::getCurrentData(){
    QString current_date =QDateTime::currentDateTime().toString("yyyy.MM.dd hh:mm:ss");
    emit sendCurrentData(current_date);
}
