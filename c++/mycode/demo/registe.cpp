#include <iostream>
#include <string>
#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/driver.h>
#include <cppconn/connection.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>

int main() {
    sql::mysql::MySQL_Driver *driver;
    sql::Connection *con;
    sql::PreparedStatement *stmt;
    sql::ResultSet *res;

    std::string password;
    std::string username;

    std::cout << "请输入用户名：";
    std::cin >> username;
    std::cout << std::endl;

    std::cout << "请输入密码：";
    std::cin >> password;
    std::cout << std::endl;

    try {
        driver = sql::mysql::get_mysql_driver_instance();
        con = driver->connect("tcp://154.8.154.13:3306", "newuser", "123456q");
        con->setSchema("db_user");

        stmt = con->prepareStatement("insert into user (username, user.hashed_password) values (?,SHA2(?, 256))");
        stmt->setString(1, username);
        stmt->setString(2, password);

        delete res;
        delete stmt;
        delete con;
    } catch (sql::SQLException &e) {
        std::cout << "SQL Exception: " << e.what() << std::endl;
    }


    return 0;
}