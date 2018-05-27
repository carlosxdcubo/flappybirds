#include "obstaculo.h"

float obstaculo::getPx() const
{
    return px;
}

void obstaculo::setPx(float value)
{
    px = value;
}

float obstaculo::getPy() const
{
    return py;
}

void obstaculo::setPy(float value)
{
    py = value;
}

float obstaculo::getVx() const
{
    return vx;
}

void obstaculo::setVx(float value)
{
    vx = value;
}

float obstaculo::getVy() const
{
    return vy;
}

void obstaculo::setVy(float value)
{
    vy = value;
}

void obstaculo::mover(float _dt)
{
    px+=vx*_dt;
}

obstaculo::obstaculo(float _px,float _py,float _vx, float _vy)
{
    px=_px;
    py=_py;
    vx=_vx;
    vy=_vy;
}
