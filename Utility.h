#ifndef UTILITY_H
#define UTILITY_H


#include <QtMath>
#include <QPoint>

inline bool collisionWithCircle(QPoint point1, int radius1, QPoint point2, int radius2)
{
    const int xx = point1.x() - point2.x();
    const int yy = point1.y() - point2.y();
    const int distance = qSqrt(xx * xx + yy * yy);

    if (distance <= radius1 + radius2)
        return true;

    return false;
}

#endif // UTILITY_H

