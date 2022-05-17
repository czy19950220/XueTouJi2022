#include "formheadleft.h"
#include "ui_formheadleft.h"

FormHeadLeft::FormHeadLeft(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormHeadLeft)
{
    ui->setupUi(this);
    //显示时间线程--动态分配空间, 不能指定父对象
    timeThread = new TimeThread;//指定父对象后下面不可以在加入子线程中,下面的子线程相当于其父对象
    threadGetTime = new QThread(this);//创建子线程
    timeThread->moveToThread(threadGetTime);//把自定义的线程加入到子线程中
    connect(this,&FormHeadLeft::startGetTime,timeThread,&TimeThread::startGetTime);
    connect(timeThread,&TimeThread::sendCurrentData,this,&FormHeadLeft::setCurrentTime);
    threadGetTime->start();//启动线程,但是没有启动线程处理函数
    emit startGetTime();
    setPushButtonCheckDetailSeeable(false);
}

FormHeadLeft::~FormHeadLeft()
{
    delete ui;
}
//设置当前时间
void FormHeadLeft::setCurrentTime(QString str){
    this->ui->labelTime->setText(str);
}
//设置当前状态标题
void FormHeadLeft::setCurrentTitle(QString str){
    this->ui->labelTitle->setText(str);
}
//查看自检详情按钮点击事件
void FormHeadLeft::on_pushButtonCheckDetail_clicked()
{
    emit checkDetailButtonClicked();
}
//设置查看按钮的文字
void FormHeadLeft::setPushButtonCheckDetailText(QString str){
    ui->pushButtonCheckDetail->setText(str);
}
//设置查看按钮是否可见
void FormHeadLeft::setPushButtonCheckDetailSeeable(bool seeable){
    if(seeable){
        ui->pushButtonCheckDetail->setVisible(1);
    }else{
        ui->pushButtonCheckDetail->setVisible(0);
    }
}
