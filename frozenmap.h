#ifndef FROZENMAP_H
#define FROZENMAP_H

#include <QMainWindow>
#include <QPainter>
#include <QPixmap>
#include <QPaintEvent>
#include <QPushButton>
#include <QString>

class FrozenMap : public QMainWindow
{
    Q_OBJECT
public:
    explicit FrozenMap(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *);

signals:

};

#endif // FROZENMAP_H
