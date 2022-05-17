#ifndef FORMHEADERCENTER_H
#define FORMHEADERCENTER_H

#include <QWidget>

namespace Ui {
class FormHeaderCenter;
}

class FormHeaderCenter : public QWidget
{
    Q_OBJECT

public:
    explicit FormHeaderCenter(QWidget *parent = nullptr);
    ~FormHeaderCenter();

public slots:
    void setHeaderText(QString str);//设置当前标题文字
    void setHeaderTextHide();//设置标题文字隐藏
private:
    Ui::FormHeaderCenter *ui;
};

#endif // FORMHEADERCENTER_H
