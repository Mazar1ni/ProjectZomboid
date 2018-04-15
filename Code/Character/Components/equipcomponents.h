#ifndef EQUIPCOMPONENTS_H
#define EQUIPCOMPONENTS_H

class StorageItem;
class EquipableItem;
class Player;
class Hat;
class Weapon;
class Main_Character;

class EquipComponents
{
public:
    EquipComponents(Main_Character* pl);

    enum Part{HeadPart, TorsPart, LegsPart, FootsPart, WeaponPart};

    bool EquipItem(EquipableItem *item, Part EquipPart);
    bool UnEquipItem(Part EquipPart);

    Hat *GetHead() const;

private:
    Hat* head = nullptr;
    Weapon* weapon = nullptr;
    Main_Character* player;

};

#endif // EQUIPCOMPONENTS_H
