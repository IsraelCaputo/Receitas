#include "receitas_pesquisa_menu.hpp"

void imprimeReceita(MYSQL *conexao, char *query, vector <string> receitas_id, unsigned int opcao)
{
    strcpy(query, ("SELECT * FROM receitas where id = " + receitas_id.at(opcao-1)).c_str());
    mysql_query(conexao, query);
    MYSQL_RES *resultado = mysql_store_result(conexao);
    MYSQL_ROW linha = mysql_fetch_row(resultado);
    cout << "\n\n- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -";
    cout << "\nReceita: " << linha[2];
    cout << " | Rendimento: " << linha[3];
    cout << " | Tempo: " << linha[4];
    cout << " | Info: " << linha[5] << endl << endl;

    strcpy(query, ("SELECT * FROM ingredientes where receita_id = '" + receitas_id.at(opcao-1) + "'").c_str());
    mysql_query(conexao, query);
    resultado = mysql_store_result(conexao);
    // int n_col = mysql_num_fields(resultado);

    cout << "INGREDIENTE - QUANTIDADE - UNIDADE";
    while ((linha = mysql_fetch_row(resultado)))
    {
        cout << "\n" << linha[1];
        cout << " - " << linha[2];
        cout << " - " << linha[3];
    }

    strcpy(query, ("SELECT * FROM receitas_etapas where receita_id = '" + receitas_id.at(opcao-1) + "'").c_str());
    mysql_query(conexao, query);
    resultado = mysql_store_result(conexao);

    cout << "\n\nMODO DE PREPARO:";
    while ((linha = mysql_fetch_row(resultado)))
    {
        cout << "\n" << linha[1];
        cout << ". " << linha[2];

        strcpy(query, ("SELECT * FROM receitas_passos where receita_id = '" + receitas_id.at(opcao-1) + "' AND etapa_numero = " + linha[1]).c_str());
        mysql_query(conexao, query);
        MYSQL_RES *resultado2 = mysql_store_result(conexao);
        MYSQL_ROW linha2;

        while ((linha2 = mysql_fetch_row(resultado2)))
        {
            cout << "\n\t" << linha2[2];
            cout << ". " << linha2[3];
        }
        cout << endl;
    }


    mysql_free_result(resultado);
}

void imprimeReceitaEncontrada(MYSQL *conexao, char *query, vector <string> receitas_id)
{  
    unsigned int i=1;
    for (auto receita_id = receitas_id.begin(); receita_id != receitas_id.end(); ++receita_id)
    {
        strcpy(query, ("SELECT * FROM receitas where id = " + *receita_id).c_str());
    
        if (mysql_query(conexao, query) != 0)
        {
            system("clear");
            cout << "Oops.. erro inesperado.\n\n";
            return;
        }

        MYSQL_RES *resultado = mysql_store_result(conexao);
        MYSQL_ROW linha;

        while ((linha = mysql_fetch_row(resultado)))
        {
            string receita_nome = linha[2];
            cout << "\n[" << i << "] "+ receita_nome;
            i++;
        }
    }
}

void menuPesquisarReceita(string usuario_id, string receita_id, MYSQL *conexao, char *query)
{
    unsigned int opcao;
    while(opcao != 0)
    {
        cout << "\n\n[1] Exibir comentarios\n[2] Exibir curtidas\n[3] Exibir foto da receita\n[4] Realizar comentario\n[5] Salvar receita\n[6] Avaliar receita\n[0] Sair\n\n>>> ";
        cin >> opcao;
        cin.ignore();
        switch(opcao)
        {
            case 0:
                opcao=0;
                break;

            case 1: // exibir comentarios receita
                exibirComentariosReceita(conexao, query, receita_id);
                break;
            
            case 2: // exibir curtidas receita
                exibirCurtidas(conexao, query, receita_id);
                break;
            
            case 3: {// exibir foto receita
                string fotoDiretorio = "xdg-open fotos/" + receita_id + ".jpg";
                const char *foto = fotoDiretorio.c_str();
                system(foto);
                break;
            }
            case 4: // realizar comentario receita
                if (usuario_id != " ")
                {
                    comentarReceita(conexao, query, receita_id, usuario_id);
                }
                else
                    cout << "\nRealize o login para comentar a receita!\n\n";
                break;
        
            case 5: // salvar receita
                if (usuario_id != " ")
                {
                    queroEsperimentar(conexao, query, receita_id, usuario_id);
                }
                else
                    cout << "\nRealize o login para salvar a receita!\n\n";
                break;
            
            case 6: // avaliar receita
                if (usuario_id != " ")
                {
                    curtirReceita(conexao, query, receita_id, usuario_id);
                }
                else
                    cout << "\nRealize o login para avaliar a receita!\n\n";
                break;
            
            default:
                cout << "\nOpção inválida!\n\n";
        }
    }
}

