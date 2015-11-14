#ifndef PLAYER
#define PLAYER
#include <QObject>
#include <QGraphicsRectItem>


/*Classe de type QGraphicsRectItem à defaut de classe graphique
 */

class Player :public QObject, public QGraphicsRectItem{
    Q_OBJECT
public:
    Player();
    void keyPressEvent(QKeyEvent *event);
    enum class Direction {UP, DOWN, LEFT, RIGHT, NONE};
public slots:
    void move();
private:
    Direction movement;
    int stepSize;
    // helper functions
    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();
    void checkCollision();
};
#endif // PLAYER

