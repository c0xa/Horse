#include "mymodel.h"
#include "database.h"

int createTblHorsesCharacteristics(QSqlQuery stbl)
{
    QString createHorsesCharacter = "CREATE TABLE tblHorsesCharacteristics ("
             "nIndexHors	INTEGER,"
             "name	TEXT NOT NULL UNIQUE,"
             "breed	INTEGER NOT NULL,"
             "gender INTEGER NOT NULL,"
             "nAge	INTEGER NOT NULL,"
             "nGrowth	INTEGER NOT NULL,"
             "nWeight	INTEGER NOT NULL,"
             "suit	INTEGER NOT NULL,"
             "type	INTEGER NOT NULL,"
             "PRIMARY KEY(nIndexHors AUTOINCREMENT),"
             "FOREIGN KEY (suit) "
             "REFERENCES tblSuit (nCode)"
                 "ON DELETE CASCADE "
                 "ON UPDATE NO ACTION,"
             "FOREIGN KEY (type) "
             "REFERENCES tblType (id_type)"
                 "ON DELETE CASCADE "
                 "ON UPDATE NO ACTION,"
            "FOREIGN KEY (breed) "
            "REFERENCES tblBreed (id_breed)"
                "ON DELETE CASCADE "
                "ON UPDATE NO ACTION,"
            "FOREIGN KEY (gender) "
            "REFERENCES tblGender (id_gender)"
                "ON DELETE CASCADE "
                "ON UPDATE NO ACTION"
             ")";
//это проверочка
        if(!stbl.exec(createHorsesCharacter))
        {//exec - выполнить //если запрос не будет выполнен успешно, то  // если вывелось. то такая таблица уже существует

            qDebug() << "error: alredy create tblHorsesCharacteristics";
            return 1; // if error
        }
    qDebug() << "LINE :" <<__LINE__ << "succesful create tblHorsesCharacteristics";
    return 0;
}
int createTblSuit(QSqlQuery stbl)
{
    QString createTblStbl = "CREATE TABLE tblSuit ("
        "nCode	INTEGER NOT NULL,"
        "suit	TEXT UNIQUE,"
        "PRIMARY KEY(nCode AUTOINCREMENT)"
        ")";
//это проверочка
        if(!stbl.exec(createTblStbl))
        {//exec - выполнить //если запрос не будет выполнен успешно, то  // если вывелось. то такая таблица уже существует

            qDebug() << "error: alredy create tblSuit";
            return 1; // if error
        }
    qDebug() << "LINE :" <<__LINE__ << "succesful create tblSuit ";
    return 0;

}
int createTblBreed(QSqlQuery stbl)
{
    QString createTblBreed = "CREATE TABLE tblBreed ("
        "id_breed	INTEGER NOT NULL,"
        "breed	TEXT UNIQUE,"
        "place_origin	TEXT NOT NULL,"
        "nLive	INTEGER NOT NULL,"
        "PRIMARY KEY(id_breed AUTOINCREMENT)"
        ")";
//это проверочка
        if(!stbl.exec(createTblBreed))
        {//exec - выполнить //если запрос не будет выполнен успешно, то  // если вывелось. то такая таблица уже существует

            qDebug() << "error: alredy create tblBreed";
            return 1; // if error
        }
    qDebug() << "LINE :" <<__LINE__ << "succesful create tblBreed ";
    return 0;

}
int createTblGender(QSqlQuery stbl)
{
    QString createTblGender = "CREATE TABLE tblGender ("
        "id_gender	INTEGER NOT NULL, "
        "gender	TEXT UNIQUE, "
        "PRIMARY KEY(id_gender AUTOINCREMENT)"
        ")";
//это проверочка
        if(!stbl.exec(createTblGender))
        {//exec - выполнить //если запрос не будет выполнен успешно, то  // если вывелось. то такая таблица уже существует

            qDebug() << "error: alredy create tblGender";
            return 1; // if error
        }
    qDebug() << "LINE :" <<__LINE__ << "succesful create tblGender";
    return 0;

}
int createTblType(QSqlQuery stbl)
{
    QString createTblType = "CREATE TABLE tblType ("
        "id_type	INTEGER NOT NULL, "
        "type	TEXT UNIQUE,"
        "PRIMARY KEY(id_type AUTOINCREMENT)"
        ")";
//это проверочка
        if(!stbl.exec(createTblType))
        {//exec - выполнить //если запрос не будет выполнен успешно, то  // если вывелось. то такая таблица уже существует

            qDebug() << "error: alredy create tblType";
            return 1; // if error
        }
    qDebug() << "LINE :" <<__LINE__ << "succesful create tblType";
    return 0;

}
int createTblUsers(QSqlQuery stbl)
{
    QString createTblUsers = "CREATE TABLE TblUsers ("
        "id_user	INTEGER  UNIQUE,"
        "login	TEXT UNIQUE,"
        " password TEXT, "
        "PRIMARY KEY(id_user AUTOINCREMENT))";
//это проверочка
        if(!stbl.exec(createTblUsers))
        {//exec - выполнить //если запрос не будет выполнен успешно, то  // если вывелось. то такая таблица уже существует

            qDebug() << "error: alredy create TblUsers";
            return 1; // if error
        }
    qDebug() << "LINE :" <<__LINE__ << "succesful create TblUsers ";
    return 0;

}
int createTblLocalBreed(QSqlQuery stbl)
{
    QString createTblLocalBreed = "CREATE TABLE TblLocalBreed ("
        "id_breed	INTEGER NOT NULL,"
        "breed	TEXT UNIQUE,"
        "place_origin	TEXT NOT NULL,"
        "nLive	INTEGER NOT NULL,"
        "breed_ru	TEXT NOT NULL,"
        "place_ru	TEXT NOT NULL,"
        "breed_eng	TEXT NOT NULL,"
        "place_eng	TEXT NOT NULL"
        ")";
//это проверочка
        if(!stbl.exec(createTblLocalBreed))
        {//exec - выполнить //если запрос не будет выполнен успешно, то  // если вывелось. то такая таблица уже существует

            qDebug() << "error: alredy create TblLocalBreed";
            return 1; // if error
        }
    qDebug() << "LINE :" <<__LINE__ << "succesful create TblLocalBreed ";
    return 0;

}


