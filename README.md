**Problema da Mochila - Algoritmo Genético**

O problema consiste em levar em uma mochila os objetos que somem o maior valor possível, mas sem extrapolar sua capacidade de peso. Cada objeto possui um peso e um valor associado. Este problema pode ser resolvido utilizando várias técnicas, incluindo programação dinâmica e algoritmos gulosos.

Descrição do Problema
Vamos assumir que a mochila suporta 20Kg e que temos 16 objetos, cada um com peso e valor mostrados abaixo:

| Objeto | Peso (Kg) | Valor ($) |
|--------|-----------|-----------|
| A      | 12        | 4         |
| B      | 3         | 4         |
| C      | 5         | 8         |
| D      | 4         | 10        |
| E      | 9         | 15        |
| F      | 1         | 3         |
| G      | 2         | 1         |
| H      | 3         | 1         |
| I      | 4         | 2         |
| J      | 1         | 10        |
| K      | 2         | 20        |
| L      | 4         | 15        |
| M      | 5         | 10        |
| N      | 2         | 3         |
| O      | 4         | 4         |
| P      | 1         | 12        |

## Representação da Solução
A solução usando algoritmos genéticos irá representar cada objeto por um bit. Vamos construir sequências de 16 bits para indicar quais objetos estão na mochila e quais não estão. Cada sequência de 16 bits representa uma solução para o problema.

Exemplo de solução:

| Objeto | A | B | C | D | E | F | G | H | I | J | K | L | M | N | O | P |
|--------|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
| Valores| 1 | 0 | 1 | 1 | 0 | 0 | 0 | 0 | 0 | 1 | 1 | 0 | 0 | 0 | 1 | 1 |

O primeiro bit igual a 1 significa que o objeto A está na mochila, o segundo bit igual a 0 significa que o objeto B não está na mochila, e assim por diante. Nem todas as sequências representadas dessa forma são possíveis, muitas vão extrapolar o peso máximo da mochila ou não representarão a melhor solução.

*Estamos interessados em encontrar a sequência de bits que nos dê uma solução ótima para o problema. A técnica de algoritmos genéticos faz isso através de tentativas. Ela parte de um conjunto inicial de soluções que são fornecidas pelo usuário. No nosso caso de exemplificação, as soluções 6 soluções iniciais serão os números (entre  0 e 65535) fornecidos pelo usuário:
- 60504
- 25000
- 12329
- 38054
- 1259
- 732

## Operadores Genéticos
Estamos interessados em encontrar a sequência de bits que nos dê uma solução ótima para o problema. A técnica de algoritmos genéticos faz isso através de tentativas. Ela parte de um conjunto inicial de soluções que são fornecidas pelo usuário. A partir daí, aplicaremos alguns operadores genéticos sobre as soluções iniciais para obter novas soluções.

## Cruzamento

Existem dois tipos de cruzamento que podem ser aplicados:

a. Ponto único: o cruzamento tipo ponto único gera uma nova solução a partir de duas soluções existentes, copiando parte dos bits da primeira solução e o restante da segunda solução.

b. Aritmético (AND): o cruzamento tipo aritmético gera uma nova solução a partir de duas soluções existentes, usando o bit 1 nas posições em que ambas as soluções iniciais sejam 1 e 0 caso contrário.

a) Ponto Único

|      | A | B | C | D | E | F | G | H | I | J | K | L | M | N | O | P |
|------|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
| Solução A  | 1 | 1 | 1 | 0 | 1 | 1 | 0 | 0 | 0 | 1 | 0 | 1 | 1 | 0 | 0 | 0 |
| Solução B  | 0 | 1 | 1 | 0 | 0 | 0 | 0 | 1 | 1 | 0 | 1 | 0 | 1 | 0 | 0 | 0 |
| Nova Solução | 1 | 1 | 1 | 0 | 1 | 1 | 0 | 0 | 1 | 0 | 1 | 0 | 1 | 0 | 0 | 0 |

b) Aritmético - (AND):

|      | A | B | C | D | E | F | G | H | I | J | K | L | M | N | O | P |
|------|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
| Solução A  | 0 | 0 | 1 | 1 | 0 | 0 | 0 | 0 | 0 | 0 | 1 | 0 | 1 | 0 | 0 | 1 |
| Solução B  | 1 | 0 | 0 | 1 | 0 | 1 | 0 | 0 | 1 | 0 | 1 | 0 | 0 | 1 | 1 | 0 |
| Nova Solução | 0 | 0 | 0 | 1 | 0 | 0 | 0 | 0 | 0 | 0 | 1 | 0 | 0 | 0 | 0 | 0 |

## Mutação

