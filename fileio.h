#ifndef FILEIO_H
#define FILEIO_H

#include <QApplication>
#include <QString>
#include <QFile>
#include <QDebug>
#include <QTextStream>
#include <QColor>
#include <QVector>
#include <QVariant>
#include <stdio.h>

void saveStamp(QString fileName, int cSizeX, int cSizeY,int sSizeX, int sSizeY, int posX, int posY, int frameNum, QList<QColor> frame);
void saveProject(QString fileName, int sizeX, int sizeY, QList<QColor> frame, QList<QString> timestamps);
void loadProject(QString fileName, int * sizeX, int * sizeY, QList<QColor> * externalFrame, QList<QString> *timestamps);
void exportFrame(QString fileName, int sizeX, int sizeY, QList<QColor> frame, QList<QString> timestamps);
void loadStamp(QString fileName, int cSizeX, int cSizeY, int posX, int posY, int frameNum, QList<QColor> * externalFrame);
int maintest();


#endif // FILEIO_H
