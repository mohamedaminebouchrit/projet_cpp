#ifndef STOCK_H
#define STOCK_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class stock
{
    QString lib_prod,datee,description;
    int idstock,qte;
public:
    stock(){}
    stock(int,QString,int,QString,QString);


    bool ajouterst();
    QSqlQueryModel * afficherst();
    bool modifierst(int idstock,QString lib_prod,int qte,QString datee,QString description);
    QSqlQueryModel * afficheroncombost();
    bool  rechercherst(int id);
    QSqlQueryModel * trides();
       QSqlQueryModel * triasc();

QSqlQueryModel* tri(QString,QString);
    bool supprimerst(int);
    void genererPDFst();
      QString showoldst(QString);
      bool dispo(QString lib_prod);
};

#endif // STOCK_H
