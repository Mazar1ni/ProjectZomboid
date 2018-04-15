#ifndef STORAGECOMPONENT_H
#define STORAGECOMPONENT_H

#include <QList>
#include <QGraphicsPixmapItem>

class StorageItem;
class Player;
class Main_Character;

class StorageComponent
{
public:
    StorageComponent(Main_Character *l_player);

    bool AddItem(StorageItem* i);
    bool ChechFreeSlotForItem(StorageItem* item);
    StorageItem *ChechItemForStack(StorageItem* item);
    StorageItem *CheckSlot(int x, int y);
    void ChangedWeight();
    bool RemoveItem(StorageItem* item, int Count, bool RemoveAll);
    bool RemoveStackedItem(StorageItem* item, int Count);
    StorageItem* GetItemInStorageByClass(QString Class);

    float GetWeight() const;
    Main_Character *GetPlayer() const;

private:
    QList<StorageItem*> Storage;
    float Weight = 0;
    float MaxWeight = 1000;
    int StorageSizeX = 5;
    int StorageSizeY = 5;
    int DropDistance = 100;
    Main_Character* player;

};

#endif // STORAGECOMPONENT_H
