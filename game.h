#ifndef GAME
#define GAME
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QWidget>
#include "player.h"
#include "score.h"

/*Implementation d'une classe Game qui va etre notre classe principale
 * qui est heritiere de la la class QGraphisView
 * QGraphicsView devrait faire partie du moteur graphique mais nous nous contenterons
 * de l'utiliser directement
*/
class Game: public QGraphicsView{
public:
    Game(QWidget *parent =0);
    void resizeEvent ( QResizeEvent * event );

    /*Objet de type QGRaphicsScene, lui aussi devrait etre implementé dans une classe
    du moteur graphique*/
    QGraphicsScene *scene;
    Player *pacman;
    Score * score;
};

#endif // GAME

