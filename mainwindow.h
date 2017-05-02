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
#include <QMouseEvent>
#include <QMessageBox>


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

    void newCanvas();
    void loadCanvas(TimelineFrame *tf);

    void getstuff(QVector2D pos, int boxset);  //Right click slot

    void boxShiftUp();
    void boxShiftDown();
    void boxShiftLeft();
    void boxShiftRight();
   // void selcShifUp();  //this was me testing some other stuff with selection and just making a whole new function for moving the pices but it really should not be needed.
    /*
    void boxShiftUp(QVector2D pos, QVector2D pos2, int boxset);
    void boxShiftDown(QVector2D pos, QVector2D pos2);
    void boxShiftLeft(QVector2D pos, QVector2D pos2);   //dumster fire code don't use this is a bad idea leaving it here as a reminder to never do dumb stuff
    void boxShiftRight(QVector2D pos, QVector2D pos2);
   */
    void boxColorChange();

private:
    Ui::MainWindow *ui;
    QVector2D frameDim;
    QColor drawColor;
    QVector< Cell* > canvasCells;
    QList<TimelineFrame*> timeline;
    int posx, posy, pos2x, pos2y, boxset; //box data


    TimelineFrame *current_tf = NULL;
    //Testing purposes only works with a 5 X 5 defined frame
    void populateCanvas();
    void saveCanvas(QVector<QColor> &canvas);
   // void getstuffupdate();        //funciton that is not used

};



#endif // MAINWINDOW_H
