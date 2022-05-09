#include "stateduact.h"
#include "ui_stateduact.h"
#include <QtCharts>
#include <QChartView>
#include <QPieSeries>
#include <QSqlQuery>

stateduact::stateduact(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::stateduact)
{
    ui->setupUi(this);
    QPieSeries *series =new QPieSeries ;

    QList<qreal> list= stat_edu();
     QList<QString> list2=stat_edu_nom();

     for(int i=0 ;i<list.size();i++)
     {
          series->append(list2[i],list[i]);

     }
        QChart *chart =new QChart;
        chart->addSeries(series);
        chart->setTitle("STATS des STOCKS");
         QChartView *chartview= new QChartView(chart);
         chartview->setParent(ui->horizontalFrame);
}


stateduact::~stateduact()
{
    delete ui;
}
QList<qreal> stateduact::stat_edu()
{
    QList<qreal> list ;
    QSqlQuery query;
    query.prepare("select qte,count(qte) from stock group by qte");
    query.exec();
    while(query.next())
    {list.append(query.value(1).toInt());}

    return list;
}

QList<QString> stateduact::stat_edu_nom()
{QList<QString> list ;
    QSqlQuery query;
    query.prepare("select qte,count(qte) from stock group by qte");
    query.exec();
    while(query.next())
    {list.append(query.value(0).toString());}

  return list;

}

