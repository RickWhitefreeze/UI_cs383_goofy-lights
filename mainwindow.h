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
#include <QTimer>
#include <QThread>

#include <cmath>


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
    void setNewCellColor(int pos);
    void eliminateBorder();

    void setBox(QVector2D pos);

    void newFile();
    void openFile();
    void saveFile();
    void exportFile();

    void newCanvas(int pos);
    void insertAfter();
    void insertBefore();

    void copyFrame();
    void deleteFrame();
    void loadCanvas(TimelineFrame *tf);
    void preview();
    void stop();

    void boxShiftUp();
    void boxShiftDown();
    void boxShiftLeft();
    void boxShiftRight();
    void boxColorChange();
    void setBoxBorder();


private:
    Ui::MainWindow *ui;
    QVector2D frameDim;
    QColor drawColor = Qt::black;
    QVector< Cell* > canvasCells;
    QList<TimelineFrame*> timeline;

    TimelineFrame *current_tf = NULL;
    bool stopped;

    void populateCanvas();
    void saveCanvas(QVector<QColor> &canvas);
    void cleanCanvas();

    bool _switch = 1;
    QVector2D selectTop, selectBottom;

};



#endif // MAINWINDOW_H
