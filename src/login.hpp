#ifndef LOGIN_HPP
#define LOGIN_HPP

#include <mysql/mysql.h>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

using namespace std;

bool efetuarLogin(MYSQL *conexao, char*query, string usuario_id);


#endif