#include <iostream>
#include "genetico.h";
#include "binario.h";

using namespace std;

#define green "\033[32m"
#define red "\033[0;31m"
#define default "\033[m"

void main() {
	system("chcp 1252 > nul");

	unsigned short valor1, valor2, valor3, valor4, valor5, valor6;

	cout << "Entre com 6 soluções iniciais (números entre 0 e 65535): " << endl;

	cin >> valor1;
	cin >> valor2;
	cin >> valor3;
	cin >> valor4;
	cin >> valor5;
	cin >> valor6;

	unsigned short valoresprime[6] = { valor1, valor2, valor3, valor4, valor5, valor6};
	//colocando em um vetor todas as respostas para aderir uma estrutura de repetição e facilitar o código

	cout << endl;
	cout << right; cout.width(5); cout << "Resultado da Avaliação";
	cout << endl;
	cout << right; cout.width(5); cout << "----------------------";
	cout << endl;

	for (int i = 0; i < 6; i++)
	{
		if (FunçãoAvaliação(valoresprime[i]) == true) {
			cout << left; cout.width(3); cout << green << "OK" << default << endl;
		}
		else {
			cout << left; cout.width(3); cout << red << "X" << default << endl;
		}
	}
	
	cout << right; cout.width(5); cout << "----------------------";
	cout << endl;

	unsigned short cruzaunico = CruzamentoPontounico(valor1, valor2);
	unsigned short cruzaarit = CruzamentoAritmetico(valor3, valor4);
	unsigned short mutasim = MutaçãoSimples(valor5);
	unsigned short mutadupla = MutaçãoDupla(valor6);

	unsigned short valoresmod[4] = {cruzaunico, cruzaarit, mutasim, mutadupla};

	for (int i = 0; i < 4; i++)
	{
		if (FunçãoAvaliação(valoresmod[i]) == true) {
			cout << left; cout.width(3); cout << green << "OK" << default << endl;
		}
		else {
			cout << left; cout.width(3); cout << red << "X" << default << endl;
		}
	}
}