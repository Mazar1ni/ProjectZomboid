#ifndef ITEM_WATER_H
#define ITEM_WATER_H

#include "Code/Storage/storageitem.h"

class Item_Water : public StorageItem
{
public:
    Item_Water();

    void UseItem();
};

#endif // ITEM_WATER_H
