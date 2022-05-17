#ifndef INDEXWINDOW_H
#define INDEXWINDOW_H

#include <QMainWindow>
#include "tools/GlobalHead.h"
#include "tools/MyTools.h"
#include "threads/timethread.h"
#include "tools/utils/cgammaramp.h"
#include "tools/statusvalue.h"

namespace Ui {
class IndexWindow;
}

class IndexWindow : public QMainWindow
{
    Q_OBJECT

signals:

public:
    explicit IndexWindow(QWidget *parent = nullptr);
    ~IndexWindow();

public slots:
    static IndexWindow& instance();
    void changeCurrentPage(int num);//切换当前界面
    void changeCurrentPageProcess(int num);//切换当前过程界面
private:
    Ui::IndexWindow *ui;
    MySeriaPort *mySeriaPort;//自定义串口类
private:
    bool onLoadFont(const QString &strPath);//设置加载字体
    void initUI();//初始化UI
};

#endif // INDEXWINDOW_H
