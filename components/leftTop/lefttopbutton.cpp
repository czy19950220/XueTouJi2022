#include "lefttopbutton.h"
#include "ui_lefttopbutton.h"

LeftTopButton::LeftTopButton(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LeftTopButton)
{
    ui->setupUi(this);
}

LeftTopButton::~LeftTopButton()
{
    delete ui;
}

//设置按钮样式10:流量关，11：流量开，20：超滤关，21：超滤开，30：肝素关，31：肝素开
void LeftTopButton::setButtonStyle(int i){
    switch (i) {
    case 10:
        ui->pushButton->setStyleSheet(buttonStyleFlowOff);
        break;
    case 11:
        ui->pushButton->setStyleSheet(buttonStyleFlowOn);
        break;
    case 20:
        ui->pushButton->setStyleSheet(buttonStyleHepariaOff);
        break;
    case 21:
        ui->pushButton->setStyleSheet(buttonStyleHepariaOn);
        break;
    case 30:
        ui->pushButton->setStyleSheet(buttonStyleUFOff);
        break;
    case 31:
        ui->pushButton->setStyleSheet(buttonStyleUFOn);
        break;
    default:
        break;
    }
}

//设置灯样式，同时灯的优先级大于按钮的优先级，按钮需要和灯同步。i：0：开，1：关，2：警告
void LeftTopButton::setLightStyle(int i,int buttonNum){
    if(i==0){
        ui->pushButtonLight->setStyleSheet(LightStyleOn);
    }else if(i==1){
        ui->pushButtonLight->setStyleSheet(LightStyleOff);
    }else{
        ui->pushButtonLight->setStyleSheet(LightStyleWarning);
    }
    setButtonStyle(buttonNum);
}
