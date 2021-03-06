#include "game.h"
#include "point.h"
#include "player.h"
#include "score.h"
#include "power.h"
#include "maze.h"
#include "labyrinthe.h"
#include <QKeyEvent>
#include <QGraphicsScene>
#include <QDebug>
#include <QList>
#include <QBrush>
#include <typeinfo>
#include <QThread>
#include <QTimer>

extern Game *game;
Player::Player():movement(Direction::NONE){
    this->setBrush(QBrush(Qt::yellow, Qt::SolidPattern));

    // Connection du timer avec la methode move()
    QTimer* moveTimer = new QTimer(this);
    connect(moveTimer,SIGNAL(timeout()),this,SLOT(move()));
    moveTimer->start(50);
}

void Player::keyPressEvent(QKeyEvent *event){

    if(event->key() == Qt::Key_Left){
        movement = Direction::LEFT;
    }

    if(event->key() == Qt::Key_Right){
        movement = Direction::RIGHT;
    }

    if(event->key() == Qt::Key_Up){
        movement = Direction::UP;
    }

    if(event->key() == Qt::Key_Down){
        movement = Direction::DOWN;
    }


}
//Slot à executer tout les X milliseconde
void Player::move(){
    //Collision avec les points et les objet sur le MAp
    checkCollision();
    switch (movement){
        case Direction::UP:
            moveUp();
            break;
        case Direction::DOWN:
            moveDown();
            break;
        case Direction::LEFT:
            moveLeft();
            break;
        case Direction::RIGHT:
            moveRight();
            break;
        case Direction::NONE:

            break;
        default:
            //assert(false); // should not get
            break;
    }
}

void Player::moveUp(){
    //Sauver positions avant collision

    int pY = y();

    if(pos().y() > 5){
        setPos(x(),y() - 5);
    }else{
        setPos(x(),0);
    }
    //A mettre dans une fonction
    QList<QGraphicsItem *> colliding_item = collidingItems();
    //Collision avec le labyrinthe
    for(int i = 0, n =colliding_item.size(); i <n; i++ ){
        if(typeid(*(colliding_item[i])) == typeid(Labyrinthe)){
            //checker la posision du pacman avant d'attribuer la position
            if(pY>=colliding_item[i]->y() +colliding_item[i]->boundingRect().height() ){
                setPos(x(),colliding_item[i]->y() +colliding_item[i]->boundingRect().height());
            }
        }
    }
}

void Player::moveDown(){
    //Sauver positions avant collision

    int pY = y();

    if(pos().y() < scene()->height()- rect().height() - 5){
        setPos(x(),y()+5);
    }else{
        setPos(x(),scene()->height() - rect().height());
    }

    //A mettre dans une fonction
    QList<QGraphicsItem *> colliding_item = collidingItems();
    //Collision avec le labyrinthe
    for(int i = 0, n =colliding_item.size(); i <n; i++ ){
        if(typeid(*(colliding_item[i])) == typeid(Labyrinthe)){
            if (colliding_item[i]->y()>=(pY +rect().height())){
                setPos(x(),colliding_item[i]->y() - rect().height() - 1);
            }
        }
    }
}

void Player::moveLeft(){
    //Sauver positions avant collision
    int pX = x();


    //Deplacement
    if(pos().x() > 5){
        setPos(x()-5,y());
    }else{
        setPos(0,y());
    }

    // ******* A mettre dans une fonction *********
    QList<QGraphicsItem *> colliding_item = collidingItems();
    //Collision avec le labyrinthe
    for(int i = 0, n =colliding_item.size(); i <n; i++ ){
        if(typeid(*(colliding_item[i])) == typeid(Labyrinthe)){
            //checker la posision du pacman avant d'attribuer la position
            int mX = colliding_item[i]->x() + colliding_item[i]->boundingRect().width();
            if( pX >= mX ){

                setPos(colliding_item[i]->x() + colliding_item[i]->boundingRect().width(), y());
            }
        }
    }
}

void Player::moveRight(){
    //Sauver positions avant collision
    int pX = x();


    if(pos().x() < scene()->width()- rect().width() - 5){
        setPos(x()+5,y());
    }else{
        setPos(scene()->width() - rect().width(),y());
    }
    //A mettre dans une fonction
    QList<QGraphicsItem *> colliding_item = collidingItems();
    //Collision avec le labyrinthe
    for(int i = 0, n =colliding_item.size(); i <n; i++ ){
        if(typeid(*(colliding_item[i])) == typeid(Labyrinthe)){
            //checker la posision du pacman avant d'attribuer la position
            if( colliding_item[i]->x()>=rect().width() + pX){
                setPos(colliding_item[i]->x() - rect().width() - 1, y());
            }
        }
    }
}

void Player::checkCollision(){
    //Checker les collisions
    QList<QGraphicsItem *> colliding_item = collidingItems();
        for(int i = 0, n =colliding_item.size(); i <n; i++ ){
            //Collision avec les points
            if(typeid(*(colliding_item[i])) == typeid(Point)){
                //Mettre à jour score
                game->score->increase(1);
                //effacer le point
                scene()->removeItem(colliding_item[i]);
                delete colliding_item[i];
                return;
            }

            //Collision avec les powers
            if(typeid(*(colliding_item[i])) == typeid(Power)){
                //Mettre à jour le timer pour l'etat super Saiyn :)

                //effacer le power
                scene()->removeItem(colliding_item[i]);
                delete colliding_item[i];
                return;
            }
        }
}
