/*
Cansados de brincar de bafo, Aldo e Beto inventaram uma nova brincadeira: um deles escolhe algumas de suas figurinhas, coloca-as em uma ordem qualquer e não a mostra para o outro, apenas informando quais figurinhas foram selecionadas. O outro, então, deve tentar adivinhar em qual ordem as figurinhas estão.

Após algumas rodadas da brincadeira, eles perceberam que a tarefa de tentar adivinhar a ordem das figurinhas pode ser bastante custosa, especialmente se o número de figurinhas for grande. Perder-se nas tentativas, esquecendo de tentar algumas opções e tentando outras mais de uma vez, não é nada difícil.

Querendo dar uma de esperto, Aldo teve a idéia de criar um programa de computador que dê, para as figurinhas selecionadas, todas as possibilidades de ordenação daquelas. Porém, como Aldo não sabe programar, ele pede que você faça tal programa.

Entrada

A entrada é composta por vários casos de teste, um por linha. Um caso de teste é iniciado com um número inteiro n (1 <= n <= 8), indicando a quantidade de figurinhas selecionadas. A seguir, são dados n números inteiros distintos, correspondentes aos números das figurinhas selecionadas. Cada número de figurinha é tal que seu valor absoluto é menor que 1000000000.

A entrada termina quando n = 0, caso que não deve ser processado.

Saída

Para cada caso de teste, seu programa deve imprimir uma lista de possibilidades de ordenação das figurinhas. Cada possibilidade de ordenação deve estar em uma linha, na qual devem ser impressos os números das figurinhas, na ordem correspondente, com exatamente um espaço entre cada número.

Imprima as possibilidades de ordenação em ordem lexicográfica. Por esta ordem, uma possibilidade de ordenação a1, ..., an deve ser impressa antes de outra b1, ..., bn se, para um determinado k (1 <= k <= n), temos o seguinte:

ai = bi, para todo i < k (i > 0); e
ak < bk.
Deixe uma linha em branco entre as saídas de cada caso de teste.

Exemplo

Entrada:
3 10 20 30
2 1 2
2 2 1
0

Saída:
10 20 30
10 30 20
20 10 30
20 30 10
30 10 20
30 20 10

1 2
2 1

1 2
2 1
*/

/*
 * SPOJ Maratona de programação
 * By Eliseu Torres
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define AB 1000000003

void troca(long X[], int i, int j)
{
   long aux;
   aux = X[i];
   X[i] = X[j];
   X[j] = aux;
}

int particao(long X[], int aux, int r)
{
   int i, j;
   int pivo;
   
   pivo = X[(aux + r)/ 2];
   i = aux - 1;
   j = r + 1;
   while (i < j) {
      do {
         j--;
      } while (X[j] > pivo);
      
      do {
         i++; 
      } while(X[i] < pivo);
      if (i < j)
         troca(X, i, j);
   }
   
   return j;
}

void quicksort(long X[], int aux, int r)
{
   int q;
   if (aux < r) {
      q = particao(X, aux, r);
      quicksort(X,aux, q);
      quicksort(X, q+1, r);
   }
}

void backtrack(long fig[], long aux[], int n, int k)
{
	int i, j, inv[n];

   if (n == k) {
   	for (i = 0; i < n; i++){
      	printf("%d", aux[i]);
         if (i != (n - 1))
         	printf(" ");
      }

   	printf("\n");
   } else {
		memset(inv,1,sizeof(inv));

      for (i = 0; i < n; i++)
      	for (j = 0; j < n; j++)
      		if (aux[i] == fig[j])
         		inv[j] = 0;

      for (i = 0; i < n; i++)
      	if (inv[i]) {
         	aux[k] = fig[i];
         	backtrack(fig, aux, n, k + 1);
            aux[k] = AB;
         }
   }
}

int main()
{
	int i, n, teste = 1;
	
	scanf("%i", &n);
	while (n != 0) {
		long fig[n], aux[n];
		
		for (i = 0; i < n; i++) {
			scanf("%li", &fig[i]);
		}		
		
		memset(aux, AB, sizeof(aux));
	
		quicksort(fig, 0, n - 1);		
		backtrack(fig, aux, n, 0);
		scanf("\n%i", &n);
	}
	return 0;
}
