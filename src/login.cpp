#include "login.hpp"
#include "hash.hpp"

string efetuarLogin(MYSQL *conexao, char* query){    
    string usuario_id;

    cout << "Informe o email: " << endl;
    string emailUser;
    cin >> emailUser;
    cin.clear();

    cout << "Informe a senha: " << endl;
    string senhaUser;
    cin >> senhaUser;
    cin.clear();

    for(int i = 0; i < 4; i++){
        senhaUser = sha256(senhaUser);
    }
    
    strcpy(query, ("SELECT id, nome FROM usuarios where email = '"+ emailUser +"'").c_str());
    
    if(mysql_query(conexao, query) != 0)
        cout<< "Erro na conexão!" << endl;
    
    MYSQL_RES *resultado = mysql_store_result(conexao);
    
    if(mysql_num_rows(resultado) == 0)
    {
        system("clear");
        cout<< "Erro ao logar. E-mail não cadastrado!" << endl;
        return usuario_id = " ";
    }

    else
    {
        MYSQL_ROW linha;                
        linha = mysql_fetch_row(resultado);
        usuario_id = linha[0];
        string usuario_nome = linha[1];

        strcpy(query , ("select senha from credenciais where id = "+ to_string(atoi(linha[0])) +" AND senha = '" + senhaUser +"'").c_str());
        
        if(mysql_query(conexao, query) != 0)
            cout<< "Erro na conexão!" << endl;
        
        resultado = mysql_store_result(conexao);
        
        if(mysql_num_rows(resultado) == 0)
        {
            system("clear");
            cout<< "Erro ao logar. Senha inválida!" << endl;
            return usuario_id = " ";
        }

        else
        {
            system("clear");
            cout<< "Bem vindo " << usuario_nome << "!\n";
            return usuario_id;
        }
    }
}