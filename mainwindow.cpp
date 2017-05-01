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
    ui->boxColorChange->setStyleSheet(QString("background-color: %1; border: 2px inset grey;").arg(drawColor.name()));
}

//Function to create new frame
// 4/25/17 - update to allow insertion before and after current frame
void MainWindow::newCanvas(int pos)
{
    if(current_tf != NULL) saveCanvas(current_tf->canvas);

    QVector<QColor> canvas;
    ui->canvasArea->hide();
    for(int i = 0; i < canvasCells.length(); i++){
        canvasCells[i]->setColor(Qt::black);
        canvas.push_back(canvasCells[i]->getColor());
    }
    ui->canvasArea->show();
    //get index of current frame
    int index;
    if(pos == 1)
        index = timeline.indexOf(current_tf); //for insert before current frame
    else if(pos == 2)
        index = timeline.indexOf(current_tf) + 1; //for insert after current frame

    TimelineFrame *tf = new TimelineFrame(this, canvas, frameDim, ui->timestamp->text());
    current_tf = tf;
    connect(tf, SIGNAL(clicked(TimelineFrame*)), this, SLOT(loadCanvas(TimelineFrame*)));
    loadCanvas(tf);
    timeline.insert(index, tf);
    ui->timeline->insertWidget(index, tf);
}

//Insert new frame after current frame
//Function calls newCanvas with a 2 for insertion after current frame
// Added 4/27/17 - RP
void MainWindow::insertAfter()
{
    if(current_tf != NULL)
        newCanvas(2);
}

//Insert new frame before current frame
//Funciton calls newCanvas with a 1 for insertion before current frame
// Added 4/27/17 - RP
void MainWindow::insertBefore()
{
    if(current_tf != NULL)
        newCanvas(1);
}

//inserts copy of current frame after current frame
//added 4/25/17 - RP
void MainWindow::copyFrame()
{
    if(current_tf == NULL) return;
    QColor current;
    if(current_tf != NULL) saveCanvas(current_tf->canvas);

    QVector<QColor> canvas;
    for(int i = 0; i < canvasCells.length(); i++){
        current = current_tf->canvas[i];
        canvasCells[i]->setColor(current);
        canvas.push_back(canvasCells[i]->getColor());
    }

    //get index of current frame
    int index;

    index = timeline.indexOf(current_tf) + 1; //for insert after current frame

    TimelineFrame *tf = new TimelineFrame(this, canvas, frameDim, ui->timestamp->text());
    tf->timestamp = current_tf->timestamp; //set timestamp the same as timestamp of frame being copied
    current_tf = tf;
    connect(tf, SIGNAL(clicked(TimelineFrame*)), this, SLOT(loadCanvas(TimelineFrame*)));

    timeline.insert(index, tf);
    ui->timeline->insertWidget(index, tf);
}


//function to delete frame
//added 4/25/17 - RP
void MainWindow::deleteFrame()
{
    TimelineFrame *temp;
    int index;

    if(current_tf == NULL || timeline.size() == 1)
        return;
    //get index of current frame
    index = timeline.indexOf(current_tf);

    //remove thumbnail of timeline view
    temp = ((TimelineFrame*)(ui->timeline->itemAt(index)->widget()));
    ui->timeline->removeWidget(temp);
    delete temp;
    ui->timeline->update();

    //remove frame from list
    timeline.removeAt(index);

    //sets the current frame to the frame after frame deleted
    //unless the last frame was deleted then sets it to the
    //new last frame.
    //changed from setting to frame before deleted frame 4/27/17 - RP
    if(index >= timeline.size())
        current_tf = timeline[index - 1];
    else
        current_tf = timeline[index];

    loadCanvas(current_tf);
}

//Func will take the colors of the canvas and save it to linked list
void MainWindow::saveCanvas(QVector<QColor> &canvas){
    for(int i = 0; i < canvasCells.length(); i++){
        canvas[i] = canvasCells[i]->getColor();
    }
    current_tf->timestamp = ui->timestamp->text();
}

