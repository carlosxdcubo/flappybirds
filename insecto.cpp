#include "insecto.h"
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

insecto::insecto(float _px,float _py,float _vx,float _vy):obstaculo(_px,_py,_vx, _vy)
{
    setPixmap(QPixmap(":/new/prefix1/beedril.png").scaled(40,40));
}

void insecto::randomov(float _dt)
{
    srand (time(NULL));
    int _ay=(rand()%20)-(rand()%20);
    int _ax=(rand()%25)-(rand()%25);

    vx+=(_ax)*_dt;
    vy+=_ay*_dt;
    px+=(vx*_dt)+((_ax*_dt*_dt)/2);
    py+=(vy*_dt)+((_ay*_dt*_dt)/2);
}
