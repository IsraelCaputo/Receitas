#ifndef RECEITAS_PRINCIPAL_MENU_HPP
#define RECEITAS_PRINCIPAL_MENU_HPP

#include <mysql/mysql.h>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <vector>

using namespace std;

void pesquisarReceitaPorNome(MYSQL *conexao, char *query, string usuario_id);
void pesquisarReceitaPorIngrediente(MYSQL *conexao, char *query, string usuario_id);
void cadastrarReceita(MYSQL *conexao, char *query, string usuario_id);
void receitasSalvas(MYSQL *conexao,char *query,string usuario_id);

#endif
