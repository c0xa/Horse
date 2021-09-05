#ifndef CHANGE_H
#define CHANGE_H

#include <QMainWindow>
#include "authentication.h"
#include "reference.h"
//#include <QWidget>
//#include <QMessageBox>

namespace Ui {class change;}

class change : public QMainWindow
{
    Q_OBJECT

public:
    explicit change(QWidget *parent = nullptr); // в примере = 0
    ~change();

private slots:
    void on_pushButtoStartAuthen_clicked();

    void on_pushButtonReference_clicked();
    void on_PicturesChang_destroyed();

private:
    Ui::change *ui;
    Reference *forRef;
    authentication * forAuth;

};

#endif // CHANGE_H
