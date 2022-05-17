#ifndef STATUSVALUE_H
#define STATUSVALUE_H
#include <QObject>

class StatusValue: public QObject
{
    Q_OBJECT
public:
    explicit StatusValue(QObject *parent = nullptr);
    static bool bloodPumpStatue;//当前血泵状态，true为开
    static int currentPage;//当前页面
    static int currentPageProcess;//当前过程页面
public:

};

#endif // STATUSVALUE_H
