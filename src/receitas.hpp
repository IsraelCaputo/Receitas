#ifndef RECEITAS_HPP
#define RECEITAS_HPP

#include <mysql/mysql.h>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

using namespace std;

void pesquisarReceitaPorNome(MYSQL *conexao, char *query, string usuario_id);
void cadastrarReceita(MYSQL *conexao, char *query, string usuario_id);
void comentarReceita(MYSQL *conexao, char *query, string receita_id, string usuario_id);
void exibirComentariosReceita(MYSQL *conexao, char *query, string receita_id);
void curtirReceita(MYSQL *conexao, char *query);


#endif