int insertTablHorse(QSqlQuery prepared_stbl, int id, const QString &name, int breed, int gender, int age, int growth,int weight, int suit, int type)
{
    prepared_stbl.prepare("INSERT INTO tblHorsesCharacteristics (name, breed, gender, nAge, nGrowth, nWeight, suit, type ) VALUES(?, ?, ?, ?, ?, ?, ?, ? )")  ; //сюда передаются параметры, перечисленные ниже в порядке перечисления. кол-во ? = колво перечисленных параметров
    //prepared_stbl.addBindValue(id);
    prepared_stbl.addBindValue(name);
    prepared_stbl.addBindValue(breed);
    prepared_stbl.addBindValue(gender);
    prepared_stbl.addBindValue(age);
    prepared_stbl.addBindValue(growth);
    prepared_stbl.addBindValue(weight);
    prepared_stbl.addBindValue(suit);
    prepared_stbl.addBindValue(type);

    if(!prepared_stbl.exec())                                            //exec - выполнить //если запрос не будет выполнен успешно, то
    {

        qDebug() << "ID :" << id << "In tblHorsescharacteristics DATA EXISTS";    //  если вывелось. то Такие данные вбиты/ запись есть
        return 1;
    }
    qDebug() << " ID :" << id << "In tblHorsescharacteristics succesful";
    return 0;
}
int insertTablSuit(QSqlQuery prepared_stbl, const QString &name)
{
    prepared_stbl.prepare("INSERT INTO tblSuit (suit) VALUES(?)")  ; //сюда передаются параметры, перечисленные ниже в порядке перечисления. кол-во ? = колво перечисленных параметров
    prepared_stbl.addBindValue(name);
    if(!prepared_stbl.exec())                                            //exec - выполнить //если запрос не будет выполнен успешно, то
    {

        qDebug() << "In tblSuit DATA EXISTS";    //  если вывелось. то Такие данные вбиты/ запись есть
        return 0; //1 if error
    }
    qDebug() << "In tblSuit succesful";
    return 0;

}
int insertTblBreed(QSqlQuery prepared_stbl, int id, const QString &name, const QString &homeland, int live)
{
    prepared_stbl.prepare("INSERT INTO tblBreed (id_breed, breed, place_origin, nLive ) VALUES(?, ?, ?, ?)")  ; //сюда передаются параметры, перечисленные ниже в порядке перечисления. кол-во ? = колво перечисленных параметров
    prepared_stbl.addBindValue(id);
    prepared_stbl.addBindValue(name);
    prepared_stbl.addBindValue(homeland);
    prepared_stbl.addBindValue(live);
    if(!prepared_stbl.exec())                                            //exec - выполнить //если запрос не будет выполнен успешно, то
    {

        qDebug() << "In tblBreed DATA EXISTS";    //  если вывелось. то Такие данные вбиты/ запись есть
        return 1; //1 if error
    }
    qDebug() << "In tblBreed succesful";
    return 0;

}
int insertTblGender(QSqlQuery prepared_stbl, int id, const QString &name)
{
    (void)id;
    prepared_stbl.prepare("INSERT INTO tblGender (gender) VALUES(?)")  ; //сюда передаются параметры, перечисленные ниже в порядке перечисления. кол-во ? = колво перечисленных параметров
    prepared_stbl.addBindValue(name);
    if(!prepared_stbl.exec())                                            //exec - выполнить //если запрос не будет выполнен успешно, то
    {
        qDebug() << "In tblGender DATA EXISTS";    //  если вывелось. то Такие данные вбиты/ запись есть
        return 1; //1 if error
    }
    qDebug() << "In tblGender succesful";
    return 0;
}
int insertTblType(QSqlQuery prepared_stbl, int id, const QString &name)
{
    prepared_stbl.prepare("INSERT INTO tblType (id_type, type) VALUES(?, ?)")  ; //сюда передаются параметры, перечисленные ниже в порядке перечисления. кол-во ? = колво перечисленных параметров
    prepared_stbl.addBindValue(id);
    prepared_stbl.addBindValue(name);
    if(!prepared_stbl.exec())                                            //exec - выполнить //если запрос не будет выполнен успешно, то
    {

        qDebug() << "In tblType DATA EXISTS";    //  если вывелось. то Такие данные вбиты/ запись есть
        return 0; //1 if error
    }
    qDebug() << "In tblType succesful";
    return 0;
}
int insertTablUser(QSqlQuery prepared_stbl, const QString &login, const QString &password)
{
    prepared_stbl.prepare("INSERT INTO TblUsers (login, password) VALUES(?, ?)")  ; //сюда передаются параметры, перечисленные ниже в порядке перечисления. кол-во ? = колво перечисленных параметров
    prepared_stbl.addBindValue(login);
    prepared_stbl.addBindValue(password);
    if(!prepared_stbl.exec())                                            //exec - выполнить //если запрос не будет выполнен успешно, то
    {

        qDebug() << "In TblUsers DATA EXISTS";    //  если вывелось. то Такие данные вбиты/ запись есть
        return 0; //1 if error
    }
    qDebug() << "In TblUsers succesful";
    return 0;

}
int insertTblLocalBreed(QSqlQuery prepared_stbl, int id, const QString &name, const QString &homeland,
                        int live, const QString &name_ru, const QString &homeland_ru,
                        const QString &name_eng, const QString &homeland_eng)
{
    prepared_stbl.prepare("INSERT INTO TblLocalBreed (id_breed, breed, place_origin, nLive, breed_ru, place_ru, breed_eng, place_eng  ) VALUES(?, ?, ?, ?, ?, ?, ?, ?)")  ; //сюда передаются параметры, перечисленные ниже в порядке перечисления. кол-во ? = колво перечисленных параметров
    prepared_stbl.addBindValue(id);
    prepared_stbl.addBindValue(name);
    prepared_stbl.addBindValue(homeland);
    prepared_stbl.addBindValue(live);
    prepared_stbl.addBindValue(name_ru);
    prepared_stbl.addBindValue(homeland_ru);
    prepared_stbl.addBindValue(name_eng);
    prepared_stbl.addBindValue(homeland_eng);

    if(!prepared_stbl.exec())                                            //exec - выполнить //если запрос не будет выполнен успешно, то
    {

        qDebug() << "In TblLocalBreed DATA EXISTS";    //  если вывелось. то Такие данные вбиты/ запись есть
        return 1; //1 if error
    }
    qDebug() << "In TblLocalBreed succesful";
    return 0;

}


