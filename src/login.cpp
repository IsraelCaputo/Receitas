#include "login.hpp"


bool efetuarLogin(MYSQL *conexao, char* query, string usuario_id){
    bool logged = false;
    
    string emailUser;
    string senhaUser;

    cout << "Informe o email: " << endl;
    cin >> emailUser;
    cin.clear();

    strcpy(query, ("SELECT id FROM usuarios where email = '"+ emailUser +"'").c_str());
    
    if(mysql_query(conexao, query) != 0)
        cout<< "Erro na conexão!" << endl;
    MYSQL_RES *resultado = mysql_store_result(conexao);
    if(mysql_num_rows(resultado) == 0){
        cout<< "Email não cadastrado!" << endl;
                
    }else{
        MYSQL_ROW id;
                    
        id = mysql_fetch_row(resultado);
        usuario_id = id[0];

        cout << "Informe a senha: " << endl;
        cin >> senhaUser;
        cin.clear();


        strcpy(query , ("select senha from credenciais where id = "+ to_string(atoi(id[0])) +"").c_str());
        if(mysql_query(conexao, query) != 0)
            cout<< "Erro na conexão!" << endl;
        MYSQL_RES *resultado1 = mysql_store_result(conexao);
        if(mysql_num_rows(resultado1) == 0){
            cout<< "Senha não encontrada!" << endl;
        }else{
            MYSQL_ROW senha;
                        
            senha = mysql_fetch_row(resultado1);

            if(senhaUser == senha[0]){
                logged = true;
                cout << "Usuário logado com sucesso!" << endl;
            }else{
                cout << "Erro ao logar, por favor confira suas informações!"<< endl;
            }
        }
    }
    return logged;
}