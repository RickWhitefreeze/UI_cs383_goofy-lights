#ifndef CELL_H
#define CELL_H

#include <QPushButton>
#include <QVector2D>
#include <QStyleOption>
#include <QPainter>
#include <QMouseEvent>\

/*All things that we click with the mouse will be put in here or we can make a new class for it
 * aswell as keyboard buttons and tool buttons if we so choose.
 */

class Cell : public QWidget
{
    Q_OBJECT

public:
    void setColor(QColor c);
    explicit Cell(QWidget *parent = 0, const QVector2D &position = QVector2D());
    ~Cell();

private:
    QColor color;
    QVector2D pos;
    QVector2D pos2;    //second position on the grid

    void paintEvent(QPaintEvent *event);
    void boxevent(QMouseEvent *event);   //event for the box selection the code for it should be the same as stamps
    void mousePressEvent(QMouseEvent *event);

signals:
    void clicked(QVector2D pos);

};


#endif // CELL_H
