#include "storageitem.h"
#include "Code/UI/game.h"
#include <QDebug>

extern Game* game;

StorageItem::StorageItem()
{
    // таймер проверки
    QTimer* timeDeteriorate = new QTimer;
    connect(timeDeteriorate, &QTimer::timeout, this, &StorageItem::DeteriorateItem);
    timeDeteriorate->start(1000);
}

// помеш€ет предмет в инвентарь
void StorageItem::ItemAddedToStorage(StorageComponent* Storage, int x, int y)
{
    InStorage = true;
    OwningStorage = Storage;

    // relocated item
    PosX = x;
    PosY = y;

    setPos(9999999, 9999999);
}

// проверка занимает ли этот предмет позицию в инвенторе по координатам x и y
bool StorageItem::CheckIfItemIsInSlot(int x, int y)
{
    if(PosX == x && PosY == y)
    {
        return true;
    }
    return false;
}

void StorageItem::UseItem()
{

}

bool StorageItem::RemoveItem(int Count)
{
    bool RemoveAll = OwningStorage->RemoveItem(this, Count, false);
    if(RemoveAll)
    {
        return true;
    }
    return false;
}

void StorageItem::ItemRemoveFromStorage()
{
    InStorage = false;
    OwningStorage = NULL;
}

bool StorageItem::ChangedCondition(int Cond)
{
    if(Broken == true)
    {
        return true;
    }

    Condition += Cond;

    if(Condition <= 0)
    {
        Broken = true;
        return true;
    }
    else
    {
        return false;
    }
}

float StorageItem::GetItemWeight(bool Total, int CountItem)
{
    if(Total == true)
    {
        return Count * Weight;
    }
    else
    {
        return CountItem * Weight;
    }
}

void StorageItem::DeteriorateItem()
{
    if(Deteriorate && Broken != true)
    {
        Condition -= SpeedDeteriorate;
        if(Condition <= 0)
        {
            Broken = true;
        }
    }
}

void StorageItem::Interact(Player *player)
{
    player->Storage->AddItem(this);
}

QIcon StorageItem::GetIcon() const
{
    return icon;
}

void StorageItem::SetPos(int x, int y)
{
    PosX = x;
    PosY = y;
}

StorageComponent *StorageItem::GetOwningStorage() const
{
    return OwningStorage;
}

int StorageItem::GetPosX() const
{
    return PosX;
}

int StorageItem::GetPosY() const
{
    return PosY;
}
