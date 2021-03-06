#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include "gameover.h"
#define ARCHIVO "partida.txt"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    srand (time(NULL));
    ui->setupUi(this);
    timer=new QTimer(this);                 //crea el timer
    scene=new QGraphicsScene(this);         //crea la scene
    count=0;
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
    std::ifstream file;
    file.open(ARCHIVO);
    QList<std::string> dats;
    std::string aux;
    std::string aux2;
    while(file.good()){      //Ciclo para guardar cada dato de la linea de texto en una string
    aux+=file.get();
        }
    for(int n=0;n<aux.size();n++){
        if(aux[n]!=' '&& aux[n]!='\n')aux2+=aux[n];
        else{
            dats.append(aux2);
            aux2="";
        }
    }

    file.close();
    dif=std::stof(dats.at(20));
    //Nubes
    n1.append(new nube(-100,rand()%300+50,-5));
    scene->addItem(n1.first());
    n2.append(new nube(800,100+rand()%300+50,-3));
    scene->addItem(n2.first());
    //insecto
    insect.append(new insecto(std::stof(dats.at(16)),std::stof(dats.at(17)),std::stof(dats.at(18)),std::stof(dats.at(19))));
    insect.first()->setPos(std::stof(dats.at(16)),std::stof(dats.at(17)));
    scene->addItem(insect.first());
    //avión
    a.append(new avion(std::stof(dats.at(12)),std::stof(dats.at(13)),std::stof(dats.at(14))));
    a.first()->setPos(std::stof(dats.at(12)),std::stof(dats.at(13)));
    scene->addItem(a.first());

    //aves
    bird.append(new ave(1,std::stof(dats.at(1)),std::stof(dats.at(2)),std::stof(dats.at(3)),std::stof(dats.at(4)),std::stof(dats.at(0)),std::stof(dats.at(5))));                 //creo el ave
    bird.first()->setPoint(std::stof(dats.at(1)),std::stof(dats.at(2)));        //la coloco en una posición
    bird.first()->setZValue(10);         //llevar al frente
    bird.append(new ave(2,std::stof(dats.at(7)),std::stof(dats.at(8)),std::stof(dats.at(9)),std::stof(dats.at(10)),std::stof(dats.at(6)),std::stof(dats.at(11))));                 //creo el ave
    bird.last()->setPoint(std::stof(dats.at(7)),std::stof(dats.at(8)));        //la coloco en una posición
    bird.last()->setZValue(10);         //llevar al frente
    scene->addItem(bird.first());           //añado el ave a la escena
    scene->addItem(bird.last());           //añado el ave a la escena
    scene->setBackgroundBrush(QBrush(QImage(":/new/prefix1/cielo.png").scaled(800,600)));


}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::actualizar()
{    //ave
    for(int i=0;i<bird.size();i++){
        bird.at(i)->actualizar(20,dt);
        bird.at(i)->mov();
        bird.at(i)->setPos(bird.at(i)->getPx(),bird.at(i)->getPy());
    }
        //nubes
        n1.first()->mover(dt);
        n1.first()->setPos(n1.first()->getPx(),n1.first()->getPy());
        n2.first()->mover(dt);
        n2.first()->setPos(n2.first()->getPx(),n2.first()->getPy());
        //aviones
        a.first()->mover(dt);
        a.first()->setPos(a.first()->getPx(),a.first()->getPy());
        //insecto
        insect.first()->randomov(dt);
        insect.first()->setPos(insect.first()->getPx(),insect.first()->getPy());
        //otras funciones.
        count++;
        chocar();
        renovar();
        animarave();
        colision();
        cambiar();
        rebotar();
        //Lcds
        ui->lcdNumber->display(bird.first()->getVidas());
        ui->lcdNumber_2->display(bird.first()->getPoints());
        ui->lcdNumber_3->display(bird.last()->getVidas());
        ui->lcdNumber_4->display(bird.last()->getPoints());
    }


void MainWindow::on_pushButton_clicked()
{
    timer->start(200*dt);
}


QList<ave *> MainWindow::getBird() const
{
    return bird;
}
void MainWindow::keyPressEvent(QKeyEvent *ev)
{
    //PAUSE
    if(ev->key()==Qt::Key_P){
        timer->stop();
        p.show();
    }
    //PLAYER 1
    if(ev->key()==Qt::Key_W){
        bird.first()->aletear(true);
    }
    if(ev->key()==Qt::Key_D){
        bird.first()->setVx(0);
        bird.first()->setVx(bird.first()->getVx()+50);
    }
    if(ev->key()==Qt::Key_A){
        bird.first()->setVx(0);
        bird.first()->setVx(bird.first()->getVx()-50);
    }

    //PLAYER 2
    if(ev->key()==Qt::Key_8){
        bird.last()->aletear(true);
    }
    if(ev->key()==Qt::Key_6){
        bird.last()->setVx(bird.last()->getVx()+10);
    }
    if(ev->key()==Qt::Key_4){
        bird.last()->setVx(bird.last()->getVx()-10);
    }
}

void MainWindow::renovar()   //elimina y añade objetos que salen
{
    if(n1.first()->getPx()<-1000){
        n1.append(new nube(1000,rand()%300+50,(-1*rand()%20+10)*dif));
        scene->addItem(n1.last());
        n1.pop_front();

    }
    if(n2.first()->getPx()<-1000){
        n2.append(new nube(1000,rand()%300+50,(-1*rand()%20+10)*dif));
        scene->addItem(n2.last());
        n2.pop_front();      
    }
    if(a.first()->getPx()<-500){
        a.append(new avion(1000,rand()%500+10,-1*dif*60));
        scene->addItem(a.last());
        a.last()->setPos(a.last()->getPx(),a.last()->getPy());
        a.pop_front();
        dif=dif+0.1;

       for(int i=0;i<bird.size();i++){
          if(bird.at(i)->getVidas()>0) bird.at(i)->setPoints(bird.at(i)->getPoints()+10);
}
    }

}

