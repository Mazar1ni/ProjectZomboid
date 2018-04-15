#include "scene.h"

Scene::Scene()
{

}

void Scene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    emit SignalTargetCoordinate(event);
}
