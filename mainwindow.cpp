#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mymodel.h"
#include "graphwidget.h"
#include "database.h"
#include "ui_anketashow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::MainWindow)
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");                  //создали класс QSqlDatabase по имени db
    db.setDatabaseName("StablesProjektSQL.db");
    if(!db.open())                                                           //опрация open булевская; здесь задаём: если не БД нет, то
       {
           qDebug()<< "LINE :" <<__LINE__  << "Something going wrong!";
           return;
       }

    ui->setupUi(this);
    _model = new MyModel(this);

     QSqlQuery stbl;
     startDatabase(stbl); //для referenc.ui startDatabaseRef

    Proverka(_model);
    on_PicturesMain_destroyed();
    ui->tableView->setModel(_model);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::Proverka(MyModel *_model)
{
    QSqlQuery stbl;
    stbl.prepare("SELECT COUNT(*) FROM tblHorsesCharacteristics ;");
    stbl.exec();
    stbl.first();
    int i = stbl.value(0).toInt();

    if (i > 0)
    {
        _model->enterDataToList(i, stbl);
    }
    else {
        if (_model->addHorse(stbl, 1, "Rorry", 7, 1, 12, 163, 526, 2, 2) ||
            _model->addHorse(stbl, 2, "Najma", 2, 2, 15, 149, 390, 5, 4) ||
            _model->addHorse(stbl, 3, "Silach", 11, 1, 9, 157, 845, 7, 1) ||
            _model->addHorse(stbl, 4, "Koketka", 1, 2, 4, 97, 220, 3, 3))
            QMessageBox::warning(this, "Error",
                                          "Add horse" , QMessageBox::Ok);
    }
}
void MainWindow::on_pushButton_3_clicked()
{
     QSqlQuery stbl;
    _model->deleteHorse(stbl, ui->tableView->currentIndex().row());
}

void MainWindow::on_pushButtonExit_2_clicked()
{
    close();
}
void MainWindow::on_pushButtonGoAuthFromMain_clicked()
{
    this->close();
    emit authwin();
}

//                               Раздел "Добавит".
void MainWindow::on_comboBoxGender_activated(const QString &arg1)
{
    QString gender = arg1;
    QSqlQuery stbl;
    stbl.prepare("SELECT id_gender FROM tblGender where gender = :row;");
    stbl.bindValue(":row", gender);
    stbl.exec();
    stbl.first();
    MainWindow::_addHorse.gender = stbl.value(0).toInt();
}
void MainWindow::on_comboBoxType_activated(const QString &arg1)
{
    QString type = arg1;
    QSqlQuery stbl;
    stbl.prepare("SELECT id_type FROM tblType where type = :row;");
    stbl.bindValue(":row", type);
    stbl.exec();
    stbl.first();
    MainWindow::_addHorse.type = stbl.value(0).toInt();
}
void MainWindow::on_comboBoxSiut_activated(const QString &arg1)
{
    QString suit = arg1;
    QSqlQuery stbl;
    stbl.prepare("SELECT nCode FROM tblSuit where suit = :row;");
    stbl.bindValue(":row", suit);
    stbl.exec();
    stbl.first();
    MainWindow::_addHorse.suit = stbl.value(0).toInt();
}
void MainWindow::on_comboBoxBreed_activated(const QString &arg1)
{
    QString breed = arg1;
    QSqlQuery stbl;
    stbl.prepare("SELECT id_breed FROM tblBreed where breed = :row;");
    stbl.bindValue(":row", breed);
    stbl.exec();
    stbl.first();
    MainWindow::_addHorse.breed = stbl.value(0).toInt();
}
void MainWindow::on_pushButtonAdd_clicked()
{
    QSqlQuery stbl;

    MainWindow::_addHorse.name = ui->lineEditAddName->text();
    MainWindow::_addHorse.age = ui->lineEditAddAge->text().toInt();
    MainWindow::_addHorse.growth =  ui->lineEditAddGrow->text().toInt();
    MainWindow::_addHorse.weight =  ui->lineEditAddWeight->text().toInt();
    if (_addHorse.name == nullptr || _addHorse.breed == NULL ||
        _addHorse.gender == NULL || _addHorse.age == NULL ||
        _addHorse.growth == NULL || _addHorse.weight == NULL ||
        _addHorse.suit == NULL || _addHorse.type == NULL)
        QMessageBox::warning(this, "Error",
                                      "Fill in all the details" , QMessageBox::Ok);
    else {
       if (_model->addHorse(stbl,  MainWindow::_addHorse))
       {
           QMessageBox::warning(this, "Ошибка",
                                         "Такая лошадь уже существует" , QMessageBox::Ok);
       }
    }
}

