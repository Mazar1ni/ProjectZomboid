#ifndef GAME_H
#define GAME_H

#include "scene.h"
#include "background.h"
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QObject>
#include <QGraphicsPixmapItem>
#include "Code/Character/player.h"
#include "Code/Character/Components/storagecomponent.h"

class Game : public QGraphicsView
{
    Q_OBJECT

public:
    Game();
    // member functions
    void mouseMoveEvent(QGraphicsSceneMouseEvent* event);

    // member values
    Scene* scene;
    Player* player;
    Background* bg;

private:
    //static QList<QGraphicsPixmapItem* > targets;

};

#endif // GAME_H
