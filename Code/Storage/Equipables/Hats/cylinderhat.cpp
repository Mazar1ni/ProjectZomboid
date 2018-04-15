#include "cylinderhat.h"

CylinderHat::CylinderHat()
{
    setPixmap(QPixmap(":/Items/CylinderHat.png"));

    icon = QPixmap(":/Items/CylinderHat.png");
    UrlIcon = ":/Items/CylinderHat.png";
    Weight = 2;
    Name = "CylinderHat";
    Price = 10;
    Type = Armor;
    CanBeStacked = false;
    Class = "CylinderHat";
}
