#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "stock.h"
#include <QMainWindow>
#include <QFileDialog>
#include <QtDebug>
#include <QFile>
#include<QMessageBox>
#include<QPainter>
#include<QPdfWriter>
#include "stateduact.h"
#include "personnel.h"
#include "arduino.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_ajouterstock_clicked();

    void on_comboBox_2_idact_currentIndexChanged(int index);

    void on_comboBox_3_idact_currentIndexChanged(int index);

    void on_pushButton_suppract_3_clicked();

    void on_pushButton_ajouteract_2_clicked();

    void on_lineEdit_rech_textChanged(const QString &arg1);

    //void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_button_tri_clicked();

    void on_Editdispolibprod_textChanged(const QString &arg1);

    void on_pushButton_3_clicked();

    void on_ajouter_clicked();

    void on_supprimer_clicked();


    void on_modifier_clicked();


    void on_pdf_clicked();

    void on_stat_clicked();

    void stats(QString,QString,int,int,QString);



    void on_ath_clicked();

    void on_pb_excel_clicked();


    void on_pushButton_clicked();
    void on_cb_tri_client_currentIndexChanged(int index);

    void on_le_recherche_client_textChanged(const QString &arg1);

    void on_pb_stat_age_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::MainWindow *ui;
  stock st;
    stateduact *stat_edu;
      Personnel P;
      QByteArray data; // variable contenant les données reçues
      Arduino A; // objet temporaire
};
#endif // MAINWINDOW_H
