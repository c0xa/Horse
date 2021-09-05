#include "change.h"
#include "ui_change.h"
#include <QPainter>

change::change(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::change)
{
    ui->setupUi(this);
    forRef = new Reference;
    connect(forRef, &Reference::join, this, &change::show);
    forAuth = new authentication;
    connect(forAuth, &authentication::fion, this, &change::show);

    on_PicturesChang_destroyed();
}

change::~change()
{
    delete ui;
}

void change::on_pushButtoStartAuthen_clicked()
{

        forAuth->show();
        this->close();


}

void change::on_pushButtonReference_clicked()
{
    forRef->show();
    this->close();
}

void change::on_PicturesChang_destroyed()
{
     QBrush br(QImage(QString::fromUtf8("C:/QT/PROGAU/semestr_6 SQL/Horse/try_picture.jpg")));
     QPalette plt = this->palette();
     plt.setBrush(QPalette::Background, br);
     this->setPalette(plt);
}
