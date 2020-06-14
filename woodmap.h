#ifndef WOODMAP_H
#define WOODMAP_H

#include <QMainWindow>
#include <QPainter>
#include <QPixmap>
#include <QPaintEvent>
#include <QPushButton>
#include <QString>
#include <QList>
#include "towerposition.h"

class WoodMap : public QMainWindow
{
    Q_OBJECT
public:
    explicit WoodMap(QWidget *parent = nullptr);
     void paintEvent(QPaintEvent *);


private:
     //塔基管理列表
     QList<TowerPosition> towerPositionsList;

     //说明塔基位置
     void addTowerPositions();



signals:

};

#endif // WOODMAP_H
