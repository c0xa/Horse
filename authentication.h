#ifndef AUTHENTICATION_H
#define AUTHENTICATION_H

#include <QMainWindow>
#include "mainwindow.h"
//#include "change.h"
#include <QWidget>
#include <QMessageBox>

namespace Ui {class authentication;}

class authentication : public QMainWindow
{
    Q_OBJECT

public:
    explicit authentication(QWidget *parent = nullptr);
    ~authentication();
signals:
    void fion();

private slots:
    void on_EnterProject_clicked();
    void on_ComebakcMenuFromAuth_clicked();
    void on_PicturesAuth_destroyed();

private:
    Ui::authentication *ui;
    MainWindow *win;
};

#endif // AUTHENTICATION_H
