#include "ave.h"

ave::ave(){
    px=0;
    py=0;
    vy=0;

}
QRectF ave::boundingRect() const
{
        return QRectF(-10,-10,20,20);
}

void ave::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::darkBlue);
    painter->drawEllipse(boundingRect());
    //QPixmap pixmap;
    //pixmap.load(":/dino.png");
    //painter->drawPixmap(boundingRect(),pixmap,pixmap.rect());
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
    if(b==true)vy-=10;
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
