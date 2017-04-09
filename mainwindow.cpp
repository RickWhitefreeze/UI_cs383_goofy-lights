#include "mainwindow.h"
#include "ui_mainwindow.h"

void MainWindow::setCellColor(QVector2D pos){
    canvasCells[pos.x() + pos.y() * frameDim.x() * 3]->setColor(drawColor);

    if(pos.x() >= frameDim.x() && pos.x() < frameDim.x() * 2 && pos.y() >= frameDim.y() && pos.y() < frameDim.y() * 2){
        canvasCells[pos.x() + pos.y() * frameDim.x() * 3]->setStyleSheet(QString("background-color: rgb(%1,%2,%3);").arg(drawColor.red()).arg(drawColor.green()).arg(drawColor.blue()));
    }else{
        canvasCells[pos.x() + pos.y() * frameDim.x() * 3]->setStyleSheet(QString("background-color: rgba(%1,%2,%3,25%);").arg(drawColor.red()).arg(drawColor.green()).arg(drawColor.blue()));
    }
}

void MainWindow::setDrawColor(){
    drawColor = QColorDialog::getColor(Qt::black, this, QString("Select Color."));
    ui->toolColor->setStyleSheet(QString("background-color: %1; border: 2px inset grey;").arg(drawColor.name()));
}

void MainWindow::renderCanvas(){
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
    renderCanvas();
    //renderCanvas(linkedlist);
}

void MainWindow::openFile(){
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"),
                                                        QStandardPaths::displayName(QStandardPaths::DocumentsLocation),
                                                        tr("Text files (*.txt)"));
    //Call the function that loads .tan format into linked list
    //Call the function that populates the canvas
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
