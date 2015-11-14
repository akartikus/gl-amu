#include "power.h"
#include <QBrush>

Power::Power(){
    this->setBrush(QBrush(Qt::green, Qt::SolidPattern));
    setRect(0,0,20,20);
}
