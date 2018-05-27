#ifndef NUBE_H
#define NUBE_H
#include "obstaculo.h"

class nube:public obstaculo
{
public:
    nube(float _px, float _py,float _vx);
};

#endif // NUBE_H
