/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QGridLayout *gridLayout;
    QFrame *line;
    QPushButton *btn4;
    QPushButton *btn6;
    QPushButton *btn2;
    QPushButton *btn8;
    QLineEdit *lineEdit;
    QPushButton *btn5;
    QPushButton *btn7;
    QPushButton *btn9;
    QPushButton *btn1;
    QPushButton *btn3;
    QPushButton *btn0;
    QPushButton *btnleft;
    QPushButton *btnRight;
    QPushButton *btnAC;
    QPushButton *btnRes;
    QPushButton *btnAdd;
    QPushButton *btnSub;
    QPushButton *btnMul;
    QPushButton *btnDiv;
    QPushButton *btnSqu;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QStringLiteral("Dialog"));
        Dialog->resize(356, 262);
        gridLayout = new QGridLayout(Dialog);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        line = new QFrame(Dialog);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line, 1, 0, 1, 4);

        btn4 = new QPushButton(Dialog);
        btn4->setObjectName(QStringLiteral("btn4"));

        gridLayout->addWidget(btn4, 4, 0, 1, 1);

        btn6 = new QPushButton(Dialog);
        btn6->setObjectName(QStringLiteral("btn6"));

        gridLayout->addWidget(btn6, 4, 2, 1, 1);

        btn2 = new QPushButton(Dialog);
        btn2->setObjectName(QStringLiteral("btn2"));

        gridLayout->addWidget(btn2, 5, 1, 1, 1);

        btn8 = new QPushButton(Dialog);
        btn8->setObjectName(QStringLiteral("btn8"));

        gridLayout->addWidget(btn8, 3, 1, 1, 1);

        lineEdit = new QLineEdit(Dialog);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        gridLayout->addWidget(lineEdit, 0, 0, 1, 4);

        btn5 = new QPushButton(Dialog);
        btn5->setObjectName(QStringLiteral("btn5"));

        gridLayout->addWidget(btn5, 4, 1, 1, 1);

        btn7 = new QPushButton(Dialog);
        btn7->setObjectName(QStringLiteral("btn7"));

        gridLayout->addWidget(btn7, 3, 0, 1, 1);

        btn9 = new QPushButton(Dialog);
        btn9->setObjectName(QStringLiteral("btn9"));

        gridLayout->addWidget(btn9, 3, 2, 1, 1);

        btn1 = new QPushButton(Dialog);
        btn1->setObjectName(QStringLiteral("btn1"));

        gridLayout->addWidget(btn1, 5, 0, 1, 1);

        btn3 = new QPushButton(Dialog);
        btn3->setObjectName(QStringLiteral("btn3"));

        gridLayout->addWidget(btn3, 5, 2, 1, 1);

        btn0 = new QPushButton(Dialog);
        btn0->setObjectName(QStringLiteral("btn0"));

        gridLayout->addWidget(btn0, 6, 1, 1, 1);

        btnleft = new QPushButton(Dialog);
        btnleft->setObjectName(QStringLiteral("btnleft"));

        gridLayout->addWidget(btnleft, 2, 0, 1, 1);

        btnRight = new QPushButton(Dialog);
        btnRight->setObjectName(QStringLiteral("btnRight"));

        gridLayout->addWidget(btnRight, 2, 1, 1, 1);

        btnAC = new QPushButton(Dialog);
        btnAC->setObjectName(QStringLiteral("btnAC"));

        gridLayout->addWidget(btnAC, 2, 2, 1, 1);

        btnRes = new QPushButton(Dialog);
        btnRes->setObjectName(QStringLiteral("btnRes"));

        gridLayout->addWidget(btnRes, 6, 2, 1, 1);

        btnAdd = new QPushButton(Dialog);
        btnAdd->setObjectName(QStringLiteral("btnAdd"));

        gridLayout->addWidget(btnAdd, 6, 3, 1, 1);

        btnSub = new QPushButton(Dialog);
        btnSub->setObjectName(QStringLiteral("btnSub"));

        gridLayout->addWidget(btnSub, 5, 3, 1, 1);

        btnMul = new QPushButton(Dialog);
        btnMul->setObjectName(QStringLiteral("btnMul"));

        gridLayout->addWidget(btnMul, 4, 3, 1, 1);

        btnDiv = new QPushButton(Dialog);
        btnDiv->setObjectName(QStringLiteral("btnDiv"));

        gridLayout->addWidget(btnDiv, 3, 3, 1, 1);

        btnSqu = new QPushButton(Dialog);
        btnSqu->setObjectName(QStringLiteral("btnSqu"));

        gridLayout->addWidget(btnSqu, 2, 3, 1, 1);


        retranslateUi(Dialog);

        btn0->setDefault(true);


        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "calc", Q_NULLPTR));
        btn4->setText(QApplication::translate("Dialog", "4", Q_NULLPTR));
        btn6->setText(QApplication::translate("Dialog", "6", Q_NULLPTR));
        btn2->setText(QApplication::translate("Dialog", "2", Q_NULLPTR));
        btn8->setText(QApplication::translate("Dialog", "8", Q_NULLPTR));
        btn5->setText(QApplication::translate("Dialog", "5", Q_NULLPTR));
        btn7->setText(QApplication::translate("Dialog", "7", Q_NULLPTR));
        btn9->setText(QApplication::translate("Dialog", "9", Q_NULLPTR));
        btn1->setText(QApplication::translate("Dialog", "1", Q_NULLPTR));
        btn3->setText(QApplication::translate("Dialog", "3", Q_NULLPTR));
        btn0->setText(QApplication::translate("Dialog", "0", Q_NULLPTR));
        btnleft->setText(QApplication::translate("Dialog", "(", Q_NULLPTR));
        btnRight->setText(QApplication::translate("Dialog", ")", Q_NULLPTR));
        btnAC->setText(QApplication::translate("Dialog", "AC", Q_NULLPTR));
        btnRes->setText(QApplication::translate("Dialog", "=", Q_NULLPTR));
        btnAdd->setText(QApplication::translate("Dialog", "+", Q_NULLPTR));
        btnSub->setText(QApplication::translate("Dialog", "-", Q_NULLPTR));
        btnMul->setText(QApplication::translate("Dialog", "*", Q_NULLPTR));
        btnDiv->setText(QApplication::translate("Dialog", "/", Q_NULLPTR));
        btnSqu->setText(QApplication::translate("Dialog", "^", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
