#ifndef RECEITAS_PESQUISA_MENU_HPP
#define RECEITAS_PESQUISA_MENU_HPP

#include <mysql/mysql.h>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <vector>

using namespace std;

void comentarReceita(MYSQL *conexao, char *query, string receita_id, string usuario_id);
void exibirComentariosReceita(MYSQL *conexao, char *query, string receita_id);
void curtirReceita(MYSQL *conexao,char *query, string receita_id,string usuario_id);
void exibirCurtidas(MYSQL *conexao,char *query, string receita_id);
void queroEsperimentar(MYSQL *conexao,char *query, string receita_id,string usuario_id);
void menuPesquisarReceita(string usuario_id, string receita_id, MYSQL *conexao, char *query);
void imprimeReceita(MYSQL *conexao, char *query, vector <string> receitas_id, unsigned int opcao);
void imprimeReceitaEncontrada(MYSQL *conexao, char *query, vector <string> receitas_id);

#endif
