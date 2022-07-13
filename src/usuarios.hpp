#ifndef USUARIOS_HPP
#define USUARIOS_HPP

#include <mysql/mysql.h>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "hash.hpp"

using namespace std;

void cadastrarUsuario(MYSQL *conexao, char *query);

#endif
