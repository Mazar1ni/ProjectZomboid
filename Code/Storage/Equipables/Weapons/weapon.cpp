#include "weapon.h"

Weapon::Weapon()
{
    SetEquipPart(EquipComponents::WeaponPart);

    Tick = new QTimer;
    connect(Tick, &QTimer::timeout, this, &Weapon::EventTick);
    Tick->start(1);
}

bool Weapon::UseWeapon(bool Use)
{
    if(Use == false)
    {
        Firing = false;
        return false;
    }

    WeaponCanBeUsedByTimer = false;

    if(ChangedCondition(ConditionPerShot * -1))
    {
        if(AutoFire == true)
        {
            Firing = true;
            return true;
        }
        else
        {
            return true;
        }
    }

    return false;
}

bool Weapon::ChangedCondition(int Cond)
{
    return StorageItem::ChangedCondition(Cond);
}

bool Weapon::IsAbleToUseWeapon()
{
    if(WeaponCanBeUsedByTimer == true && Broken == false)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Weapon::WeaponUseTimer()
{
    if(!WeaponCanBeUsedByTimer)
    {
        WeaponUseTiming++;

        if(WeaponUseTiming >= (1 / UsePerSec))
        {
            WeaponCanBeUsedByTimer = true;
            WeaponUseTiming = 0;
        }
    }
}

void Weapon::EventTick()
{
    WeaponUseTimer();
    if(Firing == true && IsAbleToUseWeapon() == true)
    {
        UseWeapon(true);
    }
}
