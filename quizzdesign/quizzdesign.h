#pragma once
#ifndef QUIZZDESIGN_H
#define QUIZZDESIGN_H

#include <QMainWindow>
#include "Question.h"

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
    void ActiveValidBtn();
    void ChangeQuestion();
    void CreateJeu();
    Question* GetNextQuestion();
    void DisplayQuestion(Question* Question);

private:
    Ui::quizzdesign *ui;
    Question question1;
    Question question2;
    Question question3;
    Question question4;
    Question question5;
    std::vector<Question*> listeQuestion;
    int numeroQuestion;
};
#endif // QUIZZDESIGN_H
