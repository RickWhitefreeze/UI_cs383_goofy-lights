#include "mainwindow.h"
#include <QApplication>
#include <QString>
#include <QFile>
#include <QDebug>
#include <QTextStream>

#define timeStampSize 10

void saveFrame(QString fileName, int headerSize, int frameNum, int sizeX, int sizeY/*, vector<QColor> Frame*/);

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    saveFrame("C:\\Users\\Toshi\\Desktop\\testfile.txt", 4, 3, 2, 2);

    return a.exec();
}

void saveFrame(QString fileName, int headerSize, int frameNum, int sizeX, int sizeY/*, vector<QColor> Frame*/){
    QFile mFile(fileName);

    if(!mFile.open(QFile::ReadWrite | QFile::Text)){
        qDebug() << "error opening file";
        return;
    }

    QTextStream out(&mFile);

    //skip to correct location
    mFile.seek(headerSize + (frameNum * (sizeX * sizeY * 3 + timeStampSize)));

    //write Timestamp
    for(int i = 0; i < timeStampSize; i++){
        //placeholder timestamp
        mFile.putChar('0');
    }

    //write RGB Data
    for(int i = 0; i < sizeX * sizeY; i++){
        //test values instead of real rgb values
        mFile.putChar('a');
        mFile.putChar('b');
        mFile.putChar('c');
    }

    mFile.close();

}
