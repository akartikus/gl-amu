#include "score.h"
#include <QFont>

Score::Score(QGraphicsItem *parent):QGraphicsTextItem(parent){
    //Initialize score to zero
    score = 0;

    //Draw text
    setPlainText(QString("Score :") + QString::number(score));
    setDefaultTextColor(Qt::blue);
    setFont(QFont("times",16));
}

void Score::increase(int inc){
    score = score + inc;
    setPlainText(QString("Score :") + QString::number(score));
}

int Score::getScore(){
    return score;
}
