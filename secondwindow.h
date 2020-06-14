#ifndef SECONDWINDOW_H
#define SECONDWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <QPixmap>
#include <QPaintEvent>
#include <QPushButton>
#include <QString>

class SecondWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit SecondWindow(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *);

signals:
     void ClickBack();

};

#endif // SECONDWINDOW_H
