#include "anketashow.h"
#include "ui_anketashow.h"

AnketaShow::AnketaShow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AnketaShow)
{
    ui->setupUi(this);
}

AnketaShow::~AnketaShow()
{
    delete ui;
}
