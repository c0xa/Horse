#include "authentication.h"
#include "ui_authentication.h"
#include "database.h"
#include <QPainter>

authentication::authentication(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::authentication)
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");                  //создали класс QSqlDatabase по имени db
    db.setDatabaseName("StablesProjektSQL.db");
    if(!db.open())                                                           //опрация open булевская; здесь задаём: если не БД нет, то
       {
           qDebug()<< "LINE :" <<__LINE__  << "Something going wrong!";
           return;
       }
    QSqlQuery stbl;
    createTblUsers(stbl);
    enterTblUsers(stbl);

    ui->setupUi(this);
    win = new MainWindow;
    connect(win, &MainWindow::authwin, this, &authentication::show);

    on_PicturesAuth_destroyed();

    ui->lineEdit_1->setText("admin");
    ui->lineEdit_2->setText("456v");


}

authentication::~authentication()
{
    delete ui;
}

void authentication::on_EnterProject_clicked()
{
    QString login;
    QString password;
    login = ui->lineEdit_1->text();
    password = ui->lineEdit_2->text();
    QSqlQuery stbl;
    stbl.prepare("SELECT COUNT(*) FROM TblUsers where password = :p and login = :l;");
    stbl.bindValue(":p", password);
    stbl.bindValue(":l", login);
    stbl.exec();
    stbl.first();
    int i = stbl.value(0).toInt();

    if(i > 0)
    {
        win->show();
        this->close();
    }
    else {
         QMessageBox::warning(this, "Error",
                                       "Wrong login or password" , QMessageBox::Ok);

    }
}

void authentication::on_ComebakcMenuFromAuth_clicked()
{
    this->close();
    emit fion();
}

void authentication::on_PicturesAuth_destroyed()
{
     QBrush br(QImage(QString::fromUtf8(":/Desktop/horse/Resources/background.jpg")));
     QPalette plt = this->palette();
     plt.setBrush(QPalette::Background, br);
     this->setPalette(plt);
}


