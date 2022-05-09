#ifndef PERSONNEL_H
#define PERSONNEL_H
#include <QString>
#include <QChar>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QtCharts>
#include <QChartView>
#include <QPieSeries>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QMessageBox>
#include <QtDebug>
#include <QPainter>
class Personnel
{
public:
    Personnel();
    Personnel(int, QString, QString,int, QString, QString, int);
    int getcin();
     QString getnom_personnel();
      QString getprenom_personnel();
      int getnum_tel();
       QString getemail();
        QString getadresse();
        int get_salaire();
        void setcin(int);
        void setnom_personnel(QString);
        void setprenom_personnel(QString);
        void setnum_tel(int);
        void setemail(QString);
        void setadresse(QString);
        void set_salaire(int);
        bool ajouter();
        bool supprimer(int);
        bool modifier(int);

         QSqlQueryModel* afficherr();
QSqlQueryModel* afficheremp();

         QSqlQueryModel * rechercher(QString );
         QSqlQueryModel * tri_cin();
         QSqlQueryModel * tri_salaire();
         void stats(QString ,QString ,int,int,QString);
         void genererPDFst();


private:
    int cin;
     QString nom_personnel;
     QString prenom_personnel;
     int num_tel;
     QString email;
     QString adresse;
     int salaire;

};

#endif // PERSONNEL_H
