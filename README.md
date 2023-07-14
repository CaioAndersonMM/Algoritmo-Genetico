# Algoritmo-Genetico
Operadores genéticos são aplicados na solução para se obter novas soluções.

O	problema consiste	em	levar	em	uma	mochila	os objetos	que	somem	o	maior	valor	possível,	mas	sem	
extrapolar	sua	capacidade de	peso. Cada	objeto	possui	um	peso	e	um	valor	associado.
Esse	problema	pode	ser	resolvido	por	várias	técnicas,	incluindo programação	dinâmica e
algoritmos	gulosos.

Vamos	assumir	que	a	mochila	suporta	20Kg	e	que	temos	16	objetos,	cada	um	com	peso	e	valor	
mostrados	abaixo:
Objeto A B C D E F G H I J K L M N O P
Peso (Kg) 12 3 5 4 9 1 2 3 4 1 2 4 5 2 4 1
Valor	($) 4 4 8 10 15 3 1 1 2 10 20 15 10 3 4 12
A	solução	usando	algoritmos	genéticos	vai	representar	cada	objeto	por	um	bit.	Vamos	construir	
sequencias	de	16	bits	para	indicar	quais	objetos	estão	na	mochila	e	quais	não	estão.	A sequência	
abaixo poderia	representar	uma	solução para	o	problema.
A B C D E F G H I J K L M N O P
1 0 1 1 0 0 0 0 0 1 1 0 0 0 1 1
O	primeiro	bit	igual	a	1	significa	que	o	objeto A	está	na	mochila,	o	segundo	bit	igual	a	zero	
significa	que	o	objeto	B	não	está	na	mochila,	e	assim	por	diante.	Cada	sequência de	16	bits	
representa	uma	solução para	o	problema.	Nem	todas	as	soluções representadas	assim	são	
possíveis,	muitas	vão	extrapolar	o	peso	máximo	da	mochila,	outras	não	representarão	a	melhor	
solução.
Estamos	interessados	em	encontrar	a	sequência de	bits	que	nos	dê	uma	solução	ótima	para	o	
problema. A	técnica	de	algoritmos	genéticos	faz	isso	através	de	tentativas.	Ela	parte de	um	
conjunto	inicial	de	soluções	que	são	fornecidas	pelo	usuário.	No	nosso	caso,	as	soluções	serão	
números:
Cada	número	entre	0	e	65535	pode	ser	armazenado	em	uma	variável	inteira	positiva	com	
capacidade	para	16	bits,	fornecendo	assim	6	soluções	iniciais	para	o	problema. A	partir	daí	
aplicaremos	alguns	operadores	genéticos em	cima	das	soluções	iniciais	para obter novas	
soluções.
A	finalidade	dos	operadores	genéticos	é	obter	uma	variação	das	soluções	iniciais	com	o	objetivo	
de	chegar	mais	próximo	de	uma	solução	ótima	para	o	problema.	Normalmente	os	operadores	
são	aplicados	sobre	soluções	“promissoras”,	mas	aqui	aplicaremos	eles	indiscriminadamente	
para	simplificar	o	problema.
1) Cruzamento
a. Ponto	único:	o	cruzamento	tipo	ponto	único	gera	uma	nova	solução	a	partir	de	duas	
soluções	existentes,	copiando	parte	dos	bits	da	primeira	solução	e	o	restante	da	
segunda	solução.
b. Aritmético	(AND):	o	cruzamento	tipo	aritmético	gera	uma	nova	solução	a	partir	de	
duas	existentes,	usando	o bit	1	nas	posições	em	que	ambas	as	soluções iniciais	sejam	
1	e	0,	caso	contrário.
A B C D E F G H I J K L M N O P
Solução	A 1 1 1 0 1 1 0 0 0 1 0 1 1 0 0 0
Solução	B 0 1 1 0 0 0 0 1 1 0 1 0 1 0 0 0
Nova 1 1 1 0 1 1 0 0 1 0 1 0 1 0 0 0
A B C D E F G H I J K L M N O P
Solução	A 0 0 1 1 0 0 0 0 0 0 1 0 1 0 0 1
Solução	B 1 0 0 1 0 1 0 0 1 0 1 0 0 1 1 0
Nova 0 0 0 1 0 0 0 0 0 0 1 0 0 0 0 0
Entre com 6 soluções iniciais (números entre 0 e 65535):
60504
25000
12329
38054
1259
732
2) Mutação
a. Simples:	a	mutação	simples	modifica	um	bit	de	uma	solução	existente,	obtendo	
assim	uma	nova	solução.
b. Dupla:	a	mutação	dupla	tem	o	mesmo	comportamento	da	simples,	mas	a	nova	
solução	tem	dois	bits	modificados,	no	lugar	de	apenas	um.
Aplicaremos	cruzamento	de	ponto	único entre	as	duas	primeiras	soluções fornecidas	pelo	
usuário,	cruzamento	aritmético entre	a	terceira	e	quarta	solução,	mutação	simples sobre	a	
quinta	solução	e,	finalmente,	mutação	dupla sobre	a	sexta	e	última	solução.	Isso	significa	que	
após	aplicação	dos	operadores	genéticos	teremos	mais	4	soluções	novas	para	avaliar.	A	
aplicação	dos	operadores	em	cima	do	exemplo	inicial	resultaria	nos	seguintes	números
