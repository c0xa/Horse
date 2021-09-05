#include "refmodel.h"
#include "database.h"

RefModel::RefModel(QObject * parent) : QAbstractTableModel(parent)
{}

int RefModel::columnCount(const QModelIndex &parent) const
{
    (void)parent;
    return 4;
}
int RefModel::rowCount(const QModelIndex &parent) const
{
    (void)parent;
    return _Refer.size();
}

QVariant RefModel::data(const QModelIndex &index, int role) const
{
    QSqlQuery stbl;
    if (!index.isValid())
        return QVariant();
    if (role == Qt::DisplayRole)
    {
        switch(index.column())
        {
        case 0:
            return _Refer[index.row()].id;
        case 1:
        {
            QString arg1 = _Refer[index.row()].breed;
             return arg1;
            /*if (arg1 == "non-pendigreed")
               return "непородистая";
            if (arg1 =="arabic")
               return "арабская";
            if (arg1 == "terskaya")
               return "терская";
            if (arg1 == "donskoy")
               return "донская";
            if (arg1 == "budennovskaya")
               return "будёновская";
            if (arg1 == "kustanayskaya")
               return "кустанайская";
            if (arg1 == "orel trotter")
               return "орловская рысистая";
            if (arg1 == "mezenskaya")
               return "мезенская";
            if (arg1 == "german trotter")
               return "немецкая рысистая";
            if (arg1 == "arden")
               return "арден";
            if (arg1 == "brabanson")
               return "брабансон";
            if (arg1 == "soviet heavy truck")
               return "советский тяжеловоз";*/
            }
        case 2:
        {
            QString arg1 = _Refer[index.row()].place;
             return arg1;
            /*if (arg1 == " ")
               return " ";
            if (arg1 =="Arabian peninsual")
               return arg1;
            if (arg1 == "USSR")
               return "СССР";
            if (arg1 == "Rostov region")
               return "Ростовская область";
            if (arg1 == "Kazakhstan")
               return "Казахстан";
            if (arg1 == "Russian Empire")
               return "Российская империя";
            if (arg1 == "Russian Empire")
               return "Российская империя";
            if (arg1 == "Arkhangelsk region")
               return "Архангельская область";
            if (arg1 == "Germany")
               return "Германия";
            if (arg1 == "Belgium, Arden Mountains")
               return "Бельгия, Горы Арден";
            if (arg1 == "Belgium")
               return "Бельгия";*/
              }
        case 3:
            return _Refer[index.row()].live;
        }
    }
    return QVariant();
}


QVariant RefModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (orientation==Qt::Horizontal)
    {
        if(role==Qt::DisplayRole)
        {
            switch(section)
            {
            case cID:
                return "id";
            case cBREED:
                return "Порода";
            case cPLACE:
                return "Родина";
            case cLIVE:
                return "Период жизни";
            }
        }
    }
    return QAbstractTableModel::headerData(section, orientation, role);
}

void RefModel::addInfoRef(QSqlQuery stbl, Refer _addRefer) //=addHorse
{
        beginInsertRows(QModelIndex(), _Refer.size() , _Refer.size());
        insertTblBreed(stbl, 1, _addRefer.breed, _addRefer.place, _addRefer.live);
        stbl.exec();
        stbl.first();
        qDebug() << "add" << stbl.value(0).toInt();
        _addRefer.id =  stbl.value(0).toInt();
        _Refer.append(_addRefer);
        endInsertRows();

}

void RefModel::enterDataList(int i, QSqlQuery stbl, QString lang) //заполнение Lista данными из БД
{
    if(lang =="ru")
          stbl.prepare("SELECT id_breed, breed_ru, place_ru, nLive FROM TblLocalBreed");
            // stbl.prepare("SELECT * FROM tblBreed"); // SELECT id_breed, breed_ru, place_ru, nLive FROM TblLocalBreed;
    if(lang =="eng")
          stbl.prepare("SELECT id_breed, breed_eng, place_eng, nLive FROM TblLocalBreed");
            stbl.exec();
    while (stbl.next())
    {
         beginInsertRows(QModelIndex(), _Refer.size(), _Refer.size());
         Refer _a;
         _a.id= stbl.value(0).toInt();
         _a.breed = stbl.value(1).toString();
         _a.place = stbl.value(2).toString();
         _a.live = stbl.value(3).toInt();
         _Refer.append(_a);
         endInsertRows();
    }
}
