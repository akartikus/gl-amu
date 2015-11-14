#include "game.h"
#include "point.h"
#include "power.h"
#include "labyrinthe.h"

#include <QApplication>
#include <QFont>
#include <stdlib.h>
#include <QBrush>

Game::Game(QWidget *parent){

    //Configuration de la vue
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setMinimumSize(900,500);
    setBackgroundBrush(QBrush(Qt::black, Qt::SolidPattern));

    //Instanciation et Configuration de la scene
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,width(),height());
    setScene(scene);

    //Instanciation et Configuration d'un player
    pacman = new Player();
    pacman->setRect(0,0,20,20);

    pacman->setFlag(QGraphicsItem::ItemIsFocusable);
    pacman->setFocus();
    pacman->setPos(50,50);
    scene->addItem(pacman);

    //Ajout tableau de score
    score = new Score();
    score->setPos(390,0);
    scene->addItem(score);


    //Ajout des points
    for(int y = 1; y<=11; y++ ){
        for(int x = 1;x<=17; x++ ){
            Point *point = new Point();
            point->setPos(x*50,y*50);
            scene->addItem(point);
        }
    }

    //Ajout de labyrinthe:

    //Barre Horizontale haut:
    for(int i = 20 ; i<880; i+=20 ){
        Labyrinthe *Laby = new Labyrinthe();
        Laby->setPos(i,35);
        scene->addItem(Laby);
    }

    for(int i = 260 ; i<640; i+=20 ){
        Labyrinthe *Laby = new Labyrinthe();
        Laby->setPos(i,65);
        scene->addItem(Laby);
    }

    for(int i = 300 ; i<600; i+=20 ){
        Labyrinthe *Laby = new Labyrinthe();
        Laby->setPos(i,100);
        scene->addItem(Laby);
    }

    for(int i = 340 ; i<560; i+=20 ){
        Labyrinthe *Laby = new Labyrinthe();
        Laby->setPos(i,135);
        scene->addItem(Laby);
    }
    for(int i = 380 ; i<520; i+=20 ){
        Labyrinthe *Laby = new Labyrinthe();
        Laby->setPos(i,170);
        scene->addItem(Laby);
    }
    for(int i = 170 ; i<377; i+=10 ){
    Labyrinthe *Laby = new Labyrinthe();
    Laby->setPos(380,i);
    scene->addItem(Laby);
    }
    for(int i = 170 ; i<377; i+=10 ){
    Labyrinthe *Laby = new Labyrinthe();
    Laby->setPos(520,i);
    scene->addItem(Laby);
    }
    for(int i = 520 ; i<700; i+=20 ){
    Labyrinthe *Laby = new Labyrinthe();
    Laby->setPos(i,377);
    scene->addItem(Laby);
    }

    for(int i = 380 ; i>190; i-=20 ){
    Labyrinthe *Laby = new Labyrinthe();
    Laby->setPos(i,377);
    scene->addItem(Laby);
    }





    for(int i = 790 ; i>=660; i-=20 ){
    Labyrinthe *Laby = new Labyrinthe();
    Laby->setPos(i,85);
    scene->addItem(Laby);
    }

    for(int i = 790 ; i>=660; i-=20 ){
    Labyrinthe *Laby = new Labyrinthe();
    Laby->setPos(i,170);
    scene->addItem(Laby);
    }

    for(int i = 790 ; i>=660; i-=20 ){
    Labyrinthe *Laby = new Labyrinthe();
    Laby->setPos(i,335);
    scene->addItem(Laby);
    }

    for(int i = 790 ; i>=660; i-=20 ){
    Labyrinthe *Laby = new Labyrinthe();
    Laby->setPos(i,420);
    scene->addItem(Laby);
    }

    for(int i = 340 ; i<=420; i+=10 ){
    Labyrinthe *Laby = new Labyrinthe();
    Laby->setPos(750,i);
    scene->addItem(Laby);
    }


    for(int i = 85 ; i<=170; i+=10 ){
    Labyrinthe *Laby = new Labyrinthe();
    Laby->setPos(750,i);
    scene->addItem(Laby);
    }

    for(int i = 90 ; i<220; i+=20 ){
    Labyrinthe *Laby = new Labyrinthe();
    Laby->setPos(i,85);
    scene->addItem(Laby);
    }

    for(int i = 90 ; i<220; i+=20 ){
        Labyrinthe *Laby = new Labyrinthe();
        Laby->setPos(i,170);
        scene->addItem(Laby);
    }

    for(int i = 90 ; i<220; i+=20 ){
        Labyrinthe *Laby = new Labyrinthe();
        Laby->setPos(i,335);
        scene->addItem(Laby);
    }

    for(int i = 90 ; i<220; i+=20 ){
        Labyrinthe *Laby = new Labyrinthe();
        Laby->setPos(i,420);
        scene->addItem(Laby);
    }

    for(int i = 85 ; i<=170; i+=10 ){
        Labyrinthe *Laby = new Labyrinthe();
        Laby->setPos(130,i);
        scene->addItem(Laby);
    }

    for(int i = 340 ; i<=420; i+=10 ){
        Labyrinthe *Laby = new Labyrinthe();
        Laby->setPos(130,i);
        scene->addItem(Laby);
    }

    for(int i = 20 ; i<100; i+=20 ){
        Labyrinthe *Laby = new Labyrinthe();
        Laby->setPos(i,128);
        scene->addItem(Laby);
    }

    for(int i = 20 ; i<100; i+=20 ){
        Labyrinthe *Laby = new Labyrinthe();
        Laby->setPos(i,378);
        scene->addItem(Laby);
    }

    for(int i = 840 ; i>780; i-=20 ){
        Labyrinthe *Laby = new Labyrinthe();
        Laby->setPos(i,128);
        scene->addItem(Laby);
    }

    for(int i = 840 ; i>780; i-=20 ){
        Labyrinthe *Laby = new Labyrinthe();
        Laby->setPos(i,378);
        scene->addItem(Laby);
    }


    //Barre Horizontale bas:
    for(int i = 20 ; i<880; i+=20 ){
        Labyrinthe *Laby = new Labyrinthe();
        Laby->setPos(i,465);
        scene->addItem(Laby);
    }

    //semi barre verticale gauche1:
    for(int i = 35 ; i<220; i+=10 ){
        Labyrinthe *Laby = new Labyrinthe();
        Laby->setPos(20,i);
        scene->addItem(Laby);
    }

    //première entrée du vertical gauche
    for(int i = 20 ; i<280; i+=20 ){
        Labyrinthe *Laby = new Labyrinthe();
        Laby->setPos(i,220);
        scene->addItem(Laby);
    }
    //Deuxième entrèe du vrtical gauche
    for(int i = 20 ; i<280; i+=20 ){
        Labyrinthe *Laby = new Labyrinthe();
        Laby->setPos(i,290);
        scene->addItem(Laby);
    }
    //fermeture des 2 entrées:
    for(int i = 220 ; i<=290; i+=10 ){
        Labyrinthe *Laby = new Labyrinthe();
        Laby->setPos(280,i);
        scene->addItem(Laby);
    }


    //semi barre verticale gauche2:
    for(int i = 290 ; i<465; i+=10 ){
        Labyrinthe *Laby = new Labyrinthe();
        Laby->setPos(20,i);
        scene->addItem(Laby);
    }


    //semi barre verticale droite1:
    for(int i = 35 ; i<220; i+=10 ){
        Labyrinthe *Laby = new Labyrinthe();
        Laby->setPos(860,i);
        scene->addItem(Laby);
    }

    //première entrée du vertical droit:
    for(int i = 860 ; i>=600; i-=20 ){
        Labyrinthe *Laby = new Labyrinthe();
        Laby->setPos(i,220);
        scene->addItem(Laby);
    }

    //Deuxième entrée du vertical droit:
    for(int i = 860 ; i>=600; i-=20 ){
        Labyrinthe *Laby = new Labyrinthe();
        Laby->setPos(i,290);
        scene->addItem(Laby);
    }

    //fermeture des 2 entrées:
    for(int i = 220 ; i<=290; i+=10 ){
        Labyrinthe *Laby = new Labyrinthe();
        Laby->setPos(600,i);
        scene->addItem(Laby);
    }

    //semi barre verticale droite2:
    for(int i = 290 ; i<465; i+=10 ){
        Labyrinthe *Laby = new Labyrinthe();
        Laby->setPos(860,i);
        scene->addItem(Laby);
    }


    //Ajout des supers pouvoirs
    for(int i = 0, x = rand() % 800,y = rand() % 400; i<5; i++ ){
        Power *power = new Power();
        power->setPos(x,y);
        scene->addItem(power);
        x = rand() % 800;
        y = rand() % 400;
    }
}

void Game::resizeEvent(QResizeEvent *event){
    this->fitInView(0, 0, scene->width(), scene->height());
}
