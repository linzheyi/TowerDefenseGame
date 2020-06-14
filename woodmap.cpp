#include "woodmap.h"
#include <QMainWindow>
#include <QPainter>
#include <QPixmap>
#include <QPaintEvent>
#include <QPushButton>
#include <QDebug>
#include <QString>
#include <QPoint>


WoodMap::WoodMap(QWidget *parent) : QMainWindow(parent)
{
    this->setFixedSize(1000,800);
    addTowerPositions();

}
void WoodMap::addTowerPositions(){
       QPoint pos[] =
       {
           QPoint(400, 120),
           QPoint(260, 130),
           QPoint(70 , 200),
           QPoint(350, 460),
           QPoint(215, 250),
           QPoint(350, 340),
           QPoint(470, 400)
           };
       int len = sizeof(pos) / sizeof(pos[0]);
        for (int i = 0; i < len; ++i)
            towerPositionsList.push_back(pos[i]);

}

void WoodMap::paintEvent(QPaintEvent *){


    QPixmap pixmap(":/picture/woodmap.bmp");
    QPainter mypainter(&pixmap);

    foreach (const TowerPosition &towerPos, towerPositionsList)
        towerPos.draw(&mypainter);

    QPainter painter(this);
    painter.drawPixmap(0, 0,this->width(),this->height(),pixmap);

  }
