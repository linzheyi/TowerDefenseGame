#include "tip.h"
#include "button.h"
#include "mainwindow.h"
#include <QMainWindow>
#include <QPainter>
#include <QPixmap>
#include <QPaintEvent>
#include <QPushButton>
#include <QDebug>
#include <QString>
tip::tip(QWidget *parent) : QMainWindow(parent)
{
    this->setFixedSize(600,300);
    Button *back_btn=new Button(":/picture/return.png");
    back_btn->setParent(this);
    back_btn->move(20,20);
    connect(back_btn,&Button::clicked,this,[=](){
        emit ClickBack();
    });
}

void tip::paintEvent(QPaintEvent *){

    QPainter painter(this);
    QPixmap pixmap(":/picture/tipwindow.jpg");
    painter.drawPixmap(0,0,this->width(),this->height(),pixmap);

}
