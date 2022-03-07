#ifndef PERSONNEL_H
#define PERSONNEL_H
#include<QString>
#include<QDate>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include<QDebug>
#include<QString>
#include<QTableView>
class Personnel
{
public:
    Personnel();
    Personnel(int, QString, QString,int, QString, QString);
    int getcin();
     QString getnom_personnel();
      QString getprenom_personnel();
      int getnum_tel();
       QString getemail();
        QString getadresse();
        void setcin(int);
        void setnom_personnel(QString);
        void setprenom_personnel(QString);
        void setnum_tel(int);
        void setemail(QString);
        void setadresse(QString);
        bool ajouter();
        bool supprimer(int);
        bool modifier(int);
         QSqlQueryModel* afficher();
private:
    int cin;
     QString nom_personnel;
     QString prenom_personnel;
     int num_tel;
     QString email;
     QString adresse;

};

#endif // PERSONNEL_H
