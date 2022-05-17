#ifndef SELFCHECK_H
#define SELFCHECK_H

#include <QWidget>
#include "tools/GlobalHead.h"

namespace Ui {
class SelfCheck;
}

class SelfCheck : public QWidget
{
    Q_OBJECT

public:
    explicit SelfCheck(QWidget *parent = nullptr);
    ~SelfCheck();

public slots:
    void initPage();//初始化界面
    void setCheckItemStatus(int num,int status);//设置自检中状态
    void checkFailed();//测试失败
    void checkSuccess();//测试成功
    void setCheckErrorCode(int itemNum, QString str);//设置错误码
private slots:
    void on_pushButtonCheckAgain_clicked();//重新测试按钮点击事件

private:
    Ui::SelfCheck *ui;
};

#endif // SELFCHECK_H
