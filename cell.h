#ifndef CELL_H
#define CELL_H

#include <QVector2D>
#include <QStyleOption>
#include <QPainter>
#include <QMouseEvent>\

class Cell : public QWidget
{
    Q_OBJECT

public:
    QColor getColor(){return color;}
    void setColor(QColor c);
    explicit Cell(QWidget *parent = 0, const QVector2D &position = QVector2D());
    ~Cell();

private:
    QColor color;
    QVector2D pos;


    void paintEvent(QPaintEvent* event);
    void mousePressEvent(QMouseEvent *event);

signals:
    void clicked(QVector2D pos);
    void clickedr(QVector2D pos);

};

#endif // CELL_H
