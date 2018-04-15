#include "storagecomponent.h"
#include <Code/Storage/storageitem.h>
#include <QDebug>
#include "Code/UI/game.h"
#include "Code/UI/inventory.h"

extern Game* game;

StorageComponent::StorageComponent(Main_Character *l_player)
{
    player = l_player;
}

// добавление предметов в инвентарь
bool StorageComponent::AddItem(StorageItem *i)
{
    float weight = i->GetItemWeight(true, 0);
    if(MaxWeight >= weight + Weight)
    {
        if(i->CanBeStacked)
        {
            if(ChechItemForStack(i) != nullptr)
            {
                ChechItemForStack(i)->Count++;
                delete i;
            }
            else if(ChechFreeSlotForItem(i))
            {
                Storage.append(i);
            }
        }
        else if(ChechFreeSlotForItem(i))
        {
            Storage.append(i);
        }
        ChangedWeight();
        return true;
    }
    return false;
}

// проверка на то есть ли свободное место в инвенторе
bool StorageComponent::ChechFreeSlotForItem(StorageItem* item)
{
    bool InSlot;
    for(int i = 0; i < StorageSizeX; i++)
    {
        for(int j = 0; j < StorageSizeY; j++)
        {
            InSlot = true;
            foreach (StorageItem* item, Storage)
            {
                if(item->CheckIfItemIsInSlot(i, j))
                {
                    InSlot = false;
                }
            }
            if(InSlot == true)
            {
                item->ItemAddedToStorage(this, i, j);
                return true;
            }
        }
    }
    return false;
}

// проверка есть ли в инвенторе такие же предметы для стака
StorageItem* StorageComponent::ChechItemForStack(StorageItem *item)
{
    foreach (StorageItem* it, Storage)
    {
        if(item->Class == it->Class)
        {
            return it;
        }
    }
    return nullptr;
}

StorageItem *StorageComponent::CheckSlot(int x, int y)
{
    foreach (StorageItem* item, Storage)
    {
        if(item->GetPosX() == x && item->GetPosY() == y)
        {
            return item;
        }
    }
    return nullptr;
}

void StorageComponent::ChangedWeight()
{
    Weight = 0;
    foreach (StorageItem* item, Storage)
    {
        Weight += item->Weight * item->Count;
    }
}

bool StorageComponent::RemoveItem(StorageItem *item, int Count, bool RemoveAll)
{
    // проверка на то что предмет из этого инвентаря и есть ли вообще столько предметов
    if(item->GetOwningStorage() == this && item->Count >= Count)
    {
        // проверка на удаление всех или не всех предметов
        int L_Count;
        RemoveAll ? L_Count = item->Count : L_Count = Count;

        Weight -= item->Weight * L_Count;

        bool RemoveAll = RemoveStackedItem(item, L_Count);

        if(dynamic_cast<Player*>(player))
        {
            dynamic_cast<Player*>(player)->inventory->InventoryUpdate();
        }

        if(RemoveAll == true)
        {
            return true;
        }
        return false;
    }
    return false;
}

bool StorageComponent::RemoveStackedItem(StorageItem *item, int Count)
{
    if(item->Count - Count <= 0)
    {
        Storage.removeOne(item);
        return true;
    }
    else
    {
        item->Count -= Count;
        return false;
    }
}

StorageItem* StorageComponent::GetItemInStorageByClass(QString Class)
{
    foreach (StorageItem* item, Storage)
    {
        if(item->Class == Class)
        {
            return item;
        }
    }
    return nullptr;
}

float StorageComponent::GetWeight() const
{
    return Weight;
}

Main_Character *StorageComponent::GetPlayer() const
{
    return player;
}
