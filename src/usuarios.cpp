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

    strcpy(query, ("INSERT INTO usuarios (id, nome, telefone, email, cidade, estado, foto) VALUES (uuid_to_bin(uuid()), '"+  nome + "','" + telefone + "','" + email +"','" + cidade +"','" + estado +"','" + foto +"')").c_str());

    if (mysql_query(conexao, query) != 0)
    {
        system("clear");
        cout << "Oops.. não consegui cadastrar seu contato.\n\n";
    }

    else system("clear");
}