void MainWindow::chocar() //chocar con los bordes
{
    if(bird.first()->getVidas()<0 && bird.last()->getVidas()<0){
               gameover *GO = new gameover();
               GO->setlcd1(bird.first()->getPoints());
               GO->setlcd2(bird.last()->getPoints());
               GO->show();


    }
 for(int i=0;i<bird.size();i++){

    if(bird.at(i)->getVidas()>0){
        if(bird.at(i)->getPy()>alto-80){
            bird.at(i)->setVidas(bird.at(i)->getVidas()-1);
            bird.at(i)->setPoint(0,200);
            bird.at(i)->setVx(0);

        }
        if(bird.at(i)->getPx()>ancho-45){

            bird.at(i)->setVidas(bird.at(i)->getVidas()-1);
            bird.at(i)->setPoint(0,200);
            bird.at(i)->setVx(0);

        }
        if(bird.at(i)->getPx()<-40){

            bird.at(i)->setVidas(bird.at(i)->getVidas()-1);
            bird.at(i)->setPoint(0,200);
            bird.at(i)->setVx(0);

        }
        if(bird.at(i)->getPy()<-45){

            bird.at(i)->setVidas(bird.at(i)->getVidas()-1);
            bird.at(i)->setPoint(0,200);
            bird.at(i)->setVx(0);

        }
    }
    else{

       scene->removeItem(bird.at(i));
       if(bird.first()->getVidas()<=0 && bird.last()->getVidas()<=0){  //GAMEOVER

                  gameover *GO = new gameover();
                  GO->setlcd1(bird.first()->getPoints());
                  GO->setlcd2(bird.last()->getPoints());
                  GO->show();
                  timer->stop();
                  this->close();

       }

    }
}
}

void MainWindow::animarave()
{
    if (count>=0 && count<=99){
        for(int i=0;i<bird.size();i++)bird.at(i)->setFlag(1);
    }
    if (count>=100 && count<=199){
        for(int i=0;i<bird.size();i++)bird.at(i)->setFlag(2);
    }
    if (count>=200 && count<=299){
        for(int i=0;i<bird.size();i++)bird.at(i)->setFlag(3);
    }
    if (count>=300){
        count=0;
    }
}

void MainWindow::colision()
{   //Colision con avion
    for(int i=0;i<bird.size();i++){
    if(bird.at(i)->collidesWithItem(a.last())){
    scene->removeItem(a.first());
    a.pop_front();
    a.append(new avion(1000,rand()%500+10,-1*dif*100));
    scene->addItem(a.last());
    a.first()->setPos(a.first()->getPx(),a.first()->getPy());
    bird.at(i)->setVidas(bird.at(i)->getVidas()-1);
    }
    //colision insecto
    if(bird.at(i)->collidesWithItem(insect.first())){
    insect.append(new insecto(rand()%700,rand()%500,0,0));
    scene->addItem(insect.last());
    scene->removeItem(insect.first());
    insect.pop_front();
    insect.first()->setPos(insect.first()->getPx(),a.first()->getPy());
    bird.at(i)->setPoints(bird.at(i)->getPoints()+10);
    }
    }
}

void MainWindow::cambiar()//Cambia los aviones
{
    if(dif>1.2 && dif<1.5){
        a.first()->setPixmap(QPixmap(":/new/prefix1/avion2.png").scaled(400/2.5,300/2.5));
    }
    if(dif>1.5 && dif<2){
        a.first()->setPixmap(QPixmap(":/new/prefix1/avion3.png").scaled(400/2.5,300/2.5));
    }
    if(dif>2 && dif<2.5){
        a.first()->setPixmap(QPixmap(":/new/prefix1/avion4.png").scaled(450/2.5,350/2.5));
    }
    if(dif>2.5){
        a.first()->setPixmap(QPixmap(":/new/prefix1/globo.png").scaled(440/2.5,520/2.5));
    }
}

void MainWindow::rebotar()
{
    if(insect.first()->getPy()>alto)insect.first()->setVy(insect.first()->getVy()*-1);
    if(insect.first()->getPy()<0)insect.first()->setVy(insect.first()->getVy()*-1);
    if(insect.first()->getPx()>ancho)insect.first()->setVx(insect.first()->getVx()*-1);
    if(insect.first()->getPx()<0)insect.first()->setVx(insect.first()->getVx()*-1);
}



void MainWindow::on_pushButton_2_clicked()
{
    timer->stop();
    p.show();
    p.datos(bird.first()->getVidas(),bird.first()->getPx(),bird.first()->getPy(),bird.first()->getVx(),
            bird.first()->getVy(),bird.first()->getPoints(),bird.last()->getVidas(),bird.last()->getPx(),bird.last()->getPy(),bird.last()->getVx(),
            bird.last()->getVy(),bird.last()->getPoints(),a.first()->getPx(),a.first()->getPy(),a.first()->getVx(),a.first()->getVy(),
            insect.first()->getPx(),insect.first()->getPy(),insect.first()->getVx(),insect.first()->getVy(),dif);

}
