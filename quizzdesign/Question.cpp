#include "Question.h"

//Question::Question(const std::string& q, const std::string& bonneRep, const std::vector<std::string>& rep, const std::string& diff)
//    : question(q), bonneReponse(bonneRep), reponse(rep), difficulte(diff)

Question::Question()
{

}

Question::Question(std::string question, std::string bonneReponse, std::vector<std::string> reponse, std::string difficulte)
{
    this->question = question;
    this->bonneReponse = bonneReponse;
    this->reponse = reponse;
    this->difficulte = difficulte;
}
