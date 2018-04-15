#include "equipableitem.h"
#include "Code/Character/player.h"
#include "Code/UI/inventory.h"
#include "Code/UI/equiptablewidget.h"
#include "Code/Character/Components/storagecomponent.h"
#include <QDebug>

EquipableItem::EquipableItem()
{

}

bool EquipableItem::EquipItem(Main_Character* player)
{
    EquipedToPlayer = player;
    Equipped = true;
    bool L_Equipped = player->EquipComponent->EquipItem(this, EquipPart);
    return L_Equipped;
}

void EquipableItem::UseItem()
{
    EquipItem(GetOwningStorage()->GetPlayer());
    if(dynamic_cast<Player*>(EquipedToPlayer))
    {
        dynamic_cast<Player*>(EquipedToPlayer)->inventory->EquipTable->EquipTableUpdate();
    }
    //EquipedToPlayer->inventory->EquipTable->EquipTableUpdate();
    RemoveItem(1);
}

bool EquipableItem::UnEquipItem()
{
    if(OwningStorage->GetPlayer()->EquipComponent->UnEquipItem(EquipPart) == true)
    {
        if(dynamic_cast<Player*>(EquipedToPlayer))
        {
            dynamic_cast<Player*>(EquipedToPlayer)->inventory->EquipTable->EquipTableUpdate();
            dynamic_cast<Player*>(EquipedToPlayer)->inventory->InventoryUpdate();
        }
        //EquipedToPlayer->inventory->EquipTable->EquipTableUpdate();
        //EquipedToPlayer->inventory->InventoryUpdate();
        EquipedToPlayer = nullptr;
        Equipped = false;
        return true;
    }
    return false;
}

void EquipableItem::SetEquipPart(const EquipComponents::Part &value)
{
    EquipPart = value;
}
