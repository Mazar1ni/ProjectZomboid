#include "equiptablewidget.h"
#include "game.h"
#include "Code/Character/Components/equipcomponents.h"
#include "Code/Storage/Equipables/Hats/hat.h"
#include <QDebug>
#include <QMouseEvent>

extern Game* game;

EquipTableWidget::EquipTableWidget(QWidget *parent) : QTableWidget(parent)
{
    setSelectionMode(QAbstractItemView::SingleSelection);
    setEditTriggers(QAbstractItemView::NoEditTriggers);
    setRowCount(5);
    setColumnCount(1);
    EquipTableUpdate();
}

void EquipTableWidget::EquipTableUpdate()
{
    QTableWidgetItem* item = new QTableWidgetItem;
    items.clear();
    if(game->player->EquipComponent->GetHead() != nullptr)
    {
        Hat* hat = game->player->EquipComponent->GetHead();
        items.push_back(hat);
        item->setIcon(hat->GetIcon());
        setItem(0, 0, item);
    }
    else
    {
        items.push_back(nullptr);
        item->setWhatsThis("none");
        setItem(0, 0, item);
    }
}

void EquipTableWidget::mouseDoubleClickEvent(QMouseEvent *event)
{
    QTableWidgetItem* item=itemAt(event->pos());
    if(item->whatsThis() != "none")
    {
        items.at(item->row())->UnEquipItem();
    }
}


