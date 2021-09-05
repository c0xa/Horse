#ifndef REFMODEL_H
#define REFMODEL_H

#include <QString>
#include <QAbstractTableModel>
#include <QtSql>
#include <QMessageBox>

struct Refer{
    int id;
    QString breed;
    QString place;
    int live;
 };

class RefModel:  public QAbstractTableModel
{
    Q_OBJECT
public:
    enum Columns
    {
        cID,
        cBREED,
        cPLACE,
        cLIVE
    };

    RefModel(QObject * parent = nullptr);
    int columnCount(const QModelIndex &parent) const;
    int rowCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;
    void addInfoRef(QSqlQuery stbl, Refer _Refer);
    void enterDataList(int i, QSqlQuery stbl, QString lang);
private:
    QList<Refer> _Refer;
};

#endif // REFMODEL_H
