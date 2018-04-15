#ifndef WEAPON_H
#define WEAPON_H

#include <QTimer>
#include "Code/Storage/Equipables/equipableitem.h"

class Weapon : public EquipableItem
{
public:
    Weapon();

    // functions
    bool UseWeapon(bool Use);
    bool ChangedCondition(int Cond);
    bool IsAbleToUseWeapon();
    void WeaponUseTimer();
    void EventTick();

    // values
    int ConditionPerShot;
    bool Firing = false;
    bool AutoFire = false;
    bool WeaponCanBeUsedByTimer = false;
    int WeaponUseTiming = 0;
    int UsePerSec = 0;
    QTimer* Tick;
};

#endif // WEAPON_H
