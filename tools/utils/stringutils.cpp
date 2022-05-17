#include "stringutils.h"

StringUtils::StringUtils(QObject *parent) : QObject(parent)
{

}


/** 将秒转换为时分秒
* @projectName   XueTouJi2022
* @brief         将秒转换为时分秒
* @author        陈振宇
* @date          2022-04-06
* @param seconds : 秒
*/
QString StringUtils::timeFormetSeconds(int seconds){
    return (QString("%1").arg((seconds / 3600),2,10,QLatin1Char('0')) + ":"
            + QString("%1").arg(((seconds % 3600) / 60),2,10,QLatin1Char('0')) + ":"
            + QString("%1").arg(((seconds % 3600) % 60),2,10,QLatin1Char('0')));
}
/** 将分钟转换为时分
* @projectName   XueTouJi2022
* @brief         将分钟转换为时分
* @author        陈振宇
* @date          2022-04-06
* @param minutes : 分钟
*/
QString StringUtils::timeFormetMinutes(int minutes) {
    return (QString("%1").arg((minutes / 60),2,10,QLatin1Char('0')) + ":"
            + QString("%1").arg((minutes % 60),2,10,QLatin1Char('0')));
}
/** 将16进制字符串转换为2进制字符串表示
* @projectName   XueTouJi2022
* @brief         摘要
* @author        陈振宇
* @date          2022-04-07
* @param hexMessage : 传过来的16进制字符串，例如："F0"
* @param theBits : 保留的位数，不足补零
*/
QString StringUtils::hexToBit(QString hexMessage,int theBits){
    bool OK;
    // 保留theBits位，不足补零;例如"1F"转8位2进制 hexToBit("1F",8) = "00011111"
    return QString("%1").arg(hexMessage.toInt(&OK,16), theBits, 2,QLatin1Char('0'));
}
