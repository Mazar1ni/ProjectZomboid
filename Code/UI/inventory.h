#ifndef INVENTORY_H
#define INVENTORY_H

#include <QWidget>
#include <QLabel>
#include "advancedtablewidget.h"
#include "equiptablewidget.h"


class Inventory : public QWidget
{
    Q_OBJECT

public:
    Inventory();

    void InventoryUpdate();

    AdvancedTableWidget* TableInventory;
    EquipTableWidget* EquipTable;
    QLabel* weight;
};

#endif // INVENTORY_H