//Func will populate canvas with appropriate colors
void MainWindow::loadCanvas(TimelineFrame *tf){
    QColor current;

    //saveCanvas(current_tf->canvas);

    if(current_tf != NULL) current_tf->timestamp = ui->timestamp->text();
    current_tf = tf;
    ui->timestamp->setText(current_tf->timestamp);

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




/***********************************************************************
 *                     Michael and Ruth 4/18/2017                      *
 * ********************************************************************/




//This function shifts every cell up one position and overwrites what was written there before
void MainWindow::boxShiftUp()
{
    if(current_tf != NULL)
    {
        int top_right, top_left, bot_right, rows, width;
        top_left = 0;
        bot_right = frameDim.x() * frameDim.y() * 9 - 1;
        width = frameDim.x() * 3;
        //The top right position of the box selected
        top_right = bot_right % width + top_left - top_left % width;
        //The number of rows in the box selected
        rows = (floor(bot_right/width))-(floor(top_left/width));
        //Traversing the matrix defined by the box selected by user
        for(int i = 0; i <= rows; i++)
        {
            for(int j = (top_left + i*width); j <= (top_right + i*width); j++)
            {
                if(j - width >= 0)  //Only copy value of rgb if the cell is not at the top of the current_tf->current_tf->canvas
                {
                    current_tf->canvas[j - width] = current_tf->canvas[j];
                }
                //Changed to i == rows-1 off by 1 error 3/28/2017
                if(i == rows)  //Overwrite the bottom row to the default rgb color
                {
                    current_tf->canvas [j] = Qt::black;

                }
            }
        }
        //If box selected would go out of bounds keep topLeft and move botRight
        if (top_left - width < 0)
        bot_right -= width;
        else
        {
            top_left -= width;
            bot_right -= width;
        }


         loadCanvas(current_tf);
         current_tf->createPreview(frameDim);
    }
}



//This function shifts every cell down one position and overwrites what was written there before
void MainWindow::boxShiftDown ()
{
    if(current_tf != NULL)
    {
        int top_left, bot_right, bot_left, rows, width, height;
        top_left = 0;
        bot_right = frameDim.x() * frameDim.y() * 9 - 1;
        width = frameDim.x() * 3;
        height = frameDim.y() * 3;
        //The number of rows in the box selected
        rows = (floor(bot_right/width))-(floor(top_left/width));
        //The bottom left position of the box selected
        //subtracted another width to correctly find the bottom left 3/28/2017
        bot_left = top_left + rows * width - width;
        //Traversing the matrix defined by the box selected by user
        for(int i = rows; i >= 0; i--)
        {
            for(int j = bot_right - ((rows - i) * width); j >= bot_left - ((rows - i) * width - width); j--)
            {
                if(j + width <= width * height - 1) //Only copy value of rgb if the cell is not at the bottom of the current_tf->canvas
                {
                    current_tf->canvas[j + width] = current_tf->canvas[j];
                }
                //Changed to i == 1 off by 1 error 3/28/2017
                if(i == 0)  //Overwrite the top row to the default rgb color
                {
                    current_tf->canvas [j] = Qt::black;

                }
            }
        }
        //If box selected would go out of bounds keep bot_right and move top_left
        if (bot_right + width >= width*height)
        top_left += width;
        else
        {
            top_left += width;
            bot_right += width;
        }

        loadCanvas(current_tf);
        current_tf->createPreview(frameDim);
    }
}
//This function shifts every pixel right one position and overwrites what was written there before
void MainWindow::boxShiftRight ()
{
    if(current_tf != NULL)
    {
        int top_left, bot_right, bot_left, rows, width;
        top_left = 0;
        bot_right = frameDim.x() * frameDim.y() * 9 - 1;
        width = frameDim.x() * 3;
        //The number of rows in the box selected
        rows = (floor(bot_right/width))-(floor(top_left/width));
        //The bottom left position of the box selected
        //subtracted another width to correctly find the bottom left 3/28/2017
        bot_left = top_left + rows * width - width;
        //Traversing the matrix defined by the box selected by user
        for(int i = rows; i >= 0; i--)
        {
            for(int j = bot_right - ((rows - i) * width); j >= bot_left - ((rows - i) * width - width); j--)
            {
                if((j % width) + 1 < width)    //Only copy value of rgb if the cell is not in the rightmost column
                {
                    current_tf->canvas[j + 1] = current_tf->canvas[j];
                }

                if(j == bot_left - ((rows - i) * width - width)) //Overwrite the left column to the default rgb color
                {

                    current_tf->canvas [j] = Qt::black;
                }
            }
        }
        //If box selected would go out of bounds keep bot_right and move top_left
        if (bot_right%width + 1 >= width)
        top_left += 1;
        else
        {
            top_left += 1;
            bot_right += 1;
        }

        loadCanvas(current_tf);
        current_tf->createPreview(frameDim);
    }
}
//This function shifts every pixel left one position and overwrites what was written there before
void MainWindow::boxShiftLeft ()
{
    if(current_tf != NULL)
    {
        int top_right, top_left, bot_right, rows, width;
        top_left = 0;
        bot_right = frameDim.x() * frameDim.y() * 9 - 1;
        width = frameDim.x() * 3;
        //The top right position of the box selected
        top_right = bot_right % width + top_left - top_left % width;
        //The number of rows in the box selected
        rows = (floor(bot_right/width))-(floor(top_left/width));
        //Traversing the matrix defined by the box selected by user
        for(int i = 0; i <= rows; i++)
        {
            for(int j = (top_left + i*width); j <= (top_right + i*width); j++)
            {
                if((j % width) - 1 >= 0)    //Only copy value of rgb if the cell is not in the leftmost column
                {
                    current_tf->canvas[j - 1] = current_tf->canvas[j];
                }

                if(j == (top_right + i*width))   //Overwrite the leftmost column to the default rgb color
                {
                    current_tf->canvas [j] = Qt::black;
                }
            }
        }
        //If box selected would go out of bounds keep top_left and move bot_right
        if (top_left%width - 1 < 0)
        bot_right -= 1;
        else
        {
            top_left -= 1;
            bot_right -= 1;
        }

        loadCanvas(current_tf);
        current_tf->createPreview(frameDim);
    }
}

//Func will change the box selected to the color currently selected
void MainWindow::boxColorChange()
{
    if(current_tf != NULL)
    {
        int top_right, top_left, bot_right, rows, width;
        top_left = 0;
        bot_right = frameDim.x() * frameDim.y() * 9 - 1;
        width = frameDim.x() * 3;
        //The top right position of the box selected
        top_right = bot_right % width + top_left - top_left % width;
        //The number of rows in the box selected
        rows = (floor(bot_right/width))-(floor(top_left/width));
        //Traversing the matrix defined by the box selected by user
        for(int i = 0; i <= rows; i++)
        {
            //Change every pixel in the box selected to the user defined rgb color
            for(int j = (top_left + i*width); j <= (top_right + i*width); j++)
            {
                current_tf->canvas[j]= drawColor;

            }
        }
        loadCanvas(current_tf);
        current_tf->createPreview(frameDim);
    }

}



/***********************************************************************
 *                     Michael and Ruth 4/18/2017                      *
 * ********************************************************************/



//Func is called whenever we have a canvas size to work with(new or load proj)
void MainWindow::populateCanvas(){
    //ui->canvasArea->setGeometry(QRect(0, 0, 12 * qRound(frameDim.x()) * 3, 12 * qRound(frameDim.y()) * 3));
    ui->canvas->setAlignment(Qt::AlignCenter);
    ui->canvasArea->hide();
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
    ui->canvasArea->show();
}

void MainWindow::cleanCanvas(){
    QLayoutItem *child;
    ui->canvasArea->hide();
    while ((child = ui->canvas->takeAt(0)) != 0) {
        delete child->widget();
        delete child;
    }
    ui->canvasArea->show();

    ui->timelineArea->hide();
    while ((child = ui->timeline->takeAt(0)) != 0) {
        delete child->widget();
        delete child;
    }
    ui->timelineArea->show();

    current_tf = NULL;
    timeline.clear();
    canvasCells.clear();
}

//TODO: Change something so that adding a new file while one is open causes the old one to close
void MainWindow::newFile(){
    QVector2D temp = NewFileDialog::getFrameDim(this, tr("Frame Size"));

    if(!temp.isNull()){
        
        frameDim = temp;

        if(!timeline.isEmpty()) cleanCanvas();
        
        //Call the function that populates the canvas
        populateCanvas();
        newCanvas(2);
    }

}

void MainWindow::openFile(){
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"),
                                                        QStandardPaths::displayName(QStandardPaths::DocumentsLocation),
                                                        tr("Text files (*.txt)"));

    if(!fileName.isEmpty()){
        
        if(!timeline.isEmpty()) cleanCanvas();
        
        int sizeX, sizeY;
        QList<QColor> externalFrame;
        QList<QString> timestamps;
        loadProject(fileName, &sizeX, &sizeY, &externalFrame, &timestamps);
        frameDim.setX(sizeX / 3);
        frameDim.setY(sizeY / 3);
        populateCanvas();

        //Just no...
        for(int i = 0; i < (externalFrame.size() + 1) / (sizeX * sizeY); i++){
            QVector<QColor> c;
            for(int j = 0; j < sizeX * sizeY; j++){
                c.push_back(externalFrame[(i * sizeX * sizeY) + j]);
            }
            TimelineFrame *tf = new TimelineFrame(this, c, frameDim, timestamps[i]);
            connect(tf, SIGNAL(clicked(TimelineFrame*)), this, SLOT(loadCanvas(TimelineFrame*)));
            timeline.push_back(tf);
            ui->timeline->addWidget(tf);
        }

        loadCanvas(timeline.front());
    }
}

