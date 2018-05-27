#include "avion.h"

avion::avion(float _px, float _py,float _vx):obstaculo(_px,_py,_vx,0)
{
setPixmap(QPixmap(":/new/prefix1/avion1.png").scaled(400/2,300/2));
}

