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

namespace Ui {
	class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();	

    QAction *actionOpen;
    QAction *actionExit;
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

private:
    Ui::MainWindow *ui;
    void openFile();
};

#endif // MAINWINDOW_H
