#ifndef EQUIPABLEITEM_H
#define EQUIPABLEITEM_H

#include "Code/Storage/storageitem.h"
#include "Code/Character/Components/equipcomponents.h"

class Player;

class EquipableItem : public StorageItem
{
public:
    EquipableItem();
    bool EquipItem(Main_Character *player);
    void UseItem();
    bool UnEquipItem();

    void SetEquipPart(const EquipComponents::Part &value);

private:
    bool Equipped = false;
    EquipComponents::Part EquipPart;
    Main_Character* EquipedToPlayer = nullptr;

};

#endif // EQUIPABLEITEM_H
