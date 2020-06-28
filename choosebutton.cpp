#include "choosebutton.h"
const QSize chooseButton::m_fixedSize(35,35);

chooseButton::chooseButton(QPoint pos,WoodMap *game):
    m_game(game),
    m_pos(pos)
{
    m_chooseBoxImagePath[0]=":/picture/firsttower.png";
    m_chooseBoxImagePath[1]=":/picture/secondtower1.png";
}


chooseButton::~chooseButton()
{
    m_game=NULL;
}

void chooseButton::draw(QPainter *painter) const
{
    painter->save();
    painter->drawPixmap(m_pos.x(),m_pos.y(),m_chooseBoxImagePath[0]);
    painter->drawPixmap(m_pos.x()+35,m_pos.y(),m_chooseBoxImagePath[1]);
    painter->restore();
}

void chooseButton::getRemoved()
{
    m_game->removeButton(this);
}

bool chooseButton::containPos(QPoint pos)
{
    bool xInhere=pos.x()>m_pos.x() && pos.x()<m_pos.x()+m_fixedSize.width();
    bool yInhere=pos.y()>m_pos.y() && pos.y()<m_pos.y()+m_fixedSize.height();
    return xInhere && yInhere;
}

QPoint chooseButton::getPos()
{
    return this->m_pos;
}
