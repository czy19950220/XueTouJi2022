#ifndef LEFTTOPBUTTON_H
#define LEFTTOPBUTTON_H

#include <QWidget>

namespace Ui {
class LeftTopButton;
}

class LeftTopButton : public QWidget
{
    Q_OBJECT

public:
    explicit LeftTopButton(QWidget *parent = nullptr);
    ~LeftTopButton();

public slots:
    void setButtonStyle(int i);//设置按钮样式
    void setLightStyle(int i,int buttonNum);//设置灯的样式,按钮样式
private:
    Ui::LeftTopButton *ui;
    QString buttonText;
    //流量样式
    QString buttonStyleFlowOff = QString("%1").arg("background-image:url(:/public/left/left_flow_off.png)");
    QString buttonStyleFlowOn = QString("%1").arg("background-image:url(:/public/left/left_flow_on.png)");
    //肝素样式
    QString buttonStyleHepariaOff = QString("%1").arg("background-image:url(:/public/left/left_heparin_off.png)");
    QString buttonStyleHepariaOn = QString("%1").arg("background-image:url(:/public/left/left_heparin_on.png)");
    //超滤样式
    QString buttonStyleUFOff = QString("%1").arg("background-image:url(:/public/left/left_uf_off.png)");
    QString buttonStyleUFOn = QString("%1").arg("background-image:url(:/public/left/left_uf_on.png)");

    QString LightStyleOn = QString("%1").arg("background-image:url(:/public/left/left_light_on.png)");
    QString LightStyleOff = QString("%1").arg("background-image:url(:/public/left/left_light_off.png)");
    QString LightStyleWarning = QString("%1").arg("background-image:url(:/public/left/left_light_warning.png)");
};

#endif // LEFTTOPBUTTON_H
