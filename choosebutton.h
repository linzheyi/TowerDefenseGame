#ifndef CHOOSEBUTTON_H
#define CHOOSEBUTTON_H

#include <QObject>
#include <QPainter>
#include <QString>
#include <QPoint>
#include <QSize>

#include "woodmap.h"

class WoodMap;

//选择框类

class chooseButton : public QObject
{
    Q_OBJECT
public:
    chooseButton(QPoint pos,WoodMap *game);
    ~chooseButton();

    void draw(QPainter * painter)const;//绘画选择框
    void getRemoved();//点击后移除选择框
    bool containPos(QPoint pos);//判断鼠标的点击点，是否在选择框的内部
    QPoint getPos();//得到选择框的左上点
private:
    WoodMap * m_game;//指向woodmap的指针
    QPoint m_pos;//图片的左上角
    QString m_chooseBoxImagePath[2];//用来储存选择框内的防御塔的图片

    static const QSize m_fixedSize;

signals:

};

#endif // CHOOSEBUTTON_H
