#include "leftbottom.h"
#include "ui_leftbottom.h"
#include "tools/GlobalHead.h"


LeftBottom::LeftBottom(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LeftBottom)
{
    ui->setupUi(this);
    setProgressBarThresholdValue(140,175);
}

LeftBottom::~LeftBottom()
{
    delete ui;
}
//设置单位和名字
void LeftBottom::setNameUnit(QString nameStr,QString unitStr){
    ui->labelName->setText(nameStr);
    ui->labelUnit->setText(unitStr);
}
//设置单位和名字的样式，电导度和跨膜压会用到
void LeftBottom::setNameUnitStyle(int i){
    if(i==1){
        ui->labelName->setStyleSheet("font-size:20px;color:#409ab4;");
        ui->labelUnit->setStyleSheet("font-size:18px;color:#409ab4;");
    }else{
        ui->labelName->setStyleSheet("font-size:20px;color:#373f44;");
        ui->labelUnit->setStyleSheet("font-size:18px;color:#373f44;");
    }

}
//设置值--传的整数：动静脉压，跨膜压使用
void LeftBottom::setPressureValue(int num){
    ui->labelValue->setText(QString("%1").arg(num));
    ui->pressureSlider->setValue(num);
}
//设置值--传的整数：电导度使用，显示需要除以10.0
void LeftBottom::setPressureValueConductivity(int num){
    ui->labelValue->setText(QString::number(num/10.0, 'f', 1));
    ui->pressureSlider->setValue(num);
}
//报警样式
void LeftBottom::setStyleAlarm(){
    ui->labelValue->setStyleSheet(alarmValueStyle);
    ui->pressureSlider->setStyleSheet(alarmProgressBarStyle);
}
//正常样式
void LeftBottom::setStyleNormal(){
    ui->labelValue->setStyleSheet(normalValueStyle);
    ui->pressureSlider->setStyleSheet(normalProgressBarStyle);
}

//开启自动调整动画
void LeftBottom::setAnimation(){
    m_pGraphicsOpacityEffect1 = new QGraphicsOpacityEffect(ui->widgetContent);
    myAnimation = new QPropertyAnimation(m_pGraphicsOpacityEffect1,"opacity",this);
    m_pGraphicsOpacityEffect1->setOpacity(1.0);
    ui->widgetContent->setGraphicsEffect(m_pGraphicsOpacityEffect1);
    myAnimation->setDuration(2000);
    myAnimation->setStartValue(1.0);
    myAnimation->setKeyValueAt(0.1, 0.8);
    myAnimation->setKeyValueAt(0.2, 0.6);
    myAnimation->setKeyValueAt(0.3, 0.4);
    myAnimation->setKeyValueAt(0.4, 0.2);
    myAnimation->setKeyValueAt(0.5, 0.1);
    myAnimation->setKeyValueAt(0.6, 0.2);
    myAnimation->setKeyValueAt(0.7, 0.4);
    myAnimation->setKeyValueAt(0.8, 0.6);
    myAnimation->setKeyValueAt(0.9, 0.8);
    myAnimation->setKeyValueAt(1.0, 1.0);
    myAnimation->setEndValue(1.0);
    myAnimation->setLoopCount(3);
    myAnimation->start();
    connect(myAnimation,&QPropertyAnimation::finished,this,&LeftBottom::setAnimationEnd);
}

//点击当前控件
void LeftBottom::on_pushButton_clicked()
{
    setAnimation();
    setPressureValue(qrand()%37+140);
}
//动画结束
void LeftBottom::setAnimationEnd(){
    qDebug()<<"自动调整执行完毕";
}

//设置进度条最大值最小值
void LeftBottom::setProgressBarThresholdValue(int min,int max){
    if(max<min){
        ui->pressureSlider->setMaximum(min);
        ui->pressureSlider->setMinimum(max);
    }else{
        ui->pressureSlider->setMaximum(max);
        ui->pressureSlider->setMinimum(min);
    }

}
