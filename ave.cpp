#include "ave.h"

float ave::getPx() const
{
    return px;
}


void ave::setFlag(int value)
{
    flag = value;
}

ave::ave(){
    px=0;
    py=0;
    vy=0;

}
//QRectF ave::boundingRect() const
//{
//        return QRectF(-100,-100,100,100);
//}

//void ave::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widgets)
//{

//    QPixmap pixmap;
//    pixmap.load(":/new/prefix1/ave1.png");
//    painter->drawPixmap(boundingRect(),pixmap,pixmap.rect());

//}
void ave::mov()
{
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