int enterTbleSuit(QSqlQuery stbl)
{
     if (insertTablSuit(stbl, "gnedoy"))
         return 1;
     if (insertTablSuit(stbl, "voronoy"))
         return 1;
     if (insertTablSuit(stbl, "pegoy"))
         return 1;
     if (insertTablSuit(stbl, "chubaryi"))
         return 1;
     if (insertTablSuit(stbl, "grey"))
         return 1;
     if (insertTablSuit(stbl, "white"))
         return 1;
     if (insertTablSuit(stbl, "red"))
         return 1;
     if (insertTablSuit(stbl, "igrenevyi"))
         return 1;
     if (insertTablSuit(stbl, "savrasyi"))
         return 1;
     if (insertTablSuit(stbl, "kauryi"))
         return 1;
     return 0;
}
int enterTbleBreed(QSqlQuery stbl)
{
     char name1[20] = "non-pendigreed";
     char name2[8] = "arabic";
     char name3[10] = "terskaya";
     char name4[9] = "donskoy";
     char name5[20]= "budennovskaya";
     char name6[20] = "kustanayskaya";
     char name7[14] = "orel trotter";
     char name8[11] = "mezenskaya";
     char name9[20] = "german trotter";
     char name10[7] = "arden";
     char name11[10] = "brabanson";
     char name12[20] = "soviet heavy truck";

     char land1[2] =" ";
     char land2[20] ="Arabian peninsual";
     char land3[5] ="USSR";
     char land4[20] ="Rostov region";
     char land5[20] ="Rostov region";
     char land6[12] ="Kazakhstan";
     char land7[20] ="Russian Empire";
     char land8[20] ="Arkhangelsk region";
     char land9[20] ="Germany";
     char land10[25] ="Belgium, Arden Mountains";
     char land11[20] ="Belgium";
     char land12[5] ="USSR";

     if (insertTblBreed(stbl, 1, name1, land1, 25))
         return 1;
     if (insertTblBreed(stbl, 2, name2, land2, 30))
         return 1;
     if (insertTblBreed(stbl, 3, name3, land3, 25))
         return 1;
     if (insertTblBreed(stbl, 4, name4, land4, 25))
         return 1;
     if (insertTblBreed(stbl, 5, name5, land5, 25))
         return 1;
     if (insertTblBreed(stbl, 6, name6, land6, 20))
         return 1;
     if (insertTblBreed(stbl, 7, name7, land7, 23))
         return 1;
     if (insertTblBreed(stbl, 8, name8, land8, 20))
         return 1;
     if (insertTblBreed(stbl, 9, name9, land9, 23))
         return 1;
     if (insertTblBreed(stbl, 10, name10, land10, 28))
         return 1;
     if (insertTblBreed(stbl, 11, name11, land11, 28))
         return 1;
     if (insertTblBreed(stbl, 12, name12, land12, 25))
         return 1;
     return 0;
}
int enterTblGender(QSqlQuery stbl)
{

     if (insertTblGender(stbl, 1, "Horse"))
         return 1;
     if (insertTblGender(stbl, 2, "Mare"))
         return 1;
     return 0;
}
int enterTblType(QSqlQuery stbl)
{
    char name1[10] = "sledged"; //упряжная
    char name2[8] = "riding"; //верховая
    char name3[10] = "local";
    char name4[9] = "private"; //частная

     if (insertTblType(stbl,1, name1))
         return 1;
     if (insertTblType(stbl,2, name2))
         return 1;
     if (insertTblType(stbl,3, name3))
         return 1;
     if (insertTblType(stbl,4, name4))
     return 0;
}
int enterTblUsers(QSqlQuery stbl)
{

     if (insertTablUser(stbl, "user", "123"))
         return 1;
     if (insertTablUser(stbl, "admin", "456v"))
         return 1;
     return 0;
}
int enterTblLocalBreed(QSqlQuery stbl)
{
    setlocale(LC_ALL, "Russian");

    char name1[20] = "non-pendigreed";
    char name2[8] = "arabic";
    char name3[10] = "terskaya";
    char name4[9] = "donskoy";
    char name5[20]= "budennovskaya";
    char name6[20] = "kustanayskaya";
    char name7[14] = "orel trotter";
    char name8[11] = "mezenskaya";
    char name9[20] = "german trotter";
    char name10[7] = "arden";
    char name11[10] = "brabanson";
    char name12[20] = "soviet heavy truck";

    char land1[2] =" ";
    char land2[20] ="Arabian peninsual";
    char land3[5] ="USSR";
    char land4[20] ="Rostov region";
    char land5[20] ="Rostov region";
    char land6[12] ="Kazakhstan";
    char land7[20] ="Russian Empire";
    char land8[20] ="Arkhangelsk region";
    char land9[20] ="Germany";
    char land10[25] ="Belgium, Arden Mountains";
    char land11[20] ="Belgium";
    char land12[5] ="USSR";

    char nameRu1[30] = "непородистая";  // neporodistaya запись"непородистая"воспринимает как ошибка
    char nameRu2[20] = "арабская";
    char nameRu3[20] = "терская";
    char nameRu4[20] = "донская";
    char nameRu5[25] = "будёновская";
    char nameRu6[30] = "кустанайская";
    char nameRu7[40] = "орловская рысистая";
    char nameRu8[20] = "мезенская";
    char nameRu9[35] = "немецкая рысистая";
    char nameRu10[20] = "арден";
    char nameRu11[20] = "брабансон";
    char nameRu12[40] = "советский тяжеловоз";

    char landRu1[2] = " ";
    char landRu2[50] = "Аравийский полуостров";
    char landRu3[20] = "СССР";
    char landRu4[36] = "Ростовская область";
    char landRu5[36] = "Ростовская область";
    char landRu6[20] = "Казахстан";
    char landRu7[40] = "Российская империя";
    char landRu8[45] = "Архангельская область";
    char landRu9[20] = "Германия";
    char landRu10[35] = "Бельгия, Горы Аpден";
    char landRu11[20] = "Бельгия";
    char landRu12[20] = "СССР";


    if (insertTblLocalBreed(stbl, 1, name1, land1, 25, nameRu1, landRu1, name1, land1))
        return 1;
    if (insertTblLocalBreed(stbl, 2, name2, land2, 30, nameRu2, landRu2, name2, land2))
        return 1;
    if (insertTblLocalBreed(stbl, 3, name3, land3, 25, nameRu3, landRu3, name3, land3))
        return 1;
    if (insertTblLocalBreed(stbl, 4, name4, land4, 25, nameRu4, landRu4, name4, land4))
        return 1;
    if (insertTblLocalBreed(stbl, 5, name5, land5, 25, nameRu5, landRu5, name5, land5))
        return 1;
    if (insertTblLocalBreed(stbl, 6, name6, land6, 20, nameRu6, landRu6, name6, land6))
        return 1;
    if (insertTblLocalBreed(stbl, 7, name7, land7, 23, nameRu7, landRu7, name7, land7))
        return 1;
    if (insertTblLocalBreed(stbl, 8, name8, land8, 20, nameRu8, landRu8, name8, land8))
        return 1;
    if (insertTblLocalBreed(stbl, 9, name9, land9, 23, nameRu9, landRu9, name9, land9))
        return 1;
    if (insertTblLocalBreed(stbl, 10, name10, land10, 28, nameRu10, landRu10, name10, land10))
        return 1;
    if (insertTblLocalBreed(stbl, 11, name11, land11, 28, nameRu11, landRu11, name11, land11))
        return 1;
    if (insertTblLocalBreed(stbl, 12, name12, land12, 25, nameRu12, landRu12, name12, land12))
        return 1;

    return 0;
}



