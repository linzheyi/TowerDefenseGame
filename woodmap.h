#ifndef WOODMAP_H
#define WOODMAP_H

#include <QMainWindow>
#include <QList>
#include <QMouseEvent>
#include "towerposition.h"
#include "tower.h"
#include "road.h"
#include "enemy.h"
#include "audioplayer.h"
#include "bullet.h"
#include "choosebutton.h"


class Enemy;
class TowerPosition;
class Tower;
class Road;
class AudioPlayer;
class Bullet;
class chooseButton;
//林地模式类


class WoodMap : public QMainWindow
{
    Q_OBJECT
public:


    explicit WoodMap(QWidget *parent = 0);
    void paintEvent(QPaintEvent *);
    void addRoadPoint();

    bool canBuyTower1();
    bool canBuyTower2();

    bool canUpdate1();
    bool canUpdate2();

    void getHpDamaged();//敌人进入基地内部，基地要扣血
    void awardGlod();
    void removeEnemy(Enemy * enemy);//敌人死亡，在mainwindow中要移除
    QList<Enemy *> getEnemyList();//得到Enemy*的list
    bool loadWaves();//加载敌人的函数
    void removeBullet(Bullet * bullet);
    void addBullet(Bullet * bullet);
    void removeButton(chooseButton * button);//在mainwindow中对button进行移除

    void drawHp(QPainter * painter)const;//画出当前基地血量的信息
    void drawGlod(QPainter * painter)const;//画出当前玩家金钱的信息
    void drawWaves(QPainter * painter)const;//画出当前的波数信息

    void doGameOver();//执行游戏结束

    AudioPlayer* audioPlayer() const;

protected:
    void mousePressEvent(QMouseEvent *);


private:
    int m_waves;//波数
    bool m_gameWin;
    bool m_gameLose;

    int m_playerHp;
    int m_playerGlod;

    AudioPlayer * m_audioPlayer;

    QString m_path;

     QList<TowerPosition> towerPositionsList;
     QList<Tower *> towerList;
     QList<Road *> roadPointList;
     QList<Enemy *> enemyList;
     QList<Bullet *> bulletList;
     QList<chooseButton * > chooseButtonList;

     //说明塔基位置
     void addTowerPositions();
     bool canBuyTower1() const;

private slots:
    //私有信号槽，将Enemy，Tower和后续的Bullet连接
    void updateMap();
    void gameStart();




signals:

};

#endif // WOODMAP_H
