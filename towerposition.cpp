#include "towerposition.h"
#include <QPainter>
#include <QPixmap>

const QSize TowerPosition::t_fixedSize(44, 44);

//构造函数，参数：塔的绘制坐标点，图片地址
TowerPosition::TowerPosition(QPoint pos, const QPixmap &sprite)
    : t_pos(pos)
    , t_hasTower(false)
    , t_sprite(sprite)
{
}

//塔基中心点
const QPoint TowerPosition::centerPos() const
{
    QPoint offsetPoint(t_fixedSize.width() / 2, t_fixedSize.height() / 2);
    return t_pos + offsetPoint;
}

bool TowerPosition::containPoint(const QPoint &pos) const
{
    bool isXHere = t_pos.x() < pos.x() && pos.x() < (t_pos.x() + t_fixedSize.width());
    bool isYHere = t_pos.y() < pos.y() && pos.y() < (t_pos.y() + t_fixedSize.height());
    return isXHere && isYHere;
}

//输出判断是否有塔
bool TowerPosition::hasTower() const
{
    return t_hasTower;
}

void TowerPosition::setHasTower(bool hasTower/* = true*/)
{
    t_hasTower = hasTower;
}

void TowerPosition::draw(QPainter *painter) const
{
    painter->drawPixmap(t_pos.x(),t_pos.y(),t_sprite);
}
