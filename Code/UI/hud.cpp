#include "game.h"
#include "hud.h"
#include "Code/Character/Components/statscomponent.h"
#include "Code/Storage/storageitem.h"
#include <QTimer>
#include <QDebug>

extern Game* game;

HUD::HUD(Player *pl) : player(pl)
{
    resize(QSize(90, 60));
    move(game->player->x() - 70, game->player->y() + 70);
    health = new QLabel(this);
    health->resize(90, 15);
    health->move(0, 0);

    thirst = new QLabel(this);
    thirst->resize(90, 15);
    thirst->move(0, 15);

    hunger = new QLabel(this);
    hunger->resize(90, 15);
    hunger->move(0, 30);

    hint = new QLabel(this);
    hint->resize(90, 15);
    hint->move(0, 45);

    QTimer *update = new QTimer;
    connect(update, &QTimer::timeout, this, &HUD::Update);
    update->start(10);
}

void HUD::Update()
{
    health->setText("Health: " + QString::number((int)ceil(game->player->Stats->GetHealth())));
    thirst->setText("Thirst: " + QString::number((int)ceil(game->player->Stats->GetThirst())));
    hunger->setText("Hunger: " + QString::number((int)ceil(game->player->Stats->GetHunger())));

    if(dynamic_cast<StorageItem*>(player->getLookAtItem()))
    {
        hint->setText(tr("Нажмите E чтобы подобрать предмет"));
    }
    else
    {
        hint->clear();
    }

    move(game->player->x() - 70, game->player->y() + 70);
}