//                               Раздел "Изменить".
void MainWindow::on_pushButtonChangeHorse_clicked()
{
    QSqlQuery stbl;

    MainWindow::_changeHorse.name = ui->lineEditChangeName->text();
    MainWindow::_changeHorse.age = ui->lineEditChangeAge->text().toInt();
    MainWindow::_changeHorse.growth =  ui->lineEditChangeGrowth->text().toInt();
    MainWindow::_changeHorse.weight =  ui->lineEditChangeWeight->text().toInt();
    /*qDebug() << _changeHorse.name;
    qDebug() << _changeHorse.breed;
    qDebug() << _changeHorse.gender;
    qDebug() << _changeHorse.age;
    qDebug() << _changeHorse.growth;
    qDebug() << _changeHorse.weight;
    qDebug() << _changeHorse.suit;
    qDebug() << _changeHorse.type;*/
    if (_changeHorse.name == nullptr || _changeHorse.breed == NULL ||
        _changeHorse.gender == NULL || _changeHorse.age == NULL ||
        _changeHorse.growth == NULL || _changeHorse.weight == NULL ||
        _changeHorse.suit == NULL || _changeHorse.type == NULL)
        QMessageBox::warning(this, "Error",
                                      "Fill in all the details" , QMessageBox::Ok);
    else {
        if (_model->changeHorse(stbl,  MainWindow::_changeHorse, ui->tableView->currentIndex().row()))
            QMessageBox::warning(this, "Ошибка",
                                          "Такая лошадь уже существует" , QMessageBox::Ok);
    }
}
void MainWindow::on_comboBoxChangeGender_activated(const QString &arg1)
{
    QString gender = arg1;
    QSqlQuery stbl;
    stbl.prepare("SELECT id_gender FROM tblGender where gender = :row;");
    stbl.bindValue(":row", gender);
    stbl.exec();
    stbl.first();
    MainWindow::_changeHorse.gender = stbl.value(0).toInt();
}
void MainWindow::on_comboBoxChangeBreed_activated(const QString &arg1)
{
    QString breed = arg1;
    QSqlQuery stbl;
    stbl.prepare("SELECT id_breed FROM tblBreed where breed = :row;");
    stbl.bindValue(":row", breed);
    stbl.exec();
    stbl.first();
    MainWindow::_changeHorse.breed = stbl.value(0).toInt();
}
void MainWindow::on_comboBoxChangeSuit_activated(const QString &arg1)
{
    QString suit = arg1;
    QSqlQuery stbl;
    stbl.prepare("SELECT nCode FROM tblSuit where suit = :row;");
    stbl.bindValue(":row", suit);
    stbl.exec();
    stbl.first();
    MainWindow::_changeHorse.suit = stbl.value(0).toInt();
}
void MainWindow::on_comboBoxChangeType_activated(const QString &arg1)
{
    QString type = arg1;
    QSqlQuery stbl;
    stbl.prepare("SELECT id_type FROM tblType where type = :row;");
    stbl.bindValue(":row", type);
    stbl.exec();
    stbl.first();
    MainWindow::_changeHorse.type = stbl.value(0).toInt();
}

