#include "maze.h"
#include <QBrush>

Maze::Maze(){
    this->setBrush(QBrush(Qt::blue, Qt::SolidPattern));
    setRect(0,0,50,50);
}
