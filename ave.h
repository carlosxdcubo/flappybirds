#ifndef AVE_H
#define AVE_H
#include <QPainter>
#include <QGraphicsItem>
#include <QGraphicsScene>

class ave:public QGraphicsPixmapItem
{
private:
    float px;
    float py;
    float vy;
    float vx;
    int flag;
    int vidas;
    float points;
    int player;

public:
    ave(int _p);
    //QRectF boundingRect() const;    //necesario definirla, devuelve el rectangulo que encierra el objeto
    //void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget); //define como se pintara el objeto
    void aletear(bool);
    void actualizar(float _ay, float dt);
    void setVel(float y);          //metodo para asignar la velocidad (en X y en Y)
    void setPoint(float x, float y);        //metodo para asignar la posicion (en X y en Y)
    float getPy() const;
    float getVy() const;
    float getPx() const;
    void mov();
    void setFlag(int value);
    void setVidas(int value);
    int getVidas() const;

    float getPoints() const;
    void setPoints(float value);
    int getPlayer() const;
    void setPx(float value);
    void setPy(float value);
    float getVx() const;
    void setVx(float value);
};

#endif // AVE_H
