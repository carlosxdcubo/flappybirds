#ifndef OBSTACULO_H
#define OBSTACULO_H
#include <QGraphicsItem>

class obstaculo:public QGraphicsPixmapItem
{
protected:
    float px;
    float py;
    float vx;
    float vy;
public:
    obstaculo(float _px,float _py,float _vx, float _vy);
    float getPx() const;
    void setPx(float value);
    float getPy() const;
    void setPy(float value);
    float getVx() const;
    void setVx(float value);
    float getVy() const;
    void setVy(float value);
    void mover(float _dt);
};

#endif // OBSTACULO_H
