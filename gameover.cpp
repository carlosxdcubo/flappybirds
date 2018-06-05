#include "gameover.h"
#include "ui_gameover.h"
#include "mainwindow.h"

gameover::gameover(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::gameover)
{
    ui->setupUi(this);

}

gameover::~gameover()
{
    delete ui;
}

void gameover::setlcd1(int a)
{
    ui->lcdNumber->display(a);
}

void gameover::setlcd2(int a)
{
    ui->lcdNumber_2->display(a);
}
