#include "mymodel.h"
#include "database.h"

MyModel::MyModel(QObject * parent) : QAbstractTableModel(parent)
{}

int MyModel::columnCount(const QModelIndex &parent) const
{
    (void)parent;
    return 9;
}
int MyModel::rowCount(const QModelIndex &parent) const
{
    (void)parent;
    return _Horse.size();
}


//QVariant MyModel::data(const QModelIndex &index, int role) const
////считывание данных из БД
//{
//    QSqlQuery stbl;
//    if (!index.isValid())
//        return QVariant();
//    if (role == Qt::DisplayRole)
//    {
//        switch(index.column())
//        {
//            case 0:
//                return _Horse[index.row()].id;
//            case 1:
//                return _Horse[index.row()].name;
//            case 2: {
//                stbl.prepare("SELECT * FROM tblBreed WHERE id_breed = :row;");
//                stbl.bindValue(":row", _Horse[index.row()].breed);
//                stbl.exec();
//                stbl.first();
//                return stbl.value(1).toString();
//            }
//            case 3: {
//                stbl.prepare("SELECT * FROM tblGender WHERE id_gender = :row;");
//                stbl.bindValue(":row",  _Horse[index.row()].gender);
//                stbl.exec();
//                stbl.first();
//                return stbl.value(1).toString();
//            }
//            case 4:
//                return _Horse[index.row()].age;
//            case 5:
//                return _Horse[index.row()].growth;
//            case 6:
//                return _Horse[index.row()].weight;
//            case 7: {
//                stbl.prepare("SELECT * FROM tblSuit WHERE nCode = :row;");
//                stbl.bindValue(":row",  _Horse[index.row()].suit);
//                stbl.exec();
//                stbl.first();
//                return stbl.value(1).toString();
//            }
//            case 8: {
//                stbl.prepare("SELECT * FROM tblType WHERE id_type = :row;");
//                stbl.bindValue(":row",  _Horse[index.row()].type);
//                stbl.exec();
//                stbl.first();
//                return stbl.value(1).toString();
//            }
//        }
//    }

//    return QVariant();
//}

QVariant MyModel::data(const QModelIndex &index, int role) const
//считывание данных из БД
{
    QSqlQuery stbl;
    if (!index.isValid())
        return QVariant();
    if (role == Qt::DisplayRole)
    {
        switch(index.column())
        {
            case 0:
                return _Horse[index.row()].id;
            case 1:
                return _Horse[index.row()].name;
            case 2: {

                int arg1 = _Horse[index.row()].breed;
                if (arg1 == 1)
                    return "не породистая";
                if (arg1 == 2)
                    return "арабская";
                if (arg1 == 3)
                    return "терская";
                if (arg1 == 4)
                    return "донская";
                if (arg1 == 5)
                    return "будёновская";
                if (arg1 == 6)
                    return "кустанайская";
                if (arg1 == 7)
                    return "орловская рысистая";
                if (arg1 == 8)
                    return "мезенская";
                if (arg1 == 9)
                    return "немецкая рысистая";
                if (arg1 == 10)
                    return "арден";
                if (arg1 == 11)
                    return "брабансон";
                if (arg1 == 12)
                    return "советский тяжеловоз";
            }
            case 3: {

                int arg1 = _Horse[index.row()].gender;
                if (arg1 == 1)
                    return "конь";
                if (arg1 == 2)
                    return "кобыла";
            }
            case 4:
                return _Horse[index.row()].age;
            case 5:
                return _Horse[index.row()].growth;
            case 6:
                return _Horse[index.row()].weight;
            case 7: {
                int arg1 = _Horse[index.row()].suit;
                if (arg1 == 1)
                    return "гнедой";
                if (arg1 == 2)
                    return "вороной";
                if (arg1 == 3)
                    return "пегой";
                if (arg1 == 4)
                    return "чубарый";
                if (arg1 == 5)
                    return "серый";
                if (arg1 == 6)
                    return "белый";
                if (arg1 == 7)
                    return "рыжий";
                if (arg1 == 8)
                    return "игреневый";
                if (arg1 == 9)
                    return "саврасый";
                if (arg1 == 10)
                    return "каурый";
            }
            case 8: {
                int arg1 = _Horse[index.row()].type;
                if (arg1 == 1)
                    return "упряжная";
                if (arg1 == 2)
                    return "верховая";
                if (arg1 == 3)
                    return "местная";
                if (arg1 == 4)
                    return "частная";
            }
        }
    }

    return QVariant();
}

QVariant MyModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (orientation==Qt::Horizontal)
    {
        if(role==Qt::DisplayRole)
        {
            switch(section)
            {
            case cID:
                return "id";
            case cNAME:
                return "Кличка";
            case cBREED:
                return "Порода";
            case cGENDER:
                return "Пол";
            case cAGE:
                return "Возраст";
            case cGROWTH:
                return "Рост (см)";
            case cWEIGTH:
                return "Вес (кг)";
            case cSUIT:
                return "Масть";
            case cTYPE:
                return "Положение";
            }
        }
    }
    return QAbstractTableModel::headerData(section, orientation, role);
}

