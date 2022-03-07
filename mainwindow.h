#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QMainWindow>
#include"personnel.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
  //  void on_ajouter_accepted();

    void on_ajouter_clicked();

    void on_supprimer_clicked();

    void on_modifier_clicked();

private:
    Ui::MainWindow *ui;
    Personnel P;
};

#endif // MAINWINDOW_H
