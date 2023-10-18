#include "quizzdesign.h"
#include "ui_quizzdesign.h"
#include "QStackedWidget"

quizzdesign::quizzdesign(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::quizzdesign)
{
    ui->setupUi(this);

    /*
    0: Menu Page
    1: Option Page
    2: Jeu Page
    */

    connect(ui->JouerBtn, &QPushButton::clicked, this, [this]{ SwitchPage(2); });
    connect(ui->OptionBtn, &QPushButton::clicked, this, [this]{ SwitchPage(1); });
    connect(ui->QuitterBtn, &QPushButton::clicked,this,[]{exit(0);});
    connect(ui->ValiderOptionBtn, &QPushButton::clicked, this, [this]{ SwitchPage(0); });

}

quizzdesign::~quizzdesign()
{
    delete ui;
}

void quizzdesign::SwitchPage(int NumeroPage)
{
    ui->stackedWidget->setCurrentIndex(NumeroPage);
}