Existem dois tipos de mutação que podem ser aplicados:

a. Simples: a mutação simples modifica um bit de uma solução existente, obtendo assim uma nova solução.

b. Dupla: a mutação dupla tem o mesmo comportamento da simples, mas a nova solução tem dois bits modificados, no lugar de apenas um.

a) Simples
|      | A | B | C | D | E | F | G | H | I | J | K | L | M | N | O | P |
|------|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
| Solução Original  | 0 | 0 | 0 | 0 | 0 | 1 | 0 | 0 | 1 | 1 | 1 | 0 | 1 | 0 | 1 |
| Nova Solução | 0 | 0 | 0 | 0 | 0 | 1 | 1 | 0 | 1 | 1 | 1 | 0 | 1 | 0 | 1 |

b) Dupla

|      | A | B | C | D | E | F | G | H | I | J | K | L | M | N | O | P |
|------|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
| Solução Original  | 0 | 0 | 0 | 0 | 0 | 0 | 1 | 0 | 1 | 1 | 0 | 1 | 1 | 1 | 0 |
| Nova Solução | 0 | 0 | 0 | 1 | 0 | 0 | 1 | 0 | 1 | 1 | 0 | 1 | 0 | 1 | 0 |

## Ficamos então com essas soluções - (mais	4	soluções	novas	para	avaliar):

|     | A | B | C | D | E | F | G | H | I | J | K | L | M | N | O | P |
| --- | - | - | - | - | - | - | - | - | - | - | - | - | - | - | - | - |
| 60504 | 1 | 1 | 1 | 0 | 1 | 1 | 0 | 0 | 0 | 1 | 0 | 1 | 1 | 0 | 0 | 0 |
| 25000 | 0 | 1 | 1 | 0 | 0 | 0 | 0 | 1 | 1 | 0 | 1 | 0 | 1 | 0 | 0 | 0 |
| 12329 | 0 | 0 | 1 | 1 | 0 | 0 | 0 | 0 | 0 | 0 | 1 | 0 | 1 | 0 | 0 | 1 |
| 38054 | 1 | 0 | 0 | 1 | 0 | 1 | 0 | 0 | 1 | 0 | 1 | 0 | 0 | 1 | 1 | 0 |
| 1259  | 0 | 0 | 0 | 0 | 0 | 1 | 0 | 0 | 1 | 1 | 1 | 0 | 1 | 0 | 1 | 1 |
| 732   | 0 | 0 | 0 | 0 | 0 | 0 | 1 | 0 | 1 | 1 | 0 | 1 | 1 | 1 | 0 | 0 |
| 60584* | 1 | 1 | 1 | 0 | 1 | 1 | 0 | 0 | 1 | 0 | 1 | 0 | 1 | 0 | 0 | 0 |
| 4128*  | 0 | 0 | 0 | 1 | 0 | 0 | 0 | 0 | 0 | 0 | 1 | 0 | 0 | 0 | 0 | 0 |
| 1771*  | 0 | 0 | 0 | 0 | 0 | 1 | 1 | 0 | 1 | 1 | 1 | 0 | 1 | 0 | 1 | 1 |
| 4820*  | 0 | 0 | 0 | 1 | 0 | 0 | 1 | 0 | 1 | 1 | 0 | 1 | 0 | 1 | 0 | 0 |

## Resultado da Avaliação
Após a aplicação dos operadores genéticos, a avaliação será baseada no valor total dos objetos selecionados e no peso total da mochila. As soluções que ultrapassarem a capacidade de peso da mochila serão marcadas como "X", enquanto aquelas que estiverem dentro da capacidade serão marcadas como "OK".

| Solução | Valor ($) | Peso (Kg) | Resultado |
| ------ | --------- | --------- | --------- |
| 60504  | $69       | 40        | X         |
| 25000  | $45       | 22        | X         |
| 12329  | $60       | 17        | OK        |
| 38054  | $46       | 29        | X         |
| 1259   | $61       | 18        | OK        |
| 732    | $41       | 18        | OK        |
| ------ | --------- | --------- | --------- |
| 60584  | $66       | 41        | X         |
| 4128   | $30       | 6         | OK        |
| 1771   | $62       | 20        | OK        |
| 4820   | $41       | 17        | OK        |

### Conclusão
Após a avaliação das soluções geradas pelos operadores genéticos, podemos observar que as soluções com os números 12329, 1259, 732, 4128, 1771 e 4820 são consideradas válidas, pois estão dentro da capacidade de peso da mochila. Essas soluções representam diferentes combinações de objetos que maximizam o valor total dos objetos selecionados, buscando obter o maior valor possível dentro das restrições de peso da mochila.