int MyModel::addHorse(QSqlQuery stbl, int id, const QString &name, int breed, int gender,
                       int age, int growth, int weight, int suit, int type) //при пустой БД
{
    if (insertTablHorse(stbl, id, name, breed, gender, age, growth, weight, suit, type))
        return 1;
    beginInsertRows(QModelIndex(), _Horse.size(),_Horse.size());
    Horse _a;
    _a.id=id;
    _a.name=name;
    _a.breed=breed;
    _a.gender=gender;
    _a.age=age;
    _a.growth=growth;
    _a.weight=weight;
    _a.suit=suit;
    _a.type=type;
    stbl.prepare("SELECT nIndexHors FROM tblHorsesCharacteristics WHERE name = :row;");
    stbl.bindValue(":row",  _a.name);
    stbl.exec();
    stbl.first();
    qDebug() << "add" << stbl.value(0).toInt();
    _a.id =  stbl.value(0).toInt();
     _Horse.append(_a);
    endInsertRows();
    return 0;
}

int MyModel::addHorse(QSqlQuery stbl, Horse _addHorse)
{
     if (insertTablHorse(stbl, 1, _addHorse.name, _addHorse.breed, _addHorse.gender,
                     _addHorse.age, _addHorse.growth, _addHorse.weight, _addHorse.suit,
                     _addHorse.type))
         return 1;
     beginInsertRows(QModelIndex(), _Horse.size(),_Horse.size());
     stbl.prepare("SELECT nIndexHors FROM tblHorsesCharacteristics WHERE name = :row;");
     stbl.bindValue(":row",  _addHorse.name);
     stbl.exec();
     stbl.first();
     qDebug() << "add" << stbl.value(0).toInt();
     _addHorse.id =  stbl.value(0).toInt();
     _Horse.append(_addHorse);
     endInsertRows();
     return 0;
}

void MyModel::enterDataToList(int i, QSqlQuery stbl) //заполнение Lista данными из БД
{
    stbl.prepare("SELECT * FROM tblHorsesCharacteristics");
    stbl.exec();
    while (stbl.next())
    {
        //stbl.first();
        beginInsertRows(QModelIndex(), _Horse.size(),_Horse.size());
        Horse _a;
        _a.id= stbl.value(0).toInt();
        _a.name = stbl.value(1).toString();
        _a.breed = stbl.value(2).toInt();
        _a.gender = stbl.value(3).toInt();
        _a.age = stbl.value(4).toInt();
        _a.growth = stbl.value(5).toInt();
        _a.weight = stbl.value(6).toInt();
        _a.suit = stbl.value(7).toInt();
        _a.type = stbl.value(8).toInt();
        _Horse.append(_a);
        endInsertRows();
    }
}

void MyModel::deleteHorse(QSqlQuery stbl, int row)
{
    beginRemoveRows(QModelIndex(), row, row);
    if (row < 0)
            return;
    if (!_Horse.size())
        return;
     qDebug()<<_Horse[row].id;
    stbl.prepare("DELETE FROM tblHorsesCharacteristics WHERE nIndexHors = :row;");
    stbl.bindValue(":row", _Horse[row].id);
    stbl.exec();
    _Horse.removeAt(row);
    if (!stbl.exec()) {
        qDebug()<<"Error";}
    else {
        qDebug()<<"Succesful";}
    endRemoveRows();
}

int MyModel::changeHorse(QSqlQuery stbl, Horse _changeHorse, int row)
{
    if (row < 0) {
        return 1;
    }
    stbl.prepare("UPDATE tblHorsesCharacteristics SET name = :name, breed = :breed,  gender = :gender, nAge = :age, nGrowth = :growth, nWeight = :weight, suit = :suit, type = :type   WHERE nIndexHors = :row; ")  ;
    //сюда передаются параметры, перечисленные ниже в порядке перечисления. кол-во ? = колво перечисленных параметров
    stbl.bindValue(":name", _changeHorse.name);
    stbl.bindValue(":breed", _changeHorse.breed);
    stbl.bindValue(":gender", _changeHorse.gender);
    stbl.bindValue(":age", _changeHorse.age);
    stbl.bindValue(":growth", _changeHorse.growth);
    stbl.bindValue(":weight", _changeHorse.weight);
    stbl.bindValue(":suit", _changeHorse.suit);
    stbl.bindValue(":type", _changeHorse.type);
    stbl.bindValue(":row", _Horse[row].id);

    if(!stbl.exec())
    {//exec - выполнить //если запрос не будет выполнен успешно, то  // если вывелось. то такая таблица уже существует

        qDebug() << "error change database";
        return 1; // if error
    }
    qDebug() << "LINE :" <<__LINE__ << "succesful change database";
    _changeHorse.id = _Horse[row].id;
    _Horse[row] = _changeHorse;
    emit dataChanged(index(row, cID), index(row, cNAME));
    return 0;
}

//QString MyModel::serializeXML(int row)
//{
//	QDomDocument document;
//	QDomElement root = document.createElement("CakeDataBase");
//	document.appendChild(root);
//    _Horse[row]
//            _a.id= stbl.value(0).toInt();
//            _a.name = stbl.value(1).toString();
//            _a.breed = stbl.value(2).toInt();
//            _a.gender = stbl.value(3).toInt();
//            _a.age = stbl.value(4).toInt();
//            _a.growth = stbl.value(5).toInt();
//            _a.weight = stbl.value(6).toInt();
//            _a.suit = stbl.value(7).toInt();
//            _a.type = stbl.value(8).toInt();
//	for (CakeAndCandy s: _CakeAndCandy)
//	{
//		QDomElement cakeElement = document.createElement("Cake");
//		QDomElement id = document.createElement("id");
//		id.appendChild(document.createTextNode(QString::number(s.id)));
//		cakeElement.appendChild(id);
//		QDomElement name = document.createElement("Name");
//		name.appendChild(document.createTextNode(s.name));
//		cakeElement.appendChild(name);
//		root.appendChild(cakeElement);
//		}
//	return document.toString();
//}
