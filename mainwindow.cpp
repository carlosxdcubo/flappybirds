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
    scene->setSceneRect(0,0,800,600);       //asigna el rectangulo que encierra la scene, determinado por h_limit y v_limit
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
    bird.first()->setPoint(100,100);        //la coloco en una posición
    bird.first()->setVel(0);                //velocidad =0
    scene->addItem(bird.first());           //añado el ave a la escena
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::actualizar()
{

        bird.first()->actualizar(-10,dt);

    }
void MainWindow::on_pushButton_clicked()
{
     timer->start(200*dt);
}
