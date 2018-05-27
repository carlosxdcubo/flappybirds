#include "nube.h"

nube::nube(float _px, float _py,float _vx):obstaculo(_px,_py,_vx,0)
{
setPixmap(QPixmap(":/new/prefix1/nubes.png").scaled(2000/2,250/2));
}
