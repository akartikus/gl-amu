#include "labyrinthe.h"
#include "power.h"
#include <QBrush>
Labyrinthe::Labyrinthe()
{
    this->setBrush(QBrush(Qt::red, Qt::SolidPattern));

    setRect(0,0,20,10);



}
