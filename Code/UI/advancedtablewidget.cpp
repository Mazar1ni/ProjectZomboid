#include "advancedtablewidget.h"
#include "Code/Storage/storageitem.h"
#include "Code/UI/game.h"
#include "Code/UI/inventory.h"
#include <QMouseEvent>
#include <QModelIndex>
#include <QDebug>

extern Game* game;

AdvancedTableWidget::AdvancedTableWidget(QWidget * parent) : QTableWidget(parent)
{
    setRowCount(5);
    setColumnCount(5);
    setSelectionMode(QAbstractItemView::SingleSelection);
    setDragEnabled(true);
    setAcceptDrops(true);
    setDropIndicatorShown(true);
    setDragDropMode(QAbstractItemView::InternalMove);
    setEditTriggers(QAbstractItemView::NoEditTriggers);

    // set cursor
    cursor = nullptr;
    setMouseTracking(true);
}

void AdvancedTableWidget::SetCursor(StorageItem* item)
{
    if(cursor)
    {
        game->scene->removeItem(cursor);
        delete cursor;
    }

    cursor = new QGraphicsPixmapItem;
    cursor->setPixmap(QPixmap(item->UrlIcon));
    game->scene->addItem(cursor);
}

void AdvancedTableWidget::mousePressEvent(QMouseEvent *event)
{
    QTableWidgetItem *targetItem=itemAt(event->pos());
    if (event->button() == Qt::LeftButton) {
        // включаем драг и дроп если ячейка выделена
        if (targetItem->whatsThis() != "none") {
            OldPosX = targetItem->row();
            OldPosY = targetItem->column();
            QTableWidget::mousePressEvent(event);
        }
        else
        {
            OldPosX = -1;
            OldPosY = -1;
        }
    }
}

void AdvancedTableWidget::mouseReleaseEvent(QMouseEvent *event)
{
    QTableWidgetItem *targetItem=itemAt(event->pos());
    if(OldPosX != -1 && OldPosY != -1 && item(OldPosX, OldPosY)->whatsThis() != "none" && targetItem != 0)
    {
        setItemSelected(item(OldPosX, OldPosY), false);
        if(item(targetItem->row(), targetItem->column())->whatsThis() == "none")
        {
            game->player->Storage->CheckSlot(OldPosX, OldPosY)->SetPos(targetItem->row(), targetItem->column());
            game->player->inventory->InventoryUpdate();
        }
    }
    QTableWidget::mouseReleaseEvent(event);
}

void AdvancedTableWidget::mouseDoubleClickEvent(QMouseEvent *event)
{
    QTableWidgetItem* item=itemAt(event->pos());
    if(item->whatsThis() != "none")
    {
        game->player->Storage->CheckSlot(item->row(), item->column())->UseItem();
    }
}
