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
#include <QtWidgets/QPushButton>
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
    QAction *actionInsertAfter;
    QAction *actionInsertBefore;
    QAction *actionDeletFrame;
    QAction *actionInsertCopy;
    QAction *actionExport;
    QAction *actionDelete;
    QAction *actionSave_Sprite;
    QAction *actionInsert_Sprite;
    QAction *actionInsert_Text;
    QAction *actionInsert_Sprite_2;
    QAction *actionSave_Sprite_2;
    QAction *actionInsert_Sprite_3;
    QAction *actionSave_Sprite_3;
    QAction *actionHelp;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QWidget *previewView;
    QHBoxLayout *horizontalLayout;
    QFrame *line;
    QToolButton *toolButton;
    QToolButton *toolButton_2;
    QLineEdit *timestamp;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *insertfBefore;
    QPushButton *insertAfter;
    QPushButton *insertCopy;
    QPushButton *deleteFrame;
    QScrollArea *canvasView;
    QWidget *canvasArea;
    QGridLayout *gridLayout_2;
    QGridLayout *canvas;
    QScrollArea *timelineScroll;
    QWidget *timelineArea;
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *timeline;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout_4;
    QToolButton *buttonUp;
    QToolButton *buttonDown;
    QToolButton *buttonLeft;
    QToolButton *buttonRight;
    QToolButton *boxColorChange;
    QToolButton *toolColor;
    QSpacerItem *verticalSpacer;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuInsert;
    QMenu *menuSprite;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->setWindowModality(Qt::NonModal);
        MainWindow->resize(1280, 720);
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
        actionInsertAfter = new QAction(MainWindow);
        actionInsertAfter->setObjectName(QStringLiteral("actionInsertAfter"));
        actionInsertBefore = new QAction(MainWindow);
        actionInsertBefore->setObjectName(QStringLiteral("actionInsertBefore"));
        actionDeletFrame = new QAction(MainWindow);
        actionDeletFrame->setObjectName(QStringLiteral("actionDeletFrame"));
        actionInsertCopy = new QAction(MainWindow);
        actionInsertCopy->setObjectName(QStringLiteral("actionInsertCopy"));
        actionExport = new QAction(MainWindow);
        actionExport->setObjectName(QStringLiteral("actionExport"));
        actionDelete = new QAction(MainWindow);
        actionDelete->setObjectName(QStringLiteral("actionDelete"));
        actionSave_Sprite = new QAction(MainWindow);
        actionSave_Sprite->setObjectName(QStringLiteral("actionSave_Sprite"));
        actionInsert_Sprite = new QAction(MainWindow);
        actionInsert_Sprite->setObjectName(QStringLiteral("actionInsert_Sprite"));
        actionInsert_Text = new QAction(MainWindow);
        actionInsert_Text->setObjectName(QStringLiteral("actionInsert_Text"));
        actionInsert_Sprite_2 = new QAction(MainWindow);
        actionInsert_Sprite_2->setObjectName(QStringLiteral("actionInsert_Sprite_2"));
        actionSave_Sprite_2 = new QAction(MainWindow);
        actionSave_Sprite_2->setObjectName(QStringLiteral("actionSave_Sprite_2"));
        actionInsert_Sprite_3 = new QAction(MainWindow);
        actionInsert_Sprite_3->setObjectName(QStringLiteral("actionInsert_Sprite_3"));
        actionSave_Sprite_3 = new QAction(MainWindow);
        actionSave_Sprite_3->setObjectName(QStringLiteral("actionSave_Sprite_3"));
        actionHelp = new QAction(MainWindow);
        actionHelp->setObjectName(QStringLiteral("actionHelp"));
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
        previewView = new QWidget(centralWidget);
        previewView->setObjectName(QStringLiteral("previewView"));
        previewView->setMaximumSize(QSize(16777215, 37));
        horizontalLayout = new QHBoxLayout(previewView);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 6, 0);
        line = new QFrame(previewView);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        horizontalLayout->addWidget(line);

        toolButton = new QToolButton(previewView);
        toolButton->setObjectName(QStringLiteral("toolButton"));
        toolButton->setMinimumSize(QSize(25, 25));
        toolButton->setMaximumSize(QSize(25, 25));
        QIcon icon;
        icon.addFile(QStringLiteral(":/images/icons/play.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton->setIcon(icon);
        toolButton->setIconSize(QSize(12, 12));

        horizontalLayout->addWidget(toolButton);

        toolButton_2 = new QToolButton(previewView);
        toolButton_2->setObjectName(QStringLiteral("toolButton_2"));
        toolButton_2->setMinimumSize(QSize(25, 25));
        toolButton_2->setMaximumSize(QSize(25, 25));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/images/icons/pause.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_2->setIcon(icon1);
        toolButton_2->setIconSize(QSize(12, 12));

        horizontalLayout->addWidget(toolButton_2);

        timestamp = new QLineEdit(previewView);
        timestamp->setObjectName(QStringLiteral("timestamp"));
        timestamp->setMinimumSize(QSize(60, 0));
        timestamp->setMaximumSize(QSize(0, 16777215));
        timestamp->setFrame(true);
        timestamp->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(timestamp);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        insertfBefore = new QPushButton(previewView);
        insertfBefore->setObjectName(QStringLiteral("insertfBefore"));
        insertfBefore->setMinimumSize(QSize(25, 25));
        insertfBefore->setMaximumSize(QSize(25, 25));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/images/icons/insertBefore.png"), QSize(), QIcon::Normal, QIcon::Off);
        insertfBefore->setIcon(icon2);

        horizontalLayout->addWidget(insertfBefore);

        insertAfter = new QPushButton(previewView);
        insertAfter->setObjectName(QStringLiteral("insertAfter"));
        insertAfter->setMinimumSize(QSize(25, 25));
        insertAfter->setMaximumSize(QSize(25, 25));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/images/icons/insertAfter.png"), QSize(), QIcon::Normal, QIcon::Off);
        insertAfter->setIcon(icon3);

        horizontalLayout->addWidget(insertAfter);

        insertCopy = new QPushButton(previewView);
        insertCopy->setObjectName(QStringLiteral("insertCopy"));
        insertCopy->setMinimumSize(QSize(25, 25));
        insertCopy->setMaximumSize(QSize(25, 25));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/images/icons/copy.png"), QSize(), QIcon::Normal, QIcon::Off);
        insertCopy->setIcon(icon4);

        horizontalLayout->addWidget(insertCopy);

        deleteFrame = new QPushButton(previewView);
        deleteFrame->setObjectName(QStringLiteral("deleteFrame"));
        deleteFrame->setMinimumSize(QSize(25, 25));
        deleteFrame->setMaximumSize(QSize(25, 25));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/images/icons/delete.png"), QSize(), QIcon::Normal, QIcon::Off);
        deleteFrame->setIcon(icon5);

        horizontalLayout->addWidget(deleteFrame);


        gridLayout->addWidget(previewView, 2, 2, 1, 1);

        canvasView = new QScrollArea(centralWidget);
        canvasView->setObjectName(QStringLiteral("canvasView"));
        canvasView->setWidgetResizable(true);
        canvasArea = new QWidget();
        canvasArea->setObjectName(QStringLiteral("canvasArea"));
        canvasArea->setGeometry(QRect(0, 0, 1175, 497));
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

        gridLayout->addWidget(canvasView, 0, 2, 1, 1);

        timelineScroll = new QScrollArea(centralWidget);
        timelineScroll->setObjectName(QStringLiteral("timelineScroll"));
        timelineScroll->setMinimumSize(QSize(0, 0));
        timelineScroll->setMaximumSize(QSize(16777215, 170));
        timelineScroll->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        timelineScroll->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        timelineScroll->setWidgetResizable(true);
        timelineArea = new QWidget();
        timelineArea->setObjectName(QStringLiteral("timelineArea"));
        timelineArea->setGeometry(QRect(0, 0, 1175, 164));
        horizontalLayout_2 = new QHBoxLayout(timelineArea);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        timeline = new QHBoxLayout();
        timeline->setSpacing(9);
        timeline->setObjectName(QStringLiteral("timeline"));
        timeline->setContentsMargins(9, 0, 9, -1);

        horizontalLayout_2->addLayout(timeline);

        timelineScroll->setWidget(timelineArea);

        gridLayout->addWidget(timelineScroll, 4, 2, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(9);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        verticalLayout->setContentsMargins(6, 6, 6, -1);
        gridLayout_4 = new QGridLayout();
        gridLayout_4->setSpacing(6);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        gridLayout_4->setContentsMargins(-1, 15, -1, 15);
        buttonUp = new QToolButton(centralWidget);
        buttonUp->setObjectName(QStringLiteral("buttonUp"));
        buttonUp->setMinimumSize(QSize(25, 25));
        buttonUp->setMaximumSize(QSize(25, 25));
        buttonUp->setArrowType(Qt::NoArrow);

        gridLayout_4->addWidget(buttonUp, 0, 2, 1, 1);

        buttonDown = new QToolButton(centralWidget);
        buttonDown->setObjectName(QStringLiteral("buttonDown"));
        buttonDown->setMinimumSize(QSize(25, 25));
        buttonDown->setMaximumSize(QSize(25, 25));
        buttonDown->setArrowType(Qt::NoArrow);

        gridLayout_4->addWidget(buttonDown, 2, 2, 1, 1);

        buttonLeft = new QToolButton(centralWidget);
        buttonLeft->setObjectName(QStringLiteral("buttonLeft"));
        buttonLeft->setMinimumSize(QSize(25, 25));
        buttonLeft->setMaximumSize(QSize(25, 25));
        buttonLeft->setArrowType(Qt::NoArrow);

        gridLayout_4->addWidget(buttonLeft, 1, 1, 1, 1);

        buttonRight = new QToolButton(centralWidget);
        buttonRight->setObjectName(QStringLiteral("buttonRight"));
        buttonRight->setMinimumSize(QSize(25, 25));
        buttonRight->setMaximumSize(QSize(25, 25));
        QFont font;
        font.setKerning(false);
        buttonRight->setFont(font);
        buttonRight->setArrowType(Qt::NoArrow);

        gridLayout_4->addWidget(buttonRight, 1, 4, 1, 1);

        boxColorChange = new QToolButton(centralWidget);
        boxColorChange->setObjectName(QStringLiteral("boxColorChange"));
        boxColorChange->setMinimumSize(QSize(25, 25));
        boxColorChange->setMaximumSize(QSize(25, 25));
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/images/icons/paintBucket.png"), QSize(), QIcon::Normal, QIcon::Off);
        boxColorChange->setIcon(icon6);

        gridLayout_4->addWidget(boxColorChange, 1, 2, 1, 1);


        verticalLayout->addLayout(gridLayout_4);

        toolColor = new QToolButton(centralWidget);
        toolColor->setObjectName(QStringLiteral("toolColor"));
        toolColor->setMinimumSize(QSize(46, 46));
        toolColor->setMaximumSize(QSize(40, 40));
        toolColor->setLayoutDirection(Qt::LeftToRight);
        toolColor->setStyleSheet(QLatin1String("background-color: black;\n"
" border: 2px inset grey;"));

        verticalLayout->addWidget(toolColor, 0, Qt::AlignHCenter);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);

        gridLayout->setRowStretch(0, 3);
        gridLayout->setRowStretch(4, 1);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1280, 26));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuInsert = new QMenu(menuBar);
        menuInsert->setObjectName(QStringLiteral("menuInsert"));
        menuSprite = new QMenu(menuBar);
        menuSprite->setObjectName(QStringLiteral("menuSprite"));
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuInsert->menuAction());
        menuBar->addAction(menuSprite->menuAction());
        menuFile->addAction(actionMenuOpen);
        menuFile->addAction(actionMenuNew);
        menuFile->addAction(actionMenuSave);
        menuFile->addAction(actionExport);
        menuFile->addSeparator();
        menuFile->addAction(actionMenuExit);
        menuInsert->addAction(actionInsertBefore);
        menuInsert->addAction(actionInsertAfter);
        menuInsert->addAction(actionInsertCopy);
        menuInsert->addSeparator();
        menuInsert->addAction(actionDelete);
        menuSprite->addAction(actionInsert_Sprite_3);
        menuSprite->addAction(actionSave_Sprite_3);

        retranslateUi(MainWindow);
        QObject::connect(actionMenuExit, SIGNAL(triggered()), MainWindow, SLOT(close()));
        QObject::connect(actionMenuOpen, SIGNAL(triggered()), MainWindow, SLOT(openFile()));
        QObject::connect(actionMenuNew, SIGNAL(triggered()), MainWindow, SLOT(newFile()));
        QObject::connect(actionMenuSave, SIGNAL(triggered()), MainWindow, SLOT(saveFile()));
        QObject::connect(toolColor, SIGNAL(clicked()), MainWindow, SLOT(setDrawColor()));
        QObject::connect(buttonUp, SIGNAL(clicked()), MainWindow, SLOT(boxShiftUp()));
        QObject::connect(buttonLeft, SIGNAL(clicked()), MainWindow, SLOT(boxShiftLeft()));
        QObject::connect(buttonRight, SIGNAL(clicked()), MainWindow, SLOT(boxShiftRight()));
        QObject::connect(buttonDown, SIGNAL(clicked()), MainWindow, SLOT(boxShiftDown()));
        QObject::connect(actionExport, SIGNAL(triggered()), MainWindow, SLOT(exportFile()));
        QObject::connect(toolButton, SIGNAL(clicked()), MainWindow, SLOT(preview()));
        QObject::connect(actionInsertAfter, SIGNAL(triggered()), MainWindow, SLOT(insertAfter()));
        QObject::connect(insertCopy, SIGNAL(clicked()), MainWindow, SLOT(copyFrame()));
        QObject::connect(insertfBefore, SIGNAL(clicked()), MainWindow, SLOT(insertBefore()));
        QObject::connect(insertAfter, SIGNAL(clicked()), MainWindow, SLOT(insertAfter()));
        QObject::connect(deleteFrame, SIGNAL(clicked()), MainWindow, SLOT(deleteFrame()));
        QObject::connect(actionInsertBefore, SIGNAL(triggered()), MainWindow, SLOT(insertBefore()));
        QObject::connect(actionInsertCopy, SIGNAL(triggered()), MainWindow, SLOT(copyFrame()));
        QObject::connect(toolButton_2, SIGNAL(clicked()), MainWindow, SLOT(stop()));
        QObject::connect(actionDelete, SIGNAL(triggered()), MainWindow, SLOT(deleteFrame()));
        QObject::connect(actionHelp, SIGNAL(triggered()), MainWindow, SLOT(help()));
        QObject::connect(boxColorChange, SIGNAL(clicked()), MainWindow, SLOT(boxColorChange()));

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
        actionInsertAfter->setText(QApplication::translate("MainWindow", "Insert After", Q_NULLPTR));
        actionInsertBefore->setText(QApplication::translate("MainWindow", "Insert Before", Q_NULLPTR));
        actionDeletFrame->setText(QApplication::translate("MainWindow", "Delete Frame", Q_NULLPTR));
        actionInsertCopy->setText(QApplication::translate("MainWindow", "Duplicate", Q_NULLPTR));
        actionExport->setText(QApplication::translate("MainWindow", "Export", Q_NULLPTR));
        actionDelete->setText(QApplication::translate("MainWindow", "Delete Frame", Q_NULLPTR));
        actionSave_Sprite->setText(QApplication::translate("MainWindow", "Save Sprite", Q_NULLPTR));
        actionInsert_Sprite->setText(QApplication::translate("MainWindow", "Insert Sprite", Q_NULLPTR));
        actionInsert_Text->setText(QApplication::translate("MainWindow", "Insert Text", Q_NULLPTR));
        actionInsert_Sprite_2->setText(QApplication::translate("MainWindow", "Insert Sprite", Q_NULLPTR));
        actionSave_Sprite_2->setText(QApplication::translate("MainWindow", "Save Sprite", Q_NULLPTR));
        actionInsert_Sprite_3->setText(QApplication::translate("MainWindow", "Insert Sprite", Q_NULLPTR));
        actionSave_Sprite_3->setText(QApplication::translate("MainWindow", "Save Sprite", Q_NULLPTR));
        actionHelp->setText(QApplication::translate("MainWindow", "Help!!!!!", Q_NULLPTR));
        toolButton->setText(QString());
        toolButton_2->setText(QApplication::translate("MainWindow", "...", Q_NULLPTR));
        timestamp->setInputMask(QApplication::translate("MainWindow", "99:99.99", Q_NULLPTR));
        timestamp->setText(QApplication::translate("MainWindow", "00:00.00", Q_NULLPTR));
        timestamp->setPlaceholderText(QString());
