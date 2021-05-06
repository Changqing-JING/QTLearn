#include <QObject>
#include <QTimer>

class EventScheduler: public QObject{
    Q_OBJECT

    public:
        void foo();

};