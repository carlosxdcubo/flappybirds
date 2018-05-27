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
    int flag;
    int vidas;
public:
    ave();
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
};

#endif // AVE_H
