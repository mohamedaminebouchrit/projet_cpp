#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"produit.h"
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
    ui->idprod->setValidator(new QIntValidator(0,999999,this));

   ui->tab_personnel->setModel(P.afficher());
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_bp_ajouter_clicked()
{QMessageBox msgBox;
    int idprod=ui->idprod->text().toInt();
    QString nomprod=ui->nomprod->text();
    QString typeprod=ui->typeprod->text();
    QString dateprod=ui->dateprod->text();
    QString qteprod=ui->qteprod->text();

    produit p (idprod,nomprod,typeprod,dateprod,qteprod);

    if(p.ajouterprod()){
        msgBox.setText("Ajout avec succes");
        ui->tab_produit->setModel(P.afficherprod());
    }
    else
        msgBox.setText("Echec de l'ajout");
    msgBox.exec();

}

void MainWindow::on_bouton_sup_clicked()
{
    bool test;
      produit P;
    p.setidprod(ui->idprod->text());
     test=P.supprimerprod(P.getidprod());
     QMessageBox msgBox;
     if(test){
         msgBox.setText("Produit supprimé avec Succees");
         ui->tab_produit->setModel(P.afficherprod());
     }
         else
             msgBox.setText("Echec de la supprission");
    msgBox.exec();
}

void MainWindow::on_modifier_button_clicked()
{
    QMessageBox msgBox;
    int idprod=ui->idprod->text().toInt();
    QString nomprod=ui->nomprod->text();
    QString typeprod=ui->typeprod->text();
    QString dateprod=ui->dateprod->text();
    QString qteprod=ui->qteprod->text();
        produit p (idprod,nomprod,typeprod,dateprod,qteprod);

        if(p.modifierprod(idprod,typeprod,nomprod,qteprod)){
            msgBox.setText("modifié avec succes");
            ui->tab_produit->setModel(P.afficherprod());
        }
        else
            msgBox.setText("Echec de la modification");
        msgBox.exec();
}
