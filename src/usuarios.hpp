#ifndef USUARIOS_HPP
#define USUARIOS_HPP

#include <mysql/mysql.h>

void cadastrarUsuario(MYSQL *conexao, char *query);

#endif
