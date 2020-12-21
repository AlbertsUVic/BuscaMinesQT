#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    cont=0;
    pols=false;

    ui->setupUi(this);

    QTimer *time=new QTimer(this);
    connect(ui->Botoprova, SIGNAL(clicked()), this, SLOT(True()));
    connect(time, SIGNAL(timeout()), this, SLOT(Contador()));
    time->start(1000);


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::True(){
    if (pols==true){
        pols=false;
    }
    else{
        pols=true;
    }
}

void MainWindow:: Contador(){
    if(pols==true){
        ui->Temps->display(cont);
        cont++;
        if(cont>999){
            cont=0;
            //afegir missatge GAME OVER
        }
    }

}

