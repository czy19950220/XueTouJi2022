#ifndef LEFTBOTTOM_H
#define LEFTBOTTOM_H

#include <QWidget>
#include <tools/GlobalHead.h>

namespace Ui {
class LeftBottom;
}

class LeftBottom : public QWidget
{
    Q_OBJECT

public:
    explicit LeftBottom(QWidget *parent = nullptr);
    ~LeftBottom();

public slots:
    void setNameUnit(QString nameStr, QString unitStr);//设置单位和名字
    void setPressureValue(int num);//设置动静脉压，跨膜压值
    void setPressureValueConductivity(int num);//设置电导度值
    void setNameUnitStyle(int i);//设置单位和名字的样式
    void setStyleAlarm();//设置报警样式
    void setStyleNormal();//设置正常样式
    void setAnimation();//执行动画
    void setAnimationEnd();//动画结束
    void setProgressBarThresholdValue(int min,int max);//设置进度条最大值最小值

private slots:
    void on_pushButton_clicked();//点击当前控件

private:
    Ui::LeftBottom *ui;
    QGraphicsOpacityEffect * m_pGraphicsOpacityEffect1;//动画效果
    QPropertyAnimation *myAnimation;//动画
    //报警样式
    QString alarmValueStyle = QString("%1").arg("font-size:48px;font-weight:blod;color:#e27053;");
    QString alarmProgressBarStyle = QString("%1").arg("QProgressBar{border-radius:2px;border:none;background-color: #e37053;}"
                                                      "QProgressBar:chunk{border-radius:2px;background-color:#e37053;}");
    //正常样式
    QString normalValueStyle = QString("%1").arg("font-size:48px;font-weight:blod;color:#409ab4;");
    QString normalProgressBarStyle = QString("%1").arg("QProgressBar{border-radius:2px;border:none;background-color: #54ce7d;}"
                                                       "QProgressBar:chunk{border-radius:2px;background-color:#54ce7d;}");
};

#endif // LEFTBOTTOM_H
