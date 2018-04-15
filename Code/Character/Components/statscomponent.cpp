#include "statscomponent.h"
#include <QTimer>
#include <algorithm>

using namespace  std;

StatsComponent::StatsComponent()
{
    QTimer* timer = new QTimer;
    connect(timer, &QTimer::timeout, this, &StatsComponent::MainLoop);
    timer->start(1000);
}

void StatsComponent::MainLoop()
{
    if(!HealthEnded)
    {
        ChangedThirst(false, 0);
        ChangedHunger(false, 0);
        ChangedHealth(0);
        HealthRegeneration();
        Bleeding();
    }
}

void StatsComponent::ChangedHealth(float Heal)
{
    Health = min(HealthMax, Health+Heal);
    if(Health <= RegenerationLow)
    {
        Regeneration = true;
    }
    else
    {
        Regeneration = false;
    }
    if(Health <= 0)
    {
        HealthEnded = true;
        emit HealthEnd();
    }
}

void StatsComponent::ChangedHunger(bool Eat, float Hun)
{
    if(Eat)
    {
        Hunger = min(HungerMax, Hunger + Hun);
    }
    else
    {
        Hunger = max(0.0, Hunger - HungerSpeed);
        if(Hunger <= 0)
        {
            Health = max(0.0, Health - HealthDamage);
            DamageTaken = true;
        }
        else
        {
            DamageTaken = false;
        }
    }
}

void StatsComponent::ChangedThirst(bool Water, float Thi)
{
    if(Water)
    {
        Thirst = min(ThirstMax, Thirst + Thi);
    }
    else
    {
        Thirst = max(0.0, Thirst - ThirstSpeed);
        if(Thirst <= 0)
        {
            Health = max(0.0, Health - HealthDamage);
            DamageTaken = true;
        }
        else
        {
            DamageTaken = false;
        }
    }
}

void StatsComponent::Bleeding()
{
    if(Bleedding)
    {
        if(BleedingTimer >= BleedingTime)
        {
            BleedingTimer = 0;
            Bleedding = false;
        }
        else
        {
            BleedingTimer++;
            DamageTaken = true;
            ChangedHealth(BleedingDamage * -1);
        }
    }
    else
    {
        BleedingTimer = 0;
    }
}

void StatsComponent::HealthRegeneration()
{
    if(Regeneration == true)
    {
        if(!DamageTaken)
        {
            if(RegenerationTime > 15)
            {
                Health = min(RegenerationLow, Health + RegenerationPerSec);
            }
            else
            {
                RegenerationTime++;
            }
        }
        else
        {
            DamageTaken = false;
            RegenerationTime = 0;
        }
    }
    else
    {
        RegenerationTime = 0;
    }
}

double StatsComponent::GetHealth() const
{
    return Health;
}

double StatsComponent::GetThirst() const
{
    return Thirst;
}

double StatsComponent::GetHunger() const
{
    return Hunger;
}

void StatsComponent::setDamageTaken(bool value)
{
    DamageTaken = value;
}

void StatsComponent::setBleedding(bool value)
{
    Bleedding = value;
}
