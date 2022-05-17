#ifndef INDEXPAGETYPETWO_H
#define INDEXPAGETYPETWO_H

#include <QWidget>
#include <tools/thresholdvalue.h>

namespace Ui {
class IndexPageTypeTwo;
}

class IndexPageTypeTwo : public QWidget
{
    Q_OBJECT

public:
    explicit IndexPageTypeTwo(QWidget *parent = nullptr);
    ~IndexPageTypeTwo();

public slots:
    void initPage();//初始化界面
private:
    Ui::IndexPageTypeTwo *ui;
};

#endif // INDEXPAGETYPETWO_H
