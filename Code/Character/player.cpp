#include "Code/UI/game.h"
#include "player.h"
#include "Code/UI/inventory.h"
#include "Code/UI/hud.h"
#include "Code/Storage/storageitem.h"
#include "Code/object.h"
#include <math.h>
#include <QDebug>

extern Game* game;

static const double Pi = 3.14159265358979323846264338327950288419717;
static double TwoPi = 2.0 * Pi;

static qreal normalizeAngle(qreal Angle)
{
    while(Angle < 0)
    {
        Angle += TwoPi;
    }
    while(Angle > TwoPi)
    {
        Angle -= TwoPi;
    }
    
    return Angle;
}

Player::Player(QGraphicsPixmapItem *parent) : QGraphicsPixmapItem(parent)
{
    setPixmap(QPixmap(":/Player/player.png"));
    setScale(0.4);
    setRotation(0);
    setTransformOriginPoint(27, 45);

    GameTimer = new QTimer();
    connect(GameTimer, &QTimer::timeout, this, &Player::SlotGameTimer);
    GameTimer->start(10);

    t = new QTimer;
    connect(t, &QTimer::timeout, this, &Player::CreateHUD);
    t->start(1000);

    Target = QPointF(0, 0);
    collision = new QRectF(0,0,520,20);
}

void Player::SlotGameTimer()
{
    TimeInventory++;

    if(InventoryShow == false)
    {
        MovePlayer();
        Interact();
        LookAtItems();
    }

    CheckShowInventory();
}

Object *Player::getLookAtItem() const
{
    return LookAtItem;
}

void Player::SlotTarget(QGraphicsSceneMouseEvent* point)
{
    // определ€ем рассто€ние до цели
//    qDebug() << this->pos() << point->scenePos();
//    if(((point->scenePos().x() - 70 < this->x() && point->scenePos().x() + 70 > this->x()) ||
//            (point->scenePos().x() - 70 > this->x() && point->scenePos().x() + 70 < this->x()))
//            && ((point->scenePos().y() - 70 < this->y() && point->scenePos().y() + 70 > this->y()) ||
//                (point->scenePos().y() - 70 > this->y() && point->scenePos().y() + 70 < this->y())))
//    {
//        point->setPos(Target);
//    }
//    else
//    {

//    }
    Target = point->scenePos();
}

void Player::MovePlayer()
{
    // перемещ€ем гг взависимости от нажатой кнопки
    if(GetAsyncKeyState('A'))
    {
        this->setX(this->x() - 2);
        game->centerOn(this->x(), this->y());
        if(game->scene->collidingItems(this).count() > 1)
        {
            this->setX(this->x() + 2);
        }
    }
    if(GetAsyncKeyState('D'))
    {
        this->setX(this->x() + 2);
        game->centerOn(this->x(), this->y());
        if(game->scene->collidingItems(this).count() > 1)
        {
            this->setX(this->x() - 2);
        }
    }
    if(GetAsyncKeyState('W'))
    {
        this->setY(this->y() - 2);
        game->centerOn(this->x(), this->y());
        if(game->scene->collidingItems(this).count() > 1)
        {
            this->setY(this->y() + 2);
        }
    }
    if(GetAsyncKeyState('S'))
    {
        this->setY(this->y() + 2);
        game->centerOn(this->x(), this->y());
        if(game->scene->collidingItems(this).count() > 1)
        {
            this->setY(this->y() - 2);
        }
    }

    // проверка за выхода за границы пол€
    // если гг выходит то возвращ€ем его назад
    if(this->x() - 100 < 0)
    {
        this->setX(100);
    }
    if(this->x() + 100 > 1824)
    {
        this->setX(1824 - 100);
    }
    if(this->y() - 100 < 0)
    {
        this->setY(100);
    }
    if(this->y() + 100 > 1440)
    {
        this->setY(1440 - 100);
    }

    QLineF LineToTarget(QPointF(0, 0), mapFromScene(Target));
    // угол поворота в направлении к цели
    qreal angleToTarget = std::acos(LineToTarget.dx() / LineToTarget.length());

    if (LineToTarget.dy() < 0)
    {
        angleToTarget = TwoPi - angleToTarget;
    }

    angleToTarget = normalizeAngle((Pi - angleToTarget) + Pi / 2);

    // направление поворота в данном тике таймера
    // скорость разворота зависит от угла, на который необходимо повернутьс€
    if (angleToTarget >= 0 && angleToTarget < Pi)
    {
        // Rotate left
        setRotation(rotation() - angleToTarget * 180 / Pi);
    }
    else if (angleToTarget <= TwoPi && angleToTarget > Pi)
    {
        // Rotate right
        setRotation(rotation() + (angleToTarget - TwoPi )* (-180) / Pi);
    }
}

void Player::CheckShowInventory()
{
    // открытие инвентор€
    if(GetAsyncKeyState('I') && InventoryShow == false && TimeInventory >= 50)
    {
        inventory = new Inventory;
        game->scene->addWidget(inventory);
        InventoryShow = true;
        TimeInventory = 0;
    }
    else if(GetAsyncKeyState('I') && InventoryShow == true && TimeInventory >= 50)
    {
        //game->setCursor(QCursor(Qt::ArrowCursor));
        //game->setCursor(QCursor(QPixmap(":/Cursor/cursorTarget.png")));
        InventoryShow = false;
        delete inventory;
        TimeInventory = 0;
    }
}

void Player::CreateHUD()
{
    hud = new HUD(this);
    game->scene->addWidget(hud);
    t->stop();
    t->deleteLater();
}

void Player::Interact()
{
    // проверка на то что игрок столкнулс€ с предметом
    if(GetAsyncKeyState('E'))
    {
        LookAtItem->Interact(this);
    }
}

void Player::LookAtItems()
{
    QList<QGraphicsItem* > colliding_items = game->scene->collidingItems(this);
    foreach(QGraphicsItem* item, colliding_items)
    {
        if(Object* it = dynamic_cast<Object* >(item))
        {
            if(LookAtItem != it)
            {
                LookAtItem = it;
            }
            else
            {
                LookAtItem = nullptr;
            }
        }
    }
}
