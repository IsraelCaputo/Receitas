#ifndef LOGIN_HPP
#define LOGIN_HPP

#include <mysql/mysql.h>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

using namespace std;

string efetuarLogin(MYSQL *conexao, char*query);

#endif