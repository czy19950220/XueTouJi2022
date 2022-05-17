#ifndef FORMHEADERRIGHT_H
#define FORMHEADERRIGHT_H

#include <QWidget>
#include "tools/GlobalHead.h"

namespace Ui {
class FormHeaderRight;
}

class FormHeaderRight : public QWidget
{
    Q_OBJECT

public:
    explicit FormHeaderRight(QWidget *parent = nullptr);
    ~FormHeaderRight();

public:
    void setPushButtonSettingMode(int i);//设置当前设置按钮状态
public slots:
    void setWidgetAlarmStatue(int alarmNum);//设置报警数量
    void pushButtonSilenceNormal();//报警静音回复正常
private slots:
    void on_pushButtonSetting_clicked();//设置按钮点击

    void on_pushButtonSilence_released();//静音按钮点击释放函数

private:
    Ui::FormHeaderRight *ui;
    int settingButtonMode = 1;//1:当前是其他界面，2：当前是设置界面，3：当前不可点击
    QString buttonSettingStyle = QString("%1").arg("FormHeaderRight #pushButtonSetting{background:url(:/public/header/header_setting.png);}");
    QString buttonSettingClickedStyle = QString("%1").arg("FormHeaderRight #pushButtonSetting{background:url(:/public/header/header_setting_clicked.png);}");
    QString buttonSettingUnClickStyle = QString("%1").arg("FormHeaderRight #pushButtonSetting{background-image:url(:/public/header/header_setting_unclicked.png);}");
    QString buttonAlarmNothingStyle = QString("%1").arg("#pushButtonAlarm{background-image:url(:/public/header/header_message_nothing.png);}"
                                                        " #pushButtonAlarm:pressed{background-image:url(:/public/header/header_message_nothing_clicked.png);}");
    QString buttonAlarmStyle = QString("%1").arg("#pushButtonAlarm{background-image:url(:/public/header/header_messages.png);}"
                                                 " #pushButtonAlarm:pressed{background-image:url(:/public/header/header_messages_clicked.png);}");
    QString buttonSilenceStyle = QString("%1").arg("#pushButtonSilence{background-image:url(:/public/header/header_alarm.png);}"
                                                   "#pushButtonSilence:pressed{background-image:url(:/public/header/header_alarm_clicked.png)}");
    QString buttonSilenceClickedStyle = QString("%1").arg("#pushButtonSilence{background-image:url(:/public/header/header_alarm_close.png)}");
signals:
    void setCurrentSettingPage(int i);//触发当前是否是设置界面
};

#endif // FORMHEADERRIGHT_H
