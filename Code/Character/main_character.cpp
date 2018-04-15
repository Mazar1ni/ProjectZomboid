#include "main_character.h"
#include "Code/Character/Components/statscomponent.h"
#include "Code/Character/Components/equipcomponents.h"
#include "Code/Character/Components/storagecomponent.h"

Main_Character::Main_Character(QObject *parent) : QObject(parent)
{
    // initialize components
    Storage = new StorageComponent(this);
    Stats = new StatsComponent;
    EquipComponent = new EquipComponents(this);

    connect(Stats, &StatsComponent::HealthEnd, this, &Main_Character::HealthEnd);
}

void Main_Character::HealthEnd()
{
    Death();
}

void Main_Character::AnyDamage(float Damage, Main_Character *Instigated)
{
    if(Instigated != this)
    {
        Stats->setDamageTaken(true);
        Stats->ChangedHealth(Damage * -1);
    }
}

void Main_Character::Death()
{
    Dead = true;
}
