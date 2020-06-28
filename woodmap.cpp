#include "woodmap.h"
#include "tower.h"
#include "towerposition.h"
#include "road.h"
#include "enemy.h"
#include "audioplayer.h"
#include "choosebutton.h"

#include <QMainWindow>
#include <QPainter>
#include <QPixmap>
#include <QPaintEvent>
#include <QPushButton>
#include <QDebug>
#include <QString>
#include <QPoint>
#include <QMouseEvent>
#include <QTimer>


static const int tower1Cost=300;//第一种塔的价钱
static const int tower2Cost=400;//第二种塔的价钱







WoodMap::WoodMap(QWidget *parent) : QMainWindow(parent),
    m_waves(0),
    m_gameWin(false),
    m_gameLose(false),
    m_playerHp(5),
    m_playerGlod(1000)
{
    this->setFixedSize(1000,800);
    addRoadPoint();
    addTowerPositions();

    m_audioPlayer = new AudioPlayer(this);
    m_audioPlayer->startBGM();

    QTimer * timer=new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(updateMap()));
    timer->start(30);
    QTimer::singleShot(300,this,SLOT(gameStart()));
}


//画图
void WoodMap::paintEvent(QPaintEvent *){
    if(m_gameLose || m_gameWin)//画出游戏结束的画面
        {
            QString text=m_gameLose ? "YOU LOST":"YOU WIN";
            QPainter painter(this);
            painter.setPen(Qt::red);
            painter.drawText(rect(),Qt::AlignCenter,text);
            return ;
        }

    QPixmap pixmap(":/picture/woodmap.bmp");
    QPainter mypainter(&pixmap);


    foreach(const Road * waypoint,roadPointList)
            waypoint->draw(&mypainter);

    foreach (const TowerPosition &towerPos, towerPositionsList)
    {

            towerPos.draw(&mypainter);
    }
    foreach(const Tower * tower, towerList)
            tower->draw(&mypainter);
    foreach(const Enemy * enemy,enemyList)
            enemy->draw(&mypainter);
    foreach(const Bullet * bullet,bulletList)
        bullet->draw(&mypainter);
    foreach(const chooseButton * button,chooseButtonList)
        button->draw(&mypainter);

    drawHp(&mypainter);
    drawGlod(&mypainter);
    drawWaves(&mypainter);

    QPainter painter(this);
    painter.drawPixmap(0, 0,this->width(),this->height(),pixmap);

}

void WoodMap::addRoadPoint()
{
    Road * waypoint1=new Road(QPoint(310,580));
    roadPointList.push_back(waypoint1);

    Road * waypoint2=new Road(QPoint(310,450));
    waypoint1->setNextRoadPoint(waypoint2);
    roadPointList.push_back(waypoint2);

    Road* waypoint3=new Road(QPoint(420,420));
    waypoint2->setNextRoadPoint(waypoint3);
    roadPointList.push_back(waypoint3);

    Road * waypoint4=new Road(QPoint(460,380));
    waypoint3->setNextRoadPoint(waypoint4);
    roadPointList.push_back(waypoint4);

    Road * waypoint5=new Road(QPoint(420,310));
    waypoint4->setNextRoadPoint(waypoint5);
    roadPointList.push_back(waypoint5);

    Road * waypoint6=new Road(QPoint(250,340));
    waypoint5->setNextRoadPoint(waypoint6);
    roadPointList.push_back(waypoint6);

    Road * waypoint7=new Road(QPoint(170,280));
    waypoint6->setNextRoadPoint(waypoint7);
    roadPointList.push_back(waypoint7);

    Road * waypoint8=new Road(QPoint(230,210));
    waypoint7->setNextRoadPoint(waypoint8);
    roadPointList.push_back(waypoint8);

    Road * waypoint9=new Road(QPoint(350,210));
    waypoint8->setNextRoadPoint(waypoint9);
    roadPointList.push_back(waypoint9);

    Road * waypoint10=new Road(QPoint(400,90));
    waypoint9->setNextRoadPoint(waypoint10);
    roadPointList.push_back(waypoint10);

    Road * waypoint11=new Road(QPoint(480,90));
    waypoint10->setNextRoadPoint(waypoint11);
    roadPointList.push_back(waypoint11);

    Road * waypoint12=new Road(QPoint(530,200));
    waypoint11->setNextRoadPoint(waypoint12);
    roadPointList.push_back(waypoint12);

    Road * waypoint13=new Road(QPoint(700,200));
    waypoint12->setNextRoadPoint(waypoint13);
    roadPointList.push_back(waypoint13);

}

//添加塔基
void WoodMap::addTowerPositions(){
       QPoint pos[] =
       {
           QPoint(400, 120),
           QPoint(260, 130),
           QPoint(70 , 200),
           QPoint(350, 460),
           QPoint(215, 250),
           QPoint(350, 340),
           QPoint(470, 400)
           };
       int len = sizeof(pos) / sizeof(pos[0]);
        for (int i = 0; i < len; ++i)
            towerPositionsList.push_back(pos[i]);

}

