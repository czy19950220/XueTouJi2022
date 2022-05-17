#include "formheadercenter.h"
#include "ui_formheadercenter.h"

FormHeaderCenter::FormHeaderCenter(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormHeaderCenter)
{
    ui->setupUi(this);
}

FormHeaderCenter::~FormHeaderCenter()
{
    delete ui;
}

void FormHeaderCenter::setHeaderText(QString str){
    this->setVisible(1);
    ui->labelHeaderText->setText(str);
}

void FormHeaderCenter::setHeaderTextHide(){
    this->setVisible(0);
}
