#include <iostream>
#include "binario.h";
using namespace std;

bool Fun��oAvalia��o(unsigned short a) {
	int pesomochila = 0;
	int valormochila = 0;
	int peso[16] = {1, 4, 2, 5, 4, 2, 1, 4, 3, 2, 1, 9, 4, 5, 3, 12};
	int valor[16] = {12, 4, 3, 10, 15, 20, 10, 2, 1, 1, 3, 15, 10, 8, 4, 4};

	//foi necess�rio inverter os valores de peso e valor pois a fun��o testar bit come�a a leitura 
	//do lado direito do bin�rio, ou seja, a ultima posi��o do vetor peso/valor

	for (int i = 0; i < 16; i++){
		if (TestarBit(a, i) == true) {
			// a fun��o testarbit est� servindo para verificar se os bit nas posi��es s�o 1 - (true)
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
	//solucao = BitsAltos(a) | BitsBaixos(b); - poderia ser assim tamb�m;
	solucao = ORBin�rio(BitsAltos(a), solucao); 
	//Est� utilizando a fun��o de OR com os BitsAltos e a Solu��o que nesse momento � 0000 0000 0000 00000;
	solucao = ORBin�rio(BitsBaixos(b), solucao);
	//Est� utilizando a fun��o de OR com os BitsBaixos e a Solu��o que nesse momento � XXXX XXXX 0000 00000;
	return solucao;
}

unsigned short CruzamentoAritmetico(unsigned short a, unsigned short b) {
	return ANDBin�rio(a, b);
}

unsigned short Muta��oSimples(unsigned short a) {
	if (TestarBit(a, 9) == true) {
		a = DesligarBit(a, 9);
		return a;
	}
	else {
		a = LigarBit(a, 9);
		return a;
	}
	//Testa o bit na posi��o 9, se estiver ligado manda desligar e se estiver desligado manda ligar
}

unsigned short Muta��oDupla(unsigned short a) {
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
	//Testa o bit na posi��o 3 e 12, se estiverem ligados manda desligar e se estiverem desligado manda ligar
}