#ifndef SELFCHECKITEM_H
#define SELFCHECKITEM_H

#include <QWidget>

namespace Ui {
class SelfCheckItem;
}

class SelfCheckItem : public QWidget
{
    Q_OBJECT

public:
    explicit SelfCheckItem(QWidget *parent = nullptr);
    ~SelfCheckItem();

public slots:
    void setCheckStatus(int num);//设置自检的状态
    void setCheckItemName(QString str);//设置检测的项的名字
    void setCheckErrorCode(QString str);//设置错误码
private:
    Ui::SelfCheckItem *ui;
    QString unCheck = "#checkIcon{background-image: url(:/public/selfCheck/self_check_not.png);}"
                      "#checkItemName{font-size:36px;color:#959a9b;}"
                      "#checkErrorCode{font-size:36px;color:#959a9b;}"
                      "#checkJumpOver{max-height:0px;min-height:0px;}";
    QString checkIng = "#checkIcon{background-image: url(:/public/selfCheck/self_check_ing.png);}"
                      "#checkItemName{font-size:36px;color:#409ab4;}"
                      "#checkErrorCode{font-size:36px;color:#409ab4;}"
                      "#checkJumpOver{max-height:0px;min-height:0px;}";
    QString checkError = "#checkIcon{background-image: url(:/public/selfCheck/self_check_error.png);}"
                      "#checkItemName{font-size:36px;color:#e27053;}"
                      "#checkErrorCode{font-size:36px;color:#e27053;}"
                      "#checkJumpOver{max-height:0px;min-height:0px;}";
    QString checkErrorJumpOver = "#checkIcon{background-image: url(:/public/selfCheck/self_check_error.png);}"
                      "#checkItemName{font-size:36px;color:#e27053;}"
                      "#checkErrorCode{font-size:36px;color:#e27053;}"
                      "#checkJumpOver{max-height:50px;min-height:50px;}";
    QString checkOk = "#checkIcon{background-image: url(:/public/selfCheck/self_check_ok.png);}"
                      "#checkItemName{font-size:36px;color:#409ab4;}"
                      "#checkErrorCode{font-size:36px;color:#409ab4;}"
                      "#checkJumpOver{max-height:0px;min-height:0px;}";
};

#endif // SELFCHECKITEM_H
