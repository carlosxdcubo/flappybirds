#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    timer=new QTimer(this);                 //crea el timer
    scene=new QGraphicsScene(this);         //crea la scene
    scene->setSceneRect(0,0,1000,600);       //asigna el rectangulo que encierra la scene, determinado por h_limit y v_limit
    dt=0.01;                                //Delta de tiempo
    ui->graphicsView->setScene(scene);      //Pone la escena en el View
    qDebug()<<ui->graphicsView->size();
    ui->centralWidget->adjustSize();        //ajusta el tamaño
    qDebug()<<ui->centralWidget->size();
    qDebug()<<this->size();
    scene->addRect(scene->sceneRect());     //Dibuja rectas para la escena
    timer->stop();                          //para el timer
    connect(timer,SIGNAL(timeout()),this,SLOT(actualizar()));    //bucle para actualizar posicion
    bird.append(new ave());                 //creo el ave
    bird.first()->setPoint(0,0);        //la coloco en una posición
    bird.first()->setVel(0);                //velocidad =0
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
        bird.first()->actualizar(10,dt);
        bird.first()->mov();
        bird.first()->setPos(bird.last()->getPx(),bird.first()->getPy());
        count++;
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


void MainWindow::on_pushButton_clicked()
{
    timer->start(200*dt);
}
void MainWindow::keyPressEvent(QKeyEvent *ev)
{
    if(ev->key()==Qt::Key_W){
        bird.first()->aletear(true);
    }
}
