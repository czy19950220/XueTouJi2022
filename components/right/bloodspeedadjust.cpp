#include "bloodspeedadjust.h"
#include "ui_bloodspeedadjust.h"

BloodSpeedAdjust::BloodSpeedAdjust(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BloodSpeedAdjust)
{
    ui->setupUi(this);
    ui->labelValue->setText(QString::number(bloodPumpSpeed));
    //设置点击穿透
    ui->labelAdd->setAttribute(Qt::WA_TransparentForMouseEvents, true);
    ui->labelSub->setAttribute(Qt::WA_TransparentForMouseEvents, true);
    //设置判断200毫秒内点击了加减按钮的timer
    timerClickRepeatedly = new QTimer(this);
    timerClickRepeatedly->setSingleShot(true);
    connect(timerClickRepeatedly,SIGNAL(timeout()),this,SLOT(slotTimerout()));
    //长按加按钮的timer
    timerAddLongClick = new QTimer(this);
    connect(timerAddLongClick,SIGNAL(timeout()),this,SLOT(slotLongClickAdd()));

    timerSubLongClick = new QTimer(this);
    connect(timerSubLongClick,SIGNAL(timeout()),this,SLOT(slotLongClickSub()));
    speedMax = ThresholdValue::tv_blood_pump_speed_max;
    speedMin = ThresholdValue::tv_blood_pump_speed_min;
}

BloodSpeedAdjust::~BloodSpeedAdjust()
{
    delete ui;
}

//血泵加按下事件--递增血泵速度值
void BloodSpeedAdjust::on_pushButtonAdd_pressed()
{
    //停止减的timer
    if(timerSubLongClick->isActive()){
        timerSubLongClick->stop();
    }
    //血泵速率直接+1
    bloodPumpSpeed += 1;
    if(bloodPumpSpeed > speedMax){
        bloodPumpSpeed = speedMax;
        ui->labelValue->setText(QString::number(bloodPumpSpeed));
        Toast::instance().show(Toast::INFOTYPE, QString("已经达到最大值：%0").arg(speedMax));
        return;
    }
    ui->labelValue->setText(QString::number(bloodPumpSpeed));
    //血泵减不可点击
    ui->pushButtonSub->setEnabled(false);
    //超过200ms判定长按
    if(timerAddLongClick->isActive()){
        timerAddLongClick->stop();
        timerAddLongClick = new QTimer(this);
        connect(timerAddLongClick,SIGNAL(timeout()),this,SLOT(slotLongClickAdd()));
    }
    timerAddLongClick->start(200);
}
//血泵加弹起事件--发送当前血泵速度值
void BloodSpeedAdjust::on_pushButtonAdd_released()
{
    times = 0;
    timerAddLongClick->stop();
    resetTimerRepeatedly();
}
//血泵减按下事件--递增血泵速度值
void BloodSpeedAdjust::on_pushButtonSub_pressed()
{
    //停止加的timer
    if(timerAddLongClick->isActive()){
        timerAddLongClick->stop();
    }
    //血泵+不可点击
    ui->pushButtonAdd->setEnabled(false);
    //血泵速率直接-1
    bloodPumpSpeed -= 1;
    if(bloodPumpSpeed < speedMin){
        bloodPumpSpeed = speedMin;
        ui->labelValue->setText(QString::number(bloodPumpSpeed));
        Toast::instance().show(Toast::INFOTYPE, QString("已经达到最小值：%0").arg(speedMin));
        return;
    }
    ui->labelValue->setText(QString::number(bloodPumpSpeed));
    //超过200ms判定长按
    if(timerSubLongClick->isActive()){
        timerSubLongClick->stop();
        timerSubLongClick = new QTimer(this);
        connect(timerSubLongClick,SIGNAL(timeout()),this,SLOT(slotLongClickSub()));
    }
    timerSubLongClick->start(200);

}
//血泵减弹起事件--发送当前血泵速度值
void BloodSpeedAdjust::on_pushButtonSub_released()
{
    timerSubLongClick->stop();
    times = 0;
    resetTimerRepeatedly();
}
//判断timerClickRepeatedly是否需要重新定义
void BloodSpeedAdjust::resetTimerRepeatedly(){
    if(timerClickRepeatedly->isActive()){
        timerClickRepeatedly->stop();
        timerClickRepeatedly = new QTimer(this);
        timerClickRepeatedly->setSingleShot(true);
        connect(timerClickRepeatedly,SIGNAL(timeout()),this,SLOT(slotTimerout()));
        timerClickRepeatedly->start(200);
    }else{
        timerClickRepeatedly->start(200);
    }
}
//定时器执行完成
void BloodSpeedAdjust::slotTimerout()
{
    ui->pushButtonAdd->setEnabled(true);
    ui->pushButtonSub->setEnabled(true);
    //TODO:发送血泵速率命令
}

//长按加
void BloodSpeedAdjust::slotLongClickAdd(){
    //根据timer执行次数判断增加的步长
    times+=1;
    if(times<5){
        speedStep = 1;
    }
    if(times>=5){
        speedStep = 5;
    }
    if(times>=10){
        speedStep = 10;
    }
    if(times>=20){
        speedStep = 20;
    }
    bloodPumpSpeed += speedStep;
    if(bloodPumpSpeed > speedMax){//超过最大值
        bloodPumpSpeed = speedMax;
        ui->labelValue->setText(QString::number(bloodPumpSpeed));
        Toast::instance().show(Toast::INFOTYPE, QString("已经达到最大值：%0").arg(speedMax));
        timerAddLongClick->stop();
        return;
    }
    ui->labelValue->setText(QString::number(bloodPumpSpeed));
}

//长按减
void BloodSpeedAdjust::slotLongClickSub(){
    //根据timer执行次数判断增加的步长
    times+=1;
    if(times<5){
        speedStep = 1;
    }
    if(times>=5){
        speedStep = 5;
    }
    if(times>=10){
        speedStep = 10;
    }
    if(times>=20){
        speedStep = 20;
    }
    bloodPumpSpeed -= speedStep;
    if(bloodPumpSpeed < speedMin){//超过最小值
        bloodPumpSpeed = speedMin;
        ui->labelValue->setText(QString::number(bloodPumpSpeed));
        Toast::instance().show(Toast::INFOTYPE, QString("已经达到最小值：%0").arg(speedMin));
        timerSubLongClick->stop();
        return;
    }
    ui->labelValue->setText(QString::number(bloodPumpSpeed));
}



