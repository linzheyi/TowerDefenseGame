#ifndef ROAD_H
#define ROAD_H

#include <QPoint>
#include <QPainter>

//路线类，负责画出路线上的点

class Road
{
public:
    Road(QPoint pos);
    void setNextRoadPoint(Road * nextRoadPoint);//设置下一个点
    Road * getNextRoadPoint();//得到下一个点的指针
    const QPoint getPos();//得到本点的中心点
    void draw(QPainter * painter) const;//绘画
private:
    QPoint m_pos;//点的中心点
    Road * m_nextRoadPoint;//下一个点的指针
};

#endif // ROAD_H
