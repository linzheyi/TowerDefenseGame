#ifndef TIP_H
#define TIP_H

#include <QMainWindow>
#include <QPainter>
#include <QPaintEvent>
#include <QPixmap>
#include <QPushButton>

//规则说明界面

class tip : public QMainWindow
{
    Q_OBJECT
public:
    explicit tip(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *);

signals:
    void ClickBack();

};

#endif // TIP_H