//                               Раздел "Сортировка".
void MainWindow::on_comboBoxToSort_activated(const QString &arg1)
{
    MainWindow::forSort = arg1;
    if (arg1 == "кличка")
        MainWindow::forSort = "name";
    else if (arg1 == "возраст")
         MainWindow::forSort = "nAge";
    else if (arg1 == "вес")
         MainWindow::forSort = "nWeight";
    else if (arg1 == "рост")
         MainWindow::forSort = "nGrowth";
}
void MainWindow::on_pushButtonToSort_clicked()
{
     QSqlQueryModel * model = new QSqlQueryModel(0);
     if (MainWindow::forSort == nullptr)
     {
         QMessageBox::warning(this, "Error",
                                       "Select the option to sort" , QMessageBox::Ok); //выбрать объект измененния в табл
         return;
     }
     model->setQuery("SELECT nIndexHors as 'id', a.name as 'Кличка', b.breed as 'Порода', g.gender as 'Пол' , a.nAge as 'Возраст', a.nGrowth as 'Рост (см)', "
                     "a.nWeight as 'Вес (кг)', s.suit as 'Масть', t.type as 'Положение' FROM tblHorsesCharacteristics a "
                     "INNER JOIN tblBreed b ON a.breed = b.id_breed "
                     "INNER JOIN tblGender g ON a.gender = g.id_gender "
                     "INNER JOIN tblSuit s ON a.suit = s.nCode "
                     "INNER JOIN tblType t ON a.type = t.id_type "
                     "order by " + MainWindow::forSort);
     ui->tableViewToSort->setModel(model);
}

//                               Раздел "Выборка".
void MainWindow::on_comboBoxToSelect_1_activated(const QString &arg1)
{
    MainWindow::forSelect_1 = arg1;
    if (arg1 == "порода")
    {
        MainWindow::forSelect_1 = "a.breed";
        MainWindow::forSel_schet = "A";
    }
    else if (arg1 == "пол")
    {
         MainWindow::forSelect_1 = "a.gender";
         MainWindow::forSel_schet = "B";
    }
    else if (arg1 == "масть")
    {
         MainWindow::forSelect_1 = "a.suit";
         MainWindow:: forSel_schet = "C";
    }
    else if (arg1 == "положение")
    {
         MainWindow::forSelect_1 = "a.type";
         MainWindow::forSel_schet = "D";
    }
    else
         MainWindow::forSel_schet = "F";
}

