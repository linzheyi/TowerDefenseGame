#include "frozenmap.h"
#include <QMainWindow>
#include <QPainter>
#include <QPixmap>
#include <QPaintEvent>
#include <QPushButton>
#include <QDebug>
#include <QString>

FrozenMap::FrozenMap(QWidget *parent) : QMainWindow(parent)
{
    this->setFixedSize(1000,800);
}
void FrozenMap::paintEvent(QPaintEvent *){
    QPainter painter(this);
    QPixmap pixmap(":/picture/frozenmap.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pixmap);

}
