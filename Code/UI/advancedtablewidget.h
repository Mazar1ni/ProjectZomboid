#ifndef ADVANCEDTABLEWIDGET_H
#define ADVANCEDTABLEWIDGET_H

#include <QObject>
#include <QTableWidget>
#include <QGraphicsPixmapItem>

class StorageItem;

class AdvancedTableWidget : public QTableWidget
{
    Q_OBJECT

public:
    AdvancedTableWidget(QWidget * parent = 0);

    void SetCursor(StorageItem *item);

    void mousePressEvent(QMouseEvent* event);
    void mouseReleaseEvent(QMouseEvent* event);
    void mouseDoubleClickEvent(QMouseEvent* event);

private:
    QGraphicsPixmapItem* cursor;
    int OldPosX = -1;
    int OldPosY = -1;

};

#endif // ADVANCEDTABLEWIDGET_H
