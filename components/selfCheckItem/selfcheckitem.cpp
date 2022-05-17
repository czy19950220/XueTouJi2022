#include "selfcheckitem.h"
#include "ui_selfcheckitem.h"

SelfCheckItem::SelfCheckItem(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SelfCheckItem)
{
    ui->setupUi(this);
    setCheckStatus(0);
    setCheckErrorCode("");
}

SelfCheckItem::~SelfCheckItem()
{
    delete ui;
}
//设置检测项名字
void SelfCheckItem::setCheckItemName(QString str){
    ui->checkItemName->setText(str);
}
//设置自检的状态
void SelfCheckItem::setCheckStatus(int num){
    switch (num) {
    case 0://未检测
        ui->selfCheckContent->setStyleSheet(unCheck);
        ui->checkErrorCode->setText("");
        break;
    case 1://检测中
        ui->selfCheckContent->setStyleSheet(checkIng);
        break;
    case 2://检测失败，不显示跳过按钮
        ui->selfCheckContent->setStyleSheet(checkError);
        break;
    case 3://检测成功
        ui->selfCheckContent->setStyleSheet(checkOk);
        ui->checkErrorCode->setText("");
        break;
    case 4://检测失败，显示跳过按钮
        ui->selfCheckContent->setStyleSheet(checkErrorJumpOver);
        break;
    default:
        break;
    }
}
//设置错误码
void SelfCheckItem::setCheckErrorCode(QString str){
    ui->checkErrorCode->setText(str);
}
