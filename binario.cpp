#include <iostream>
using namespace std;

unsigned short LigarBit(unsigned short a, unsigned short posicao) {
	return a | (1 << posicao);

	//pega o valor bin�rio da vari�vel a e aplica um OR na m�scara 0....01, movendo esse bit 1 para a posi��o desejada (vari�vel posicao).
	//ap�s colocar o bit 1 na posi��o desejada aplica o OR, se for 0 naquele lugar ficar� 1, e se for 1 permanecer�!
}

unsigned short DesligarBit(unsigned short a, unsigned short posicao) {
	return a & ~(1 << posicao);

	//aqui segue a mesma l�gica do ligar bit, a diferen�a � que a m�scara 0....01 est� sendo negada, ou seja o bit 1 est� como 0 movendo x posi��es.
	//chegando na posi��o desejada ele ir� aplicar um AND, pois o bit da vari�vel a pode ser 1 e se aplicarmos um OR nisso o bit continuaria 1. 
	//ent�o, � necess�rio que seja um AND justamente para zerar mesmo que seja 0 ou 1 a posi��o que esteja em a;
}

bool TestarBit(unsigned short a, unsigned short posicao) {
	return (a & (1 << posicao)) != 0;
	//pega a vari�vel a e faz um AND com o bit 1 da mascara 0000 0000 0000 0001 - colocando esse bit 1 em uma posi��o desejada (passada pela variavel posicao)
	//ao colocar esse bit 1 na posi��o desejada, faz um AND para verificar se � VERDADEIRO (caso 1 esteja naquela posicao em a) e FALSO(caso 1 n�o esteja em a) visto que o BIT 1 sempre ser� 1.
	//a express�o != 0 far� o return ser verdadeiro caso a opera��o seja diferente de 0, e falso caso a opera��o seja 0.
}

unsigned short ORBin�rio(unsigned short a, unsigned short b) {
	return a | b;
}

unsigned short ANDBin�rio(unsigned short a, unsigned short b) {
	return a & b;
}

unsigned short BitsBaixos(unsigned short a) {
	unsigned short mascara = 255;
	//essa mascara �: 0000 0000 1111 1111 - (pegando os bits baixos)
	return a & mascara;
}
unsigned short BitsAltos(unsigned short a) {
	unsigned short mascara = 65280;
	//essa mascara �: 1111 1111 0000 0000 - (pegando os bits altos)
	return a & mascara;
}
