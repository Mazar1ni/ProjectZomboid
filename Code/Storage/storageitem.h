#ifndef STORAGEITEM_H
#define STORAGEITEM_H

#include "Code/object.h"
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QIcon>

class StorageComponent;

class StorageItem : public QObject, public Object, public QGraphicsPixmapItem
{
    Q_OBJECT

public:
    StorageItem();

    enum Type{None, Weapon, Other, Armor};

    // functions
    void ItemAddedToStorage(StorageComponent *Storage, int x, int y);
    bool CheckIfItemIsInSlot(int x, int y);
    virtual void UseItem();
    bool RemoveItem(int Count);
    void ItemRemoveFromStorage();
    bool ChangedCondition(int Cond);
    float GetItemWeight(bool Total, int CountItem);
    void DeteriorateItem();
    virtual void Interact(Player* player);

    int GetPosX() const;
    int GetPosY() const;
    QIcon GetIcon() const;
    void SetPos(int x, int y);
    StorageComponent *GetOwningStorage() const;

    // values
    QString Name;
    Type Type = None;
    float Weight = 0;
    int Count = 1;
    float Condition = 100;
    int Price = 0;
    bool Usable = false;
    bool CanBeStacked = false;
    bool Equipable = false;
    QString UrlIcon;
    QIcon icon;
    QString Description;
    QString Class;
    bool Broken = false;
    bool InStorage = false;
    StorageComponent* OwningStorage = nullptr;
    int PosX = 0;
    int PosY = 0;
    float SpeedDeteriorate = 0;
    bool Deteriorate = false;

};

#endif // STORAGEITEM_H
