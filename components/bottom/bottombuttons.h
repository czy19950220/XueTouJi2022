#ifndef BOTTOMBUTTONS_H
#define BOTTOMBUTTONS_H

#include <QWidget>
#include "./tools/GlobalHead.h"

namespace Ui {
class BottomButtons;
}

class BottomButtons : public QWidget
{
    Q_OBJECT

public:
    explicit BottomButtons(QWidget *parent = nullptr);
    ~BottomButtons();

public slots:
    void setButtonDisabled(int button1, int button2, int button3, int button4, int button5);//设置按钮样式

    void resetParamButtonStyle();//重置参数按钮样式
private slots:
    void on_rbBlood_clicked();

    void on_rbPrepare_clicked();

    void on_rbTreat_clicked();

    void on_rbBloodReturn_clicked();

    void on_rbClean_clicked();

    void on_radioParamDialysis_clicked();

    void on_radioParamUF_clicked();

    void on_radioParamHeparin_clicked();

private://私有变量
    Ui::BottomButtons *ui;
    QString leftButtonDisabledStyle = "QRadioButton::indicator{   image: url(:/public/bottom/button_close.png);}";
    QString leftButtonUnclickStyle = "QRadioButton::indicator:unchecked{	image: url(:/public/bottom/button_open.png);}";
    QString leftButtonClickedStyle = "QRadioButton::indicator:checked{	image: url(:/public/bottom/button_ing.png);}";
    QString rightButtonUnclickStyle = "background-image: url(:/public/bottom/paramset.png);";
    QString rightButtonClickedStyle = "background-image: url(:/public/bottom/paramset_clicked.png);";
private://私有方法
    void setButtonStyle(QRadioButton *mButton, int num);

signals:
    void setCurrentParamPage(int num);//参数界面切换
    void setCurrentProcessPage(int num);//过程界面切换
};

#endif // BOTTOMBUTTONS_H
