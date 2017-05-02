#include "cell.h"
#include <QDebug>
int boxset = 0;

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
        boxset = 0;
    }
    else if(event->buttons() == Qt::RightButton){
       /* posx = pos.x();
        posy = pos.y();
       */
        boxset = 1;
        emit Rclick(pos, boxset);
        /*
QMessageBox::information(this,
                         tr("first rclick"),
                         tr("first =1"));
    */

    }
}
/*
    void Cell::mouseReleaseEvent(QMouseEvent *event){
      if(event->button() == Qt::RightButton){
        boxset = 1;
        pos2x = pos.x();
        pos2y = pos.y();
        emit Rclick(posx, posy, pos2x, pos2y, boxset);
        QMessageBox::information(this,
                                 tr("released"),
                                 tr("ohyeah"));

       }
  */
    //  qDebug() << "" << this;
      //qDebug()<<" "<<posx;
        //qDebug()<<" "<<posy;
        //qDebug()<<" "<<pos2x;
        //qDebug()<<" "<<pos2y;



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
