

#define QT_NO_DEBUG
#include <QDataStream>
#include <QVector>




int main(){


    QByteArray packData;
    QDataStream stream(&packData, QIODevice::ReadWrite); 
    
    uint32_t a = 0xFFFFFFFF;

    stream << a;

    

    QVector<qint64> v1;

    for(int i = 0;i<100;i++){
        v1.append(i);
    }

    

    stream<<v1;

    stream.device()->reset();

    QVector<qint64> sgbmVec;
    stream >> sgbmVec;   
    
  
    
    return 0;
}


