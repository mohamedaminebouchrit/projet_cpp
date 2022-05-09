#include "stock.h"
#include<QPainter>
#include<QPdfWriter>
#include <QMessageBox>
stock::stock(int idstock,QString lib_prod,int qte,QString datee,QString description)
{
    this->idstock=idstock;
        this->lib_prod=lib_prod;
        this->qte=qte;
        this->datee=datee;
        this->description=description;
}
bool stock::ajouterst()
{
QSqlQuery query;
    //QString id= QString::number(ID);
    query.prepare("INSERT INTO STOCK (idstock,lib_prod,qte,datee,description) "
                        "VALUES (:idstock, :lib_prod, :qte,:datee ,:description)");
    query.bindValue(":idstock",idstock);
    query.bindValue(":lib_prod",lib_prod);
    query.bindValue(":qte",qte);
    query.bindValue(":datee",datee);
    query.bindValue(":description",description);



    return    query.exec();

}
QSqlQueryModel * stock ::afficherst()
{

    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from stock");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("idstock"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("lib_prod "));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("qte "));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("datee "));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("description "));

        return model;
}

bool stock::modifierst(int idstock,QString lib_prod,int qte,QString datee,QString description)
{

    QSqlQuery query;
//QString idc=QString::number(id);
    query.prepare("UPDATE STOCK SET lib_prod= :lib_prod, qte= :qte, datee= :datee, description= :description where idstock= :idstock ");
    query.bindValue(":idstock", idstock);
    query.bindValue(":lib_prod", lib_prod);
    query.bindValue(":qte",qte);
    query.bindValue(":datee",datee);
    query.bindValue(":description",description);

            return    query.exec();

}
QSqlQueryModel * stock ::afficheroncombost()
{

    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from STOCK");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("idstock"));

        return model;
}

bool stock :: supprimerst(int idstock)
{
    //QString ident1= QString ::number(idd);
    QSqlQuery query;
    query.prepare("Delete from STOCK where idstock = :idstock ");
    query.bindValue(":idstock",idstock);
    return    query.exec();

}
QSqlQueryModel* stock::trides()
{
    QSqlQueryModel * model= new QSqlQueryModel();
        model->setQuery("select * from STOCK order by prix DESC");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("idstock"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("lib_prod "));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("qte "));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("datee "));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("description "));


            return model;
}

QSqlQueryModel * stock::triasc()
{
    QSqlQueryModel * model= new QSqlQueryModel();
       model->setQuery("select * from STOCK order by prix ASC");
       model->setHeaderData(0, Qt::Horizontal, QObject::tr("idstock"));
       model->setHeaderData(1, Qt::Horizontal, QObject::tr("lib_prod "));
       model->setHeaderData(2, Qt::Horizontal, QObject::tr("qte "));
       model->setHeaderData(3, Qt::Horizontal, QObject::tr("datee "));
       model->setHeaderData(4, Qt::Horizontal, QObject::tr("description "));

           return model;
}

void stock::genererPDFst()
{
    QPdfWriter pdf("C:\\Users\\hedia\\OneDrive\\Bureau\\pdf.pdf");
    QPainter painter(&pdf);
   int i = 4000;
        painter.setPen(Qt::green);
        painter.setFont(QFont("Arial", 50));
        painter.drawText(1100,1200,"Liste Des stocks");
        painter.setPen(Qt::red);
        painter.setFont(QFont("Arial", 15));
        painter.drawRect(100,100,7300,2600);
        painter.drawRect(0,3000,9600,500);
        painter.setFont(QFont("Arial", 9));
        painter.drawText(200,3300,"id stock");
        painter.drawText(1300,3300,"lib_prod");
        painter.drawText(2400,3300,"qte");
           painter.drawText(3500,3300,"date");
              painter.drawText(4600,3300,"description");

        QSqlQuery query;
        query.prepare("select * from stock");
        query.exec();
        while (query.next())
        {
            painter.drawText(200,i,query.value(0).toString());
            painter.drawText(1300,i,query.value(1).toString());
            painter.drawText(2400,i,query.value(2).toString());
            painter.drawText(3500,i,query.value(3).toString());
            painter.drawText(4600,i,query.value(4).toString());


           i = i + 500;
        }

}

QSqlQueryModel*  stock::tri(QString colone, QString ordre)
{
QSqlQueryModel* model=new QSqlQueryModel();
model->setQuery("select * from stock order by "+colone+" "+ordre+"");
return model;
}

bool stock::dispo(QString lib_prod)
{
    QSqlQuery query;
    QByteArray mot=lib_prod.toLatin1();
               query.prepare("Select * from stock where lib_prod= :lib_prod");
               query.bindValue(":lib_prod", lib_prod);
               query.exec();
                QSqlQueryModel * model = new QSqlQueryModel();
              model->setQuery(query);
              if(model->rowCount() == 0){
                  return false;
                  QMessageBox::information(nullptr,QObject::tr("OK"),
                                       QObject::tr(mot+" :non dispo"),
                                       QMessageBox::Ok);


              }
              QMessageBox::information(nullptr,QObject::tr("OK"),
                                   QObject::tr(mot+" :disponible"),
                                   QMessageBox::Ok);//thabet e requete ili b3thetha el SQL heki el 7aja mawjouda wala la
           return  true;
}
