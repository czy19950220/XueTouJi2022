#ifndef FORMHEADLEFT_H
#define FORMHEADLEFT_H

#include <QWidget>
#include "tools/GlobalHead.h"
#include "threads/timethread.h"

namespace Ui {
class FormHeadLeft;
}

class FormHeadLeft : public QWidget
{
    Q_OBJECT
signals:
    void startGetTime();//开始获取时间
    void checkDetailButtonClicked();//自检详情按钮
public:
    explicit FormHeadLeft(QWidget *parent = nullptr);
    ~FormHeadLeft();

public slots:
    void setCurrentTime(QString str);//设置当前时间
    void setCurrentTitle(QString str);//设置当前状态标题
    void setPushButtonCheckDetailText(QString str);//设置按钮的文字
    void setPushButtonCheckDetailSeeable(bool seeable);//设置按钮是否可见
private slots:
    void on_pushButtonCheckDetail_clicked();

private:
    Ui::FormHeadLeft *ui;
    TimeThread *timeThread;//获取当前时间显示的线程
    QThread *threadGetTime; //时间显示的线程--定义一个线程对象指针在构造函数中分配空间
};

#endif // FORMHEADLEFT_H
