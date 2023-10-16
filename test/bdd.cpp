#include <stdlib.h>
#include <iostream>

#include "mysql_connection.h"
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/prepared_statement.h>
using namespace std;

//for demonstration only. never save your password in the code!
const string server = "tcp://127.0.0.1:3306";
const string username = "root";
const string password = "";

int main()
{
    sql::Driver *driver;
    sql::Connection *con;
    sql::Statement *stmt;
    sql::PreparedStatement *pstmt;

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

    stmt = con->createStatement();
    stmt->execute("CREATE TABLE questions (id serial PRIMARY KEY, questions VARCHAR(100), reponse VARCHAR(100), r�ponse_a VARCHAR(30), r�ponse_b VARCHAR(30), r�ponse_c VARCHAR(30),r�ponse_d VARCHAR(30) , theme VARCHAR(20), difficult� VARCHAR(2));");
    cout << "Finished creating table" << endl;
    delete stmt;

    pstmt = con->prepareStatement("INSERT INTO questions(questions, reponse, r�ponse_a , r�ponse_b , r�ponse_c , r�ponse_d , theme , difficult�) VALUES(?,?,?,?,?,?,?,?)");
    pstmt->setString(1, "qui est le pr�sident actuel fr");
    pstmt->setString(2, "Macron");
    pstmt->setString(3, "Sarko");
    pstmt->setString(4, "Holland");
    pstmt->setString(5, "Macron");
    pstmt->setString(6, "Obama");
    pstmt->setString(7, "Culutre g");
    pstmt->setString(8, "*");
    pstmt->execute();
    cout << "One row inserted." << endl;

    delete pstmt;
    delete con;
    system("pause");
    return 0;
}