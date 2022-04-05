#ifndef STATEDUACT_H
#define STATEDUACT_H

#include <QDialog>

namespace Ui {
class stateduact;
}

class stateduact : public QDialog
{
    Q_OBJECT

public:
    explicit stateduact(QWidget *parent = nullptr);
    ~stateduact();
    QList<qreal> stat_edu();
    QList <QString> stat_edu_nom();
private:
    Ui::stateduact *ui;
};

#endif // STATEDUACT_H
