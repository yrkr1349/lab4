#include "dialog.h"
#include "ui_dialog.h"
#include "stdafx.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_btn0_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text()+"0");
}

void Dialog::on_btn1_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text()+"1");
}

void Dialog::on_btn2_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text()+"2");
}

void Dialog::on_btn3_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text()+"3");
}

void Dialog::on_btn4_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text()+"4");
}

void Dialog::on_btn5_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text()+"5");
}

void Dialog::on_btn6_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text()+"6");
}

void Dialog::on_btn7_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text()+"7");
}

void Dialog::on_btn8_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text()+"8");
}

void Dialog::on_btn9_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text()+"9");
}

void Dialog::on_btnAdd_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text()+"+");
}

void Dialog::on_btnSub_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text()+"-");
}

void Dialog::on_btnMul_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text()+"*");
}

void Dialog::on_btnDiv_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text()+"/");
}

void Dialog::on_btnRes_clicked()
{
    //ui->lineEdit->setText("");
    QString text = ui->lineEdit->text();
    auto resultTuple = Calculator::Calculate(text.toStdString());
            if (std::get<0>(resultTuple))
            {
                double result = std::move(std::get<1>(resultTuple));;
                ui->lineEdit->setText(QString::number(result));
            }
            else
                ui->lineEdit->setText("식이 잘못되었습니다.");
}

void Dialog::on_btnleft_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text()+"(");
}

void Dialog::on_btnRight_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text()+")");
}

void Dialog::on_btnAC_clicked()
{
    ui->lineEdit->setText("");
}

void Dialog::on_btnSqu_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text()+"^");
}
