#include "background.h"

Background::Background(QGraphicsItem *parent) : QGraphicsPixmapItem(parent)
{
    setPixmap(QPixmap(":/Background/background.png"));
}
