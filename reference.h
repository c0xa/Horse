#ifndef REFERENCE_H
#define REFERENCE_H

#include <QMainWindow>
#include <refmodel.h>
#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QTextEdit>
#include <QMessageBox>
#include <QPushButton>

namespace Ui {class Reference;}

class Reference : public QMainWindow
{
    Q_OBJECT

public:
    explicit Reference(QWidget *parent = nullptr);
    ~Reference();

signals:
    void join();

private slots:
    void on_tableViewReference_activated(const QModelIndex &index);
    void VvodDate(RefModel *_model);
    void on_pushButtonExit_1_clicked();
    void on_pushButtonGoMenuFromRef_clicked();
    void on_PicturesRef_destroyed();

private:
    Ui::Reference *ui;
    RefModel *_moder;
};

#endif // REFERENCE_H
