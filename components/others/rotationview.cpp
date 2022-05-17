#include "rotationview.h"

#include<windows.h>

#include <QLabel>

#include <QPropertyAnimation>

#include <QRect>
#include <qDebug>

RotationView::RotationView(QWidget *parent)

    : QGraphicsView(parent)

{

    //setWindowModality(Qt::NonModal);

    setWindowFlags(Qt::FramelessWindowHint);
    setAttribute(Qt::WA_TranslucentBackground);//设置背景透明
    setWindowOpacity(0);
    QGraphicsScene* scene = new QGraphicsScene(this);
    // 创建部件，并关联它们的信号和槽
    QLabel* plabel = new QLabel("");
    plabel->resize(99,102);
    plabel->setStyleSheet("border-image: url(:/public/right/bloodpump_closeimg.png);border-radius:44px;background:transparent;");
    // 将部件添加到场景中
    pushButton = scene->addWidget(plabel);
    //scene->addItem(pushButton);
    view = new QGraphicsView(scene,this);

    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    pushButton->setParent(view);

    pushButton->setPos(0, 0);

    view->resize(99, 102);
    view->setAttribute(Qt::WA_TranslucentBackground);
    view->show();
}

RotationView::~RotationView()

{

}

void RotationView::setturnangle(int angle)

{

    QRectF r = pushButton->boundingRect();

    pushButton->setTransform(QTransform()

                             .translate(r.width() / 2, r.height() / 2)

                             .rotate(angle - 360 * 1, Qt::ZAxis)

                             .translate(-r.width() / 2, -r.height() / 2));

    view->update();

}

void RotationView::startMove()

{

    QPropertyAnimation * linelength = new QPropertyAnimation(pushButton, "geometry");

    linelength->setDuration(3000);

    linelength->setStartValue(QRect(5,5,50,50));

    linelength->setEndValue(QRect(100, 100, 50, 50));

    linelength->setEasingCurve(QEasingCurve::Linear);

    linelength->start(QAbstractAnimation::DeleteWhenStopped);

}
