#ifndef CALCLAYOUT_H
#define CALCLAYOUT_H

#include <QDialog>
#include <QLineEdit>
#include "Calculator.h"

class calcLayoutDialog : public QDialog
{
    Q_OBJECT

public:
    calcLayoutDialog(QWidget *parent = 0);
private:
    QLineEdit* editText;
    Calculator calc;
    QString lastOper;
public slots:
    void equals();
    void number();
    void operationAdd();
    void operationSub();
    void operationMul();
    void operationDiv();
    void operationSqrt();
    void clear();
signals:
};
#endif // CALCLAYOUT_H
