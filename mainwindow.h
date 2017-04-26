#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QStandardPaths>
#include <QVector2D>
#include <QMessageBox>
#include <QColorDialog>
#include <QVector>
#include <QSignalMapper>
#include <QLinkedList>

#include "timelineframe.h"
#include "newfiledialog.h"
#include "fileio.h"
#include "cell.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void setDrawColor();
    void setCellColor(QVector2D pos);

    void newFile();
    void openFile();
    void saveFile();

    void newCanvas(int pos);
    void deleteFrame();
    void loadCanvas(TimelineFrame *tf);

    void boxShiftUp();
    void boxShiftDown();
    void boxShiftLeft();
    void boxShiftRight();

private slots:
    void on_actionInsert_After_triggered();

    void on_actionInsert_Before_triggered();

    void on_actionDelete_Frame_triggered();

    void on_deleteFrameButton_clicked();

    void on_insertAfter_clicked();

    void on_insertBefore_clicked();

private:
    Ui::MainWindow *ui;
    QVector2D frameDim;
    QColor drawColor;
    QVector< Cell* > canvasCells;
    QList<TimelineFrame*> timeline;

    TimelineFrame *current_tf = NULL;

    void populateCanvas();
    void saveCanvas(QVector<QColor> &canvas);

};



#endif // MAINWINDOW_H
