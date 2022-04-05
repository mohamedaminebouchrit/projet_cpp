#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "stock.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableView_stock->setModel(st.afficherst());
    ui->comboBox_3_idact->setModel(st.afficheroncombost());
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_ajouterstock_clicked()
{
    stock s(ui->lineEdit_idstock->text().toInt(),ui->lineEdit_libprod->text(),ui->lineEdit_qte->text().toInt(),ui->dateEdit_date->text(),ui->lineEdit_desc->text());
       bool test= s.ajouterst();
       ui->tableView_stock->setModel(st.afficherst());
       ui->comboBox_3_idact->setModel(st.afficheroncombost());

}



void MainWindow::on_comboBox_3_idact_currentIndexChanged(int index)
{
    ui->comboBox_3_idact->currentText();
}

void MainWindow::on_pushButton_suppract_3_clicked()
{
    bool test=st.supprimerst(ui->comboBox_3_idact->currentText().toInt());
    if(test)
    {ui->tableView_stock->setModel(st.afficherst());//actualisation taa afficher
            QMessageBox::information(nullptr,QObject::tr("ok"),
                                     QObject::tr("suppression succful .\n"),
                    QMessageBox::Cancel);
        }

        else
            QMessageBox::critical(nullptr,QObject::tr("supprimer not open"),
                                    QObject::tr("click cancel to exist"),
                                    QMessageBox::Cancel);

}

void MainWindow::on_pushButton_ajouteract_2_clicked()
{
    bool    test=st.modifierst(ui->lineEdit_idstock->text().toInt(),ui->lineEdit_libprod->text(),ui->lineEdit_qte->text().toInt(),ui->dateEdit_date->text(),ui->lineEdit_desc->text()) ;
          if (test)
          {
                  ui->tableView_stock->setModel(st.afficherst());
                  ui->comboBox_3_idact->setModel(st.afficheroncombost());
              QMessageBox::information(nullptr,QObject::tr("OK"),
                                   QObject::tr("modification établie"),
                                   QMessageBox::Ok);}
          else{
          QMessageBox::critical(nullptr,QObject::tr("ERROR404"),
                                  QObject::tr("modification non établie"),
                                  QMessageBox::Cancel);}
}

void MainWindow::on_lineEdit_rech_textChanged(const QString &arg1)
{
    QSqlQueryModel *model= new QSqlQueryModel();
            QSqlQuery   *query= new QSqlQuery();
    if(ui->comboBox_crit->currentText()=="idstock"
            ){
        query->prepare("SELECT * FROM stock WHERE idstock LIKE'"+arg1+"%'");//
query->exec();
    model->setQuery(*query);
ui->tableView_stock->setModel(model);


    }
    else {
        if(ui->comboBox_crit->currentText()=="lib_prod"){
            query->prepare("SELECT * FROM stock WHERE lib_prod LIKE'"+arg1+"%'");//+tri
    query->exec();
        model->setQuery(*query);
    ui->tableView_stock->setModel(model);
        }
        else{
            if(ui->comboBox_crit->currentText()=="datee")
                query->prepare("SELECT * FROM stock WHERE datee LIKE'"+arg1+"%'");//+tri
        query->exec();
            model->setQuery(*query);
        ui->tableView_stock->setModel(model);
            }

        }
}

void MainWindow::on_pushButton_clicked()
{
    st.genererPDFst();
}

void MainWindow::on_pushButton_2_clicked()
{
    stat_edu=new stateduact(this);
    stat_edu->show();
}

void MainWindow::on_button_tri_clicked()
{
    QString colone=ui->colone_tri->currentText();
        QString ordre=ui->ordre_tri->currentText();
        stock s;
        ui->tableView_stock->setModel(s.tri(colone,ordre));
}



void MainWindow::on_pushButton_3_clicked()
{bool test;
    test=st.dispo(ui->Editdispolibprod->text());
    if(!test)
    {
        QMessageBox::information(nullptr,QObject::tr("OK"),
                             QObject::tr("non dispo"),
                             QMessageBox::Ok);
    }
}
