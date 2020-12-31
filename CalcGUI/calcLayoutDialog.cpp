#include <QFormLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QMessageBox>
#include <iostream>

using namespace std;
#include "calcLayoutDialog.h"

calcLayoutDialog::calcLayoutDialog(QWidget *parent) : QDialog (parent)
{
    //Create textBox
    editText = new QLineEdit();

    QHBoxLayout* topRow = new QHBoxLayout;
    topRow->addWidget(editText);

    //Create buttons
    QPushButton* btnClear = new QPushButton("C");
    QPushButton* btnZero = new QPushButton("0");
    QPushButton* btnOne = new QPushButton("1");
    QPushButton* btnTwo = new QPushButton("2");
    QPushButton* btnThree = new QPushButton("3");
    QPushButton* btnFour = new QPushButton("4");
    QPushButton* btnFive = new QPushButton("5");
    QPushButton* btnSix = new QPushButton("6");
    QPushButton* btnSeven = new QPushButton("7");
    QPushButton* btnEight = new QPushButton("8");
    QPushButton* btnNine = new QPushButton("9");
    QPushButton* btnAdd = new QPushButton("+");
    QPushButton* btnSubtract = new QPushButton("-");
    QPushButton* btnMultiply = new QPushButton("*");
    QPushButton* btnDivide = new QPushButton("/");
    QPushButton* btnSqrt = new QPushButton("sqrt");
    QPushButton* btnDecimal = new QPushButton(".");
    QPushButton* btnEquals = new QPushButton("=");
    //Set equals button to be able to expand
    btnEquals->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);

    //Add buttons to rows
    QHBoxLayout* secondRow = new QHBoxLayout;
    secondRow->addWidget(btnSeven);
    secondRow->addWidget(btnEight);
    secondRow->addWidget(btnNine);
    secondRow->addWidget(btnAdd);

    QHBoxLayout* thirdRow = new QHBoxLayout;
    thirdRow->addWidget(btnFour);
    thirdRow->addWidget(btnFive);
    thirdRow->addWidget(btnSix);
    thirdRow->addWidget(btnSubtract);

    QHBoxLayout* fourthRow = new QHBoxLayout;
    fourthRow->addWidget(btnOne);
    fourthRow->addWidget(btnTwo);
    fourthRow->addWidget(btnThree);
    fourthRow->addWidget(btnDivide);

    QHBoxLayout* fifthRow = new QHBoxLayout;
    fifthRow->addWidget(btnZero);
    fifthRow->addWidget(btnDecimal);
    fifthRow->addWidget(btnSqrt);
    fifthRow->addWidget(btnMultiply);

    QHBoxLayout* sixthRow = new QHBoxLayout;
    sixthRow->addWidget(btnClear);
    sixthRow->addWidget(btnEquals);

    //Add rows to box layout
    QVBoxLayout* mainLayout = new QVBoxLayout;
    mainLayout->addLayout(topRow);
    mainLayout->addLayout(secondRow);
    mainLayout->addLayout(thirdRow);
    mainLayout->addLayout(fourthRow);
    mainLayout->addLayout(fifthRow);
    mainLayout->addLayout(sixthRow);

    //Create layout
    this->setLayout(mainLayout);

    //Connect buttons to functions
    connect(btnZero, SIGNAL(clicked()), this, SLOT(number()));
    connect(btnOne, SIGNAL(clicked()), this, SLOT(number()));
    connect(btnTwo, SIGNAL(clicked()), this, SLOT(number()));
    connect(btnThree, SIGNAL(clicked()), this, SLOT(number()));
    connect(btnFour, SIGNAL(clicked()), this, SLOT(number()));
    connect(btnFive, SIGNAL(clicked()), this, SLOT(number()));
    connect(btnSix, SIGNAL(clicked()), this, SLOT(number()));
    connect(btnSeven, SIGNAL(clicked()), this, SLOT(number()));
    connect(btnEight, SIGNAL(clicked()), this, SLOT(number()));
    connect(btnNine, SIGNAL(clicked()), this, SLOT(number()));

    connect(btnAdd, SIGNAL(clicked()), this, SLOT(operationAdd()));
    connect(btnSubtract, SIGNAL(clicked()), this, SLOT(operationSub()));
    connect(btnMultiply, SIGNAL(clicked()), this, SLOT(operationMul()));
    connect(btnDivide, SIGNAL(clicked()), this, SLOT(operationDiv()));
    connect(btnSqrt, SIGNAL(clicked()), this, SLOT(operationSqrt()));

    connect(btnDecimal, SIGNAL(clicked()), this, SLOT(number()));

    connect(btnEquals, SIGNAL(clicked()), this, SLOT(equals()));
    connect(btnClear, SIGNAL(clicked()), this, SLOT(clear()));
}

