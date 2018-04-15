#ifndef STATS_H
#define STATS_H

#include <QObject>

class StatsComponent : public QObject
{
    Q_OBJECT

public:
    StatsComponent();

    void MainLoop();
    void ChangedHealth(float Heal);
    void ChangedHunger(bool Eat, float Hun);
    void ChangedThirst(bool Water, float Thi);
    void Bleeding();
    void HealthRegeneration();

    double GetHealth() const;
    double GetThirst() const;
    double GetHunger() const;

    void setDamageTaken(bool value);
    void setBleedding(bool value);

signals:
    void HealthEnd();

private:
    // Health
    double Health = 100;
    double HealthMax = 100;
    double HealthDamage = 0.4;
    double RegenerationLow = 30;
    double RegenerationPerSec = 0.1;
    double RegenerationTime = 0;
    bool Regeneration = false;
    bool HealthEnded = false;
    bool DamageTaken = false;

    // Thirst
    double Thirst = 100;
    double ThirstMax = 100;
    double ThirstSpeed = 0.1;
    bool ThirstEnded = false;

    // Hunger
    double Hunger = 100;
    double HungerMax = 100;
    double HungerSpeed = 0.05;
    bool HungerEnded = false;

    // Bleeding
    int BleedingTimer = 0;
    int BleedingTime = 5;
    bool Bleedding = false;
    double BleedingDamage = 0.5;


};

#endif // STATS_H
