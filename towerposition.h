#ifndef TOWERPOSITION_H
#define TOWERPOSITION_H

#include <QPixmap>
#include <QPainter>
#include <QPoint>
#include <QSize>


class TowerPosition
{
public:
    TowerPosition(QPoint pos, const QPixmap &sprite = QPixmap(":/picture/choose.png"));
    void setHasTower(bool hasTower = true);
    bool hasTower() const;
    const QPoint centerPos() const;
    bool containPoint(const QPoint &pos) const;
    void draw(QPainter *painter) const;

private:
    QPoint  t_pos;          //塔的绘制坐标点（左上角）
    bool    t_hasTower;     //是否有塔
    QPixmap	t_sprite;       //保存塔的图片路径

    static const QSize t_fixedSize;

};

#endif // TOWERPOSITION_H
