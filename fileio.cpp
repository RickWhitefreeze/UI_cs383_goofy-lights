//Joey and Jocelyn's file
//handles file loading and saving/exporting
//also handles stamps

#include "fileio.h"


#define bufferLength 400

void saveProject(QString fileName, int sizeX, int sizeY, QList<QColor> frame, QList<QString> timestamps, QList<TimelineFrame*> timeline){
    QFile mFile(fileName);

    if(!mFile.open(QFile::ReadWrite | QFile::Text)){
        qDebug() << "error opening file";
        return;
    }

    QTextStream out(&mFile);

    out << "24.7\nNoAudioFile\n" << sizeX << " " << sizeY << endl;

    int minutes = 0;
    int seconds = 0;
    int miliseconds = 0;
    
    for(int k = 0; k < (frame.size() + 1) / (sizeY*sizeX); k++){
       
        QStringList temp;
        
        temp.append(((timeline[k]->timestamp).split('.'))[0].split(':')[0]);
        temp.append(((timeline[k]->timestamp).split('.'))[0].split(':')[1]);
        temp.append(((timeline[k]->timestamp).split('.'))[1]);
        
        miliseconds = (miliseconds + temp[2].toInt());
        int carry = miliseconds/100;
        miliseconds = miliseconds%100;

        seconds = (seconds + carry + temp[1].toInt());
        carry = seconds/60;
        seconds = seconds%60;

        minutes = (minutes + carry + temp[0].toInt())%60;
        
        QString output, tempString;
        output.append(tempString.sprintf("%02d:", minutes));
        output.append(tempString.sprintf("%02d.", seconds));
        output.append(tempString.sprintf("%02d", miliseconds));
         
        //write Timestamp
        out << output << "\n";

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
void loadProject(QString fileName, int * sizeX, int * sizeY, QList<QColor> * externalFrame, QList<QString> *timestamps){

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


    int i = 0;
    while(!mFile.atEnd()){

        //read timestamp
        mFile.readLine(buffer, bufferLength);
        temp = buffer;
        timestamps->append(temp.remove(temp.size() - 1,temp.size()));

        for(int j = 0; j < ( *sizeY ); j++){

            mFile.readLine(buffer, bufferLength);
            temp = buffer;
            QStringList rgbList = temp.split(' ');

            for(int k = 0; k < rgbList.size() - 1; k += 3){

                int red = rgbList[k].toInt();
                int green = rgbList[k+1].toInt();
                int blue = rgbList[k+2].toInt();

                frame.append(QColor(red,green,blue));
            }
        }
        i++;
    }
    * externalFrame = frame;

    mFile.close();
}

void exportFrame(QString fileName, int sizeX, int sizeY, QList<QColor> frame, QList<QString> timestamps, QList<TimelineFrame*> timeline){
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

    saveProject(fileName, sizeX/3, sizeY/3, exportList, timestamps, timeline);
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

    for(int j = 0; j < ( sSizeY ); j++){

        mFile.readLine(buffer, bufferLength);
        temp = buffer;
        QStringList rgbList = temp.split(' ');
        int i = 0;
        for(int k = 0; k < rgbList.size() - 1; k +=3, i++){

            int red = rgbList[k].toInt();
            int green = rgbList[k+1].toInt();
            int blue = rgbList[k+2].toInt();

            frame.removeAt((frameNum - 1)*cSizeY*cSizeX + cSizeX*(posY - 1) + j*cSizeX + (posX - 1) + i);
            frame.insert((frameNum - 1)*cSizeY*cSizeX + cSizeX*(posY - 1) + j*cSizeX + (posX - 1) + i, QColor(red,green, blue));
        }
    }

    * externalFrame = frame;

    mFile.close();

}
