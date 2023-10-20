#include "quizzdesign.h"
#include "ui_quizzdesign.h"
#include "QStackedWidget"
#include "fonction.h"

#include <qDebug>


quizzdesign::quizzdesign(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::quizzdesign), question1()
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

    // On initialise le compteur de la question à afficher
    numeroQuestion = 0;

    // On vient initialiser les questions
    //std::vector<std::string> tempVector = {"ma mauvaise réponse 1", "ma bonne réponse", "ma mauvaise réponse 2", "ma mauvaise réponse 3"};
    //question1 = Question("Quelle est la longueur d'un marathon ?", "ma bonne réponse", tempVector, "normal");
    question1 = Question("Quelle est la longueur d'un marathon ?", "42km" , {"41km" , "56km" , "45km" , "42km"}, "normal" );
    question2 = Question("Quel est l'actuel président français ?", "Macron",{ "Sarkozy", "Obama", "Macron","Holland"}, "normal");
    question3 = Question("Qui à un lampadaire dans lol ?", "Jax",{ "Sejuani", "Jax", "Milio","Sion"},"normal");
        question4 = Question("Combien font 2(2+4) ?", "12", {"18","22","8","12"},"normal");
    question5 = Question("Quel est la traduction de la phrase suivante : 'The sun is yellow' en français ?","Le soleil est jaune",{"Le soleil est beau","Le fils est jaune","La lune est blanche","Le soleil est jaune"},"normal");


    listeQuestion.push_back(&question1);
    listeQuestion.push_back(&question2);
    listeQuestion.push_back(&question3);
    listeQuestion.push_back(&question4);
    listeQuestion.push_back(&question5);

    // On récupère la première question
    Question* Question = GetNextQuestion();

    // On affiche la première question et ce qui va avec
    DisplayQuestion(Question);
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
    ui->InvisibleRadioButton->setChecked(true);

    Question* Question = GetNextQuestion();

    DisplayQuestion(Question);
}

Question* quizzdesign::GetNextQuestion()
{
    Question* NextQuestion= listeQuestion[numeroQuestion];
    numeroQuestion++;

    return NextQuestion;
}

void quizzdesign::DisplayQuestion(Question* Question)
{
    qDebug() << Question->getQuestion();
    ui->LabelQuestion->setText(QString::fromStdString(Question->getQuestion()));

    ui->LabelNumeroQuestion->setText(QString::fromStdString(std::to_string(numeroQuestion) + "/" + std::to_string(listeQuestion.size())));
    ui->LabelMontant->setText(QString::fromStdString("10000€"));

    // On vient afficher les réponses possible
    ui->RadioBtnQ1->setText(QString::fromStdString(Question->getReponse()[0]));
    ui->RadioBtnQ2->setText(QString::fromStdString(Question->getReponse()[1]));
    ui->RadioBtnQ3->setText(QString::fromStdString(Question->getReponse()[2]));
    ui->RadioBtnQ4->setText(QString::fromStdString(Question->getReponse()[3]));
}