void WoodMap::mousePressEvent(QMouseEvent * event)
{
    QPoint pressPos=event->pos();//得到鼠标点击的位置
    auto it=towerPositionsList.begin();
    while(it!=towerPositionsList.end())//遍历所有的防御塔坑
        {
            if(Qt::LeftButton==event->button())//如果是鼠标左键点击
            {
                if(!it->hasButton() && it->ContainPos(pressPos) && !it->hasTower())//如果没有button，点击的点在防御塔坑的内部
                {
                    QPoint tmp(it->getPos().x()-35,it->getPos().y()-35);//得到该防御塔坑处的button的左上点
                    chooseButton * button=new chooseButton(tmp,this);//创建一个button
                    it->setHasButton(true);//设置该位置有button
                    it->setButton(button);//设置该位置的button
                    chooseButtonList.push_back(button);//把这个button加入到mainwidnow中
                    update();
                    break;
                }
                else if(it->hasButton() && it->getButton()->containPos(pressPos) && !it->hasTower())//如果这个位置有button，并且没有防御塔
                {
                    if(pressPos.x()<it->getButton()->getPos().x()+35 && canBuyTower1())//如果鼠标点击的地方在第一张图片内，创造第一个防御塔
                    {
                        it->setHasTower1(true);
                        m_playerGlod-=tower1Cost;
                        QString path=":/picture/firsttower.png";
                        Tower * tower=new Tower(it->getCenterPos(),this,path,10);
                        towerList.push_back(tower);
                    }
                    else if(pressPos.x()>it->getButton()->getPos().x()+35 && pressPos.x()<it->getButton()->getPos().x()+70
                            && canBuyTower2())//鼠标点击点在第二张图片内，创建第二种防御塔
                    {
                        it->setHasTower2(true);
                        m_playerGlod-=tower2Cost;
                        QString path=":/picture/secondtower1.png";
                        Tower * tower=new Tower(it->getCenterPos(),this,path,15);
                        towerList.push_back(tower);
                    }

                    //构造完防御塔后，原来的button就要消失，下面对该button进行移除
                    it->getButton()->getRemoved();
                    it->setButton(NULL);
                    it->setHasButton(false);
                    update();
                    break;
                }
            }
            ++it;
        }
}


bool WoodMap::canBuyTower1()
{
    if(m_playerGlod>=tower1Cost)
    {
        return true;
    }
    return false;
}

bool WoodMap::canBuyTower2()
{
    if(m_playerGlod>=tower2Cost)
    {
        return true;
    }
    return false;
}



void WoodMap::getHpDamaged()
{
    m_playerHp-=1;//敌人进入基地，扣一滴血
}

void WoodMap::awardGlod()
{
    m_playerGlod+=200;//每杀死一个敌人增加200金币
}

AudioPlayer *WoodMap::audioPlayer() const
{
    return m_audioPlayer;
}

void WoodMap::removeEnemy(Enemy *enemy)
{

    Q_ASSERT(enemy);
    enemyList.removeOne(enemy);//死亡的敌人从enemylist中移除
    delete enemy;
    if(enemyList.empty())
        {
            ++m_waves;
            if(!loadWaves())
            {
                m_gameWin=true;
            }
        }
}

QList<Enemy *> WoodMap::getEnemyList()
{
    return enemyList;
}

bool WoodMap::loadWaves()
{
    if(m_waves>=6)
    {
        return false;
    }
    int enemyStartInterval[]={2000,4000,6000,8000,10000};
    for(int i=0;i<6;++i)
    {
        Road * startWayPoint;
        startWayPoint=roadPointList.first();
        Enemy * enemy=new Enemy(startWayPoint,this);//创建一个新的enemy
        enemyList.push_back(enemy);
        QTimer::singleShot(enemyStartInterval[i],enemy,SLOT(doActive()));
    }
    return true;
}

void WoodMap::gameStart()
{
    loadWaves();
}

void WoodMap::updateMap()
{
    foreach(Enemy * enemy,enemyList)
        enemy->move();
    foreach(Tower * tower,towerList)
        tower->checkEnemyInRange();
    update();
}

void WoodMap::doGameOver()
{
    if(!m_gameLose)
    {
        m_gameLose=true;
    }
}



void WoodMap::drawWaves(QPainter *painter) const
{
    painter->save();
    painter->setPen(Qt::black);
    painter->drawText(QRect(30,40,100,25),QString("WAVES: %1").arg(m_waves+1));
    painter->restore();
}

void WoodMap::drawHp(QPainter *painter) const
{
    painter->save();
    painter->setPen(Qt::black);
    painter->drawText(QRect(30,5,100,25),QString("HP: %1").arg(m_playerHp));
    painter->restore();
}

void WoodMap::drawGlod(QPainter *painter) const
{
    painter->save();
    painter->setPen(Qt::black);
    painter->drawText(QRect(30,70,100,25),QString("GLOD: %1").arg(m_playerGlod));
}

void WoodMap::removeBullet(Bullet *bullet)
{
    Q_ASSERT(bullet);
    bulletList.removeOne(bullet);

}

void WoodMap::addBullet(Bullet *bullet)
{
    Q_ASSERT(bullet);
    bulletList.push_back(bullet);
}


void WoodMap::removeButton(chooseButton *button)
{
    chooseButtonList.removeOne(button);
}
