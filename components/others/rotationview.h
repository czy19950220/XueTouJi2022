#ifndef ROTATIONVIEW_H

#define ROTATIONVIEW_H

#include <QGraphicsScene>

#include <QGraphicsView>

#include <QGraphicsWidget>

#include <QTextEdit>

#include <QPushButton>

#include <QGraphicsProxyWidget>

#include <QGraphicsLinearLayout>

class RotationView : public QGraphicsView

{

    Q_OBJECT

    Q_PROPERTY(int angle READ turnangle WRITE setturnangle)//自定义角度属性

public:

    RotationView(QWidget *parent);

    ~RotationView();

    int turnangle() { return angle; };//get方法

    void setturnangle(int angle);//set方法，动画会通过这个函数输入插值，使图片转动。

    void startMove();

private:

    QGraphicsView* view = NULL;

    int angle=0;

    QGraphicsWidget *pushButton = NULL;

};

#endif // ROTATIONVIEW_H
