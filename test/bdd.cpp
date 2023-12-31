#include <stdlib.h>
#include <iostream>

#include "mysql_connection.h"
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/prepared_statement.h>
using namespace std;

//for demonstration only. never save your password in the code!
const string server = "localhost";
const string username = "root";
const string password = "";

int main()
{
    sql::Driver *driver;
    sql::Connection *con;
    sql::Statement *stmt;
    sql::PreparedStatement *pstmt;
    sql::ResultSet* res;

    try
    {
        driver = get_driver_instance();
        con = driver->connect(server, username, password);
    }
    catch (sql::SQLException e)
    {
        cout << "Could not connect to server. Error message: " << e.what() << endl;
        system("pause");
        exit(1);
    }

    //please create database "quickstartdb" ahead of time
  con->setSchema("quizz_c++");

  const int maxQuestions = 25;
  const int numColumns = 8;
  string tab[maxQuestions][numColumns];
  string tab2[numColumns] = { "reponse", "r�ponse_a", "r�ponse_b", "r�ponse_c", "r�ponse_d", "theme", "difficult�" };

  pstmt = con->prepareStatement("SELECT * from questions;");
  res = pstmt->executeQuery();

  for (int i = 0; i < maxQuestions && res->next(); i++) {
      tab[i][0] = res->getString("questions");
      
      for (int j = 0; j < numColumns; j++) {
          string reponsetst[8] = { "reponse", "r�ponse_a" , "r�ponse_b", "r�ponse_c", "r�ponse_d", "theme", "difficult�" };
          tab[i][j] = res->getString(reponsetst[0]);
          cout << tab[i][j] << endl;
          tab[i][j] = res->getString(reponsetst[1]);
          cout << tab[i][j] << endl;
          tab[i][j] = res->getString(reponsetst[3]);
          cout << tab[i][j] << endl;
          tab[i][j] = res->getString(reponsetst[4]);
          cout << tab[i][j] << endl;
          tab[i][j] = res->getString(reponsetst[5]);
          cout << tab[i][j] << endl;
          tab[i][j] = res->getString(reponsetst[6]);
          cout << tab[i][j] << endl;
          tab[i][j] = res->getString(reponsetst[7]);
          cout << tab[i][j] << endl;
          tab[i][j] = res->getString(reponsetst[8]);
          cout << tab[i][j] << endl;

          
      }
  }





    //stmt = con->createStatement();
    //stmt->execute("CREATE TABLE questions (id serial PRIMARY KEY, questions VARCHAR(100), reponse VARCHAR(100), r�ponse_a VARCHAR(30), r�ponse_b VARCHAR(30), r�ponse_c VARCHAR(30),r�ponse_d VARCHAR(30) , theme VARCHAR(20), difficult� VARCHAR(2));");
    //cout << "Finished creating table" << endl;
    //delete stmt;

    /*pstmt = con->prepareStatement("INSERT INTO questions(questions, reponse, r�ponse_a , r�ponse_b , r�ponse_c , r�ponse_d , theme , difficult�) VALUES(?,?,?,?,?,?,?,?)");
    pstmt->setString(1, "Qui est l'actuel pr�sident fran�ais ?");
    pstmt->setString(2, "Macron");
    pstmt->setString(3, "Sarkozy");
    pstmt->setString(4, "Holland");
    pstmt->setString(5, "Macron");
    pstmt->setString(6, "Obama");
    pstmt->setString(7, "Culutre g");
    pstmt->setString(8, "*");
    pstmt->execute();
    cout << "One row inserted." << endl;
    pstmt = con->prepareStatement("INSERT INTO questions(questions, reponse, r�ponse_a , r�ponse_b , r�ponse_c , r�ponse_d , theme , difficult�) VALUES(?,?,?,?,?,?,?,?)");
    pstmt->setString(1, "O� est situ� la statue de la libert� ?");
    pstmt->setString(2, "Etats-Unis");
    pstmt->setString(3, "Etats-unis");
    pstmt->setString(4, "Br�sil");
    pstmt->setString(5, "Norv�ge");
    pstmt->setString(6, "Madagascar");
    pstmt->setString(7, "Culutre g");
    pstmt->setString(8, "*");
    pstmt->execute();
    cout << "One row inserted." << endl;
    pstmt = con->prepareStatement("INSERT INTO questions(questions, reponse, r�ponse_a , r�ponse_b , r�ponse_c , r�ponse_d , theme , difficult�) VALUES(?,?,?,?,?,?,?,?)");
    pstmt->setString(1, "Combien de jours poss�de une ann�e ?");
    pstmt->setString(2, "365");
    pstmt->setString(3, "369");
    pstmt->setString(4, "365");
    pstmt->setString(5, "387");
    pstmt->setString(6, "24");
    pstmt->setString(7, "Culutre g");
    pstmt->setString(8, "*");
    pstmt->execute();
    cout << "One row inserted." << endl;
    pstmt = con->prepareStatement("INSERT INTO questions(questions, reponse, r�ponse_a , r�ponse_b , r�ponse_c , r�ponse_d , theme , difficult�) VALUES(?,?,?,?,?,?,?,?)");
    pstmt->setString(1, "Tout les combien de temps est �lu un pr�sident en France ?");
    pstmt->setString(2, "5");
    pstmt->setString(3, "7");
    pstmt->setString(4, "3");
    pstmt->setString(5, "4");
    pstmt->setString(6, "5");
    pstmt->setString(7, "Culutre g");
    pstmt->setString(8, "*");
    pstmt->execute();
    cout << "One row inserted." << endl;
    pstmt = con->prepareStatement("INSERT INTO questions(questions, reponse, r�ponse_a , r�ponse_b , r�ponse_c , r�ponse_d , theme , difficult�) VALUES(?,?,?,?,?,?,?,?)");
    pstmt->setString(1, "Qui � remporter la coupe du monde 2022");
    pstmt->setString(2, "Agentine");
    pstmt->setString(3, "Maroc");
    pstmt->setString(4, "Br�sil");
    pstmt->setString(5, "France");
    pstmt->setString(6, "Argentine");
    pstmt->setString(7, "Culutre g");
    pstmt->setString(8, "*");
    pstmt->execute();
    cout << "One row inserted." << endl;
    pstmt = con->prepareStatement("INSERT INTO questions(questions, reponse, r�ponse_a , r�ponse_b , r�ponse_c , r�ponse_d , theme , difficult�) VALUES(?,?,?,?,?,?,?,?)");
    pstmt->setString(1, "Quel est ce ch�teau de l'Oise dans lequel on peut visiter le mus�e Cond� ?");
    pstmt->setString(2, "Le ch�teau de Chantilly");
    pstmt->setString(3, "Le ch�teau de Chenonceau");
    pstmt->setString(4, "Le ch�teau de Fontainebleau");
    pstmt->setString(5, "Le ch�teau de Chantilly");
    pstmt->setString(6, "Le ch�teau de Saumur");
    pstmt->setString(7, "Culutre g");
    pstmt->setString(8, "**");
    pstmt->execute();
    cout << "One row inserted." << endl;
    pstmt = con->prepareStatement("INSERT INTO questions(questions, reponse, r�ponse_a , r�ponse_b , r�ponse_c , r�ponse_d , theme , difficult�) VALUES(?,?,?,?,?,?,?,?)");
    pstmt->setString(1, "Quelle est la longueur d'un marathon ?");
    pstmt->setString(2, "42km");
    pstmt->setString(3, "41km");
    pstmt->setString(4, "56km");
    pstmt->setString(5, "45km");
    pstmt->setString(6, "42km");
    pstmt->setString(7, "Culutre g");
    pstmt->setString(8, "**");
    pstmt->execute();
    cout << "One row inserted." << endl;*/
   
    delete pstmt;
    delete con;
    system("pause");
    return 0;
}