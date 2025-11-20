#include "top.h"
#include <QPainter>
#include <QtMath>
#include <iostream>
#include <ctime>

Top::Top(QWidget *parent)
    : QWidget(parent),
    resim(setImage()),
    px(rand() % 400 + 1), py(rand() % 300 + 1), dx(rand() % 10 - 5), dy(rand() % 10 - 5) //15 ya da 5 bulup - 10 yapmayı dusundum

//    px(rand() % 400 + 1), py(rand() % 300 + 1), dx(hiz - 10), dy(hiz - 10)
{
    resim = resim.scaled(70, 70, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    resize(resim.size());
    zamanlayici = new QTimer(this);
    connect(zamanlayici, &QTimer::timeout, this, &Top::moveTop);
    zamanlayici->start(16);
}
/*
void Top::hizBulma(int &hiz){
    srand(time(NULL));
    hiz = 0
    while(hiz != 2){
        hiz = rand() % 2 + 1;
    }
    hiz *= 5;
}
*/
QString Top::setImage()
{

    srand(time(NULL));
    int a = rand() % 4 + 1;
    //std::cout << a << std::endl;

    if(a == 1) return ":/0.jpg";
    if(a == 2) return ":/1.jpg";
    if(a == 3) return ":/2.jpg";
    if(a == 4) return ":/3.jpg";
}

void Top::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.drawPixmap(0, 0, resim);
}

void Top::moveTop()
{
    px += dx;
    py += dy;

    if (px <= 0 || px + width() >= parentWidget()->width()) dx = -dx;
    if (py <= 0 || py + height() >= parentWidget()->height()) dy = -dy;

    move(px, py);
}
