#ifndef MAIN_CHARACTER_H
#define MAIN_CHARACTER_H

#include <QObject>

class StatsComponent;
class StorageComponent;
class EquipComponents;
class Inventory;

class Main_Character : public QObject
{
    Q_OBJECT
public:
    Main_Character(QObject* parent = nullptr);

    StorageComponent* Storage;
    StatsComponent* Stats;
    EquipComponents* EquipComponent;

public slots:
    void HealthEnd();
    void AnyDamage(float Damage, Main_Character* Instigated);

private:
    void Death();

    bool Dead = false;
};

#endif // MAIN_CHARACTER_H
