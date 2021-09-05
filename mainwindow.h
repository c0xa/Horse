#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <mymodel.h>
#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QTextEdit>
#include <QMessageBox>
#include <QPushButton>
#include <anketashow.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    Horse _addHorse;
    Horse _changeHorse;
    QString forSort;
    QString forSelect_1;
    QString forSelect_2;
    QString forSel_schet;
    QString forSel_chic;
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
signals:
    void authwin();

private slots:
    void on_pushButton_3_clicked();//кнопка удаления
    void Proverka(MyModel *_model);
    void on_comboBoxGender_activated(const QString &arg1);
    void on_comboBoxType_activated(const QString &arg1);
    void on_comboBoxSiut_activated(const QString &arg1);
    void on_comboBoxBreed_activated(const QString &arg1);
    void on_pushButtonAdd_clicked();
    void on_pushButtonChangeHorse_clicked();
    void on_comboBoxChangeGender_activated(const QString &arg1);
    void on_comboBoxChangeBreed_activated(const QString &arg1);
    void on_comboBoxChangeSuit_activated(const QString &arg1);
    void on_comboBoxChangeType_activated(const QString &arg1);
    void on_comboBoxToSort_activated(const QString &arg1);
    void on_pushButtonToSort_clicked();
    void on_comboBoxToSelect_1_activated(const QString &arg);
    void on_comboBoxToSelect_2_activated(const QString &arg1);
    void on_pushButtonToSelect_clicked();
    void on_PicturesMain_destroyed();
    void on_pushButtonExit_2_clicked();
    void on_pushButtonGoAuthFromMain_clicked();

    void on_pushButtonAnketa_clicked();

private:
    Ui::MainWindow *ui;
    MyModel *_model;
    AnketaShow *vizovAnSh;
};
#endif // MAINWINDOW_H
