#ifndef ANKETASHOW_H
#define ANKETASHOW_H

#include <QMainWindow>

namespace Ui {
class AnketaShow;
}

class AnketaShow : public QMainWindow
{
    Q_OBJECT

public:
    explicit AnketaShow(QWidget *parent = nullptr);
    ~AnketaShow();

private:
    Ui::AnketaShow *ui;
};
#endif // ANKETASHOW_H
