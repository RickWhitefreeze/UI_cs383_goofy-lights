//Joey and Jocelyn's file
//handles file loading and saving/exporting
//also handles stamps

#include "fileio.h"

#define bufferLength 400


int maintest()
{

    QList<QColor> frame;
    QList<QString> timestamps;

    for(int i = 0; i <= 9*9*10; i++){
        frame.append(QColor(i%256,(i+100)%256,(i+200)%256,255));
    }
    for(int i = 0; i < 10; i++){
        timestamps.append("11.13.023");
    }

    //saveProject("C:\\Users\\Toshi\\Desktop\\testfile.txt", 9, 9, frame, timestamps);

    int x, y;

    loadProject("C:\\Users\\Toshi\\Desktop\\testfile.txt", &x, &y, & frame, timestamps);

    exportFrame("C:\\Users\\Toshi\\Desktop\\testfile.tan", 9, 9, frame, timestamps);

    //saveStamp("C:\\Users\\Toshi\\Desktop\\testfile.stmp", 9, 9, 2, 2, 4, 3, 3, frame);

    loadStamp("C:\\Users\\Toshi\\Desktop\\testfile.stmp", 9, 9, 4, 3, 3, & frame);

    saveProject("C:\\Users\\Toshi\\Desktop\\testfile.txt", 9, 9, frame, timestamps);


    return 1;
}

void saveProject(QString fileName, int sizeX, int sizeY, QList<QColor> frame, QList<QString> timestamps){
    QFile mFile(fileName);

    if(!mFile.open(QFile::ReadWrite | QFile::Text)){
        qDebug() << "error opening file";
        return;
    }

    QTextStream out(&mFile);

    out << "24.7\nNoAudioFile\n" << sizeX << " " << sizeY << endl;

    for(int k = 0; k < (frame.size() - 1) / (sizeY*sizeX); k++){

        //write Timestamp
        out << timestamps[k] << "\n";

        //write RGB Data
        for(int i = 0; i < sizeY; i++){
            for(int j = 0; j < sizeX; j++){
                QString buff;

                buff = QString::number(frame[k*sizeY*sizeX + i*sizeX + j].red());
                out << buff << " ";
                buff = QString::number(frame[k*sizeY*sizeX + i*sizeX + j].green());
                out << buff << " ";
                buff = QString::number(frame[k*sizeY*sizeX + i*sizeX + j].blue());
                out << buff << " ";
            }
            out << endl;
        }
    }

    mFile.close();

}

//updates sizeX and sizeY passed in by reference so the parent function knows the frame size
void loadProject(QString fileName, int * sizeX, int * sizeY, QList<QColor> * externalFrame, QList<QString> timestamps){

    QList<QColor> frame = * externalFrame;
    //clear vector to load new project
    frame.clear();

    QFile mFile(fileName);

    if(!mFile.open(QFile::ReadOnly | QFile::Text)){
        qDebug() << "error opening file2";
        return;
    }

    char buffer[bufferLength];

    //skip version number
    mFile.readLine();
    //skip audio/no audio
    mFile.readLine();
    //read frame size
    mFile.readLine(buffer, bufferLength);
    QString temp = buffer;
    QStringList tempList = temp.split(" ");
    *sizeX = tempList[0].toInt();
    *sizeY = tempList[1].toInt();
    //qDebug() << frame.length() << " " << *sizeX << " " << *sizeY << "\n";

    //for(int i = 0; i < frame.length()/(( *sizeX ) * ( *sizeY )); i++){
    int i = 0;
    while(!mFile.atEnd()){

        //read timestamp
        mFile.readLine(buffer, bufferLength);
        temp = buffer;
        timestamps.append(temp.remove(temp.size() - 1,temp.size()));
     //   qDebug() << timestamps[i];

        for(int j = 0; j < ( *sizeY ); j++){

            mFile.readLine(buffer, bufferLength);
            temp = buffer;
            QStringList rgbList = temp.split(' ');

            for(int k = 0; k < rgbList.size() - 1; k += 3){

                int red = rgbList[k].toInt();
                int green = rgbList[k+1].toInt();
                int blue = rgbList[k+2].toInt();

                //qDebug() << red << " | " << green << " | " << blue << " | ";
                frame.append(QColor(red,green,blue));
            }
        }
        //qDebug();
        i++;
    }
    * externalFrame = frame;

    mFile.close();
}

