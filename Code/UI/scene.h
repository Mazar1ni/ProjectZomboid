#ifndef SCENE_H
#define SCENE_H

#include <QObject>
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>

class Scene : public QGraphicsScene
{
    Q_OBJECT

public:
    Scene();

signals:
    // Сигнал для передачи координат положения курсора мыши
    void SignalTargetCoordinate(QGraphicsSceneMouseEvent* point);

private:
    // Функция, в которой производится отслеживание положения мыши
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
};

#endif // SCENE_H
