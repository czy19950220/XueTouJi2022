#ifndef BLOODSPEEDADJUST_H
#define BLOODSPEEDADJUST_H

#include <QWidget>
#include <./tools/GlobalHead.h>

namespace Ui {
class BloodSpeedAdjust;
}

class BloodSpeedAdjust : public QWidget
{
    Q_OBJECT

public:
    explicit BloodSpeedAdjust(QWidget *parent = nullptr);
    ~BloodSpeedAdjust();

private slots:
    void on_pushButtonAdd_pressed();//+按下

    void on_pushButtonAdd_released();//+弹起

    void on_pushButtonSub_pressed();//-按下

    void on_pushButtonSub_released();//-弹起

    void slotTimerout();//定时器执行完

    void slotLongClickAdd();//长按加按钮
    void slotLongClickSub();//长按减按钮
private://私有变量
    Ui::BloodSpeedAdjust *ui;
    int bloodPumpSpeed = 20;//血泵速率
    int times=0;//长按次数
    int speedStep=1;//长按递增步长
    int speedMax;//血泵最大速率
    int speedMin;//血泵最小速率
    QTimer * timerClickRepeatedly;//判断200毫秒内点击了加减按钮
    QTimer * timerAddLongClick;//长按加按钮
    QTimer * timerSubLongClick;//长按减按钮

private://私有方法
    void resetTimerRepeatedly();//判断timerClickRepeatedly是否需要重新定义
};

#endif // BLOODSPEEDADJUST_H
