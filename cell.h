#ifndef CELL_H
#define CELL_H

#include <QVector2D>
#include <QStyleOption>
#include <QPainter>
#include <QMouseEvent>
#include <QMessageBox>  //this is how You can make the error messages for stuff also have differnt sounds too!

class Cell : public QWidget
{
    Q_OBJECT

public:
    QColor getColor(){return color;}
    void setColor(QColor c);
    explicit Cell(QWidget *parent = 0, const QVector2D &position = QVector2D());
    int posx, posy, boxset;  //box data

    ~Cell();

private:
    QColor color;
    QVector2D pos;

    void paintEvent(QPaintEvent* event);
    void mousePressEvent(QMouseEvent *event);
 //   void mouseReleaseEvent(QMouseEvent *event); //will not work lance don't think about it will not work in this scope

signals:
    void clicked(QVector2D pos);
    void Rclick(QVector2D pos, int boxset);  //signal for the right click
};

#endif // CELL_H
