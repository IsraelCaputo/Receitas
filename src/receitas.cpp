#include "receitas.hpp"
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

using namespace std;

void pesquisarReceitaPorNome(MYSQL *conexao, char *query)
{
    cout << "\nNome da receita: ";
    while(getchar() != '\n');
    string receita;
    getline(cin, receita);
    cin.clear();

    strcpy(query, ("SELECT * FROM receitas where nome = '"+ receita +"'").c_str());

    if (mysql_query(conexao, query) != 0)
    {
        system("clear");
        cout << "Oops.. nenhuma receita encontrada.\n\n";
    }

    else 
    {
        mysql_query(conexao, "SELECT * FROM receitas");
        MYSQL_RES *resultado = mysql_store_result(conexao);
        // int n_col = mysql_num_fields(resultado);
        MYSQL_ROW linha; // colunas
        
        while ((linha = mysql_fetch_row(resultado)))
        {
            cout << "| Receita: " << linha[2];
            cout << " | Rendimento: " << linha[3];
            cout << " | Tempo: " << linha[4];
            cout << " | Info: " << linha[5] << endl << endl;
        }

        // imprimir detalhes da receita

        mysql_free_result(resultado);
    }
}

void cadastrarReceita(MYSQL *conexao, char *query)
{
    cout << "Nome da receita: ";
    while(getchar() != '\n');
    string receita;
    getline(cin, receita);

    cout << "Rendimento: ";
    int rendimento;
    cin >> rendimento;
    cin.clear();

    cout << "Tempo: ";
    int tempo;
    cin >> tempo;
    cin.clear();

    cout << "Info: ";
    while(getchar() != '\n');
    string info;
    getline(cin, info);

    // get user id sem 0x
    // (UNHEX(REPLACE('52EF9FA6F1A811EC88721CBFCE373CA6', '-', '')), 'Bolo de Cenoura', 1, 60, '');

    cout << "Usuario: ";
    string usuario;
    cin >> usuario;
    cin.clear();

    strcpy(query, ("INSERT INTO receitas (usuario_id, nome, rendimento, tempo, info) VALUES (UNHEX(REPLACE('"+ usuario +"', '-', '')), '"+ receita + "','"+ to_string(rendimento) +"','"+ to_string(tempo) +"','"  + info +"')").c_str());

    if (mysql_query(conexao, query) != 0)
    {
        system("clear");
        cout << "Oops.. não consegui cadastrar sua receita.\n\n";
    }

    else system("clear");
}