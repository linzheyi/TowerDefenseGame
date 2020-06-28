#ifndef ENEMY_H
#define ENEMY_H

#include <QObject>
#include <QPoint>
#include <QString>
#include <QPainter>
#include <QSize>

#include "road.h"
#include "woodmap.h"
#include "tower.h"

class WoodMap;
class Tower;
class QPainter;
class Road;

//敌人类

class Enemy:public QObject
{
    Q_OBJECT
public:
    Enemy(Road * startPoint, WoodMap * game,QString path=":/picture/enemy1.png");
    ~Enemy();
    void draw(QPainter * painter)const;
    void move();//敌人的移动

    QPoint getPos();//得到敌人的当前位置

    void getAttacked(Tower * tower);//被tower攻击
    void getDamaged(int damage);//敌人被攻击受到伤害
    void getRemoved();//当血量非正时，敌人死亡，需要移除
    void getLostSight(Tower * tower);//敌人脱离tower的攻击范围

private slots:
    void doActive();//敌人是否可以移动

private:
    int m_maxHp;//最大血量
    int m_currentHp;//当前血量
    int m_walkingSpeed;//移动速度
    bool m_active;//是否可以移动

    Road * m_destinationRoadPoint;//目标点的指针
    WoodMap * m_game;
    QPoint m_pos;//当前位置
    QString m_path;//图片路径
    QList<Tower *> m_attackerTowerList;//正在攻击该敌人的防御塔list

    static const QSize m_fixedSize;
};
#endif // ENEMY_H
