#include "bloodpump.h"
#include "ui_bloodpump.h"

BloodPump::BloodPump(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BloodPump)
{
    ui->setupUi(this);
    //设置遮罩层，左边半圆外不让电机
    QPixmap map(":/public/right/bloodmotor.png");
    map = map.scaled(ui->pushButtonShade->width(),ui->pushButtonShade->height());
    ui->pushButtonShade->setMask(map.mask());
    //设置动画---
    roview = new RotationView(ui->widgetRoViewCon);
    roview->setStyleSheet("background: transparent;border:none;padding:0px;");
    roview->setGeometry(0, 0, 102, 102);
    //由于动画经常会出现卡顿，现在用timer来进行动画
//    rotation = new QPropertyAnimation(roview, "angle", this);

    m_timer = new QTimer(this);
    m_timer->setInterval(20);
    connect(m_timer,&QTimer::timeout,this,&BloodPump::on_timeOut);
}

BloodPump::~BloodPump()
{
    delete ui;
}

//设置血泵开关状态
void BloodPump::setBloodPumpOpenClose(bool open){
    if(open){//血泵开状态
        ui->widgetContent->setStyleSheet(widgetContentStyleOpen);
    }else{
        ui->widgetContent->setStyleSheet(widgetContentStyleClose);
    }

}

//当前血泵模块点击事件
void BloodPump::on_pushButtonShade_clicked()
{
    if(StatusValue::bloodPumpStatue){//当前血泵为开，发送关闭命令
        StatusValue::bloodPumpStatue = false;
        setBloodPumpOpenClose(false);
        m_timer->stop();
    }else{//当前血泵为关，发送开启命令
        StatusValue::bloodPumpStatue = true;
        setBloodPumpOpenClose(true);
        m_timer->start();
    }
}

//开启血泵动画
void BloodPump::startBloodPumpCartoon(){
    rotation->setDuration(1440);
    rotation->setStartValue(0);
    rotation->setEasingCurve(QEasingCurve::Linear);
    rotation->setEndValue(360);
    rotation->setLoopCount(-1);
    rotation->start();
}


void BloodPump::on_timeOut()
{
    m_i +=13;
    m_i =m_i%360;
    roview->setturnangle(m_i);
}
