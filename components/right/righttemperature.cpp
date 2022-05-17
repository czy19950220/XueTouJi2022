#include "righttemperature.h"
#include "ui_righttemperature.h"

RightTemperature::RightTemperature(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RightTemperature)
{
    ui->setupUi(this);
}

RightTemperature::~RightTemperature()
{
    delete ui;
}
//设置温度值，需要传入乘以10的值,显示的值是除以10.0保留一位小数
void RightTemperature::setTemperatureValue(int num){
    ui->labelTemperature->setText(QString::number(num/10.0,'f',1));
}
