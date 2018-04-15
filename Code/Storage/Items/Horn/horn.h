#ifndef HORN_H
#define HORN_H

#include <QTimer>
#include "Code/Storage/storageitem.h"

class Horn : public StorageItem
{
public:
    Horn();

    // functions
    void ReloadProcess();
    void EventTick();
    bool NullAmmoHorn();

    // values
    bool Reload = false;
    int ReloadTimer = 0;
    QTimer* Time;

    // horn settings
    int ClipSize = 0;
    int CurClipAmmo = 0;
    int ReloadTime = 0;

};

#endif // HORN_H
