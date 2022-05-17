#ifndef TIMETHREAD_H
#define TIMETHREAD_H

#include "tools/GlobalHead.h"

class TimeThread : public QObject
{
    Q_OBJECT
private slots:
    void getCurrentData();//获取当前时间
public:
    explicit TimeThread(QObject *parent = nullptr);
public slots:
    void startGetTime();//开始获取时间
private:
    QTimer *timer;

signals:
    void sendCurrentData(QString str);//发送当前时间

};

#endif // TIMETHREAD_H
