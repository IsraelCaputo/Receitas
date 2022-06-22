#ifndef RECEITAS_HPP
#define RECEITAS_HPP

#include <mysql/mysql.h>

void pesquisarReceitaPorNome(MYSQL *conexao, char *query);
void cadastrarReceita(MYSQL *conexao, char *query);

#endif
