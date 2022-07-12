#include "usuarios.hpp"
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

using namespace std;

void cadastrarUsuario(MYSQL *conexao, char *query)
{
    cout << "Nome: ";
    while(getchar() != '\n');
    string nome;
    getline(cin, nome);
    cin.clear();

    cout << "Telefone: ";
    string telefone;
    cin >> telefone;
    cin.clear();

    cout << "Email: ";
    string email;
    cin >> email;
    cin.clear();

    cout << "Cidade: ";
    while(getchar() != '\n');
    string cidade;
    getline(cin, cidade);
    cin.clear();

    cout << "Estado: ";
    string estado;
    cin >> estado;
    cin.clear();

    cout << "Foto: ";
    string foto;
    cin >> foto;
    cin.clear();

    strcpy(query, ("INSERT INTO usuarios (nome, telefone, email, cidade, estado, foto) VALUES ('"+  nome + "','" + telefone + "','" + email +"','" + cidade +"','" + estado +"','" + foto +"')").c_str());

    if (mysql_query(conexao, query) != 0)
    {
        system("clear");
        cout << "Oops.. não consegui cadastrar seu contato.\n\n";
    }

    else 
    {
        strcpy(query, ("select id from usuarios where email = '" + email + "'").c_str());
        mysql_query(conexao, query);
        MYSQL_RES *resultado = mysql_store_result(conexao);
        // int n_col = mysql_num_fields(resultado);
        MYSQL_ROW linha; // colunas
        
        linha = mysql_fetch_row(resultado);
        string senha;
        cout<<"Digite uma senha: ";
        cin>>senha;

        strcpy(query, ("insert into credenciais(senha,id) values ('" + senha + "'," + linha[0] + ")").c_str());
        mysql_query(conexao, query);

        system("clear");
        cout<<"Usuario cadastrado.\n\n";
    }
}