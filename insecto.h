#ifndef INSECTO_H
#define INSECTO_H
#include "obstaculo.h"

class insecto:public obstaculo
{
public:
    insecto(float _px,float _py,float _vx, float _vy);
    void randomov(float _dt);
};

#endif // INSECTO_H
