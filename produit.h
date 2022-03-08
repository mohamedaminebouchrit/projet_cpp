#ifndef PRODUIT_H
#define PRODUIT_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class produit
{
    QString typeprod,nomprod,dateprod,qteprod;
    int idprod;
public:
    produit(){}
    produit(int,QString,QString,QString,QString);
    //Getters
    QString gettypeprod(){return   typeprod;}
    QString getnomprod(){return   nomprod;}
    QString getdateprod(){return   dateprod;}
    QString getqteprod(){return   qteprod;}
    int getidprod (){return idprod;}
    //Setters
    void settypeprod(QString t){typeprod=t;}
    void setnomprod(QString n){nomprod=n;}
    void setdateprod(QString d){dateprod=d;}
    void setqteprod(QString q){qteprod=q;}
    void setidprod (int idprod){this->idprod=idprod;}



    bool ajouterprod();
    QSqlQueryModel * afficherprod();
    bool modifierprod(int idprod,QString typeprod, QString nomprod, QString qteprod);
    bool supprimerprod(int);
    bool  rechercherprod(int id  );
    void genererPDFprod();


};

#endif // PRODUIT_H
