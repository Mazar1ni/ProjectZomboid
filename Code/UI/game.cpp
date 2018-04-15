#include "game.h"
#include "Code/Storage/Items/item_water.h"
#include "Code/Storage/Equipables/Hats/cylinderhat.h"

Game::Game() : QGraphicsView()
{
    scene = new Scene;

    setScene(scene);

    bg = new Background;
    scene->addItem(bg);

    setFixedSize(800, 700);
    setRenderHint(QPainter::Antialiasing);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    // custom cursor
    QCursor cursor = QCursor(QPixmap(":/Cursor/cursorTarget.png"));
    setCursor(cursor);

    player = new Player;
    player->setPos(250, 250);
    scene->addItem(player);

    // разрешаем отслеживать положение курсора
    setMouseTracking(true);

    connect(scene, &Scene::SignalTargetCoordinate, player, &Player::SlotTarget);

    Item_Water* item = new Item_Water;
    item->setPos(100, 100);
    scene->addItem(item);
    Item_Water* item1 = new Item_Water;
    item1->setPos(200, 100);
    scene->addItem(item1);
    Item_Water* item2 = new Item_Water;
    item2->setPos(300, 100);
    scene->addItem(item2);

    CylinderHat* item3 = new CylinderHat;
    item3->setPos(400, 100);
    scene->addItem(item3);
}
