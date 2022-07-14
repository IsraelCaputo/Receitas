# Receitas
Trabalho final realizado para a disciplina de Banco de Dados 1.

## Dependências
Bibliotecas:
```
sudo apt isntall libssl-dev
sudo apt install libmysqlclient-dev
```
Banco de dados: \
São necessários alguns passos após instalar as bibliotecas: \
Criando o user aluno:
```
sudo mysql
create user 'aluno'@'localhost' identified by '123456';
grant all privileges on *.* to 'aluno'@'localhsot';
flush privileges;
exit
```
Gerando o banco de dados:
```
sudo mysql -u aluno -p < BD-sql/receitas.sql
sudo mysql -u aluno -p < BD-sql/query.sql
```
Para adicionar foto da receita no banco de dados siga os seguintes passos:
```
Obs.: Somente é aceito imagem no formato .JPG
1. Antes de cadastrar a receita adicione sua foto na pasta 'uploaded fotos'. Essa pasta simula a funcionalidade 'fazer upload de foto'. 
Obs.: É importante saber o nome do arquivo, uma vez que você deverá inseri-lo no cadastro da receita.
2. Realize o cadastro da receita. 
3. Na pergunta 'Deseja realizar upload da imagem da receita? (y/n)' digite y.
4. Digite o nome do arquivo imagem salva no passo 1 (sem .jpg).
```

## Para compilar e executar
```
make clean
make
make run
```

