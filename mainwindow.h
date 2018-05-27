#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QTimer>
#include <QKeyEvent>
#include "ave.h"
#include "nube.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    //void eliminar();


private slots:
    void actualizar();
    void on_pushButton_clicked();

private:
    int ancho;
    int alto;
    QTimer *timer;              //timer para los intervalos de tiempo entre cada frame
    QGraphicsScene *scene;      //scene que muestra los objetos animados
    float dt;                   //intervalo de tiempo entre frames
    Ui::MainWindow *ui;
    QList<ave*> bird;
    void keyPressEvent(QKeyEvent *ev);
    int count;
    QList<nube*> n1;
    QList<nube*> n2;
    void renovar();
    void chocar();
};

#endif // MAINWINDOW_H
