#include "myseriaport.h"
#include <QtSerialPort/QtSerialPort>
#include <QDebug>
#include <QByteArray>
MySeriaPort::MySeriaPort()
{
    serial1 = new QSerialPort;
    serial2 = new QSerialPort;
    serial3 = new QSerialPort;
    //处理数据的类型
    commandMap = new QMap<QString,int>;
    commandMap->insert("41",0);
    commandMap->insert("51",1);
    commandMap->insert("61",2);
    commandMap->insert("70",3);
    commandMap->insert("81",4);
    commandMap->insert("90",5);
    findPorts();
    QString str = "7E";
    QString str2 = "5AA5";
    QString str3 = "03";
    QString str4 = "500500";
    QString str5 = "00557E5AA503";
    disposeCommand(str);

    disposeCommand(str2);

    disposeCommand(str3);

    disposeCommand(str4);

    disposeCommand(str5);


}

void MySeriaPort::findPorts()
{
    serialPortInfos = QSerialPortInfo::availablePorts();
    if(serialPortInfos.size() <=0){//没有串口可用
        return;
    }else {
        QStringList list;
        for (const QSerialPortInfo &serialPortInfo : serialPortInfos)
        {
            list << serialPortInfo.portName();
            qDebug()<<"串口可用--"<<list;
        }
        //当前最多设置3个
        if(list.size()>0){//第一个串口
            //设置串口
            setPortSetting(serial1,list.at(0));
            //打开串口
            if (serial1->open(QIODevice::ReadWrite)){
                //信号与槽函数关联
                connect(serial1, &QSerialPort::readyRead, this, &MySeriaPort::readData);
            }else{
                qDebug()<<"未打开串口"<<serial1->portName();
            }
        }
        if(list.size()>1){//第二个串口
            //设置串口
            setPortSetting(serial2,list.at(1));
            //打开串口
            if (serial2->open(QIODevice::ReadWrite)){
                //信号与槽函数关联
                connect(serial2, &QSerialPort::readyRead, this, &MySeriaPort::readData);
            }
        }
        if(list.size()>2){//第三个串口
            //设置串口
            setPortSetting(serial3,list.at(2));
            //打开串口
            if (serial3->open(QIODevice::ReadWrite)){
                //信号与槽函数关联
                connect(serial3, &QSerialPort::readyRead, this, &MySeriaPort::readData);
            }
        }
    }
}
//设置串口
void MySeriaPort::setPortSetting(QSerialPort *serial,QString portName)
{
    //设置串口名字
    serial->setPortName(portName);
    //设置波特率
    serial->setBaudRate(115200);
    //设置数据位
    serial->setDataBits(QSerialPort::Data8);
    //设置奇偶校验位
    serial->setParity(QSerialPort::NoParity);
    //设置停止位
    serial->setStopBits(QSerialPort::OneStop);
    //设置流控
    serial->setFlowControl(QSerialPort::NoFlowControl);
}
//读取串口数据
void MySeriaPort::readData()
{
    QByteArray buf;
    //qDebug() << "readData: " << endl;
    buf = serial1->readAll();

    if (!buf.isEmpty())
    {
        disposeCommand(buf.toHex().toUpper());
    }
}
//处理接收数据--多个储存，然后拆包或者合并包
void MySeriaPort::disposeCommand(QString str){
    repeatedly += str;
    repeatedly = repeatedly.remove(QRegExp("\\s"));//去除空格
    //当前存储的字符串包好帧头并且不是以帧头开头，就舍弃前边无用的
    if(repeatedly.indexOf(frameHeader)<0){//缓存的字符串不包含帧头，直接返回
        return;
    }else if(repeatedly.indexOf(frameHeader)>=0){//缓存的字符串包含帧头,就去除帧头前面无用部分
        repeatedly = repeatedly.mid(repeatedly.indexOf(frameHeader));
        if(repeatedly.indexOf(frameHeader,frameHeader.size())<0){//不需要拆包，从第frameHeader.size()往后没有frameHeader,表示只有一个帧头字符
            //命令给的长度 = 命令的长度 - 帧头长度 - 帧尾长度 - 校验位长度 - 长度的长度（2）,这里都是字符串长度
            //如果大于，说明还没有接收完
            if((2 * QString("%1").arg(repeatedly.mid(4, 2), 0, 10).toInt()) > (repeatedly.size()-frameHeader.size()-frameEnd.size()-checkCommandSize-2)){
                return;
            }else{//接收完一包,截取根据命令给的长度的长度
                onceCommand = repeatedly.mid(0,frameHeader.size()+frameEnd.size()+checkCommandSize + 2 + (2 * QString("%1").arg(repeatedly.mid(4, 2), 0, 10).toInt()));
                if(onceCommand.startsWith(frameHeader) && onceCommand.endsWith(frameEnd)){//帧头帧尾正确
                    splitCommand(onceCommand);
                }else{
                    qDebug()<<"未通过校验数据--"<<onceCommand;
                }
                //不管通过校验与否，都删除做过处理的数据
                repeatedly = repeatedly.mid(onceCommand.size());
            }
        }else{//当前frameHeader的个数>=2，需要拆包
            splitCommand(repeatedly);
        }
    }
}

