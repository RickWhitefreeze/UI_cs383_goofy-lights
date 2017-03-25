#include "mainwindow.h"
#include "ui_mainwindow.h"

void MainWindow::openFile(){
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"),
                                                    QStandardPaths::displayName(QStandardPaths::DocumentsLocation),
                                                    tr("Text files (*.txt)"));
}

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
	resize(640, 480);
	setMinimumSize(QSize(640, 480));
    actionOpen = new QAction(this);
	actionOpen->setObjectName(QStringLiteral("actionOpen"));
    actionExit = new QAction(this);
	actionExit->setObjectName(QStringLiteral("actionExit"));
    centralWidget = new QWidget(this);
	centralWidget->setObjectName(QStringLiteral("centralWidget"));
	horizontalLayout = new QHBoxLayout(centralWidget);
	horizontalLayout->setSpacing(0);
	horizontalLayout->setContentsMargins(11, 11, 11, 11);
	horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
	horizontalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
	horizontalLayout->setContentsMargins(0, 0, 0, 0);
	toolBox = new QGroupBox(centralWidget);
	toolBox->setObjectName(QStringLiteral("toolBox"));
	toolBox->setEnabled(true);
	QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
	sizePolicy.setHorizontalStretch(0);
	sizePolicy.setVerticalStretch(0);
	sizePolicy.setHeightForWidth(toolBox->sizePolicy().hasHeightForWidth());
	toolBox->setSizePolicy(sizePolicy);
	toolBox->setMinimumSize(QSize(48, 0));
	toolBox->setMaximumSize(QSize(48, 16777215));
	toolBox->setAlignment(Qt::AlignCenter);
	toolBox->setFlat(true);
	toolBrush = new QToolButton(toolBox);
	toolBrush->setObjectName(QStringLiteral("toolBrush"));
	toolBrush->setGeometry(QRect(4, 10, 40, 40));
	QIcon icon;
	icon.addFile(QStringLiteral(":/images/icons/brush.png"), QSize(), QIcon::Normal, QIcon::Off);
	toolBrush->setIcon(icon);
	toolBrush->setIconSize(QSize(20, 20));
	toolBrush->setCheckable(false);
	toolBrush->setAutoExclusive(false);
	toolWrite = new QToolButton(toolBox);
	toolWrite->setObjectName(QStringLiteral("toolWrite"));
	toolWrite->setGeometry(QRect(4, 60, 40, 40));
	QIcon icon1;
	icon1.addFile(QStringLiteral(":/images/icons/text.png"), QSize(), QIcon::Normal, QIcon::Off);
	toolWrite->setIcon(icon1);
	toolWrite->setIconSize(QSize(18, 18));
	toolWrite->setCheckable(false);
	toolWrite->setAutoExclusive(false);
	toolSelect = new QToolButton(toolBox);
	toolSelect->setObjectName(QStringLiteral("toolSelect"));
	toolSelect->setGeometry(QRect(4, 110, 40, 40));
	QIcon icon2;
	icon2.addFile(QStringLiteral(":/images/icons/box.png"), QSize(), QIcon::Normal, QIcon::Off);
	toolSelect->setIcon(icon2);
	toolSelect->setIconSize(QSize(32, 24));
	toolSelect->setCheckable(false);
	toolSelect->setAutoExclusive(false);
	toolColor = new QToolButton(toolBox);
	toolColor->setObjectName(QStringLiteral("toolColor"));
	toolColor->setGeometry(QRect(4, 160, 40, 40));
	QIcon icon3;
	icon3.addFile(QStringLiteral(":/images/icons/color.png"), QSize(), QIcon::Normal, QIcon::Off);
	toolColor->setIcon(icon3);
	toolColor->setIconSize(QSize(32, 24));
	toolColor->setCheckable(false);
	toolColor->setAutoExclusive(false);

	horizontalLayout->addWidget(toolBox);

	viewer = new QGroupBox(centralWidget);
	viewer->setObjectName(QStringLiteral("viewer"));
	sizePolicy.setHeightForWidth(viewer->sizePolicy().hasHeightForWidth());
	viewer->setSizePolicy(sizePolicy);
	viewer->setFlat(true);
	verticalLayout = new QVBoxLayout(viewer);
	verticalLayout->setSpacing(0);
	verticalLayout->setContentsMargins(11, 11, 11, 11);
	verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
	verticalLayout->setContentsMargins(0, 0, 0, 0);
	canvas = new QGraphicsView(viewer);
	canvas->setObjectName(QStringLiteral("canvas"));
	canvas->setEnabled(true);
	canvas->setFrameShape(QFrame::Panel);
	canvas->setFrameShadow(QFrame::Plain);
	canvas->setLineWidth(1);
	canvas->setMidLineWidth(0);

	verticalLayout->addWidget(canvas);

	timeline = new QColumnView(viewer);
	timeline->setObjectName(QStringLiteral("timeline"));
	timeline->setMinimumSize(QSize(0, 0));
	timeline->setMaximumSize(QSize(16777215, 180));
	timeline->setFrameShape(QFrame::Panel);
	timeline->setFrameShadow(QFrame::Plain);
	timeline->setLineWidth(1);
	timeline->setMidLineWidth(0);

	verticalLayout->addWidget(timeline);

	verticalLayout->setStretch(0, 3);
	verticalLayout->setStretch(1, 1);

	horizontalLayout->addWidget(viewer);

	setCentralWidget(centralWidget);
    menuBar = new QMenuBar(this);
	menuBar->setObjectName(QStringLiteral("menuBar"));
	menuBar->setGeometry(QRect(0, 0, 640, 21));
	menuFile = new QMenu(menuBar);
	menuFile->setObjectName(QStringLiteral("menuFile"));
	setMenuBar(menuBar);

	menuBar->addAction(menuFile->menuAction());
	menuFile->addAction(actionOpen);
	menuFile->addAction(actionExit);
	
    setWindowTitle(QApplication::translate("MainWindow", "Goofy Lights Editor", Q_NULLPTR));
    actionOpen->setText(QApplication::translate("MainWindow", "O&pen File", Q_NULLPTR));
	actionOpen->setShortcut(QApplication::translate("MainWindow", "Ctrl+O", Q_NULLPTR));
    connect(actionOpen, &QAction::triggered, this, &MainWindow::openFile);

    actionExit->setText(QApplication::translate("MainWindow", "E&xit", Q_NULLPTR));
    actionExit->setShortcuts(QKeySequence::Quit);
	connect(actionExit, &QAction::triggered, this, &QWidget::close);
	
	toolBox->setTitle(QString());
#ifndef QT_NO_TOOLTIP
        toolBrush->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>Paint</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        toolBrush->setText(QString());
#ifndef QT_NO_TOOLTIP
        toolWrite->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>Text</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        toolWrite->setText(QApplication::translate("MainWindow", "...", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        toolSelect->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>Box Select</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        toolSelect->setText(QString());
#ifndef QT_NO_TOOLTIP
        toolColor->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>Color Picker</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        toolColor->setText(QString());
        menuFile->setTitle(QApplication::translate("MainWindow", "File", Q_NULLPTR));
}

MainWindow::~MainWindow()
{
    delete ui;
}
