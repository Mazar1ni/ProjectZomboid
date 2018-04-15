#ifndef OBJECT_H
#define OBJECT_H
class Player;

class Object
{
public:
    explicit Object();

    virtual void Interact(Player*);
};

#endif // OBJECT_H
