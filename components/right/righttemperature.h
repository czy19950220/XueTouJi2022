#ifndef RIGHTTEMPERATURE_H
#define RIGHTTEMPERATURE_H

#include <QWidget>

namespace Ui {
class RightTemperature;
}

class RightTemperature : public QWidget
{
    Q_OBJECT

public:
    explicit RightTemperature(QWidget *parent = nullptr);
    ~RightTemperature();

public slots:
    void setTemperatureValue(int num);//设置温度值，需要传入乘以10的值
private:
    Ui::RightTemperature *ui;
};

#endif // RIGHTTEMPERATURE_H
