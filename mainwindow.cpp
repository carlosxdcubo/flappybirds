#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include "gameover.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    srand (time(NULL));
    ui->setupUi(this);
    timer=new QTimer(this);                 //crea el timer
    scene=new QGraphicsScene(this);         //crea la scene
    ancho=1000;
    alto=600;
    scene->setSceneRect(0,0,ancho,alto);       //asigna el rectangulo que encierra la scene, determinado por h_limit y v_limit
    dt=0.01;                                //Delta de tiempo
    dif=1;                                  //dificultad
    ui->graphicsView->setScene(scene);      //Pone la escena en el View
    qDebug()<<ui->graphicsView->size();
    ui->centralWidget->adjustSize();        //ajusta el tamaño
    qDebug()<<ui->centralWidget->size();
    qDebug()<<this->size();
    scene->addRect(scene->sceneRect());     //Dibuja rectas para la escena
    timer->stop();                          //para el timer
    connect(timer,SIGNAL(timeout()),this,SLOT(actualizar()));    //bucle para actualizar posicion
    //Nubes
    n1.append(new nube(-100,rand()%300+50,-5));
    scene->addItem(n1.first());
    n2.append(new nube(800,100+rand()%300+50,-3));
    scene->addItem(n2.first());
    //avión
    a.append(new avion(1000,rand()%600+50,-1*(rand()%80+50)*dif));
    scene->addItem(a.first());
    //ave
    bird.append(new ave());                 //creo el ave
    bird.first()->setPoint(0,80);        //la coloco en una posición
    bird.first()->setVel(0);                //velocidad =0
    bird.first()->setZValue(10);         //llevar al frente
    scene->addItem(bird.first());           //añado el ave a la escena
    count=0;
    scene->setBackgroundBrush(QBrush(QImage(":/new/prefix1/cielo.png").scaled(800,600)));


}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::actualizar()
{
        //ave
        bird.first()->actualizar(10,dt);
        bird.first()->mov();
        bird.first()->setPos(bird.last()->getPx(),bird.first()->getPy());
        n1.first()->mover(dt);
        //nubes
        n1.first()->setPos(n1.first()->getPx(),n1.first()->getPy());
        n2.first()->mover(dt);
        n2.first()->setPos(n2.first()->getPx(),n2.first()->getPy());
        //aviones
        a.first()->mover(dt);
        a.first()->setPos(a.first()->getPx(),a.first()->getPy());
        //otras funciones.
        count++;
        chocar();
        renovar();
        animarave();
        colision();
        cambiar();
        //Lcds
        ui->lcdNumber->display(bird.first()->getVidas());
        ui->lcdNumber_2->display(points);
    }


void MainWindow::on_pushButton_clicked()
{
    timer->start(200*dt);
}

float MainWindow::getPoints() const
{
    return points;
}

QList<ave *> MainWindow::getBird() const
{
    return bird;
}
void MainWindow::keyPressEvent(QKeyEvent *ev)
{
    if(ev->key()==Qt::Key_W){
        bird.first()->aletear(true);
    }
}

void MainWindow::renovar()
{
    if(n1.first()->getPx()<-1000){
        n1.append(new nube(1000,rand()%300+50,-1*rand()%20+10));
        scene->addItem(n1.last());
        n1.pop_front();

    }
    if(n2.first()->getPx()<-1000){
        n2.append(new nube(1000,rand()%300+50,-1*rand()%20+10));
        scene->addItem(n2.last());
        n2.pop_front();      
    }
    if(a.first()->getPx()<-500){
        a.append(new avion(1000,rand()%500+10,-1*dif*60));
        scene->addItem(a.last());
        a.pop_front();
        dif=dif+0.03;
        points=points+10;


    }

}

void MainWindow::chocar()
{
    if(bird.first()->getVidas()>0){
        if(bird.first()->getPy()>alto-80){

            bird.first()->setVidas(bird.first()->getVidas()-1);
            bird.first()->setPoint(0,100);
            timer->stop();
        }
        if(bird.first()->getPy()<-40){

            bird.first()->setVidas(bird.first()->getVidas()-1);
            bird.first()->setPoint(0,100);
            timer->stop();
        }
    }
    else{
       gameover *MyDialog = new gameover(); MyDialog->show();
       MyDialog->setlcd(points);
       bird.first()->setVidas(3);
       bird.first()->setPoint(0,80);
       points=0;
       timer->stop();
    }
}

void MainWindow::animarave()
{
    if (count>=0 && count<=99){
        bird.first()->setFlag(1);
    }
    if (count>=100 && count<=199){
        bird.first()->setFlag(2);
    }
    if (count>=200 && count<=299){
        bird.first()->setFlag(3);
    }
    if (count>=300){
        count=0;
    }
}

void MainWindow::colision()
{
    if(bird.first()->collidesWithItem(a.first())){
    scene->removeItem(a.first());
    a.pop_front();
    a.append(new avion(1000,rand()%500+10,-1*dif*100));
    scene->addItem(a.last());
    bird.first()->setVidas(bird.first()->getVidas()-1);
    }
}

void MainWindow::cambiar()
{
    if(dif>1.2 && dif<1.5){
        a.first()->setPixmap(QPixmap(":/new/prefix1/avion2.png").scaled(400/2,300/2));
    }
    if(dif>1.5 && dif<2){
        a.first()->setPixmap(QPixmap(":/new/prefix1/avion3.png").scaled(400/2,300/2));
    }
    if(dif>2 && dif<2.5){
        a.first()->setPixmap(QPixmap(":/new/prefix1/avion4.png").scaled(450/2,350/2));
    }
    if(dif>2.5 && dif<3){
        a.first()->setPixmap(QPixmap(":/new/prefix1/globo.png").scaled(440/2,520/2));
    }
}

