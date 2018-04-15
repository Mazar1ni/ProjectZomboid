#include "rangeweapon.h"
#include "Code/Storage/Items/Horn/horn.h"
#include "Code/Character/Components/storagecomponent.h"

RangeWeapon::RangeWeapon()
{
    Time = new QTimer;
    connect(Time, &QTimer::timeout, this, &RangeWeapon::EventTick);
    Time->start(1);
}

bool RangeWeapon::UseWeapon(bool Use)
{
    if(Use == true)
    {
        if(IsAbleToUseWeapon() == true)
        {
            UseAmmo(1);
            return Weapon::UseWeapon(true);
        }
        return false;
    }
    else
    {
        return Weapon::UseWeapon(false);
    }
}

bool RangeWeapon::IsAbleToUseWeapon()
{
    if(HornItemRef == nullptr)
    {
        return false;
    }

    if(HornItemRef->CurClipAmmo > 0 && Reloading == false && Weapon::IsAbleToUseWeapon() == true)
    {
        return true;
    }

    return false;
}

void RangeWeapon::UseAmmo(int Count)
{
    HornItemRef->CurClipAmmo -= Count;
}

Horn *RangeWeapon::FindAmmo()
{
    Horn* horn = (Horn*)OwningStorage->GetItemInStorageByClass(Class);
    if(horn != nullptr)
    {
        if(!horn->Reload)
        {
            return horn;
        }
    }
    return nullptr;
}

bool RangeWeapon::Reload()
{
    Horn* horn = FindAmmo();
    if(HornItemRef != nullptr)
    {
        if(horn != nullptr)
        {
            HornItemRef->OwningStorage->AddItem(HornItemRef);
            HornItemRef = horn;
            Reloading = true;
            return true;
        }
        else
        {
            HornItemRef->OwningStorage->AddItem(HornItemRef);
            Reloading = true;
            return false;
        }
    }
    else
    {
        if(horn != nullptr)
        {
            HornItemRef = horn;
            Reloading = true;
            return true;
        }
        else
        {
            return false;
        }
    }
}

void RangeWeapon::ReloadingProcess()
{
    if(Reloading == true)
    {
        ReloadTimer++;
        if(ReloadTimer >= ReloadTime)
        {
            ReloadTimer = 0;
            Reloading = false;

            if(HornItemRef->NullAmmoHorn())
            {
                HornItemRef->OwningStorage->RemoveItem(HornItemRef, 1, false);
            }
        }
    }
}

void RangeWeapon::EventTick()
{
    ReloadingProcess();
}

bool RangeWeapon::UnEquipItem()
{
    Reloading = false;
    ReloadTimer = 0;
    HornItemRef = nullptr;
    return EquipableItem::UnEquipItem();
}
