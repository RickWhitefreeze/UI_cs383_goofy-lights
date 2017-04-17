#ifndef TIMELINEFRAME_H
#define TIMELINEFRAME_H

#include <QToolButton>
#include <QImage>
#include <QPixmap>
#include <QVector>
#include <QVector2D>
#include <QColor>
#include <QMouseEvent>

class TimelineFrame : public QToolButton
{
    Q_OBJECT

public:
    void createPreview(const QVector2D &frameDim);
    TimelineFrame(QWidget *parent, const QVector<QColor> &frame, const QVector2D &frameDim);
    QVector<QColor> canvas;

private:

    void mousePressEvent(QMouseEvent *event);

signals:
    void clicked(TimelineFrame *tf);

};

#endif // TIMELINEFRAME_H