#ifndef QT_NO_TOOLTIP
        insertfBefore->setToolTip(QApplication::translate("MainWindow", "Insert frame before", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        insertfBefore->setText(QString());
#ifndef QT_NO_TOOLTIP
        insertAfter->setToolTip(QApplication::translate("MainWindow", "Insert frame after", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        insertAfter->setText(QString());
#ifndef QT_NO_TOOLTIP
        insertCopy->setToolTip(QApplication::translate("MainWindow", "Insert copy of frame", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        insertCopy->setText(QString());
#ifndef QT_NO_TOOLTIP
        deleteFrame->setToolTip(QApplication::translate("MainWindow", "Delete frame", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        deleteFrame->setText(QString());
        buttonUp->setText(QApplication::translate("MainWindow", "\342\226\262", Q_NULLPTR));
        buttonDown->setText(QApplication::translate("MainWindow", "\342\226\274", Q_NULLPTR));
        buttonLeft->setText(QApplication::translate("MainWindow", "\342\227\204", Q_NULLPTR));
        buttonRight->setText(QApplication::translate("MainWindow", "\342\226\272", Q_NULLPTR));
        boxColorChange->setText(QApplication::translate("MainWindow", "...", Q_NULLPTR));
        toolColor->setText(QString());
        menuFile->setTitle(QApplication::translate("MainWindow", "File", Q_NULLPTR));
        menuInsert->setTitle(QApplication::translate("MainWindow", "Frame", Q_NULLPTR));
        menuSprite->setTitle(QApplication::translate("MainWindow", "Tools", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
