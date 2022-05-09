#include "personnel.h"


#include <QSqlQuery>
#include <QtDebug>
#include <QtCharts>
#include <QChartView>
#include <QPieSeries>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QMessageBox>
#include <QDateTime>
\
Personnel::Personnel()
{
cin=0; nom_personnel=" ";prenom_personnel=" ";num_tel=0;email=" ";adresse=" ";salaire=0 ;

}

Personnel::Personnel(int cin, QString nom_personnel, QString prenom_personnel,int num_tel, QString email, QString adresse, int salaire)
{this->cin=cin; this->nom_personnel=nom_personnel;this->prenom_personnel=prenom_personnel; this->num_tel=num_tel; this->email=email; this->adresse=adresse;this->salaire=salaire;}
int Personnel::getcin(){return cin;};
QString Personnel::getnom_personnel(){return nom_personnel;}
QString Personnel::getprenom_personnel(){return  prenom_personnel;}
int Personnel::getnum_tel(){return num_tel;}
   QString Personnel::getemail(){return email;}
   QString Personnel::getadresse(){return adresse;}
   int Personnel::get_salaire(){return salaire;}
   void Personnel::setcin(int cin){this->cin=cin;}
   void Personnel::setnom_personnel(QString nom_personnel){this->nom_personnel=nom_personnel;}
   void Personnel::setprenom_personnel(QString prenom_personnel){this->prenom_personnel=prenom_personnel;}
   void Personnel::setnum_tel(int num_tel){this->num_tel=num_tel;}
   void Personnel::setemail(QString email){this->email=email;}
   void Personnel::setadresse(QString adresse){this->adresse=adresse;}
     void Personnel::set_salaire(int salaire){this->salaire=salaire;}

   bool Personnel::ajouter()
   {
   QSqlQuery query;


       query.prepare("INSERT INTO personnel(cin,nom_personnel,prenom_personnel,num_tel,email,adresse,salaire) "
                     "VALUES (:cin,:nom_personnel,:prenom_personnel, :num_tel,:email ,:adresse ,:salaire )");
       query.bindValue(":cin",cin);
       query.bindValue(":nom_personnel",nom_personnel);
       query.bindValue(":prenom_personnel",prenom_personnel);
       query.bindValue(":num_tel",num_tel);
     query.bindValue(":email",email);
     query.bindValue(":adresse",adresse);
     query.bindValue(":salaire",salaire);
       return query.exec();

   }


  /* QSqlQueryModel* Personnel::afficheremp()

   {

   QSqlQueryModel* model=new QSqlQueryModel();
   model->setQuery("SELECT* FROM personnel");

   return model;
   }
*/
   QSqlQueryModel* Personnel::afficheremp()

     {

     QSqlQueryModel* model=new QSqlQueryModel();
     model->setQuery("SELECT* FROM personnel");

     return model;
     }

   bool Personnel::supprimer(int cin)
   { QSqlQuery query;
       query.prepare("DELETE FROM PERSONNEL WHERE cin=:cin");
       query.bindValue(":cin",cin);

       return query.exec();
   }

  bool Personnel::modifier(int cin)
   {

        QSqlQuery query;

        query.prepare("UPDATE PERSONNEL SET nom_personnel=:nom_personnel,prenom_personnel=:prenom_personnel,num_tel=:num_tel,email=:email,adresse=:adresse,salaire=:salaire WHERE cin=:cin");

       query.bindValue(":cin",cin);
       query.bindValue(":nom_personnel",nom_personnel);
       query.bindValue(":prenom_personnel",prenom_personnel);
       query.bindValue(":num_tel",num_tel);
     query.bindValue(":email",email);
     query.bindValue(":adresse",adresse);
       query.bindValue(":salaire",salaire);
       return query.exec();

   }

  QSqlQueryModel * Personnel::rechercher(QString cin)
   {
   QSqlQueryModel * model= new QSqlQueryModel();

   model->setQuery("SELECT * FROM Personnel WHERE  cin LIKE '%"+cin+"%'" );
   model->setHeaderData(0, Qt::Horizontal,QObject::tr("cin"));
   model->setHeaderData(1, Qt::Horizontal,QObject::tr("Nom personnel"));
   model->setHeaderData(2, Qt::Horizontal,QObject::tr("Prénom personnel"));
   model->setHeaderData(3, Qt::Horizontal,QObject::tr("Numero téléphone"));
   model->setHeaderData(4, Qt::Horizontal,QObject::tr("Email"));
   model->setHeaderData(4, Qt::Horizontal,QObject::tr("Adresse"));
   model->setHeaderData(3, Qt::Horizontal,QObject::tr("Salaire"));


   return model ;
   }

  QSqlQueryModel *Personnel::tri_cin()
   {
       QSqlQueryModel * model=new QSqlQueryModel();

       model->setQuery("select * from  Personnel ORDER BY cin");


       model->setHeaderData(0, Qt::Horizontal,QObject::tr("cin"));
       model->setHeaderData(1, Qt::Horizontal,QObject::tr("Nom personnel"));
       model->setHeaderData(2, Qt::Horizontal,QObject::tr("Prénom personnel"));
       model->setHeaderData(3, Qt::Horizontal,QObject::tr("Numero téléphone"));
       model->setHeaderData(4, Qt::Horizontal,QObject::tr("Email"));
       model->setHeaderData(4, Qt::Horizontal,QObject::tr("Adresse"));
       model->setHeaderData(3, Qt::Horizontal,QObject::tr("Salaire"));

  return model;
   }

   QSqlQueryModel *Personnel::tri_salaire()
   {
       QSqlQueryModel * model=new QSqlQueryModel();

       model->setQuery("select * from  Personnel ORDER BY Salaire");


       model->setHeaderData(0, Qt::Horizontal,QObject::tr("cin"));
       model->setHeaderData(1, Qt::Horizontal,QObject::tr("Nom personnel"));
       model->setHeaderData(2, Qt::Horizontal,QObject::tr("Prénom personnel"));
       model->setHeaderData(3, Qt::Horizontal,QObject::tr("Numero téléphone"));
       model->setHeaderData(4, Qt::Horizontal,QObject::tr("Email"));
       model->setHeaderData(4, Qt::Horizontal,QObject::tr("Adresse"));
       model->setHeaderData(3, Qt::Horizontal,QObject::tr("Salaire"));

  return model;
   }
   void Personnel::stats(QString table,QString critere,int valeur1,int valeur2,QString unite)
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

   void Personnel::genererPDFst()
   {
       QPdfWriter pdf("C:\\Users\\bouchrit\\Desktop\\Atelier_Connexion\\pdf.pdf");
       QPainter painter(&pdf);
      int i = 4000;
           painter.setPen(Qt::green);
           painter.setFont(QFont("Arial", 30));
           painter.drawText(500,700,"Liste Des personnels");
           painter.setPen(Qt::black);
           painter.setFont(QFont("Arial", 25));
           painter.drawRect(100,100,7300,2600);
           painter.drawRect(0,3000,9600,500);
           painter.setFont(QFont("Arial", 9));
           painter.drawText(200,3300,"cin");
           painter.drawText(1300,3300,"nom");
           painter.drawText(2400,3300,"prenom");
              painter.drawText(3500,3300,"num");
                 painter.drawText(4600,3300,"email");
                 painter.drawText(5700,3300,"adresse");
                 painter.drawText(6800,3300,"salaire");

           QSqlQuery query;
           query.prepare("select * from Personnel");
           query.exec();
           while (query.next())
           {
               painter.drawText(200,i,query.value(0).toString());
               painter.drawText(1300,i,query.value(1).toString());
               painter.drawText(2400,i,query.value(2).toString());
               painter.drawText(3500,i,query.value(3).toString());
               painter.drawText(4600,i,query.value(4).toString());
               painter.drawText(5700,i,query.value(5).toString());
               painter.drawText(6800,i,query.value(6).toString());


              i = i + 500;
           }

   }

