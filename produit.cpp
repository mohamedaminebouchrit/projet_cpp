#include "produit.h"
#include<QPainter>
#include<QPdfWriter>

/*produit::produit()
{

}
*/
produit::produit(int idprod,QString catprod, QString nomprod, QString qteprod)
{
this->idprod=idprod;
    this->typeprod=typeprod;
    this->nomprod=nomprod;
    this->dateprod=dateprod;
    this->qteprod=qteprod;

}
bool produit::ajouterprod()
{
QSqlQuery query;
    //QString idprod= QString::number(idprod);
    query.prepare("INSERT INTO PROD (idprod,catprod,qteprod,nomprod,dateprod) "
                        "VALUES (:idprod, :catprod, :qteprod,:nomprod ,:dateprod)");
    query.bindValue(":id",idprod);
    query.bindValue(":catprod",typeprod);
    query.bindValue(":qteprod",qteprod);
    query.bindValue(":nomprod",nomprod);
    query.bindValue(":dateprod",dateprod);



    return    query.exec();

}
QSqlQueryModel * produit ::afficherprod()
{

    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from PROD");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("idprod"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("catprod "));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("qteprod "));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("nomprod "));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("dateprod "));

        return model;
}

bool produit::modifierprod(int idprod,QString typeprod, QString nomprod, QString qteprod)
{

    QSqlQuery query;
//QString idc=QString::number(id);
    query.prepare("UPDATE PROD SET typeprod= :typeprod, nomprod= :nomprod, qteprod= :qteprod, dateprod= :dateprod  where idprod= :idprod ");
    query.bindValue(":id", idprod);
    query.bindValue(":typeprod", typeprod);
    query.bindValue(":nomprod",nomprod);
    query.bindValue(":dateprod",dateprod);
    query.bindValue(":dateprod",qteprod);


            return    query.exec();

}

bool produit :: supprimerprod(int id)
{
    //QString ident1= QString ::number(idd);
    QSqlQuery query;
    query.prepare("Delete from PROD where idprod = :idprod ");
    query.bindValue(":id",id);
    return    query.exec();

}

bool produit::rechercherprod(int idprod)
{

    QSqlQuery query;
               query.prepare("Select * from PROD where ID= :ID");
               query.bindValue(":ID", idprod);
               query.exec();
                QSqlQueryModel * model = new QSqlQueryModel();
              model->setQuery(query);
              if(model->rowCount() == 0){ return false;}
           return  true;


}