void comentarReceita(MYSQL *conexao, char *query, string receita_id, string usuario_id)
{
    cout << "\n\nDigite o seu comentario: \n\n";
    string mensagem;
    getline(cin, mensagem);
    cin.clear();

    strcpy(query, ("SELECT now()"));
    mysql_query(conexao, query);
    MYSQL_RES *resultado = mysql_store_result(conexao);
    MYSQL_ROW linha; // colunas
    linha = mysql_fetch_row(resultado);
    string date_time = linha[0];

    strcpy(query, ("INSERT INTO comentarios(receita_id, usuario_id, data_hora, mensagem) VALUES (" + receita_id + "," + usuario_id + ",'" + date_time + "','" + mensagem + "')").c_str());
    mysql_query(conexao, query);

    mysql_free_result(resultado);
    system("clear");
    cout << "\n\nComentario registrado com sucesso.";
}

void exibirComentariosReceita(MYSQL *conexao, char *query, string receita_id)
{
    strcpy(query, ("SELECT * FROM comentarios where receita_id = " + receita_id + "").c_str());
    mysql_query(conexao, query);
    MYSQL_RES *resultado = mysql_store_result(conexao);
    MYSQL_ROW linha; // colunas

    cout << "\n\n-------COMENTARIOS-------\n";
    if (mysql_num_rows(resultado) > 0)
    {
        while ((linha = mysql_fetch_row(resultado)))
        {
            string nome = linha[0];
            strcpy(query, ("SELECT * FROM usuarios where id = " + nome + "").c_str());
            mysql_query(conexao, query);
            MYSQL_RES *resultado2 = mysql_store_result(conexao);
            MYSQL_ROW linha2; // colunas
            linha2 = mysql_fetch_row(resultado2);

            cout << "\n"
                << linha2[1];
            cout << "\nem " << linha[2];
            cout << "\n"
                << linha[3];
            cout << endl;
        }
    }

    else
    {
        cout << "\nReceita nao possui comentarios.";
    }
    
    mysql_free_result(resultado);
}

void curtirReceita(MYSQL *conexao, char *query, string receita_id, string usuario_id)
{
    string entrada;
    int aval = -1;
    cout << "\nAvalie a receita entre 0 e 5 estrelas.\n>>> ";
    cin >> entrada;

    try
    {
        aval = stoi(entrada);
    }
    catch (invalid_argument &e)
    {
        cout << "\nEntrada inválida.\n";
        return;
    }

    if (aval > 5 || aval < 0)
    {
        cout << "\nEntrada inválida.\n";
        return;
    }

    strcpy(query, ("INSERT INTO curtidas(receita_id, usuario_id,estrelas) VALUES (" + receita_id + "," + usuario_id + "," + to_string(aval) + ")").c_str());

    if (mysql_query(conexao, query))
    {
        cout << "\nOops.. não foi possível registrar a avaliação.\n";
    }
    else
    {
        cout << "\nAvaliação enviada !";
    }
}

void exibirCurtidas(MYSQL *conexao, char *query, string receita_id)
{
    strcpy(query, ("SELECT usuario_id,estrelas FROM curtidas where receita_id = " + receita_id).c_str());

    mysql_query(conexao, query);
    MYSQL_RES *resultado = mysql_store_result(conexao);
    MYSQL_ROW linha; // colunas

    cout << "\n\n------CURTIDAS-----\n";
    if (mysql_num_rows(resultado) > 0)
    {
        while ((linha = mysql_fetch_row(resultado)))
        {

            string usuario = linha[0];
            strcpy(query, ("SELECT nome FROM usuarios where id = " + usuario).c_str());
            mysql_query(conexao, query);
            MYSQL_RES *nome_usuario_res = mysql_store_result(conexao);
            MYSQL_ROW nome_usuario = mysql_fetch_row(nome_usuario_res);

            cout << "\nUsuario: " << nome_usuario[0] << "\nEstrelas: " << linha[1] << "\n";
        }
    }

    else
    {
        cout << "\nReceita nao possui curtidas.";
    }
    
}

void queroEsperimentar(MYSQL *conexao, char *query, string receita_id, string usuario_id)
{
    strcpy(query, ("INSERT INTO receitas_salvas(receita_id, usuario_id) VALUES (" + receita_id + "," + usuario_id + ")").c_str());
    if (mysql_query(conexao, query))
    {
        cout << "\nOops.. não foi possível salvar a receita, é provável que ela já esteja salva.";
    }
    else
    {
        cout << "\nReceita salva!";
    }
}