void MainWindow::on_comboBoxToSelect_2_activated(const QString &arg1)
{
    if (MainWindow::forSelect_1 == "a.gender")
    {
        MainWindow::forSelect_2 = arg1;
        MainWindow::forSel_chic = "B";
        if (arg1 == "конь")
             MainWindow::forSelect_2 = "1";
        else if (arg1 == "кобыла")
             MainWindow::forSelect_2 = "2";
        else
            MainWindow::forSel_chic = "P";
    }
    else if (MainWindow::forSelect_1 == "a.breed")
    {
        MainWindow::forSel_chic = "A";
        if (arg1 == "не породистая")
             MainWindow::forSelect_2 = "1";
        else if (arg1 == "арабская")
             MainWindow::forSelect_2 = "2";
        else if (arg1 == "терская")
             MainWindow::forSelect_2 = "3";
        else if (arg1 == "донская")
             MainWindow::forSelect_2 = "4";
        else if (arg1 == "буденовская")
             MainWindow::forSelect_2 = "5";
        else if (arg1 == "кустанайская")
             MainWindow::forSelect_2 = "6";
        else if (arg1 == "орловский рысак")
             MainWindow::forSelect_2 = "7";
        else if (arg1 == "мезенская")
             MainWindow::forSelect_2 = "8";
        else if (arg1 == "немецкая рысистая")
             MainWindow::forSelect_2 = "9";
        else if (arg1 == "арден")
             MainWindow::forSelect_2 = "10";
        else if (arg1 == "брабансон")
             MainWindow::forSelect_2 = "11";
        else if (arg1 == "советский тяжеловоз")
             MainWindow::forSelect_2 = "12";
        else
            MainWindow::forSel_chic = "P";
    }
    else if (MainWindow::forSelect_1 == "a.suit")
    {
        MainWindow::forSel_chic = "C";
        if (arg1 == "гнедой")
             MainWindow::forSelect_2 = "1";
        else if (arg1 == "вороной")
             MainWindow::forSelect_2 = "2";
        else if (arg1 == "пегой")
             MainWindow::forSelect_2 = "3";
        else if (arg1 == "чубарый")
             MainWindow::forSelect_2 = "4";
        else if (arg1 == "серый")
             MainWindow::forSelect_2 = "5";
        else if (arg1 == "белый")
             MainWindow::forSelect_2 = "6";
        else if (arg1 == "рыжий")
             MainWindow::forSelect_2 = "7";
        else if (arg1 == "игреневый")
             MainWindow::forSelect_2 = "8";
        else if (arg1 == "саврасый")
             MainWindow::forSelect_2 = "9";
        else if (arg1 == "каурый")
             MainWindow::forSelect_2 = "10";
        else
            MainWindow::forSel_chic = "P";
    }
    else if (MainWindow::forSelect_1 == "a.type")
    {
        MainWindow::forSel_chic = "D";
        if (arg1 == "упряжная")
             MainWindow::forSelect_2 = "1";
        else if (arg1 == "верховая")
             MainWindow::forSelect_2 = "2";
        else if (arg1 == "местная")
             MainWindow::forSelect_2 = "3";
        else if (arg1 == "частная")
             MainWindow::forSelect_2 = "4";
        else
            MainWindow::forSel_chic = "P";
    }
    else
        MainWindow::forSel_chic = "P";
}
void MainWindow::on_pushButtonToSelect_clicked()
{
    QSqlQueryModel * model = new QSqlQueryModel(0);
    if ((MainWindow::forSelect_1 == nullptr)||(MainWindow::forSelect_2 == nullptr))
    {
        QMessageBox::warning(this, "Error",
                                      "Select ALL options to selection" , QMessageBox::Ok); //выбрать объект измененния в табл
        return;
    }
    model->setQuery("SELECT a.name as 'Кличка', b.breed as 'Порода', g.gender as 'Пол' , a.nAge as 'Возраст', a.nGrowth as 'Рост', "
                    "a.nWeight as 'Вес (кг)', s.suit as 'Масть', t.type as 'Положение' FROM tblHorsesCharacteristics a "
                    "INNER JOIN tblBreed b ON a.breed = b.id_breed "
                    "INNER JOIN tblGender g ON a.gender = g.id_gender "
                    "INNER JOIN tblSuit s ON a.suit = s.nCode "
                    "INNER JOIN tblType t ON a.type = t.id_type "
                    "where " + MainWindow::forSelect_1 + " = '" + MainWindow::forSelect_2 + "'");
    if (MainWindow::forSel_schet != MainWindow::forSel_chic)
    {
        QMessageBox::warning(this, "Error",
                                      "Select the fields correctly" , QMessageBox::Ok); //выбрать объект измененния в табл
        return;
    }
    else  ui->tableViewToSelect->setModel(model);

}

void MainWindow::on_PicturesMain_destroyed()
{
     QBrush br(QImage(QString::fromUtf8(":/Resources/background.jpg")));
     QPalette plt = this->palette();
     plt.setBrush(QPalette::Background, br);
     this->setPalette(plt);
}

void MainWindow::on_pushButtonAnketa_clicked()
{
//    vizovAnSh->show();
//    this->close();
    GraphWidget *widget = new GraphWidget;
    QMainWindow AnketaShow;

    AnketaShow.setCentralWidget(widget);
    AnketaShow.show();
}
