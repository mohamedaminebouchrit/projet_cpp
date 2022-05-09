#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "stock.h"
#include "exporttoexcel.h"
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
       ui->tab_personnel->setModel(P.afficheremp());

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

void MainWindow::on_ajouter_clicked()
{
    QMessageBox msgBox;
        int cin=ui->cin->text().toInt();
        QString nom_personnel=ui->nom->text();
        QString prenom_personnel=ui->prenom->text();
        int num_tel=ui->num->text().toInt();
        QString email=ui->email->text();
        QString adresse=ui->adresse->text();
        int salaire=ui->salaire->text().toInt();
        Personnel P(cin, nom_personnel, prenom_personnel, num_tel, email,adresse,salaire);

        if(P.ajouter()){
            msgBox.setText("Ajout avec succes");
        ui->tab_personnel->setModel(P.afficheremp());
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
         ui->tab_personnel->setModel(P.afficheremp());
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
        int salaire=ui->salaire->text().toInt();
        Personnel P(cin, nom_personnel, prenom_personnel, num_tel, email,adresse, salaire);

        if(P.modifier(cin)){
            msgBox.setText("modifié avec succes");
   ui->tab_personnel->setModel(P.afficheremp());
        }
        else
            msgBox.setText("Echec de la modification");
        msgBox.exec();
}

void MainWindow::on_pdf_clicked()
{

}


void MainWindow::on_stat_clicked()
{

}


void MainWindow::stats(QString table,QString critere,int valeur1,int valeur2,QString unite)
{
    QSqlQueryModel * model= new QSqlQueryModel();
    QString valeur1QString=QString::number(valeur1);
    QString valeur2QString=QString::number(valeur2);
                model->setQuery("select * from "+table+" where "+critere+"<"+valeur1QString);
                float countFirst=model->rowCount();
                model->setQuery("select * from "+table+" where " +critere+" between " +valeur1QString+ " and "+valeur2QString);
                float countSecond=model->rowCount();
                model->setQuery("select * from "+table+" where " +critere+">"+valeur2QString);
                float countThird=model->rowCount();
                float total=countFirst+countSecond+countThird;
                QString a=QString("moins de "+valeur1QString+" "+unite+" "+QString::number((countFirst*100)/total,'f',2)+"%" );
                QString b=QString("entre "+valeur1QString+ " et " +valeur2QString+" "+unite+" "+QString::number((countSecond*100)/total,'f',2)+"%" );
                QString c=QString("Plus que "+valeur2QString +" "+unite+" "+QString::number((countThird*100)/total,'f',2)+"%" );
                QPieSeries *series = new QPieSeries();
                series->append(a,countFirst);
                series->append(b,countSecond);
                series->append(c,countThird);
        if (countFirst!=0)
        {QPieSlice *slice = series->slices().at(0);
         slice->setLabelVisible();
         slice->setPen(QPen());}
        if ( countSecond!=0)
        {
                 QPieSlice *slice1 = series->slices().at(1);
                 slice1->setLabelVisible();
        }
       if(countThird!=0)
        {
                 QPieSlice *slice2 = series->slices().at(2);
                 slice2->setLabelVisible();
        }
                QChart *chart = new QChart();
                chart->addSeries(series);
                if(critere=="SALAIRE")
                    critere="salaire";
                chart->setTitle("Pourcentage Par " +critere+":Nombre Des " +table+" :" +QString::number(total));
                chart->legend()->hide();
                QChartView *chartView = new QChartView(chart);
                chartView->setRenderHint(QPainter::Antialiasing);
                chartView->resize(1000,500);
                chartView->show();

}



void MainWindow::on_ath_clicked()
{

}

void MainWindow::on_pb_excel_clicked()
{
QString fileName = QFileDialog::getSaveFileName(this, tr("Exportation en fichier Excel"), qApp->applicationDirPath (),
                                                            tr("Fichiers d'extension Excel (*.xls)"));
            if (fileName.isEmpty())
                return;

            ExportExcelObject obj(fileName, "projet2A", ui->tab_personnel);


            obj.addField(0, "cin", "char(20)");
            obj.addField(1, "nom_personnel", "char(20)");
            obj.addField(2, "prenom_personnel", "char(20)");
            obj.addField(3, "num_tel", "char(20)");
            obj.addField(4, "email", "char(20)");
            obj.addField(5, "adresse", "char(20)");
            obj.addField(6, "salaire", "char(20)");




            int retVal = obj.export2Excel();

            if( retVal > 0)
            {
                QMessageBox::information(this, tr("FAIS!"),
                                         QString(tr("%1 enregistrements exportés!")).arg(retVal)
                                         );
 }           }



void MainWindow::on_cb_tri_client_currentIndexChanged(int index)
{
    if(index==1)
                  ui->tab_personnel->setModel(P.tri_cin());
     else if(index==2)
                  ui->tab_personnel->setModel(P.tri_salaire());

}


void MainWindow::on_le_recherche_client_textChanged(const QString &arg1)
{  if(ui->le_recherche_client->text()!="")
    {
        QString id_ab=ui->le_recherche_client->text();
        ui->tableView_rech->setModel(P.rechercher(id_ab));
    }
     else
         ui->tab_personnel->setModel(P.afficheremp());

}

void MainWindow::on_pb_stat_age_clicked()
{
    stats("Personnel","salaire",1000,3000,"Tunisisedinar");
}


void MainWindow::on_pushButton_4_clicked()
{
    P.genererPDFst();
}
