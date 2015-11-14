#include "point.h"
#include <QBrush>

Point::Point(){
    this->setBrush(QBrush(Qt::white, Qt::SolidPattern));
    setRect(0,0,5,5);
}
