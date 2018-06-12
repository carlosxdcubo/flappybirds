#ifndef PAUSE_H
#define PAUSE_H

#include <QWidget>
//#include "mainwindow.h"
#include <fstream>
#include <iostream>
#include <string>


namespace Ui {
class pause;
}

class pause : public QWidget
{
    Q_OBJECT

public:
    explicit pause(QWidget *parent = 0);
    void datos(float n1,float n2,float n3,float n4,float n5,
               float n6,float n7,float n8,float n9,float n10,
               float n11,float n12,float n13,float n14,float n15,
               float n16,float n17,float n18,float n19,float n20,float n21);

    ~pause();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::pause *ui;
    std:: string n_1,n_2,n_3,n_4,n_5,n_6,n_7,n_8,n_9,n_10,
    n_11,n_12,n_13,n_14,n_15,n_16,n_17,n_18,n_19,n_20,n_21;


};

#endif // PAUSE_H
