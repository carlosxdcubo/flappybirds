#include "pause.h"
#include "ui_pause.h"


pause::pause(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::pause)
{
    ui->setupUi(this);
}

void pause::datos(float n1, float n2, float n3, float n4, float n5,
                  float n6, float n7, float n8, float n9, float n10,
                  float n11, float n12, float n13, float n14, float n15,
                  float n16, float n17, float n18, float n19, float n20,float n21)
{
    n_1=std::to_string(n1);
    n_2=std::to_string(n2);
    n_3=std::to_string(n3);
    n_4=std::to_string(n4);
    n_5=std::to_string(n5);
    n_6=std::to_string(n6);
    n_7=std::to_string(n7);
    n_8=std::to_string(n8);
    n_9=std::to_string(n9);
    n_10=std::to_string(n10);
    n_11=std::to_string(n11);
    n_12=std::to_string(n12);
    n_13=std::to_string(n13);
    n_14=std::to_string(n14);
    n_15=std::to_string(n15);
    n_16=std::to_string(n16);
    n_17=std::to_string(n17);
    n_18=std::to_string(n18);
    n_19=std::to_string(n19);
    n_20=std::to_string(n20);
    n_21=std::to_string(n21);

}

pause::~pause()
{
    delete ui;
}

void pause::on_pushButton_clicked()
{
    this->close();
}

void pause::on_pushButton_2_clicked()
{
    std::ofstream fs;           //Objeto para manejar la lectura del archivo
    fs.open("partida.txt");     //Abre el archivo en modo lectura
    fs<<n_1<<" "<<n_2<<" "<<n_3<<" "<<n_4<<" "<<n_5<<" "<<n_6<<" "<<n_7<<" "<<n_8<<" "<<n_9<<" "<<n_10<<" "<<n_11<<" "<<n_12<<" "<<n_13<<" "
    <<n_14<<" "<<n_15<<" "<<n_16<<" "<<n_17<<" "<<n_18<<" "<<n_19<<" "<<n_20<<" "<<n_21<< std::endl;
    fs.close();

}