void exportFrame(QString fileName, int sizeX, int sizeY, QList<QColor> frame, QList<QString> timestamps){
    QList<QColor> exportList;

    for(int k = 0; k < (frame.size() - 1) / (sizeY*sizeX); k++){

        for(int i = 0; i < sizeY; i++){

            if(i < sizeY / 3 || i >= sizeY / 3 * 2){
                continue;
            }

            for(int j = 0; j < sizeX; j++){
                if(j < sizeX / 3 || j >= sizeX / 3 * 2){
                    continue;
                }
                exportList.append(frame[k*sizeY*sizeX + i*sizeX + j]);
            }
        }
    }

    //exportList.append(QColor(1,1,1));
    //exportList.pop_back();
    saveProject("C:\\Users\\Toshi\\Desktop\\testfile.tan", sizeX/3, sizeY/3, exportList, timestamps);
    return;
}

//saves a section of the passed size with the position specified as the top left corner from the passed frame as a stamp
void saveStamp(QString fileName, int cSizeX, int cSizeY,int sSizeX, int sSizeY, int posX, int posY, int frameNum, QList<QColor> frame){

    QFile mFile(fileName);

    if(!mFile.open(QFile::ReadWrite | QFile::Text)){
        qDebug() << "error opening file";
        return;
    }

    QTextStream out(&mFile);

    out << sSizeX << " " << sSizeY << endl;

    for(int i = 0; i < sSizeY; i++){

        for(int j = 0; j < sSizeX; j++){

            QString buff;
            //                          skip to frame + skip lines above stamp + iterate each line in stamp + pixels before stamp + iterate X
            buff = QString::number(frame[(frameNum - 1)*cSizeY*cSizeX + cSizeX*(posY - 1) + i*cSizeX + (posX - 1) + j].red());
            out << buff << " ";
            buff = QString::number(frame[(frameNum - 1)*cSizeY*cSizeX + cSizeX*(posY - 1) + i*cSizeX + (posX - 1) + j].green());
            out << buff << " ";
            buff = QString::number(frame[(frameNum - 1)*cSizeY*cSizeX + cSizeX*(posY - 1) + i*cSizeX + (posX - 1) + j].blue());
            out << buff << " ";
        }
        out << endl;
    }

    mFile.close();


}

void loadStamp(QString fileName, int cSizeX, int cSizeY, int posX, int posY, int frameNum, QList<QColor> *externalFrame){

    QList<QColor> frame = * externalFrame;

    QFile mFile(fileName);

    if(!mFile.open(QFile::ReadOnly | QFile::Text)){
        qDebug() << "error opening file2";
        return;
    }

    char buffer[bufferLength];

    //read stamp size
    mFile.readLine(buffer, bufferLength);
    QString temp = buffer;
    QStringList tempList = temp.split(" ");
    int sSizeX = tempList[0].toInt();
    int sSizeY = tempList[1].toInt();

    //frame.insert(0,QColor(111,222,111));
    //frame.removeAt(0);

    for(int j = 0; j < ( sSizeY ); j++){

        mFile.readLine(buffer, bufferLength);
        temp = buffer;
        QStringList rgbList = temp.split(' ');
        int i = 0;
        for(int k = 0; k < rgbList.size() - 1; k +=3, i++){

            int red = rgbList[k].toInt();
            int green = rgbList[k+1].toInt();
            int blue = rgbList[k+2].toInt();

            //qDebug() << red << " | " << green << " | " << blue << " | ";
            //frame.append(QColor(red,green,blue));

            frame.removeAt((frameNum - 1)*cSizeY*cSizeX + cSizeX*(posY - 1) + j*cSizeX + (posX - 1) + i);
            frame.insert((frameNum - 1)*cSizeY*cSizeX + cSizeX*(posY - 1) + j*cSizeX + (posX - 1) + i, QColor(red,green, blue));
        }
    }

    * externalFrame = frame;

    mFile.close();

}