int startDatabase(QSqlQuery stbl)
{
    if (createTblType(stbl))  // это вызов функций
              qDebug() << "error1";   // если функция уже сделала свою работу (тут - создала таблицу в прошлый запуск кода), то в консоль выведется error1
    if (createTblSuit(stbl))  // это вызов функций
          qDebug() << "error2";   // если функция уже сделала свою работу (тут - создала таблицу в прошлый запуск кода), то в консоль выведется error1
    if (createTblBreed(stbl))
      qDebug() << "error3";
    if (createTblGender(stbl))
          qDebug() << "error4";
    if (createTblHorsesCharacteristics(stbl))
          qDebug() << "error5";

    if (createTblLocalBreed(stbl))
          qDebug() << "error900";
    if (enterTblLocalBreed(stbl))
              qDebug() << "error111";

    if (enterTblType(stbl))
          qDebug() << "error6";
    if (enterTbleSuit(stbl))
          qDebug() << "error7";
    if (enterTbleBreed(stbl))
          qDebug() << "error8";
    if (enterTblGender(stbl))
         qDebug() << "error9";
    return 0;
}

int startDatabaseRef(QSqlQuery stbl)
{
    //    if (createTblBreed(stbl))
    //      qDebug() << "error3";
    //    if (enterTbleBreed(stbl))
    //      qDebug() << "error8";
        if (createTblLocalBreed(stbl))
              qDebug() << "error909";
        if (enterTblLocalBreed(stbl))
              qDebug() << "error101";
}
