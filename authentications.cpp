#include "authentications.h"
#include "ui_authentications.h"
#include <QTextStream>

authentications::authentications(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::authentications)
{
    ui->setupUi(this);
    win = new MainWindow;
    connect(win, &MainWindow::authwin, this, &authentications::show);

    ui->lineEdit->setText("test");
    ui->lineEdit_2->setText("test");


}

authentications::~authentications()
{
    delete ui;
}

void authentications::on_pushButton_2_clicked()
{
    QString login;
    QString Password;
    login = ui->lineEdit->text();
    Password = ui->lineEdit_2->text();
    if(login=="test" && Password=="test")
    {
        win->show();
        this->close();
    }
    else qWarning("Неправильный логин или пароль!");
}

void authentications::on_pushButton_clicked()
{
    close();
}
