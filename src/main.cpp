#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <mysql/mysql.h>
#include "receitas.hpp"
#include "usuarios.hpp"

using namespace std;

int main()
{
    system("clear");
    // cout << "%s\n", mysql_get_client_info());
    string usuario_id = " ";

    MYSQL *conexao = mysql_init(NULL);
    if (conexao == NULL)
    {
        cout << "Não foi possível carregar o cliente MySQL.\n";
        return EXIT_FAILURE;
    }

    if (mysql_real_connect(conexao, "localhost", "aluno", "123456", "cefet_receitas", 0, NULL, 0) == NULL)
    {
        cout << "Não foi possível conectar ao SGBD.\n";
        return EXIT_FAILURE;
    };

    // Area do usuario não logado

    int opcao;
    char query[1024];
    
    do
    {
        cout << "-----------NAO LOGADO-----------\n\n";
        cout << "[1] Pesquisar receita por nome\n";
        cout << "[2] Pesquisar receita por ingrediente\n";
        cout << "[3] Logar\n";
        cout << "[4] Cadastrar usuário\n";
        cout << "[0] Sair\n";
        cout << ">>> ";
        cin >> opcao;
        cin.clear();

        if(opcao == 1) // pesquisar receita por nome
        {
            pesquisarReceitaPorNome(conexao, query, usuario_id);
        }

        if(opcao == 2) // pesquisar receita por ingrediente
        {

        }

        if(opcao == 3) // logar
        {
            system("clear");
            // dados do usuario logado
            usuario_id = "1";
            do
            {
                cout << "-----------LOGADO-----------\n\n";
                cout << "[1] Pesquisar receita por nome\n";
                cout << "[2] Pesquisar receia por ingrediente\n";
                cout << "[3] Cadastrar receita\n";
                cout << "[4] Receitas salvas\n";
                cout << "[5] Logout\n";
                cout << ">>> ";
                cin >> opcao;
                cin.clear();

                if (opcao == 1) // pesquisar receita por nome
                {
                    pesquisarReceitaPorNome(conexao, query, usuario_id);
                }

                else if(opcao == 2) // pesquisar receita por ingrediente
                {
                    
                }

                else if(opcao == 3) // cadastrar receita
                {
                    cadastrarReceita(conexao, query, usuario_id);
                }

                else if(opcao == 4) // receitas salvas
                {
                    
                }

                else if(opcao == 5) // logout
                {
                    opcao = 5;
                    usuario_id = " ";
                    system("clear");
                }
        
                else
                {
                    cout << "\nOpção inválida!!!\n\n";
                }

            } while (opcao != 5);

        }

        if(opcao == 4) // cadastrar usuario
        {
            cadastrarUsuario(conexao, query);
        }

        if(opcao == 0)
        {
            opcao = 0;
        }

    } while (opcao != 0);
    
    mysql_close(conexao);

    return EXIT_SUCCESS;
}