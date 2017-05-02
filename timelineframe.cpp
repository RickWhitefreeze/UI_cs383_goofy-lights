#include "timelineframe.h"

void TimelineFrame::createPreview(const QVector2D &frameDim){
    QImage image(frameDim.x(), frameDim.y(), QImage::Format_RGB16);

    int i = frameDim.x() * 3 * frameDim.y() + frameDim.x();
    for(int y = 0; y < frameDim.y(); y++){
        for(int x = 0; x < frameDim.x(); x++){
            image.setPixelColor(x, y, canvas[i++]);
        }
        i += frameDim.x() * 2;
    }

    QPixmap pixmap(frameDim.x(), frameDim.y());
    pixmap.convertFromImage(image);
    pixmap = pixmap.scaled(64, 64 * frameDim.y() / frameDim.x(), Qt::IgnoreAspectRatio, Qt::FastTransformation);

    QIcon icon(pixmap);
    setIcon(icon);
    setIconSize(QSize(frameDim.x() * 12, frameDim.y() * frameDim.y() / frameDim.x() * 12));
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

TimelineFrame::TimelineFrame(QWidget *parent, QVector<QColor> &frame,
                             const QVector2D &frameDim, const QString time) : QToolButton(parent), canvas(frame), timestamp(time)
{
    setStyleSheet("padding: 4px;");

    createPreview(frameDim);
    setMaximumHeight(76 * frameDim.y() / frameDim.x());
    setMaximumWidth(76);
    setAutoRaise(true);
    setCheckable(true);
}
