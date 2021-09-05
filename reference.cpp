#include "reference.h"
#include "ui_reference.h"
#include "refmodel.h"
#include "database.h"

Reference::Reference(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Reference)
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");                  //создали класс QSqlDatabase по имени db
     db.setDatabaseName("StablesProjektSQL.db");
     if(!db.open())                                                           //опрация open булевская; здесь задаём: если не БД нет, то
        {
            qDebug()<< "LINE :" <<__LINE__  << "Something going wrong!";
            return;
        }
     QSqlQuery stbl;

    startDatabaseRef(stbl);

    ui->setupUi(this);
    _moder = new RefModel(this);
    on_PicturesRef_destroyed();
    VvodDate(_moder);

     ui->tableViewReference->setModel(_moder);
}

Reference::~Reference()
{
    delete ui;
}


void Reference::VvodDate(RefModel *_moder)
{
    QSqlQuery stbl;
    stbl.prepare("SELECT COUNT(*) FROM tblBreed ;");//  SELECT id_breed, breed_ru, place_ru, nLive FROM TblLocalBreed;
    stbl.exec();
    stbl.first();
    QString lang = "ru";  // ="eng" // ="ru"
    int i = stbl.value(0).toInt();
    qDebug()<<"sm tut, i ="<<i;

    if (i > 0)
    {
    _moder->enterDataList(i,stbl,lang);
    }
    else
    {
        QMessageBox::warning(this, "Error",
                                      "Database is empty" , QMessageBox::Ok); //выбрать объект измененния в табл
        return;
    }
}
void Reference::on_tableViewReference_activated(const QModelIndex &index)
{

}

void Reference::on_pushButtonExit_1_clicked()
{
    close();
}

void Reference::on_pushButtonGoMenuFromRef_clicked()
{
    this->close();
    emit join();
}

void Reference::on_PicturesRef_destroyed()
{
     QBrush br(QImage(QString::fromUtf8("C:/QT/PROGAU/semestr_6 SQL/Horse/try_picture_2.jpg")));
     QPalette plt = this->palette();
     plt.setBrush(QPalette::Background, br);
     this->setPalette(plt);
}
