#include "selfcheck.h"
#include "ui_selfcheck.h"

SelfCheck::SelfCheck(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SelfCheck)
{
    ui->setupUi(this);
    initPage();

    checkSuccess();
}

SelfCheck::~SelfCheck()
{
    delete ui;
}

//初始化界面
void SelfCheck::initPage(){
    //血路系统、动脉压、静脉压、空气探测器、光学探测器、漏血、肝素
    ui->widgetBloodLine->setCheckItemName("血路检测");
    ui->widgetBloodLine->setCheckStatus(0);
    ui->widgetArterialPressure->setCheckItemName("动脉压");
    ui->widgetArterialPressure->setCheckStatus(0);
    ui->widgetVenousPressure->setCheckItemName("静脉压");
    ui->widgetVenousPressure->setCheckStatus(0);
    ui->widgetAirDetector->setCheckItemName("空气探测器");
    ui->widgetAirDetector->setCheckStatus(0);
    ui->widgetOpticalDetector->setCheckItemName("光学探测器");
    ui->widgetOpticalDetector->setCheckStatus(0);
    ui->widgetBloodLeak->setCheckItemName("漏血");
    ui->widgetBloodLeak->setCheckStatus(0);
    ui->widgetHeparin->setCheckItemName("肝素");
    ui->widgetHeparin->setCheckStatus(0);
    //旁路、温度、负压、电导度、正压、超滤功能、透析液过滤器
    ui->widgetByPass->setCheckItemName("旁路");
    ui->widgetByPass->setCheckStatus(0);
    ui->widgetTemperature->setCheckItemName("温度");
    ui->widgetTemperature->setCheckStatus(0);
    ui->widgetNegativePressure->setCheckItemName("负压");
    ui->widgetNegativePressure->setCheckStatus(0);
    ui->widgetConductivity->setCheckItemName("电导度");
    ui->widgetConductivity->setCheckStatus(0);
    ui->widgetPositivePressure->setCheckItemName("正压");
    ui->widgetPositivePressure->setCheckStatus(0);
    ui->widgetUF->setCheckItemName("超滤功能");
    ui->widgetUF->setCheckStatus(0);
    ui->widgetDialysate->setCheckItemName("透析液过滤器 ");
    ui->widgetDialysate->setCheckStatus(0);
}

//设置检测中状态--num:哪一个检测项，status：状态，0未检测、1检测中，2检测失败，不显示跳过按钮，3检测成功、4检测失败，显示跳过按钮
void SelfCheck::setCheckItemStatus(int itemNum,int status){
    switch (itemNum) {
    case 1://血路检测
        ui->widgetBloodLine->setCheckStatus(status);
        break;
    case 2://动脉压
        ui->widgetArterialPressure->setCheckStatus(status);
        break;
    case 3://静脉压
        ui->widgetVenousPressure->setCheckStatus(status);
        break;
    case 4://空气探测器
        ui->widgetAirDetector->setCheckStatus(status);
        break;
    case 5://光学探测器
        ui->widgetOpticalDetector->setCheckStatus(status);
        break;
    case 6://漏血
        ui->widgetBloodLeak->setCheckStatus(status);
        break;
    case 7://肝素
        ui->widgetHeparin->setCheckStatus(status);
        break;
    case 8://旁路
        ui->widgetByPass->setCheckStatus(status);
        break;
    case 9://温度
        ui->widgetTemperature->setCheckStatus(status);
        break;
    case 10://负压
        ui->widgetNegativePressure->setCheckStatus(status);
        break;
    case 11://电导度
        ui->widgetConductivity->setCheckStatus(status);
        break;
    case 12://正压
        ui->widgetPositivePressure->setCheckStatus(status);
        break;
    case 13://超滤功能
        ui->widgetUF->setCheckStatus(status);
        break;
    case 14://透析液过滤器
        ui->widgetDialysate->setCheckStatus(status);
        break;
    default:
        break;
    }
}
//设置错误码
void SelfCheck::setCheckErrorCode(int itemNum,QString str){
    switch (itemNum) {
    case 1://血路检测
        ui->widgetBloodLine->setCheckErrorCode(str);
        break;
    case 2://动脉压
        ui->widgetArterialPressure->setCheckErrorCode(str);
        break;
    case 3://静脉压
        ui->widgetVenousPressure->setCheckErrorCode(str);
        break;
    case 4://空气探测器
        ui->widgetAirDetector->setCheckErrorCode(str);
        break;
    case 5://光学探测器
        ui->widgetOpticalDetector->setCheckErrorCode(str);
        break;
    case 6://漏血
        ui->widgetBloodLeak->setCheckErrorCode(str);
        break;
    case 7://肝素
        ui->widgetHeparin->setCheckErrorCode(str);
        break;
    case 8://旁路
        ui->widgetByPass->setCheckErrorCode(str);
        break;
    case 9://温度
        ui->widgetTemperature->setCheckErrorCode(str);
        break;
    case 10://负压
        ui->widgetNegativePressure->setCheckErrorCode(str);
        break;
    case 11://电导度
        ui->widgetConductivity->setCheckErrorCode(str);
        break;
    case 12://正压
        ui->widgetPositivePressure->setCheckErrorCode(str);
        break;
    case 13://超滤功能
        ui->widgetUF->setCheckErrorCode(str);
        break;
    case 14://透析液过滤器
        ui->widgetDialysate->setCheckErrorCode(str);
        break;
    default:
        break;
    }
}
//重新测试按钮点击事件
void SelfCheck::on_pushButtonCheckAgain_clicked()
{
    //发送自检命令
    qDebug()<<"重新检测";
}

//测试失败
void SelfCheck::checkFailed(){
    ui->pushButtonCheckAgain->setVisible(true);
}
//测试成功
void SelfCheck::checkSuccess()
{
    ui->pushButtonCheckAgain->setVisible(false);
}
