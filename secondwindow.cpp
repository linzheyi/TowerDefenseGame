#include "secondwindow.h"
#include "button.h"
#include "frozenmap.h"
#include "woodmap.h"
#include <QMainWindow>
#include <QPainter>
#include <QPixmap>
#include <QPaintEvent>
#include <QPushButton>
#include <QDebug>
#include <QString>

SecondWindow::SecondWindow(QWidget *parent) : QMainWindow(parent)

{
    this->setFixedSize(1000,800);
    Button *back_btn=new Button(":/picture/return.png");
    back_btn->setParent(this);
    back_btn->move(40,40);
    connect(back_btn,&Button::clicked,this,[=](){
        emit ClickBack();
    });

    Button *frozen_btn=new Button(":/picture/settowrbutton.png");
    frozen_btn->setParent(this);
    frozen_btn->move(150,100);
    FrozenMap *fm=new FrozenMap;
    connect(frozen_btn,&QPushButton::clicked,this,[=](){

        this->close();
        fm->show();

  });

    Button *wood_btn=new Button(":/picture/settowrbutton.png");
    wood_btn->setParent(this);
    wood_btn->move(270,225);
    WoodMap *wm=new WoodMap;
    connect(wood_btn,&QPushButton::clicked,this,[=](){

        this->close();
        wm->show();

  });


}
void SecondWindow::paintEvent(QPaintEvent *){
    QPainter painter(this);
    QPixmap pixmap(":/picture/secondwindow.bmp");
    painter.drawPixmap(0,0,this->width(),this->height(),pixmap);
}
