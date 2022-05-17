#include "indexwindow.h"
#include "ui_indexwindow.h"


IndexWindow::IndexWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::IndexWindow)
{
    ui->setupUi(this);

    //串口类
    mySeriaPort = new MySeriaPort;

    initUI();
    connect(ui->widgetBottom,&BottomButtons::setCurrentProcessPage,this,&IndexWindow::changeCurrentPageProcess);
    connect(ui->widgetBottom,&BottomButtons::setCurrentParamPage,this,&IndexWindow::changeCurrentPage);
}

IndexWindow::~IndexWindow()
{
    delete ui;
}

void IndexWindow::initUI(){

    //加载自定义字体
    qDebug()<<"SourceHanSansCN-Medium.otf 字体加载成功？："<<onLoadFont(":/fonts/SourceHanSansCN-Medium.otf");
    //调整亮度
    CGammaRamp GammaRamp;
    GammaRamp.SetBrightness(NULL, 120);
    ui->stackedWidgetCenter->setCurrentIndex(1);
    //设置无边框+置顶
    //this->setWindowFlags(Qt::WindowStaysOnTopHint| Qt::CustomizeWindowHint| Qt::FramelessWindowHint);
    //setWindowFlags(Qt::WindowStaysOnTopHint);
    setWindowState(Qt::WindowFullScreen);
    qDebug()<<QSysInfo::kernelType();
}

//设置加载自定义字体
bool IndexWindow::onLoadFont(const QString& strPath)
{
    QFile dFontFile(strPath);
    if(!dFontFile.open(QIODevice::ReadOnly))
    {
        //说明打开字体文件失败了
        return false;
    }

    int nFontId = QFontDatabase::addApplicationFontFromData(dFontFile.readAll());
    if(nFontId == -1)
    {
        //说明加载字体文件失败了，该字体不可用
        return false;
    }

    QStringList lFontFamily = QFontDatabase::applicationFontFamilies(nFontId);
    if(lFontFamily.empty())
    {
        //说明从字体中获取字体簇失败了
        return false;
    }

    QFont font(lFontFamily.at(0));
    qApp->setFont(font);
    return true;
}
//切换界面槽函数
void IndexWindow::changeCurrentPage(int num){
    StatusValue::currentPage = num;//当前界面
    qDebug()<<"当前界面"<<StatusValue::currentPage<<"当前过程界面"<<StatusValue::currentPageProcess;
}
//切换界面槽函数
void IndexWindow::changeCurrentPageProcess(int num){

    StatusValue::currentPage = num;//当前界面
    StatusValue::currentPageProcess = num;//当前界面
    qDebug()<<"当前界面"<<StatusValue::currentPage<<"当前过程界面"<<StatusValue::currentPageProcess;
}

//返回一个实例(instance)
IndexWindow &IndexWindow::instance()
{
    static IndexWindow thiz;//这种实例化方法会自动回收内存
    return thiz;
}
