#include "equipcomponents.h"
#include "Code/Storage/Equipables/equipableitem.h"
#include "Code/Character/player.h"
#include "Code/Character/Components/storagecomponent.h"
#include "Code/Character/main_character.h"
#include <QDebug>

EquipComponents::EquipComponents(Main_Character *pl) : player(pl)
{

}

bool EquipComponents::EquipItem(EquipableItem *Item, Part EquipPart)
{
    if(UnEquipItem(EquipPart))
    {
        switch(EquipPart)
        {
        case HeadPart:
            head = (Hat*)Item;
            return true;
            break;
        case TorsPart:
            break;
        case LegsPart:
            break;
        case FootsPart:
            break;
        case WeaponPart:
            weapon = (Weapon*)Item;
            return true;
            break;
        }
    }
    return false;
}

bool EquipComponents::UnEquipItem(Part EquipPart)
{
    switch(EquipPart)
    {
    case HeadPart:
        if(head != nullptr)
        {
            if(player->Storage->AddItem((StorageItem*)head))
            {
                head = nullptr;
                return true;
            }
            return false;
        }
        return true;
        break;
    case TorsPart:
        break;
    case LegsPart:
        break;
    case FootsPart:
        break;
    case WeaponPart:
        if(weapon != nullptr)
        {
            if(player->Storage->AddItem((StorageItem*)weapon))
            {
                weapon = nullptr;
                return true;
            }
            return false;
        }
        return true;
        break;
    }
    return false;
}

Hat *EquipComponents::GetHead() const
{
    return head;
}
