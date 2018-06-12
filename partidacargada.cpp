#include "partidacargada.h"
#include "ui_partidacargada.h"

partidacargada::partidacargada(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::partidacargada)
{
    ui->setupUi(this);
}

partidacargada::~partidacargada()
{
    delete ui;
}
