#include "mainwindow.h"
#include "ui_mainwindow.h"

void MainWindow::setCellColor(QVector2D pos){
    canvasCells[pos.x() + pos.y() * frameDim.x() * 3]->setColor(drawColor);

    if(pos.x() >= frameDim.x() && pos.x() < frameDim.x() * 2 && pos.y() >= frameDim.y() && pos.y() < frameDim.y() * 2){
        canvasCells[pos.x() + pos.y() * frameDim.x() * 3]->setStyleSheet(QString("background-color: rgb(%1,%2,%3);").arg(drawColor.red()).arg(drawColor.green()).arg(drawColor.blue()));
    }else{
        canvasCells[pos.x() + pos.y() * frameDim.x() * 3]->setStyleSheet(QString("background-color: rgba(%1,%2,%3,25%);").arg(drawColor.red()).arg(drawColor.green()).arg(drawColor.blue()));
    }

    saveCanvas(current_tf->canvas);
    current_tf->createPreview(frameDim);
}

void MainWindow::setDrawColor(){
    drawColor = QColorDialog::getColor(Qt::black, this, QString("Select Color."));
    ui->toolColor->setStyleSheet(QString("background-color: %1; border: 2px inset grey;").arg(drawColor.name()));
}

void MainWindow::newCanvas(){

    if(current_tf != NULL) saveCanvas(current_tf->canvas);

    QVector<QColor> canvas;
    for(int i = 0; i < canvasCells.length(); i++){
        canvasCells[i]->setColor(Qt::black);
        canvas.push_back(canvasCells[i]->getColor());
    }

    TimelineFrame *tf = new TimelineFrame(this, canvas, frameDim);
    current_tf = tf;
    connect(tf, SIGNAL(clicked(TimelineFrame*)), this, SLOT(loadCanvas(TimelineFrame*)));
    loadCanvas(tf);

    timeline.push_back(canvas);
    ui->timeline->addWidget(tf);
}

//Func will take the colors of the canvas and save it to linked list
void MainWindow::saveCanvas(QVector<QColor> &canvas){
    for(int i = 0; i < canvasCells.length(); i++){
        canvas[i] = canvasCells[i]->getColor();
    }
}

//Func will populate canvas with appropriate colors
void MainWindow::loadCanvas(TimelineFrame *tf){
    QColor current;

    //saveCanvas(current_tf->canvas);
    current_tf = tf;

    int i = 0;
    for(int y = 0; y < frameDim.y() * 3; y++){
        for(int x = 0; x < frameDim.x() * 3; x++){
            current = tf->canvas[i];
            canvasCells[i]->setColor(current);

            if(x >= frameDim.x() && x < frameDim.x() * 2 && y >= frameDim.y() && y < frameDim.y() * 2){
                canvasCells[i]->setStyleSheet(QString("background-color:rgba(%1,%2,%3,100%);").arg(current.red()).arg(current.green()).arg(current.blue()));
            }else{
                canvasCells[i]->setStyleSheet(QString("background-color:rgba(%1,%2,%3,25%);").arg(current.red()).arg(current.green()).arg(current.blue()));
            }
            i++;
        }
    }
}

//Func is called whenever we have a canvas size to work with(new or load proj)
void MainWindow::populateCanvas(){
    //ui->canvasArea->setGeometry(QRect(0, 0, 12 * qRound(frameDim.x()) * 3, 12 * qRound(frameDim.y()) * 3));
    ui->canvas->setAlignment(Qt::AlignCenter);

    for(int y = 0; y < frameDim.y() * 3; y++){
        for(int x = 0; x < frameDim.x() * 3; x++){
            QVector2D pos(x,y);
            Cell *temp = new Cell(this, pos);
            connect(temp, SIGNAL(clicked(QVector2D)), this, SLOT(setCellColor(QVector2D)));
            canvasCells.push_back(temp);
            if(x >= frameDim.x() && x < frameDim.x() * 2 && y >= frameDim.y() && y < frameDim.y() * 2){
                temp->setStyleSheet("background-color:rgba(0,0,0,100%);");
            }
            ui->canvas->addWidget(temp, y, x);
        }
    }
}

//TODO: Change something so that adding a new file while one is open causes the old one to close
void MainWindow::newFile(){
    frameDim = NewFileDialog::getFrameDim(this, tr("Frame Size"));
    //Create a linked list
    //Call the function that populates the canvas
    populateCanvas();
    newCanvas();
}

void MainWindow::openFile(){
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"),
                                                        QStandardPaths::displayName(QStandardPaths::DocumentsLocation),
                                                        tr("Text files (*.txt)"));
    //Call the function that loads .tan format into linked list
    //Call the function that populates the canvas
    //populateCanvas();
    //loadCanvas(timeline.front());
}

void MainWindow::saveFile(){
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"),
                                                        QStandardPaths::displayName(QStandardPaths::DocumentsLocation),
                                                        tr("Text files (*.txt)"));
    //Call the function that saves the linked list to the .tan format
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}
