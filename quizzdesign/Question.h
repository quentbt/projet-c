#include <string>
#include <vector>

class Question
{
public:
    // Getter pour la question
    std::string getQuestion() const {
        return this->question;
    }

    // Setter pour la question
    void setQuestion(const std::string& newQuestion) {
        this->question = newQuestion;
    }

    // Getter pour la bonne réponse
    std::string getBonneReponse() const {
        return this->bonneReponse;
    }

    // Setter pour la bonne réponse
    void setBonneReponse(const std::string& newBonneReponse) {
        this->bonneReponse = newBonneReponse;
    }

    // Getter pour les réponses
    std::vector<std::string> getReponse() const {
        return this->reponse;
    }

    // Setter pour les réponses
    void setReponse(const std::vector<std::string>& newReponse) {
        this->reponse = newReponse;
    }

    // Getter pour la difficulté
    std::string getDifficulte() const {
        return this->difficulte;
    }

    // Setter pour la difficulté
    void setDifficulte(const std::string& newDifficulte) {
        this->difficulte = newDifficulte;
    }

private:
    std::string question;
    std::string bonneReponse;
    std::vector<std::string> reponse;
    std::string difficulte;
};
