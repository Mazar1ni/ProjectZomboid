#include "item_water.h"
#include "Code/UI/game.h"
#include "Code/Character/Components/statscomponent.h"

extern Game* game;

Item_Water::Item_Water()
{
    setPixmap(QPixmap(":/Items/Water.png"));
    setScale(0.04);

    icon = QPixmap(":/Items/Water.png");
    UrlIcon = ":/Items/Water.png";
    Weight = 0.5;
    Name = "Water";
    Price = 10;
    Type = Other;
    CanBeStacked = true;
    Class = "Water";
    Deteriorate = true;
    SpeedDeteriorate = 10;
}

void Item_Water::UseItem()
{
    game->player->Stats->ChangedThirst(true, 10);
    if(RemoveItem(1))
    {
        delete this;
    }
}
