#include "nube.h"

nube::nube(float _px, float _py):obstaculo(_px,_py,-1,0)
{
setPixmap(QPixmap(":/new/prefix1/nubes.png").scaled(2000/2,250/2));
}
