#ifndef MYSERIAPORT_H
#define MYSERIAPORT_H

#include "tools/GlobalHead.h"

class MySeriaPort : public QObject
{
public:
    MySeriaPort();

private://私有变量
    QList<QSerialPortInfo> serialPortInfos;
    QSerialPort *serial1;//串口1
    QSerialPort *serial2;//串口2
    QSerialPort *serial3;//串口3
    QString onceCommand="";//一次完整读取的命令
    QString repeatedly;//一次完整读取的命令--拆包
    QString frameHeader="5AA5";//帧头
    QString frameEnd="7E";//帧尾
    int minSize = 18;//与主控交互最短字符串长度 5AA5 03 50 05 00 0055 7E 最短命令例子
    int checkCommandSize = 4;//检验位长度
    QMap<QString,int> *commandMap;//处理数据的类型
private://私有函数
    void findPorts();//查找所有串口
    void setPortSetting(QSerialPort *serial,QString portName);//设置串口
    char convertCharToHex(char ch);//char 转为 16进制
    void convertStringToHex(const QString &str, QByteArray &byteData);//Qstring 转为 16进制
    void sendInfo(const QString &info,int portNum);//发送命令
    bool checkCommand(QString str);//检验函数
    void processData(QString str);//处理接收的有效数据
    void splitCommand(QString &str);//拆包函数
public slots://公共槽
    void readData();
    void dataType41(QString str);//数据类型41处理函数
    void dataType51(QString str);//数据类型51处理函数
    void dataType61(QString str);//数据类型61处理函数
    void dataType70(QString str);//数据类型70处理函数
    void dataType81(QString str);//数据类型81处理函数
    void dataType90(QString str);//数据类型90处理函数
    void disposeCommand(QString str);//处理接收数据
};

#endif // MYSERIAPORT_H
