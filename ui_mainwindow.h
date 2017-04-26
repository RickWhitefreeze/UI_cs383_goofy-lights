/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionMenuOpen;
    QAction *actionMenuNew;
    QAction *actionMenuSave;
    QAction *actionMenuExit;
    QAction *actionNew_Frame;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QScrollArea *timelineScroll;
    QWidget *timelineArea;
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *timeline;
    QScrollArea *canvasView;
    QWidget *canvasArea;
    QGridLayout *gridLayout_2;
    QGridLayout *canvas;
    QHBoxLayout *horizontalLayout_6;
    QFrame *line;
    QToolButton *toolButton;
    QToolButton *toolButton_2;
    QSpacerItem *horizontalSpacer;
    QLineEdit *timestamp;
    QVBoxLayout *verticalLayout;
    QToolButton *toolButton_4;
    QToolButton *toolButton_3;
    QToolButton *toolColor;
    QGridLayout *gridLayout_4;
    QToolButton *buttonDown;
    QToolButton *buttonLeft;
    QToolButton *buttonUp;
    QToolButton *buttonRight;
    QSpacerItem *verticalSpacer;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuInsert;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->setWindowModality(Qt::NonModal);
        MainWindow->resize(640, 480);
        MainWindow->setMinimumSize(QSize(640, 480));
        actionMenuOpen = new QAction(MainWindow);
        actionMenuOpen->setObjectName(QStringLiteral("actionMenuOpen"));
        actionMenuNew = new QAction(MainWindow);
        actionMenuNew->setObjectName(QStringLiteral("actionMenuNew"));
        actionMenuSave = new QAction(MainWindow);
        actionMenuSave->setObjectName(QStringLiteral("actionMenuSave"));
        actionMenuExit = new QAction(MainWindow);
        actionMenuExit->setObjectName(QStringLiteral("actionMenuExit"));
        actionNew_Frame = new QAction(MainWindow);
        actionNew_Frame->setObjectName(QStringLiteral("actionNew_Frame"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(centralWidget->sizePolicy().hasHeightForWidth());
        centralWidget->setSizePolicy(sizePolicy);
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setHorizontalSpacing(0);
        gridLayout->setVerticalSpacing(2);
        gridLayout->setContentsMargins(0, 0, 0, 0);
        timelineScroll = new QScrollArea(centralWidget);
        timelineScroll->setObjectName(QStringLiteral("timelineScroll"));
        timelineScroll->setMinimumSize(QSize(0, 0));
        timelineScroll->setMaximumSize(QSize(16777215, 170));
        timelineScroll->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        timelineScroll->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        timelineScroll->setWidgetResizable(true);
        timelineArea = new QWidget();
        timelineArea->setObjectName(QStringLiteral("timelineArea"));
        timelineArea->setGeometry(QRect(0, 0, 537, 105));
        horizontalLayout_2 = new QHBoxLayout(timelineArea);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        timeline = new QHBoxLayout();
        timeline->setSpacing(6);
        timeline->setObjectName(QStringLiteral("timeline"));

        horizontalLayout_2->addLayout(timeline);

        timelineScroll->setWidget(timelineArea);

        gridLayout->addWidget(timelineScroll, 2, 1, 1, 1);

        canvasView = new QScrollArea(centralWidget);
        canvasView->setObjectName(QStringLiteral("canvasView"));
        canvasView->setWidgetResizable(true);
        canvasArea = new QWidget();
        canvasArea->setObjectName(QStringLiteral("canvasArea"));
        canvasArea->setGeometry(QRect(0, 0, 537, 319));
        canvasArea->setStyleSheet(QStringLiteral("background-color: rgb(65, 65, 65);"));
        gridLayout_2 = new QGridLayout(canvasArea);
        gridLayout_2->setSpacing(0);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(6, 6, 6, 6);
        canvas = new QGridLayout();
        canvas->setSpacing(1);
        canvas->setObjectName(QStringLiteral("canvas"));

        gridLayout_2->addLayout(canvas, 0, 1, 1, 1);

        canvasView->setWidget(canvasArea);

        gridLayout->addWidget(canvasView, 0, 1, 1, 1);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(0, -1, 6, -1);
        line = new QFrame(centralWidget);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        horizontalLayout_6->addWidget(line);

        toolButton = new QToolButton(centralWidget);
        toolButton->setObjectName(QStringLiteral("toolButton"));
        toolButton->setMinimumSize(QSize(25, 25));
        toolButton->setMaximumSize(QSize(25, 25));
        QIcon icon;
        icon.addFile(QStringLiteral(":/images/icons/play.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton->setIcon(icon);
        toolButton->setIconSize(QSize(12, 12));

        horizontalLayout_6->addWidget(toolButton);

        toolButton_2 = new QToolButton(centralWidget);
        toolButton_2->setObjectName(QStringLiteral("toolButton_2"));
        toolButton_2->setMinimumSize(QSize(25, 25));
        toolButton_2->setMaximumSize(QSize(25, 25));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/images/icons/pause.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_2->setIcon(icon1);
        toolButton_2->setIconSize(QSize(12, 12));

        horizontalLayout_6->addWidget(toolButton_2);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer);

        timestamp = new QLineEdit(centralWidget);
        timestamp->setObjectName(QStringLiteral("timestamp"));
        timestamp->setMinimumSize(QSize(60, 0));
        timestamp->setMaximumSize(QSize(0, 16777215));
        timestamp->setFrame(true);
        timestamp->setAlignment(Qt::AlignCenter);

        horizontalLayout_6->addWidget(timestamp);


        gridLayout->addLayout(horizontalLayout_6, 1, 1, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        verticalLayout->setContentsMargins(6, 6, 6, -1);
        toolButton_4 = new QToolButton(centralWidget);
        toolButton_4->setObjectName(QStringLiteral("toolButton_4"));
        toolButton_4->setMinimumSize(QSize(40, 40));
        toolButton_4->setMaximumSize(QSize(40, 40));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/images/icons/brush.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_4->setIcon(icon2);

        verticalLayout->addWidget(toolButton_4);

        toolButton_3 = new QToolButton(centralWidget);
        toolButton_3->setObjectName(QStringLiteral("toolButton_3"));
        toolButton_3->setMinimumSize(QSize(40, 40));
        toolButton_3->setMaximumSize(QSize(40, 40));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/images/icons/text.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_3->setIcon(icon3);

        verticalLayout->addWidget(toolButton_3);

        toolColor = new QToolButton(centralWidget);
        toolColor->setObjectName(QStringLiteral("toolColor"));
        toolColor->setMinimumSize(QSize(40, 40));
        toolColor->setMaximumSize(QSize(40, 40));
        toolColor->setStyleSheet(QLatin1String("background-color: black;\n"
" border: 2px inset grey;"));

        verticalLayout->addWidget(toolColor);

        gridLayout_4 = new QGridLayout();
        gridLayout_4->setSpacing(6);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        buttonDown = new QToolButton(centralWidget);
        buttonDown->setObjectName(QStringLiteral("buttonDown"));
        buttonDown->setMinimumSize(QSize(25, 25));
        buttonDown->setMaximumSize(QSize(25, 25));

        gridLayout_4->addWidget(buttonDown, 2, 2, 1, 1);

        buttonLeft = new QToolButton(centralWidget);
        buttonLeft->setObjectName(QStringLiteral("buttonLeft"));
        buttonLeft->setMinimumSize(QSize(25, 25));
        buttonLeft->setMaximumSize(QSize(25, 25));

        gridLayout_4->addWidget(buttonLeft, 1, 1, 1, 1);

        buttonUp = new QToolButton(centralWidget);
        buttonUp->setObjectName(QStringLiteral("buttonUp"));
        buttonUp->setMinimumSize(QSize(25, 25));
        buttonUp->setMaximumSize(QSize(25, 25));

        gridLayout_4->addWidget(buttonUp, 0, 2, 1, 1);

        buttonRight = new QToolButton(centralWidget);
        buttonRight->setObjectName(QStringLiteral("buttonRight"));
        buttonRight->setMinimumSize(QSize(25, 25));
        buttonRight->setMaximumSize(QSize(25, 25));

        gridLayout_4->addWidget(buttonRight, 1, 3, 1, 1);


        verticalLayout->addLayout(gridLayout_4);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);

        gridLayout->setRowStretch(0, 12);
        gridLayout->setRowStretch(1, 1);
        gridLayout->setRowStretch(2, 4);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 640, 21));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuInsert = new QMenu(menuBar);
        menuInsert->setObjectName(QStringLiteral("menuInsert"));
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuInsert->menuAction());
        menuFile->addAction(actionMenuOpen);
        menuFile->addAction(actionMenuNew);
        menuFile->addAction(actionMenuSave);
        menuFile->addSeparator();
        menuFile->addAction(actionMenuExit);
        menuInsert->addAction(actionNew_Frame);

        retranslateUi(MainWindow);
        QObject::connect(actionMenuExit, SIGNAL(triggered()), MainWindow, SLOT(close()));
        QObject::connect(actionMenuOpen, SIGNAL(triggered()), MainWindow, SLOT(openFile()));
        QObject::connect(actionMenuNew, SIGNAL(triggered()), MainWindow, SLOT(newFile()));
        QObject::connect(actionMenuSave, SIGNAL(triggered()), MainWindow, SLOT(saveFile()));
        QObject::connect(toolColor, SIGNAL(clicked()), MainWindow, SLOT(setDrawColor()));
        QObject::connect(actionNew_Frame, SIGNAL(triggered()), MainWindow, SLOT(newCanvas()));
        QObject::connect(buttonUp, SIGNAL(clicked()), MainWindow, SLOT(boxShiftUp()));
        QObject::connect(buttonLeft, SIGNAL(clicked()), MainWindow, SLOT(boxShiftLeft()));
        QObject::connect(buttonRight, SIGNAL(clicked()), MainWindow, SLOT(boxShiftRight()));
        QObject::connect(buttonDown, SIGNAL(clicked()), MainWindow, SLOT(boxShiftDown()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Goofy Lights Editor", Q_NULLPTR));
        actionMenuOpen->setText(QApplication::translate("MainWindow", "Open", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actionMenuOpen->setToolTip(QApplication::translate("MainWindow", "Opens a saved project.", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actionMenuOpen->setShortcut(QApplication::translate("MainWindow", "Ctrl+O", Q_NULLPTR));
        actionMenuNew->setText(QApplication::translate("MainWindow", "New", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actionMenuNew->setToolTip(QApplication::translate("MainWindow", "Creates a project.", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actionMenuNew->setShortcut(QApplication::translate("MainWindow", "Ctrl+N", Q_NULLPTR));
        actionMenuSave->setText(QApplication::translate("MainWindow", "Save", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actionMenuSave->setToolTip(QApplication::translate("MainWindow", "Saves the current project.", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actionMenuSave->setShortcut(QApplication::translate("MainWindow", "Ctrl+S", Q_NULLPTR));
        actionMenuExit->setText(QApplication::translate("MainWindow", "Exit", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actionMenuExit->setToolTip(QApplication::translate("MainWindow", "Closes the application.", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actionNew_Frame->setText(QApplication::translate("MainWindow", "New Frame", Q_NULLPTR));
        toolButton->setText(QString());
        toolButton_2->setText(QApplication::translate("MainWindow", "...", Q_NULLPTR));
        timestamp->setInputMask(QApplication::translate("MainWindow", "99:99.99", Q_NULLPTR));
        timestamp->setText(QApplication::translate("MainWindow", "00:00.00", Q_NULLPTR));
        timestamp->setPlaceholderText(QString());
        toolButton_4->setText(QString());
        toolButton_3->setText(QString());
        toolColor->setText(QString());
        buttonDown->setText(QApplication::translate("MainWindow", "\342\226\274", Q_NULLPTR));
        buttonLeft->setText(QApplication::translate("MainWindow", "\342\227\204", Q_NULLPTR));
        buttonUp->setText(QApplication::translate("MainWindow", "\342\226\262", Q_NULLPTR));
        buttonRight->setText(QApplication::translate("MainWindow", "\342\226\272", Q_NULLPTR));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", Q_NULLPTR));
        menuInsert->setTitle(QApplication::translate("MainWindow", "Insert", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
