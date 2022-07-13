drop database if exists cefet_receitas;
create database cefet_receitas;
use cefet_receitas;

create table usuarios(
	id int primary key auto_increment,
	nome varchar(64) not null,
	telefone char(11) not null unique,
	email varchar(128) not null unique,
	cidade varchar(64) not null,
	estado char(2) not null,
	foto varchar(128) not null
);

create table credenciais(
	id INT primary key,
	senha varchar(256) not null,
	foreign key (id) references usuarios(id)
);

create table receitas(
	id int primary key auto_increment,
	usuario_id int,
	nome varchar(128) not null,
	rendimento int not null,
	tempo int not null,
	info text,
	foreign key (usuario_id) references usuarios(id)
);

create table ingredientes(
	receita_id int not null,
	nome varchar(128) not null,
	quantidade float not null,
	unidade varchar(32) not null,
	primary key(receita_id, nome),
	foreign key (receita_id) references receitas(id)
);

create table receitas_fotos(
	receita_id int not null,
	arquivo varchar(128) not null,
	primary key(receita_id, arquivo),
	foreign key (receita_id) references receitas(id)
);

create table receitas_etapas (
	receita_id int not null,
	numero int not null,
	titulo varchar(32) not null,
	primary key (receita_id, numero),
	foreign key (receita_id) references receitas (id)
);

create table receitas_passos (
	receita_id int,
	etapa_numero int not null,
	sequencia int not null,
	instrucao varchar(256) not null,
	primary key (receita_id, etapa_numero, sequencia),
	foreign key (receita_id, etapa_numero) references receitas_etapas (receita_id, numero)
);

create table comentarios(
	usuario_id int not null,
	receita_id int not null,
	data_hora timestamp not null,
	mensagem text,
	primary key(usuario_id, receita_id, data_hora),
	foreign key(usuario_id) references usuarios(id),
	foreign key(receita_id) references receitas(id)
);

create table curtidas(
	usuario_id int not null,
	receita_id int not null,
	estrelas int not null,
	primary key(usuario_id, receita_id),
	foreign key(usuario_id) references usuarios(id),
	foreign key(receita_id) references receitas(id)
);

create table receitas_salvas(
	usuario_id int not null,
	receita_id int not null,
	primary key(usuario_id, receita_id),
	foreign key(usuario_id) references usuarios(id),
	foreign key(receita_id) references receitas(id)
);
