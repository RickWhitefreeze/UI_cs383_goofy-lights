#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QColumnView>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

#include <QFileDialog>
#include <QStandardPaths>
#include <QColorDialog>
#include <QRect>

class Ui_MainWindow : public QMainWindow
{

public:
    QAction *actionOpen;
    QAction *actionNew;
    QAction *actionSave;
    QAction *actionExit;
    QAction *actionSetColor;

    QColor drawColor;

    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;

    QGroupBox *toolBox;
    QToolButton *toolBrush;
    QToolButton *toolWrite;
    QToolButton *toolSelect;
    QToolButton *toolColor;

    QGroupBox *viewer;
    QVBoxLayout *verticalLayout;
    QGraphicsView *canvas;
    QColumnView *timeline;

    QMenuBar *menuBar;
    QMenu *menuFile;

    Ui_MainWindow(){
        setupUi(this);
    }

private:
    void setupUi(QMainWindow *MainWindow);
    void retranslateUi(QMainWindow *MainWindow);
    void openFile();
    void createFile();
    void saveFile();

    void setDrawColor();

};

namespace Ui {
    class MainWindow : public Ui_MainWindow {};
}

#endif // MAINWINDOW_H
