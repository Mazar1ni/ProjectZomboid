#ifndef PLAYER_H
#define PLAYER_H

#include "main_character.h"
#include <QPolygon>
#include <QTimer>
#include <QPainter>
#include <QPushButton>
#include <QGraphicsPixmapItem>
#include <windows.h>

class Inventory;
class HUD;
class StorageItem;
class Object;

class Player : public Main_Character, public QGraphicsPixmapItem
{
    Q_OBJECT

public:
    Player(QGraphicsPixmapItem* parent = nullptr);

    // functions
    void SlotTarget(QGraphicsSceneMouseEvent* point);
    void MovePlayer();
    void CheckShowInventory();
    void CreateHUD();
    void Interact();
    void LookAtItems();

    Object *getLookAtItem() const;

    // values
    Inventory* inventory;
    HUD* hud;

private slots:
    void SlotGameTimer();

private:
    QTimer* GameTimer;
    QPointF Target;

    QTimer* t;

    int TimeInventory = 0;
    bool InventoryShow = false;

    Object* LookAtItem = nullptr;
    QRectF* collision;
};

#endif // PLAYER_H