//char 转为 16进制
char MySeriaPort::convertCharToHex(char ch)
{
    /*
        0x30等于十进制的48，48也是0的ASCII值，，
        1-9的ASCII值是49-57，，所以某一个值－0x30，，
        就是将字符0-9转换为0-9

        */
    if((ch >= '0') && (ch <= '9'))
        return ch-0x30;
    else if((ch >= 'A') && (ch <= 'F'))
        return ch-'A'+10;
    else if((ch >= 'a') && (ch <= 'f'))
        return ch-'a'+10;
    else return (-1);
}

//基本和单片机交互 数据 都是16进制的 我们这里自己写一个 Qstring 转为 16进制的函数
void MySeriaPort::convertStringToHex(const QString &str, QByteArray &byteData)
{
    int hexdata,lowhexdata;
    int hexdatalen = 0;
    int len = str.length();
    byteData.resize(len/2);
    char lstr,hstr;
    for(int i=0; i<len; )
    {
        //char lstr,
        hstr=str[i].toLatin1();
        if(hstr == ' ')
        {
            i++;
            continue;
        }
        i++;
        if(i >= len)
            break;
        lstr = str[i].toLatin1();
        hexdata = convertCharToHex(hstr);
        lowhexdata = convertCharToHex(lstr);
        if((hexdata == 16) || (lowhexdata == 16))
            break;
        else
            hexdata = hexdata*16+lowhexdata;
        i++;
        byteData[hexdatalen] = (char)hexdata;
        hexdatalen++;
    }
    byteData.resize(hexdatalen);
}

/** 串口发送数据发送
 * @param info :需要发送的数据
 * @param portNum : 串口1、2、3
*/
void MySeriaPort::sendInfo(const QString &info,int portNum){//

    QByteArray sendBuf;
    if (info.contains(" "))
    {
        //info.replace(" ","");
    }
    if(info==""){return;}
    //qDebug()<<"本次发送命令: "<<info;
    //当前时间
    //QString current_date =QDateTime::currentDateTime().toString("hh:mm:ss.zzz");
    convertStringToHex(info, sendBuf); //把QString 转换 为 hex
    switch (portNum) {
    case 1:
        serial1->write(sendBuf);//这句是真正的给单片机发数据 用到的是QIODevice::write 具体可以看文档
        break;
    case 2:
        serial2->write(sendBuf);//这句是真正的给单片机发数据 用到的是QIODevice::write 具体可以看文档
        break;
    case 3:
        serial3->write(sendBuf);//这句是真正的给单片机发数据 用到的是QIODevice::write 具体可以看文档
        break;
    default:
        break;
    }
}

//拆包主控发过来的命令函数
void MySeriaPort::splitCommand(QString &str){
    //当前frameHeader的个数>=2
    if(str.indexOf(frameHeader)==0 && str.indexOf(frameHeader,frameHeader.size())>0){
        onceCommand = str.mid(0,str.indexOf(frameHeader,frameHeader.size()));//截取最前边一个有效数据
        //当前时间
        QString current_date =QDateTime::currentDateTime().toString("hh:mm:ss.zzz");//当前时间
        //校验数据
        if(checkCommand(onceCommand)){//校验通过
            qDebug()<<current_date<<"收到数据： "<<onceCommand;
            processData(onceCommand);//处理数据
        }else{//不通过
            qDebug()<<current_date<<"未通过校验数据： "<<onceCommand;
        }
        //处理完数据后重新置空
        onceCommand ="";
        str = str.mid(str.indexOf(frameHeader,frameHeader.size()));
        splitCommand(str);//剩下的再递归拆包，直到不满足条件
    }else if(str.startsWith(frameHeader) && str.endsWith(frameEnd)){//剩下的内容只剩下一个帧头，且剩下的是一个完整包
        onceCommand = str;
        //当前时间
        QString current_date =QDateTime::currentDateTime().toString("hh:mm:ss.zzz");//当前时间
        //校验数据
        if(checkCommand(onceCommand)){//校验通过
            qDebug()<<current_date<<"收到数据： "<<onceCommand;
            processData(onceCommand);//处理数据
        }else{//不通过
            qDebug()<<current_date<<"未通过校验数据： "<<onceCommand;
        }
        onceCommand = "";
        str = "";
    }else{
        return;
    }
}