void calcLayoutDialog::number()
{
    QObject* Sender = QObject::sender();

    QPushButton* theBtn = dynamic_cast<QPushButton*>(Sender);
    QString text = editText->text();
    text.append(theBtn->text());
    if (theBtn->text() == '.')
    {
        if (text.contains('.'))
        {
                int count = text.count('.');
                if (count > 1)
                {
                    text.chop(1);
                }
        }
    }

    editText->setText(text);
}

void calcLayoutDialog::clear()
{
    calc.clear();
    editText->setText("");
}

void calcLayoutDialog::operationAdd()
{
    bool ok;
    QObject* Sender = QObject::sender();
    QPushButton* theBtn = dynamic_cast<QPushButton*>(Sender);
    double text = editText->text().toDouble(&ok);
    if (theBtn->text() == '+')
    {
        if (lastOper == '-')
        {
            calc.store(text);
            calc.handleOperation(Calculator::SUBTRACT);
        }
        else if (lastOper == '*')
        {
            calc.store(text);
            calc.handleOperation(Calculator::MULTIPLY);
        }
        else if (lastOper == '/')
        {
            calc.store(text);
            calc.handleOperation(Calculator::DIVIDE);
        }
        else if (lastOper == "sqrt")
        {
            calc.handleOperation(Calculator::SQRT);
        }
        else if (lastOper == '=')
        {
            lastOper = '+';
        }
        else
        {
            calc.store(text);
            editText->setText("");
            calc.handleOperation(Calculator::ADD);
        }
        calc.store(text);
        editText->setText("");
        lastOper = '+';
    }
}

void calcLayoutDialog::operationSub()
{
    bool ok;
    QObject* Sender = QObject::sender();
    QPushButton* theBtn = dynamic_cast<QPushButton*>(Sender);
    double text = editText->text().toDouble(&ok);
    if (theBtn->text() == '-')
    {
        if (lastOper == '+')
        {
            calc.store(text);
            calc.handleOperation(Calculator::ADD);
        }
        else if (lastOper == '*')
        {
            calc.store(text);
            calc.handleOperation(Calculator::MULTIPLY);
        }
        else if (lastOper == '/')
        {
            calc.store(text);
            calc.handleOperation(Calculator::DIVIDE);
        }
        else if (lastOper == "sqrt")
        {
            calc.handleOperation(Calculator::SQRT);
        }
        else if (lastOper == '=')
        {
            lastOper = '-';
        }
        else
        {
            calc.store(text);
            editText->setText("");
            calc.handleOperation(Calculator::SUBTRACT);
        }
        calc.store(text);
        editText->setText("");
        lastOper = '-';
    }

}

void calcLayoutDialog::operationMul()
{
    bool ok;
    QObject* Sender = QObject::sender();
    QPushButton* theBtn = dynamic_cast<QPushButton*>(Sender);
    double text = editText->text().toDouble(&ok);
    QString oper = theBtn->text();
    if (oper == '*')
    {
        if (lastOper == '+')
        {
            calc.store(text);
            calc.handleOperation(Calculator::ADD);
        }
        else if (lastOper == '-')
        {
            calc.store(text);
            calc.handleOperation(Calculator::SUBTRACT);
        }
        else if (lastOper == '/')
        {
            calc.store(text);
            calc.handleOperation(Calculator::DIVIDE);
        }
        else if (lastOper == "sqrt")
        {
            calc.handleOperation(Calculator::SQRT);
        }
        else if (lastOper == '=')
        {
            lastOper = '*';
        }
        else
        {
            calc.store(text);
            editText->setText("");
            calc.handleOperation(Calculator::MULTIPLY);
        }
        calc.store(text);
        editText->setText("");
        lastOper = '*';
    }
}

