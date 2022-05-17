#ifndef BLOODPUMP_H
#define BLOODPUMP_H

#include <QWidget>
#include "tools/GlobalHead.h"
#include "./components/others/rotationview.h"

namespace Ui {
class BloodPump;
}

class BloodPump : public QWidget
{
    Q_OBJECT

public:
    explicit BloodPump(QWidget *parent = nullptr);
    ~BloodPump();

public slots:
    void setBloodPumpOpenClose(bool open);//设置血泵开关状态
private slots:
    void on_pushButtonShade_clicked();//按钮点击事件

    void on_timeOut();//计时器
private:
    int m_angle;
    int m_type;
private:
    Ui::BloodPump *ui;
    RotationView* roview;
    QPropertyAnimation* rotation;
    QTimer *m_timer = nullptr;
    int m_i = 0;
    //血泵当前开的样式
    QString widgetContentStyleOpen = QString("%0").arg("#widgetContent{background-image: url(:/public/right/bloodpump_open.png);}"
                                                   "#bloodPumpPoint{"
                                                       "background-image:url(:/public/right/bloodlight_open.png);"
                                                       "background-repeat:no-repeat;}"
                                                   "#pushButton{background-image: url(:/public/right/bloodpump_opening.png);}");
    //血泵当前关的样式
    QString widgetContentStyleClose = QString("%0").arg("#widgetContent{background-image: url(:/public/right/bloodpump_close.png);}"
                                                   "#bloodPumpPoint{"
                                                       "background-image:url(:/public/right/bloodlight_close.png);"
                                                       "background-repeat:no-repeat;}"
                                                        "#pushButton{background-image: url(:/public/right/bloodpump_closeimg.png);}");
    void startBloodPumpCartoon();//血泵启动动画
};

#endif // BLOODPUMP_H
