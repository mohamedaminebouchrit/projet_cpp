#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"personnel.h"
#include<QMessageBox>
#include<QSqlTableModel>
#include<QString>
#include<QDebug>
#include<QSqlRecord>
#include<QIntValidator>
#include<iostream>
#
using namespace std;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->cin->setValidator(new QIntValidator(0,999999,this));

   ui->tab_personnel->setModel(P.afficher());
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_ajouter_clicked()
{QMessageBox msgBox;
    int cin=ui->cin->text().toInt();
    QString nom_personnel=ui->nom->text();
    QString prenom_personnel=ui->prenom->text();
    int num_tel=ui->num->text().toInt();
    QString email=ui->email->text();
    QString adresse=ui->adresse->text();
    Personnel P(cin, nom_personnel, prenom_personnel, num_tel, email,adresse);

    if(P.ajouter()){
        msgBox.setText("Ajout avec succes");
        ui->tab_personnel->setModel(P.afficher());
    }
    else
        msgBox.setText("Echec de l'ajout");
    msgBox.exec();

}

void MainWindow::on_supprimer_clicked()
{
    bool test;
      Personnel P;
    P.setcin(ui->id_supp->text().toInt());
     test=P.supprimer(P.getcin());
     QMessageBox msgBox;
     if(test){
         msgBox.setText("Supprission avec Succes");
         ui->tab_personnel->setModel(P.afficher());
     }
         else
             msgBox.setText("Echec de la supprission");
    msgBox.exec();
}

void MainWindow::on_modifier_clicked()
{
    QMessageBox msgBox;
        int cin=ui->cin->text().toInt();
        QString nom_personnel=ui->nom->text();
        QString prenom_personnel=ui->prenom->text();
        int num_tel=ui->num->text().toInt();
        QString email=ui->email->text();
        QString adresse=ui->adresse->text();
        Personnel P(cin, nom_personnel, prenom_personnel, num_tel, email,adresse);

        if(P.modifier(cin)){
            msgBox.setText("modifié avec succes");
            ui->tab_personnel->setModel(P.afficher());
        }
        else
            msgBox.setText("Echec de la modification");
        msgBox.exec();
}
