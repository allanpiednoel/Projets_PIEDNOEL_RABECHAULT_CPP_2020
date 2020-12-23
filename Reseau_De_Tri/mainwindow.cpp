#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QLabel>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::TriDesValeurs(){

        QList<int>tableau;

        tableau.append(ui->spinBox->value());
        tableau.append(ui->spinBox_2->value());
        tableau.append(ui->spinBox_3->value());
        tableau.append(ui->spinBox_4->value());

        std::sort(tableau.begin(),tableau.end());
        ui->label->setNum(tableau.value(0));
        ui->label_2->setNum(tableau.value(1));
        ui->label_3->setNum(tableau.value(2));
        ui->label_4->setNum(tableau.value(3));}

void MainWindow::on_pushButton_clicked()
{

    listeValeur.clear();
    listeValeur <<ui->spinBox->value()<<ui->spinBox_2->value()<<ui->spinBox_3->value()<<ui->spinBox_4->value();
    m_scene = new Mon_dessin(this);
    ui->graphicsView->setScene(m_scene);
    TriDesValeurs();
}

void MainWindow::on_pushButton_2_clicked()
{
  //  QMessageBox::information(this,"Reset","Réinitialisation du Réseau de Tri");
    ui->spinBox->setValue(0);
    ui->spinBox_2->setValue(0);
    ui->spinBox_3->setValue(0);
    ui->spinBox_4->setValue(0);

    ui->label->setNum(0);
    ui->label_2->setNum(0);
    ui->label_3->setNum(0);
    ui->label_4->setNum(0);

    MainWindow::on_pushButton_clicked();
}
