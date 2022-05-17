#include "indexpagetypetwo.h"
#include "ui_indexpagetypetwo.h"

IndexPageTypeTwo::IndexPageTypeTwo(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::IndexPageTypeTwo)
{
    ui->setupUi(this);
    initPage();
}

IndexPageTypeTwo::~IndexPageTypeTwo()
{
    delete ui;
}
//初始化界面
void IndexPageTypeTwo::initPage(){
    //初始化流量，肝素，超滤，全部设置为关闭状态
    //0：开，1：关。10:流量关，11：流量开，20：超滤关，21：超滤开，30：肝素关，31：肝素开
    ui->widgetFlow->setLightStyle(1,10);
    ui->widgetHeparin->setLightStyle(1,20);
    ui->widgetUF->setLightStyle(1,30);
    //初始化气压
    //动脉压
    ui->pressureArterial->setNameUnit("动脉压","mmHg");
    ui->pressureArterial->setProgressBarThresholdValue(ThresholdValue::tv_arterial_max,ThresholdValue::tv_arterial_min);
    ui->pressureArterial->setPressureValue(0);
    //静脉压
    ui->pressureVenous->setNameUnit("静脉压","mmHg");
    ui->pressureVenous->setProgressBarThresholdValue(ThresholdValue::tv_venous_max,ThresholdValue::tv_venous_min);
    ui->pressureVenous->setPressureValue(0);
    //电导度
    ui->pressureConductivity->setNameUnit("电导度","mS/cm");
    ui->pressureConductivity->setProgressBarThresholdValue(ThresholdValue::tv_conductivity_max,ThresholdValue::tv_conductivity_min);
    ui->pressureConductivity->setPressureValue(0);
    //跨膜压
    ui->pressureTmp->setNameUnit("跨膜压","mmHg");
    ui->pressureTmp->setProgressBarThresholdValue(ThresholdValue::tv_tmp_max,ThresholdValue::tv_tmp_min);
    ui->pressureTmp->setPressureValueConductivity(0);
    //设置当前页
    ui->stackedWidget->setCurrentIndex(0);//默认第一页：自检
    ui->pageSelfCheck->checkSuccess();
    ui->pageSelfCheck->initPage();
}
