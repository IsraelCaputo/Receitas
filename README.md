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

## Para compilar e executar
```
make clean
make
make run
```