//校验主控发过来的命令
bool MySeriaPort::checkCommand(QString str){
    str = str.remove(QRegExp("\\s"));
    if(!str.startsWith(frameHeader)){
        qDebug()<<"校验不通过："<<"帧头校验未通过";
        return false;
    }else if(!str.endsWith(frameEnd)){
        qDebug()<<"校验不通过："<<"帧尾校验未通过";
        return false;
    }
    int strSize = str.size();
    //5AA5 03 50 05 00 0055 7E 最短命令例子
    //传过来的命令不是2的倍数，或者小于 minSize 直接返回false
    if(str.size() % 2 !=0 || str.size()<minSize){
        qDebug()<<"校验不通过："<<str<<",传过来的命令不是2的倍数，或者小于 minSize 直接返回false";
        return false;
    }else{
        //接收命令的长度
        int resultSize = QString("%1").arg(str.mid(4, 2), 0, 10).toInt();
        //qDebug()<<"resultSize"<<string16ToInt(str.mid(4, 2));
        //收到命令的数据长度不等于 数据的长度-帧头长度-帧尾长度-校验位长度（4）- 数据长度校验的长度（2）
        if(2 * resultSize != (strSize-frameHeader.size()-frameEnd.size()-checkCommandSize-2)){
            qDebug()<<"校验不通过："<<str<<",总长度："<<strSize<<"收到命令的数据长度:"<<2*resultSize<<"不等于 数据的长度-帧头长度-帧尾长度-校验位长度（4）::"<<(strSize-frameHeader.size()-frameEnd.size()-4-2);
            return false;
        }else{
            //截取需要校验的字符串
            QString data_check = str.mid(6,2*resultSize);
            QStringList result;
            //校验是1个字节1个字节相加，这里把它们放到一个list中
            for (int i = 0;i<data_check.length();i=i+2) {
                result<<data_check.mid(i,2);
            }
            //转换为4字符串长度的16进制字符串
            QString result_hex="0";
            bool ok;
            for (int j = 0;j < result.size();j++) {
                result_hex = QString("%1").arg(result_hex.toInt(&ok,16) + result.at(j).toInt(&ok,16), 4, 16, QLatin1Char('0'));
            }
            if(QString::compare(result_hex.toUpper(), str.mid((6+2*resultSize),4).toUpper()) != 0){
                qDebug()<<"校验不通过："<<str<<",根据需要校验的字符串："<<result<<"，得到校验结果："<<result_hex.toUpper()<<"，接收到的结果"<<str.mid((6+2*resultSize),4).toUpper();
                return false;
            }
        }
        return true;
    }
}

//region
//处理数据
void MySeriaPort::processData(QString str){
    //判断数据类型
    switch (commandMap->value(str.mid(6,2))) {
    case 0://0x41
        dataType41(onceCommand);
        break;
    case 1://0x51
        dataType51(onceCommand);
        break;
    case 2://0x61
        dataType61(onceCommand);
        break;
    case 3://0x70
        dataType70(onceCommand);
        break;
    case 4://0x81
        dataType81(onceCommand);
        break;
    case 5://0x90
        dataType90(onceCommand);
        break;
    default:
        break;
    }
}

//数据类型41处理方法
void MySeriaPort::dataType41(QString str){

}
//数据类型51处理方法
void MySeriaPort::dataType51(QString str)
{

}
//数据类型61处理方法
void MySeriaPort::dataType61(QString str)
{

}
//数据类型70处理方法
void MySeriaPort::dataType70(QString str)
{

}
//数据类型81处理方法
void MySeriaPort::dataType81(QString str)
{

}
//数据类型90处理方法
void MySeriaPort::dataType90(QString str)
{

}
//endregion
