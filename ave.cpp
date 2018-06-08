#include "ave.h"

float ave::getPx() const
{
    return px;
}


void ave::setFlag(int value)
{
    flag = value;
}

void ave::setVidas(int value)
{
    vidas = value;
}

int ave::getVidas() const
{
    return vidas;
}


float ave::getPoints() const
{
    return points;
}

void ave::setPoints(float value)
{
    points = value;
}

int ave::getPlayer() const
{
    return player;
}

void ave::setPx(float value)
{
    px = value;
}

void ave::setPy(float value)
{
    py = value;
}

float ave::getVx() const
{
    return vx;
}

void ave::setVx(float value)
{
    vx = value;
}

ave::ave(int _p){
    px=0;
    py=100;
    vy=0;
    vx=0;
    vidas=3;
    points=0;
    player=_p;
    
}

void ave::mov()
{
    if(player==1){
    if (flag==0)
    {

        setPixmap(QPixmap(":/new/prefix1/ave1.png").scaled(80*2,60*2));

    }
    if (flag==1)
    {
        setPixmap(QPixmap(":/new/prefix1/ave2.png").scaled(80*2,60*2));
    }
    if (flag==2)
    {
        setPixmap(QPixmap(":/new/prefix1/ave4.png").scaled(80*2,60*2));
    }
    }
    if(player==2){
    if (flag==1)
    {
        setPixmap(QPixmap(":/new/prefix1/aveb1.png").scaled(80*2,60*2));

    }
    if (flag==2)
    {
        setPixmap(QPixmap(":/new/prefix1/aveb2.png").scaled(80*2,60*2));
    }
    if (flag==0)
    {
        setPixmap(QPixmap(":/new/prefix1/aveb3.png").scaled(80*2,60*2));
    }

}
}

float ave::getPy() const
{
    return py;
}

float ave::getVy() const
{
    return vy;
}


void ave::aletear(bool b)
{
    if(b==true)vy=-50;
}

void ave::actualizar(float _ay, float dt)
{
    px+=vx*dt+((-100*vx)*dt*dt/2);
    vy+=_ay*dt;
    py+=(vy*dt)+((_ay*dt*dt)/2);
}

void ave::setVel(float y)
{
    vy=y;
}

void ave::setPoint(float x, float y)
{
    px=x;
    py=y;
    vy=0;
}

