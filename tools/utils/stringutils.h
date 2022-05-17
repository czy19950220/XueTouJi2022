#ifndef STRINGUTILS_H
#define STRINGUTILS_H

#include "tools/GlobalHead.h"

class StringUtils : public QObject
{
    Q_OBJECT
public:
    explicit StringUtils(QObject *parent = nullptr);

    static QString timeFormetSeconds(int seconds);//将秒转换为时分秒
    static QString timeFormetMinutes(int minutes);//将分钟转换为时分
    static QString hexToBit(QString hexMessage, int theBits);//将hex转换为2进制表示

signals:

};

#endif // STRINGUTILS_H
