#include <iostream>
#include "binario.h";
using namespace std;

bool FunçãoAvaliação(unsigned short a) {
	int pesomochila = 0;
	int valormochila = 0;
	int peso[16] = {1, 4, 2, 5, 4, 2, 1, 4, 3, 2, 1, 9, 4, 5, 3, 12};
	int valor[16] = {12, 4, 3, 10, 15, 20, 10, 2, 1, 1, 3, 15, 10, 8, 4, 4};

	//foi necessário inverter os valores de peso e valor pois a função testar bit começa a leitura 
	//do lado direito do binário, ou seja, a ultima posição do vetor peso/valor

	for (int i = 0; i < 16; i++){
		if (TestarBit(a, i) == true) {
			// a função testarbit está servindo para verificar se os bit nas posições são 1 - (true)
			pesomochila = peso[i] + pesomochila;
			valormochila = valor[i] + valormochila;
		}
	}

	cout << right; cout.width(5); cout << a;
		
	cout << right; cout.width(3); cout << " - $";
	cout << left; cout.width(3); cout << valormochila;
	cout << right; cout.width(3); cout << " - ";
	cout << right; cout.width(2); cout << pesomochila << "kg - ";

	if (pesomochila > 20) {
		return false;
	}
	else {
		return true;
	}
}

unsigned short CruzamentoPontounico(unsigned short a, unsigned short b) {
	unsigned short solucao = 0;
	//solucao = BitsAltos(a) | BitsBaixos(b); - poderia ser assim também;
	solucao = ORBinário(BitsAltos(a), solucao); 
	//Está utilizando a função de OR com os BitsAltos e a Solução que nesse momento é 0000 0000 0000 00000;
	solucao = ORBinário(BitsBaixos(b), solucao);
	//Está utilizando a função de OR com os BitsBaixos e a Solução que nesse momento é XXXX XXXX 0000 00000;
	return solucao;
}

unsigned short CruzamentoAritmetico(unsigned short a, unsigned short b) {
	return ANDBinário(a, b);
}

unsigned short MutaçãoSimples(unsigned short a) {
	if (TestarBit(a, 9) == true) {
		a = DesligarBit(a, 9);
		return a;
	}
	else {
		a = LigarBit(a, 9);
		return a;
	}
	//Testa o bit na posição 9, se estiver ligado manda desligar e se estiver desligado manda ligar
}

unsigned short MutaçãoDupla(unsigned short a) {
	if (TestarBit(a, 3) == true) {
		a = DesligarBit(a, 3);
	}
	else{
		a = LigarBit(a, 9);
		
	}
	if (TestarBit(a, 12) == true) {
		a = DesligarBit(a, 9);
	}
	else{
		a = LigarBit(a, 12);
	}
	return a;
	//Testa o bit na posição 3 e 12, se estiverem ligados manda desligar e se estiverem desligado manda ligar
}