#ifndef PARTIDACARGADA_H
#define PARTIDACARGADA_H

#include <QWidget>

namespace Ui {
class partidacargada;
}

class partidacargada : public QWidget
{
    Q_OBJECT

public:
    explicit partidacargada(QWidget *parent = 0);
    ~partidacargada();

private:
    Ui::partidacargada *ui;
};

#endif // PARTIDACARGADA_H
