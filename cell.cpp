#include "cell.h"

void Cell::setColor(QColor c){
    color = c;
}

void Cell::paintEvent(QPaintEvent* event)
{
    QPainter painter(this);
    QStyleOption styleOpt;

    styleOpt.initFrom(this);
    style()->drawPrimitive(QStyle::PE_Widget, &styleOpt, &painter, this);
}

void Cell::mousePressEvent(QMouseEvent *event){
    if(event->buttons() == Qt::LeftButton){
        emit clicked(pos);
    }
    if(event->buttons() == Qt::RightButton){
        emit clickedr(pos);

    }
}

Cell::Cell(QWidget *parent, const QVector2D &position) : QWidget(parent), pos(position)
{
    QSizePolicy cellPolicy;
    QSize cellSize(25,25);

    cellPolicy.setHorizontalPolicy(QSizePolicy::Fixed);
    cellPolicy.setHorizontalStretch(1);
    cellPolicy.setVerticalPolicy(QSizePolicy::Fixed);
    cellPolicy.setVerticalStretch(1);
    cellPolicy.setHeightForWidth(true);

    setMinimumSize(cellSize);
    setSizePolicy(cellPolicy);

    color = Qt::black;
}

Cell::~Cell()
{

}
