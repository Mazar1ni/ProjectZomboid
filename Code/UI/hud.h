#ifndef HUD_H
#define HUD_H

#include <QWidget>
#include <QLabel>

class Player;

class HUD : public QWidget
{
    Q_OBJECT

public:
    HUD(Player* pl);

    void Update();

private:
    QLabel* health;
    QLabel* thirst;
    QLabel* hunger;
    QLabel* hint;

    Player* player;
};

#endif // HUD_H
