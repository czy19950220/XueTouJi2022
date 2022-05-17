#include "bottombuttons.h"
#include "ui_bottombuttons.h"

BottomButtons::BottomButtons(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BottomButtons)
{
    ui->setupUi(this);
    setButtonDisabled(-1,-1,0,0,1);
    ui->widgetTextLeft->setAttribute(Qt::WA_TransparentForMouseEvents, true);
}

BottomButtons::~BottomButtons()
{
    delete ui;
}

//设置按钮样式，-1：不可点击，0：未点击，1：当前点击了
void BottomButtons::setButtonDisabled(int button1,int button2,int button3,int button4,int button5){
    setButtonStyle(ui->rbBlood,button1);
    setButtonStyle(ui->rbPrepare,button2);
    setButtonStyle(ui->rbTreat,button3);
    setButtonStyle(ui->rbBloodReturn,button4);
    setButtonStyle(ui->rbClean,button5);
}
//设置按钮的样式
void BottomButtons::setButtonStyle(QRadioButton *mButton,int num){
    if(num == -1){
        mButton->setChecked(false);
        mButton->setDisabled(true);
        mButton->setStyleSheet(leftButtonDisabledStyle);
    }else if(num == 0){
        mButton->setChecked(false);
        mButton->setDisabled(false);
    }else{
        mButton->setChecked(true);
        mButton->setDisabled(false);
    }
}

//血路按钮点击
void BottomButtons::on_rbBlood_clicked()
{
    if(StatusValue::currentPage == 1){//当前界面是本界面就返回
        return;
    }
    emit setCurrentProcessPage(1);
    resetParamButtonStyle();
}
//准备按钮 点击
void BottomButtons::on_rbPrepare_clicked()
{
    if(StatusValue::currentPage == 2){//当前界面是本界面就返回
        return;
    }
    emit setCurrentProcessPage(2);
    resetParamButtonStyle();
}
//治疗按钮点击
void BottomButtons::on_rbTreat_clicked()
{
    if(StatusValue::currentPage == 3){//当前界面是本界面就返回
        return;
    }
    emit setCurrentProcessPage(3);
    resetParamButtonStyle();
}
//回血按钮点击
void BottomButtons::on_rbBloodReturn_clicked()
{
    if(StatusValue::currentPage == 4){//当前界面是本界面就返回
        return;
    }
    emit setCurrentProcessPage(4);
    resetParamButtonStyle();
}
//清洗按钮点击
void BottomButtons::on_rbClean_clicked()
{
    if(StatusValue::currentPage == 5){//当前界面是本界面就返回
        return;
    }
    emit setCurrentProcessPage(5);
    resetParamButtonStyle();
}
//透析参数
void BottomButtons::on_radioParamDialysis_clicked()
{
    if(StatusValue::currentPage == 100){//当前界面是本参数界面，就返回过程界面
        ui->radioParamDialysis->setStyleSheet(rightButtonUnclickStyle);
        emit setCurrentProcessPage(StatusValue::currentPageProcess);
        return;
    }
    resetParamButtonStyle();
    ui->radioParamDialysis->setStyleSheet(rightButtonClickedStyle);
    emit setCurrentParamPage(100);
}
//超滤参数
void BottomButtons::on_radioParamUF_clicked()
{
    if(StatusValue::currentPage == 101){//当前界面是本参数界面，就返回过程界面
        ui->radioParamUF->setStyleSheet(rightButtonUnclickStyle);
        emit setCurrentProcessPage(StatusValue::currentPageProcess);
        return;
    }
    resetParamButtonStyle();
    ui->radioParamUF->setStyleSheet(rightButtonClickedStyle);
    emit setCurrentParamPage(101);
}
//肝素参数
void BottomButtons::on_radioParamHeparin_clicked()
{
    if(StatusValue::currentPage == 102){//当前界面是本参数界面，就返回过程界面
        ui->radioParamHeparin->setStyleSheet(rightButtonUnclickStyle);
        emit setCurrentProcessPage(StatusValue::currentPageProcess);
        return;
    }
    resetParamButtonStyle();
    ui->radioParamHeparin->setStyleSheet(rightButtonClickedStyle);
    emit setCurrentParamPage(102);
}
//重置参数按钮样式
void BottomButtons::resetParamButtonStyle(){
    ui->radioParamDialysis->setStyleSheet(rightButtonUnclickStyle);
    ui->radioParamUF->setStyleSheet(rightButtonUnclickStyle);
    ui->radioParamHeparin->setStyleSheet(rightButtonUnclickStyle);
}
