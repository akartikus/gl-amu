#ifndef SCORE
#define SCORE
#include <QGraphicsTextItem>

/*Herite de QGraphicsTextItem à defaut de moteur UI*/

class Score: public QGraphicsTextItem{
public:
  Score(QGraphicsItem * parent = 0);
  void increase(int inc);
  int getScore();
private:
  int score;
};
#endif // SCORE

