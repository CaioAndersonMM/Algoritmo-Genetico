#include <iostream>
using namespace std;

unsigned short LigarBit(unsigned short a, unsigned short posicao) {
	return a | (1 << posicao);

	//pega o valor binário da variável a e aplica um OR na máscara 0....01, movendo esse bit 1 para a posição desejada (variável posicao).
	//após colocar o bit 1 na posição desejada aplica o OR, se for 0 naquele lugar ficará 1, e se for 1 permanecerá!
}

unsigned short DesligarBit(unsigned short a, unsigned short posicao) {
	return a & ~(1 << posicao);

	//aqui segue a mesma lógica do ligar bit, a diferença é que a máscara 0....01 está sendo negada, ou seja o bit 1 está como 0 movendo x posições.
	//chegando na posição desejada ele irá aplicar um AND, pois o bit da variável a pode ser 1 e se aplicarmos um OR nisso o bit continuaria 1. 
	//então, é necessário que seja um AND justamente para zerar mesmo que seja 0 ou 1 a posição que esteja em a;
}

bool TestarBit(unsigned short a, unsigned short posicao) {
	return (a & (1 << posicao)) != 0;
	//pega a variável a e faz um AND com o bit 1 da mascara 0000 0000 0000 0001 - colocando esse bit 1 em uma posição desejada (passada pela variavel posicao)
	//ao colocar esse bit 1 na posição desejada, faz um AND para verificar se é VERDADEIRO (caso 1 esteja naquela posicao em a) e FALSO(caso 1 não esteja em a) visto que o BIT 1 sempre será 1.
	//a expressão != 0 fará o return ser verdadeiro caso a operação seja diferente de 0, e falso caso a operação seja 0.
}

unsigned short ORBinário(unsigned short a, unsigned short b) {
	return a | b;
}

unsigned short ANDBinário(unsigned short a, unsigned short b) {
	return a & b;
}

unsigned short BitsBaixos(unsigned short a) {
	unsigned short mascara = 255;
	//essa mascara é: 0000 0000 1111 1111 - (pegando os bits baixos)
	return a & mascara;
}
unsigned short BitsAltos(unsigned short a) {
	unsigned short mascara = 65280;
	//essa mascara é: 1111 1111 0000 0000 - (pegando os bits altos)
	return a & mascara;
}