void MainWindow::saveFile(){
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"),
                                                        QStandardPaths::displayName(QStandardPaths::DocumentsLocation),
                                                        tr("Text files (*.txt)"));
    if(!fileName.isEmpty()){

        saveCanvas(current_tf->canvas);

        QList<QColor> list;
        QList<QString> timestamp;

        //Creating a QList from the timeline is not an optimal choice
        for(int i = 0; i < timeline.size(); i++){
            TimelineFrame *temp = timeline[i];
            timestamp.append(temp->timestamp);
            for(int j = 0; j < temp->canvas.size(); j++){
                list.append(temp->canvas[j]);
            }
        }

        saveProject(fileName, frameDim.x() * 3, frameDim.y() * 3, list, timestamp);

        //Call the function that saves the linked list to the .tan format
    }
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



void MainWindow::preview()
{
    int i = 0;
    while(i < timeline.length()){
        current_tf = timeline[i];
        loadCanvas(current_tf);
        qApp->processEvents();
        this->repaint();

    //code works, timestamp currently has a bug that lets the initial timestamp
    //save over all timestamps, will include when bug is fixed

    //QStringList temp;// = ((timeline[i]->timestamp).split('.'))[0].split(':');

    //temp.append(((timeline[i]->timestamp).split('.'))[0].split(':')[0]);
    //temp.append(((timeline[i]->timestamp).split('.'))[0].split(':')[1]);
    //temp.append(((timeline[i]->timestamp).split('.'))[1]);
    //qDebug() << i << " is the run" << timeline[i]->timestamp;
    //for(int j = 0; j < temp.length(); j++){
        //qDebug() << temp[j];
    //}

        QThread::usleep(33333);

        i++;
    }
}

void MainWindow::exportFile(){
    QString fileName = QFileDialog::getSaveFileName(this, tr("Export File"),
                                                        QStandardPaths::displayName(QStandardPaths::DocumentsLocation),
                                                        tr("Tan files (*.tan)"));
    if(!fileName.isEmpty()){

        saveCanvas(current_tf->canvas);

        QList<QColor> list;
        QList<QString> timestamp;

        //Creating a QList from the timeline is not an optimal choice
        for(int i = 0; i < timeline.size(); i++){
            TimelineFrame *temp = timeline[i];
            timestamp.append(temp->timestamp);
            for(int j = 0; j < temp->canvas.size(); j++){
                list.append(temp->canvas[j]);
            }
        }
        exportFrame(fileName, frameDim.x() * 3, frameDim.y() * 3, list, timestamp);

        //Call the function that saves the linked list to the .tan format
    }
}
