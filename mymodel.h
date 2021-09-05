#ifndef MYMODEL_H
#define MYMODEL_H

#include <QString>
#include <QAbstractTableModel>
#include <QtSql>
#include <QMessageBox>
#include <QDomNode>
#include <QMessageBox>
#include <QDomElement>
#include <QKeyEvent>
#include <QGraphicsTextItem>
#include <QRandomGenerator>
#include <QFile>

struct Horse{
    int id;
    QString name;
    int breed;
    int gender;
    int age;
    int growth;
    int weight;
    int suit;
    int type;
};

class MyModel: public QAbstractTableModel
{
     Q_OBJECT
public:
    enum Columns  // enum - это тип, use в case
    {
        cID,
        cNAME,
        cBREED,
        cGENDER,
        cAGE,
        cGROWTH,
        cWEIGTH,
        cSUIT,
        cTYPE
    };
MyModel(QObject * parent = nullptr);
    int columnCount(const QModelIndex &parent) const; //возвращ колво столбцов
    int rowCount(const QModelIndex &parent) const;  //возвращ колво строк
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;
    int addHorse(QSqlQuery stbl, int id, const QString &name, int breed,int gender,
                           int age, int growth, int weight, int suit, int type);
    void deleteHorse(QSqlQuery stbl, int row);
    int changeHorse(QSqlQuery stbl, Horse _changeHorse, int row);
    void enterDataToList(int i, QSqlQuery stbl);
    int addHorse(QSqlQuery stbl, Horse _addHorse);
//    QString serializeXML(int row);
private:
    QList<Horse> _Horse;
};
#endif // MYMODEL_H
