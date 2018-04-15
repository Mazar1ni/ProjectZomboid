#ifndef EQUIPTABLEWIDGET_H
#define EQUIPTABLEWIDGET_H

#include <QObject>
#include <QTableWidget>

class EquipableItem;

class EquipTableWidget : public QTableWidget
{
    Q_OBJECT

public:
    EquipTableWidget(QWidget * parent = 0);
    void mouseDoubleClickEvent(QMouseEvent *event);

    void EquipTableUpdate();
    QList<EquipableItem*> items;
};

#endif // EQUIPTABLEWIDGET_H
