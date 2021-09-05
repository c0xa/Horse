#ifndef AUTHENTICATIONS_H
#define AUTHENTICATIONS_H

#include <QWidget>
#include "mainwindow.h"

QT_BEGIN_NAMESPACE
namespace Ui {class authentications }
QT_END_NAMESPACE

class authentications : public QWidget
{
    Q_OBJECT

public:
    explicit authentications(QWidget *parent = nullptr);
    ~authentications();

    int aut;
    QString a[3];

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();


private:
    Ui::authentications *ui;

    MainWindow *win;
};


#endif // AVTORIZATION_H
