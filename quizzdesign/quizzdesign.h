#ifndef QUIZZDESIGN_H
#define QUIZZDESIGN_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class quizzdesign; }
QT_END_NAMESPACE

class quizzdesign : public QMainWindow
{
    Q_OBJECT

public:
    quizzdesign(QWidget *parent = nullptr);
    ~quizzdesign();

    // Fonctions
    void SwitchPage(int NumeroPage);



private:
    Ui::quizzdesign *ui;
};
#endif // QUIZZDESIGN_H
