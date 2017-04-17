#include "timelineframe.h"

void TimelineFrame::createPreview(const QVector2D &frameDim){
    QImage image(frameDim.x() * 3, frameDim.y() * 3, QImage::Format_RGB16);

    int i = 0;
    for(int y = 0; y < frameDim.y() * 3; y++){
        for(int x = 0; x < frameDim.x() * 3; x++){
            image.setPixelColor(x, y, canvas[i++]);
        }
    }

    QPixmap pixmap(frameDim.x() * 3, frameDim.y() * 3);
    pixmap.convertFromImage(image);
    pixmap = pixmap.scaled(64, 64, Qt::IgnoreAspectRatio, Qt::FastTransformation);

    QIcon icon(pixmap);
    setIcon(icon);
    setIconSize(QSize(frameDim.x() * 12, frameDim.y() * 12));
}

void TimelineFrame::mousePressEvent(QMouseEvent *event){
    if(event->buttons() == Qt::LeftButton){
        emit clicked(this);
    }else if(event->buttons() == Qt::RightButton){
        //Open Context menu
            //Insert new left/right/front/back
            //Copy left/right/front/back
            //Move left/right/front/back
            //Delete
    }
}

TimelineFrame::TimelineFrame(QWidget *parent, const QVector<QColor> &frame,
                             const QVector2D &frameDim) : QToolButton(parent), canvas(frame)
{
    setStyleSheet("padding: 4px;");

    createPreview(frameDim);
    setMaximumHeight(90);
}
