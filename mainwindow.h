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

    void boxShiftUp();
    void boxShiftDown();
    void boxShiftLeft();
    void boxShiftRight();

private:
    Ui::MainWindow *ui;
    QVector2D frameDim;
    QColor drawColor;
    QVector< Cell* > canvasCells;
    QLinkedList<QVector<QColor>> timeline;

    TimelineFrame *current_tf = NULL;
    //Testing purposes only works with a 5 X 5 defined frame
    void populateCanvas();
    void saveCanvas(QVector<QColor> &canvas);

};



#endif // MAINWINDOW_H
