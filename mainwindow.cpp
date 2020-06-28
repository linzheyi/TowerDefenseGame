#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "button.h"
#include "secondwindow.h"
#include "tip.h"
#include <QMainWindow>
#include <QPainter>
#include <QPixmap>
#include <QPaintEvent>
#include <QPushButton>
#include <QDebug>
#include <QString>




MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    this->setFixedSize(1000,800);
    ui->setupUi(this);
    Button *start_btn=new Button(":/picture/start_btn.png");
    start_btn->setParent(this);
    start_btn->move(410,350);
    SecondWindow *sw=new SecondWindow;
    connect(start_btn,&QPushButton::clicked,this,[=](){

          this->hide();
          sw->show();

    });
    connect(sw,&SecondWindow::ClickBack,this,[=](){
        sw->hide();
        this->show();
    });
    Button *tip_btn=new Button(":/picture/tip.png");
    tip_btn->setParent(this);
    tip_btn->move(700,600);
    tip *t=new tip;
    connect(tip_btn,&QPushButton::clicked,this,[=](){
        this->hide();
        t->show();
    });
    connect(t,&tip::ClickBack,this,[=](){
        t->hide();
        this->show();
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *){

    QPainter painter(this);
    QPixmap pixmap(":/picture/mainwindow.bmp");
    painter.drawPixmap(0,0,this->width(),this->height(),pixmap);

}
