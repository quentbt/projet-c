#include "quizzdesign.h"
#include "ui_quizzdesign.h"
#include "QStackedWidget"
#include "fonction.h"

#include <qDebug>






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
    connect(ui->RadioBtnQ1, &QRadioButton::clicked, this, &quizzdesign::ActiveValidBtn);
    connect(ui->RadioBtnQ2, &QRadioButton::clicked, this, &quizzdesign::ActiveValidBtn);
    connect(ui->RadioBtnQ3, &QRadioButton::clicked, this, &quizzdesign::ActiveValidBtn);
    connect(ui->RadioBtnQ4, &QRadioButton::clicked, this, &quizzdesign::ActiveValidBtn);
    connect(ui->ValiderReponseBtn, &QPushButton::clicked,this, &quizzdesign::ChangeQuestion);

    ui->ValiderReponseBtn->setEnabled(false);
    ui->InvisibleRadioButton->hide();



    qDebug() << jeu.listeMatiere[1]->nom;

}

quizzdesign::~quizzdesign()
{
    delete ui;
}

void quizzdesign::SwitchPage(int NumeroPage)
{
    ui->stackedWidget->setCurrentIndex(NumeroPage);
}

void quizzdesign::ActiveValidBtn()
{
    if(!ui->ValiderReponseBtn->isEnabled())
    {
        ui->ValiderReponseBtn->setEnabled(true);
    }

}

void quizzdesign::ChangeQuestion()
{
    ui->ValiderReponseBtn->setEnabled(false);
    ui->LabelQuestion->setText(QString::fromStdString("ma nouvelle question"));
    ui->LabelNumeroQuestion->setText(QString::fromStdString("2/2"));
    ui->LabelMontant->setText(QString::fromStdString("10000€"));
    ui->InvisibleRadioButton->setChecked(true);

    ui->RadioBtnQ1->setText(QString::fromStdString("ma nouvelle reponse1"));
    ui->RadioBtnQ2->setText(QString::fromStdString("ma nouvelle reponse2"));
    ui->RadioBtnQ3->setText(QString::fromStdString("ma nouvelle reponse3"));
    ui->RadioBtnQ4->setText(QString::fromStdString("ma nouvelle reponse4"));
}






