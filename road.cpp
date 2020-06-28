#include "road.h"

#include <QPoint>
#include <QPainter>

Road::Road(QPoint pos):
    m_pos(pos),
    m_nextRoadPoint(NULL)
{
}

void Road::setNextRoadPoint(Road *nextWayPoint)
{
    this->m_nextRoadPoint=nextWayPoint;
}

Road * Road::getNextRoadPoint()
{
    return this->m_nextRoadPoint;
}

const QPoint Road::getPos()
{
    return this->m_pos;
}

void Road::draw(QPainter * painter) const
{
    painter->save();//保存原始的绘画参数
    painter->setPen(Qt::green);//设置画笔的颜色
    painter->drawEllipse(m_pos,4,4);//画一个半径为4的圆
    //注意，图片的大小单位是像素
    painter->drawEllipse(m_pos,1,1);//半径为1的圆
    if(m_nextRoadPoint)//如果存在下一个航点，就把这两个航点连接起来
    {
        painter->drawLine(m_pos,m_nextRoadPoint->getPos());//painter内的画直线的方法
    }
    painter->restore();//还原原来的画笔设置
}