void calcLayoutDialog::operationDiv()
{
    bool ok;
    QObject* Sender = QObject::sender();
    QPushButton* theBtn = dynamic_cast<QPushButton*>(Sender);
    double text = editText->text().toDouble(&ok);
    QString oper = theBtn->text();
    if (oper == '/')
    {
        if (lastOper == '+')
        {
            calc.store(text);
            calc.handleOperation(Calculator::ADD);
        }
        else if (lastOper == '-')
        {
            calc.store(text);
            calc.handleOperation(Calculator::SUBTRACT);
        }
        else if (lastOper == '*')
        {
            calc.store(text);
            calc.handleOperation(Calculator::MULTIPLY);
        }
        else if (lastOper == "sqrt")
        {
            calc.handleOperation(Calculator::SQRT);
        }
        else if (lastOper == '=')
        {
            lastOper = '/';
        }
        else
        {
            calc.store(text);
            editText->setText("");
            calc.handleOperation(Calculator::DIVIDE);
        }
        calc.store(text);
        editText->setText("");
        lastOper = '/';
    }
}

void calcLayoutDialog::operationSqrt()
{
    bool ok;
    QObject* Sender = QObject::sender();
    QPushButton* theBtn = dynamic_cast<QPushButton*>(Sender);
    double text = editText->text().toDouble(&ok);
    QString oper = theBtn->text();
    if (oper == "sqrt")
    {
        calc.store(text);
        double theSqrt = calc.handleOperation(Calculator::SQRT);
        calc.setNum1(0);
        QString op = QString::number(theSqrt);
        editText->setText(op);
    }
}

void calcLayoutDialog::equals()
{
    bool ok;
    QObject* Sender = QObject::sender();
    QPushButton* theBtn = dynamic_cast<QPushButton*>(Sender);
    double text = editText->text().toDouble(&ok);
    if (theBtn->text() == '=')
    {
        if (lastOper == '=')
        {
            double equal = calc.equalsPressed();
            QString theEqual = QString::number(equal);
            editText->setText(theEqual);
        }
        else
        {
            if (lastOper == '+')
            {
                calc.store(text);
                editText->setText("");
                calc.setOper(Calculator::ADD);
                double equal = calc.handleOperation(Calculator::ADD);
                QString theEqual = QString::number(equal);
                editText->setText(theEqual);
            }
            else if (lastOper == '-')
            {
                calc.store(text);
                editText->setText("");
                calc.setOper(Calculator::SUBTRACT);
                double equal = calc.handleOperation(Calculator::SUBTRACT);
                QString theEqual = QString::number(equal);
                editText->setText(theEqual);
            }
            else if (lastOper == '*')
            {
                calc.store(text);
                editText->setText("");
                calc.setOper(Calculator::MULTIPLY);
                double equal = calc.handleOperation(Calculator::MULTIPLY);
                QString theEqual = QString::number(equal);
                editText->setText(theEqual);
            }
            else if (lastOper == '/')
            {
                calc.store(text);
                editText->setText("");
                calc.setOper(Calculator::DIVIDE);
                double equal = calc.handleOperation(Calculator::DIVIDE);
                QString theEqual = QString::number(equal);
                editText->setText(theEqual);
            }
            else if (lastOper == "sqrt")
            {
                editText->setText("");
                double equal = calc.handleOperation(Calculator::SQRT);
                QString theEqual = QString::number(equal);
                editText->setText(theEqual);
            }
            lastOper = '=';
        }
    }
}
