#ifndef MENU_H
#define MENU_H

#include <QWidget>
#include "mainwindow.h"

namespace Ui {
class menu;
}

class menu : public QWidget
{
    Q_OBJECT

public:
    explicit menu(QWidget *parent = 0);
    MainWindow juego;
    ~menu();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::menu *ui;
};

#endif // MENU_H
