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
        cout << "Oops.. erro inesperado.\n\n";
        return;
    }

    MYSQL_RES *resultado = mysql_store_result(conexao);
    if(mysql_num_rows(resultado) > 0)
    {
        MYSQL_ROW linha; // colunas
        string receita_id;

        while ((linha = mysql_fetch_row(resultado)))
        {
            receita_id = linha[0];
            cout << "Receita: " << linha[2];
            cout << " | Rendimento: " << linha[3];
            cout << " | Tempo: " << linha[4];
            cout << " | Info: " << linha[5] << endl << endl;
        }

        // imprimir detalhes da receita

        strcpy(query, ("SELECT * FROM ingredientes where receita_id = '"+ receita_id +"'").c_str());
        // cout << endl << query << endl;
        mysql_query(conexao, query);
        resultado = mysql_store_result(conexao);
        // int n_col = mysql_num_fields(resultado);
        
        cout << "Ingrediente - Quantidade - Unidade";
        while((linha = mysql_fetch_row(resultado))) 
        {
            cout << "\n" << linha[1];
            cout << " - " << linha[2];
            cout << " - " << linha[3];
        }

        cout << endl << endl;
        mysql_free_result(resultado);
    }

    else 
    {
        system("clear");
        cout << "Oops... receita não existe\n";
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

    cout << "Usuario: ";
    int usuario;
    cin >> usuario;
    cin.clear();

    strcpy(query, ("INSERT INTO receitas (usuario_id, nome, rendimento, tempo, info) VALUES ("+ to_string(usuario) + ",'" + receita +  "'," + to_string(rendimento) + "," + to_string(tempo) + ",' "+ info +"')").c_str());
    mysql_query(conexao, query);
    
    // cadastrar ingredientes da receita

    strcpy(query, ("SELECT * FROM receitas WHERE usuario_id = "+ to_string(usuario) + " AND nome = '" + receita + "'").c_str());
    
    mysql_query(conexao, query);
    MYSQL_RES *resultado = mysql_store_result(conexao);
    // int n_col = mysql_num_fields(resultado);
    MYSQL_ROW linha; // colunas
    linha = mysql_fetch_row(resultado);
    string receita_id = linha[0];

    cout << "Número de ingredientes: ";
    int num_ingredientes;
    cin >> num_ingredientes;
    while(getchar() != '\n');
    int i=1;

    while(num_ingredientes--) 
    {
        cout << "\nIngrediente " << i << ": ";
        string ingrediente;
        getline(cin, ingrediente);
        cin.clear();

        cout << "Quantidade: ";
        float quantidade;
        cin >> quantidade;
        while(getchar() != '\n');

        cout << "Unidade: ";
        string unidade;
        getline(cin, unidade);
        cin.clear();

        strcpy(query, ("INSERT INTO ingredientes (receita_id, nome, quantidade, unidade) VALUES ("+ receita_id + ",'" + ingrediente + "'," + to_string(quantidade) +  ",'" + unidade +"')").c_str());
        mysql_query(conexao, query);
        i++;
    }

    // cadastrar etapas da receita

    cout << "\nNúmero de etapas: ";
    int num_etapas;
    cin >> num_etapas;
    while(getchar() != '\n');
    int etapa=1;

    while(num_etapas--) 
    {
        cout << "\nTitulo da etapa " << etapa << ": ";
        string titulo;
        getline(cin, titulo);
        cin.clear();
            
        strcpy(query, ("INSERT INTO receitas_etapas (receita_id, numero, titulo) VALUES ("+ receita_id + "," + to_string(etapa) + ",'" + titulo +"')").c_str());
        mysql_query(conexao, query);
        
        cout << "\nNúmero de passos da etapa " << etapa << ": ";
        int num_passos;
        cin >> num_passos;
        while(getchar() != '\n');

        for(int sequencia=1; sequencia <= num_passos; sequencia++)
        {
            cout << "\nPasso " << sequencia << ": ";
            string instrucao;
            getline(cin, instrucao);
            cin.clear();

            strcpy(query, ("INSERT INTO receitas_passos(receita_id, etapa_numero, sequencia, instrucao) VALUES ("+ receita_id + "," + to_string(etapa) + "," + to_string(sequencia) +  ",'" + instrucao + "')").c_str());
            mysql_query(conexao, query);
            cout << endl << query << endl;
        }
        etapa++;
    }

    mysql_free_result(resultado);
    system("clear");
    cout << "Receita cadastrada.\n\n";
}