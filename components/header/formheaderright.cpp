#include "formheaderright.h"
#include "ui_formheaderright.h"

FormHeaderRight::FormHeaderRight(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormHeaderRight)
{
    ui->setupUi(this);
    setPushButtonSettingMode(settingButtonMode);
    setWidgetAlarmStatue(0);
}

FormHeaderRight::~FormHeaderRight()
{
    delete ui;
}

//设置按钮点击事件
void FormHeaderRight::on_pushButtonSetting_clicked()
{
    switch (settingButtonMode) {
    case 1://当前是其他界面，切换到设置界面
        setPushButtonSettingMode(2);
        emit setCurrentSettingPage(2);

        break;
    case 2://当前是设置界面，切换到其他界面
        setPushButtonSettingMode(1);
        emit setCurrentSettingPage(1);

        break;
    case 3://当前是不可点击状态

        break;
    default:
        break;
    }

}

void FormHeaderRight::setPushButtonSettingMode(int i){
    switch (i) {
    case 1://其他界面状态
        settingButtonMode = i;
        ui->pushButtonSetting->setStyleSheet(buttonSettingStyle); //设置背景图片
        break;
    case 2://设置界面状态
        settingButtonMode = i;
        ui->pushButtonSetting->setStyleSheet(buttonSettingClickedStyle); //设置背景图片
        break;
    case 3://不可点击状态
        ui->pushButtonSetting->setStyleSheet(buttonSettingUnClickStyle); //设置背景图片
        settingButtonMode = i;
        break;
    default:
        break;
    }
}
//设置报警模块的个数和样式
void FormHeaderRight::setWidgetAlarmStatue(int alarmNum){
    ui->labelAlarm->setAttribute(Qt::WA_TransparentForMouseEvents);
    if(alarmNum<=0){
        alarmNum = 0;
        ui->labelAlarm->setText("");
        ui->pushButtonAlarm->setStyleSheet(buttonAlarmNothingStyle);
    }else{
        ui->labelAlarm->setText(QString("%1").arg(alarmNum));
        ui->pushButtonAlarm->setStyleSheet(buttonAlarmStyle);
    }
}

//点击进行静音
void FormHeaderRight::on_pushButtonSilence_released()
{
    ui->pushButtonSilence->setStyleSheet(buttonSilenceClickedStyle);

}
//静音取消
void FormHeaderRight::pushButtonSilenceNormal()
{
    ui->pushButtonSilence->setStyleSheet(buttonSilenceStyle);
}

