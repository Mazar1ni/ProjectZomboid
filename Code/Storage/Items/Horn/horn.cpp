#include "horn.h"

Horn::Horn()
{
    Time = new QTimer;
    connect(Time, &QTimer::timeout, this, &Horn::EventTick);
    Time->start(1);
}

void Horn::ReloadProcess()
{
    if(Reload == true)
    {
        ReloadTimer++;

        if(ReloadTimer >= ReloadTime)
        {
            Reload = false;
            ReloadTimer = 0;
        }
    }
}

void Horn::EventTick()
{
    ReloadProcess();
}

bool Horn::NullAmmoHorn()
{
    return CurClipAmmo > 0;
}
