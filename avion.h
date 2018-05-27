#ifndef AVION_H
#define AVION_H
#include "obstaculo.h"

class avion:public obstaculo
{
public:
    avion(float _px, float _py,float _vx);
};

#endif // AVION_H
