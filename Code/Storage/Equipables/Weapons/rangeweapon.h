#ifndef RANGEWEAPON_H
#define RANGEWEAPON_H

#include "Code/Storage/Equipables/Weapons/weapon.h"
class Horn;

class RangeWeapon : public Weapon
{
public:
    RangeWeapon();

    // functions
    bool UseWeapon(bool Use);
    bool IsAbleToUseWeapon();
    void UseAmmo(int Count);
    Horn* FindAmmo();
    bool Reload();
    void ReloadingProcess();
    void EventTick();
    bool UnEquipItem();

    // values
    Horn* HornItemRef = nullptr;
    bool Reloading = false;
    QTimer* Time;
    int ReloadTimer = 0;
    int ReloadTime = 0;

};

#endif // RANGEWEAPON_H
