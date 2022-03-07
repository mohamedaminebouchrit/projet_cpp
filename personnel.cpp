#include "personnel.h"
#include <QtDebug>
#include <QString>
#include <QSqlQuery>
#include<QObject>
#include<QSqlQueryModel>
Personnel::Personnel()
{
cin=0; nom_personnel=" ";prenom_personnel=" ";num_tel=0;email=" ";adresse=" ";

}

Personnel::Personnel(int cin, QString nom_personnel, QString prenom_personnel,int num_tel, QString email, QString adresse)
{this->cin=cin; this->nom_personnel=nom_personnel;this->prenom_personnel=prenom_personnel; this->num_tel=num_tel; this->email=email; this->adresse=adresse;}
int Personnel::getcin(){return cin;};
QString Personnel::getnom_personnel(){return nom_personnel;}
QString Personnel::getprenom_personnel(){return  prenom_personnel;}
int Personnel::getnum_tel(){return num_tel;}
   QString Personnel::getemail(){return email;}
   QString Personnel::getadresse(){return adresse;}
   void Personnel::setcin(int cin){this->cin=cin;}
   void Personnel::setnom_personnel(QString nom_personnel){this->nom_personnel=nom_personnel;}
   void Personnel::setprenom_personnel(QString prenom_personnel){this->prenom_personnel=prenom_personnel;}
   void Personnel::setnum_tel(int num_tel){this->num_tel=num_tel;}
   void Personnel::setemail(QString email){this->email=email;}
   void Personnel::setadresse(QString adresse){this->adresse=adresse;}

   bool Personnel::ajouter()
   {
   QSqlQuery query;


       query.prepare("INSERT INTO personnel(cin,nom_personnel,prenom_personnel,num_tel,email,adresse) "
                     "VALUES (:cin,:nom_personnel,:prenom_personnel, :num_tel,:email ,:adresse)");
       query.bindValue(":cin",cin);
       query.bindValue(":nom_personnel",nom_personnel);
       query.bindValue(":prenom_personnel",prenom_personnel);
       query.bindValue(":num_tel",num_tel);
     query.bindValue(":email",email);
     query.bindValue(":adresse",adresse);
       return query.exec();

   }

   QSqlQueryModel* Personnel::afficher()
   {
   QSqlQueryModel* model=new QSqlQueryModel();
   model->setQuery("SELECT* FROM personnel");
   model->setHeaderData(0, Qt::Horizontal,QObject::tr("cin"));
   model->setHeaderData(1, Qt::Horizontal,QObject::tr("Nom personnel"));
   model->setHeaderData(2, Qt::Horizontal,QObject::tr("Prénom personnel"));
   model->setHeaderData(3, Qt::Horizontal,QObject::tr("Numero téléphone"));
   model->setHeaderData(4, Qt::Horizontal,QObject::tr("Email"));
   model->setHeaderData(4, Qt::Horizontal,QObject::tr("Adresse"));


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

        query.prepare("UPDATE PERSONNEL SET nom_personnel=:nom_personnel,prenom_personnel=:prenom_personnel,num_tel=:num_tel,email=:email,adresse=:adresse WHERE cin=:cin");

       query.bindValue(":cin",cin);
       query.bindValue(":nom_personnel",nom_personnel);
       query.bindValue(":prenom_personnel",prenom_personnel);
       query.bindValue(":num_tel",num_tel);
     query.bindValue(":email",email);
     query.bindValue(":adresse",adresse);
       return query.exec();

   }


