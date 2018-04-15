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
    // ������ ��� �������� ��������� ��������� ������� ����
    void SignalTargetCoordinate(QGraphicsSceneMouseEvent* point);

private:
    // �������, � ������� ������������ ������������ ��������� ����
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
};

#endif // SCENE_H
