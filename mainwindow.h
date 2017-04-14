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

private slots:
    void on_toolButton_3_clicked();  //we can also just make it a tool and set up the mouse to have a bool for what tool it is


private:
    Ui::MainWindow *ui;
    QVector2D frameDim;
    QColor drawColor;
    QVector< Cell* > canvasCells;

    void renderCanvas();

};

#endif // MAINWINDOW_H
