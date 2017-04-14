#include "cell.h"

void Cell::setColor(QColor c){
    color = c;
}

void Cell::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QStyleOption styleOpt;

    styleOpt.initFrom(this);
    style()->drawPrimitive(QStyle::PE_Widget, &styleOpt, &painter, this);
}

void Cell::boxevent(QMouseEvent *event){
    //Here we could put the code for the stamps and just treat the box selecting as a stamp.
}

void Cell::mousePressEvent(QMouseEvent *event){
    if(event->buttons() == Qt::LeftButton){
        emit clicked(pos);
    }
    else if (event->buttons()==Qt::RightButton){  //Mouse event happens is it right or left.
        emit clicked(pos);
        if(event->buttons()== Qt::RightButton){   //Looks for another right mouse event if it happens it makes two positions.
            emit clicked(pos2);
        }//This code is really the same for all so we could just have one function but made buttons on the window for the tools it could be a bool for what tool the mouse is using.
    }
}

Cell::Cell(QWidget *parent, const QVector2D &position) : QWidget(parent), pos(position)
{
    QSizePolicy cellPolicy;
    QSize cellSize(12,12);

    cellPolicy.setHorizontalPolicy(QSizePolicy::Fixed);
    cellPolicy.setHorizontalStretch(1);
    cellPolicy.setVerticalPolicy(QSizePolicy::Fixed);
    cellPolicy.setVerticalStretch(1);
    cellPolicy.setHeightForWidth(true);

    setMinimumSize(cellSize);
    setSizePolicy(cellPolicy);

    setStyleSheet("background-color:rgba(0,0,0,25%);");
    color = Qt::black;
}

Cell::~Cell()
{

}
