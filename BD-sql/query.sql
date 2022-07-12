use cefet_receitas;

insert into usuarios(nome, telefone, email, cidade, estado, foto) values
	("Admin", "988332244", "admin@admin", "Divinopolis", "MG", "fotos.txt")
    ;

insert into credenciais(id, senha) values
	(1, 123456)
    ;

insert into receitas(usuario_id, nome, tempo, rendimento, info) values
	(1, "Pao de Queijo", 40, 25, "São realmente 3 ingredientes, não vai fermento."),
    (1, "Cajuzinho", 25, 40, ""),
    (1, "Pao de Queijo", 40, 30, "Se a massa de pão de queijo ficar muito líquida, acrescente mais polvilho azedo. E, se você gosta de um pão de queijo com sabor mais apurado, pode dobrar a quantidade de queijo sem medo."),
    (1, "Bolo de Cenoura", 40, 8, "")
    ;

insert into ingredientes(receita_id, nome, quantidade, unidade) values
	(1, "Creme de leite", 1, "caixa (200 ml)"),
    (1, "Queijo", 1, "copo (250 ml)"),
    (1, "Polvilho", 1, "copo (250 ml)"),
    (2, "Amendoim", 150, "g"),
    (2, "Açucar Cristal", 0.5, "xicara"),
    (2, "Leite Condensado", 1, "lata"),
    (2, "Chocolate em Po", 2, "colheres"),
    (2, "Manteiga", 1, "colher"),
    (2, "Açucar", 1, "xicara"),
    (2, "Amendoim em Grao", 50, "g"),
    (3, "Polvilho", 800, "g"),
    (3, "Agua", 1, "xicara"),
    (3, "Leite", 1, "xicara"),
    (3, "Oleo", 0.5, "xicara"),
    (3, "Ovo", 2, "unidades"),
    (3, "Queijo", 100, "g"),
    (3, "Sal", "0", "a gosto"),
    (4, "Oleo", 0.5, "xicara"),
    (4, "Cenoura", 3, "unidades"),
    (4, "Ovo", 4, "unidade"),
    (4, "Açucar Cristal", 2, "xicara"),
    (4, "Farinha de Trigo", 2.5, "xicara"),
    (4, "Fermento em Po", 1, "colher sopa"),
    (4, "Manteiga", 1, "colher sopa"),
    (4, "Chocolate em Po", 3, "colher sopa"),
    (4, "Açucar", 1, "xicara"),
    (4, "Leite", 1, "xicara")
    ;
    
insert into receitas_etapas(receita_id, numero, titulo) values
	(1, 1, "Preparo"),
    (1, 2, "Assamento"),
    (2, 1, "Preparo"),
    (3, 1, "Preparo"),
    (3, 2, "Assamento"),
    (4, 1, "Massa"),
    (4, 2, "Cobertura")
    ;

insert into receitas_passos(receita_id, etapa_numero, sequencia, instrucao) values
	(1, 1, 1, "Amasse até soltar das mãos."),
    (1, 1, 2, "Faça bolinhas, coloque em forma untada e asse em forno preaquecido bem quente."),
    (1, 1, 3, "Se achar necessário, acrescente sal."),
    (1, 2, 1, "Asse até ficarem douradinhos levemente."),
    (2, 1, 1, "Leve o amendoim torrado e moido ao liquidificador, sem líquidos e triture-os."),
    (2, 1, 2, "Em uma tigela misture todos os ingredientes até a massa ficar homogênea e atingir o ponto de enrolar."),
    (2, 1, 3, "Unte as mãos com manteiga e modele os docinhos para ficarem no formato de pequenos cajús."),
    (2, 1, 4, "Passe os docinhos no açúcar (cristal ou demerara) e coloque um grão para se assemelhar à castanha do caju."),
    (2, 1, 5, "Coloque em forminhas."),
    (3, 1, 1, "Em uma panela, ferva a água e acrescente o leite, o óleo e o sal."),
    (3, 1, 2, "Adicione o polvilho aos poucos até dar liga. Pode ser que você não precise usar os 800g, então coloque devagar e sove a massa até soltar da mão: esse é o ponto."),
    (3, 1, 3, "Quando a massa estiver morna, acrescente o queijo parmesão, os ovos e misture bem."),
    (3, 1, 4, "Unte as mãos e enrole bolinhas de 2 cm de diâmetro."),
    (3, 1, 5, "Disponha as bolinhas em uma assadeira untada com óleo, deixando um espaço entre elas."),
    (3, 2, 1, "Asse em forno médio (180º C), preaquecido, por cerca de 40 minutos."),
    (4, 1, 1, "Em um liquidificador, adicione a cenoura, os ovos e o óleo, depois misture."),
    (4, 1, 2, "Acrescente o açúcar e bata novamente por 5 minutos."),
    (4, 1, 3, "Em uma tigela ou na batedeira, adicione a farinha de trigo e depois misture novamente."),
    (4, 1, 4, "Acrescente o fermento e misture lentamente com uma colher."),
    (4, 1, 5, "Asse em um forno preaquecido a 180° C por aproximadamente 40 minutos."),
    (4, 2, 1, "Despeje em uma tigela a manteiga, o chocolate em pó, o açúcar e o leite, depois misture."),
    (4, 2, 2, "Leve a mistura ao fogo e continue misturando até obter uma consistência cremosa, depois despeje a calda por cima do bolo.")
    ;
