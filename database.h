#ifndef DATABASE_H
#define DATABASE_H

#include <mymodel.h>
#include <QDebug>
#include <QtSql>
#include <QString>

    int createTblHorsesCharacteristics(QSqlQuery stbl);
    int createTblSuit(QSqlQuery stbl);
    int createTblBreed(QSqlQuery stbl);
    int createTblGender(QSqlQuery stbl);
    int createTblType(QSqlQuery stbl);
    int createTblUsers(QSqlQuery stbl);
    int createTblLocalBreed(QSqlQuery stbl);

    int insertTablHorse(QSqlQuery prepared_stbl, int id, const QString &name,
                        int breed, int gender, int age, int growth,
                        int weight, int suit, int type);
    int insertTablSuit(QSqlQuery prepared_stbl, const QString &name);
    int insertTblBreed(QSqlQuery prepared_stbl, int id, const QString &name,
                      const QString &homeland, int live);
    int insertTblGender(QSqlQuery prepared_stbl, int id, const QString &name);
    int insertTblType(QSqlQuery prepared_stbl, int id, const QString &name);
    int insertTablUser(QSqlQuery prepared_stbl, const QString &login, const QString &password);
    int insertTblLocalBreed(QSqlQuery prepared_stbl, int id, const QString &name, const QString &homeland,
                            int live, const QString &name_ru, const QString &homeland_ru,
                            const QString &name_eng, const QString &homeland_eng);

    int enterTbleSuit(QSqlQuery stbl);
    int enterTbleBreed(QSqlQuery stbl);
    int enterTblGender(QSqlQuery stbl);
    int enterTblType(QSqlQuery stbl);
    int enterTblUsers(QSqlQuery stbl);
    int enterTblLocalBreed(QSqlQuery stbl);

    int startDatabase(QSqlQuery stbl);
    int startDatabaseRef(QSqlQuery stbl);

#endif // DATABASE_H


