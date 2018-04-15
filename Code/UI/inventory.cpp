#include "inventory.h"
#include "Code/UI/game.h"
#include <QTableWidget>
#include <QHeaderView>
#include "Code/Storage/storageitem.h"
#include <QDebug>

extern Game* game;

Inventory::Inventory()
{
    resize(QSize(410, 340));
    move(game->player->x(), game->player->y());
    weight = new QLabel(this);
    weight->setText("Weight: " + QString::number(game->player->Storage->GetWeight()));
    weight->resize(300, 30);
    weight->move(100, 0);

    //game->setCursor(QCursor(Qt::PointingHandCursor));

    EquipTable = new EquipTableWidget(this);

    // скрываем скроллбары
    EquipTable->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    EquipTable->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    // скрываем заголовки таблицы и задаём фиксированнаый размер
    EquipTable->verticalHeader()->setDefaultSectionSize(60);
    EquipTable->horizontalHeader()->setDefaultSectionSize(60);
    EquipTable->verticalHeader()->hide();
    EquipTable->horizontalHeader()->hide();

    // задаём размер таблице
    EquipTable->move(20, 30);
    EquipTable->resize(60, 300);

    TableInventory = new AdvancedTableWidget(this);

    InventoryUpdate();

    // скрываем скроллбары
    TableInventory->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    TableInventory->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    // скрываем заголовки таблицы и задаём фиксированнаый размер
    TableInventory->verticalHeader()->setDefaultSectionSize(60);
    TableInventory->horizontalHeader()->setDefaultSectionSize(60);
    TableInventory->verticalHeader()->hide();
    TableInventory->horizontalHeader()->hide();

    // задаём размер таблице
    TableInventory->move(100, 30);
    TableInventory->resize(300, 300);
}

void Inventory::InventoryUpdate()
{
    // добавляем все предметы
    for(int i = 0; i != 5; i++)
    {
        for(int j = 0; j != 5; j++)
        {
            QTableWidgetItem* item = new QTableWidgetItem;
            if(StorageItem* it = game->player->Storage->CheckSlot(i, j))
            {
                item->setIcon(it->GetIcon());
                item->setText(QString::number(it->Count));
                item->setTextAlignment(30);
                TableInventory->setItem(i, j, item);
            }
            else
            {
                item->setWhatsThis("none");
                TableInventory->setItem(i, j, item);
            }
        }
    }

    weight->setText("Weight: " + QString::number(game->player->Storage->GetWeight()));
}
