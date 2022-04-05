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

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_button_tri_clicked();

    void on_Editdispolibprod_textChanged(const QString &arg1);

    void on_pushButton_3_clicked();

private:
    Ui::MainWindow *ui;
  stock st;
    stateduact *stat_edu;
};
#endif // MAINWINDOW_H
