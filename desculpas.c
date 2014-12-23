/*
Cuca saiu para jogar futebol com os amigos e esqueceu do encontro que tinha com a namorada. Ciente da mancada, Cuca deseja elaborar um pedido especial de desculpas. Resolveu então enviar flores e usar o cartão da floricultura para escrever um pedido especial de desculpas.

Cuca buscou na internet um conjunto de frases bonitas contendo a palavra ‘desculpe’ (que pode ocorrer mais de uma vez na mesma frase). No entanto, o cartão da floricultura é pequeno, e nem todas as frases que Cuca colecionou poderão ser aproveitadas.

Cuca quer aproveitar o espaço do cartão, onde cabe um número limitado de caracteres, para escrever um sub-conjunto das frases coletadas de modo que apareça o máximo de vezes possível a palavra ‘desculpe’.

Tarefa

Escreva um programa que, dados o número de caracteres que cabem no cartão e a quantidade de frases coletadas (com os respectivos comprimentos e os números de ocorrências da palavra ‘desculpe’), determine o número máximo de vezes que a palavra aparece, utilizando apenas as frases colecionadas, sem repetí-las.

Entrada

A entrada é constituída de vários casos de teste. A primeira linha de um caso de teste contém dois números inteiros C e F indicando respectivamente o comprimento do cartão em caracteres (8 <= C <= 1000) e o número de frases coletadas (1 <= F <= 50). Cada uma das F linhas seguintes descreve uma frase coletada. A descrição é composta por dois inteiros N e D que indicam respectivamente o número de caracteres na frase (8 <= N <= 200) e quantas vezes a palavra ‘desculpe’ ocorre na frase (1 <= D <= 25). O final da entrada é indicado por C = F = 0.

Saída

Para cada caso de teste seu programa deve produzir três linhas na saída. A primeira identifica o conjunto de teste no formato “Teste n”, onde n é numerado a partir de 1. A segunda linha deve conter o máximo número de vezes que a palavra ‘desculpe’ pode aparecer no cartão, considerando que apenas frases coletadas podem ser utilizadas, e cada frase não é utilizada mais de uma vez. A terceira linha deve ser deixada em branco. A grafia mostrada no Exemplo de Saída, abaixo, deve ser seguida rigorosamente.

Exemplo

Entrada:
200 4
100 4
100 1
120 2
80 5
40 3
10 1
10 1
20 2
0 0

Saída:
Teste 1
9

Teste 2
4

Restrições

8 <= C <= 1000 (C = 0 apenas para indicar o fim da entrada)
1 <= F <= 50 (S = 0 apenas para indicar o fim da entrada)
8 <= N <= 200
1 <= D <= 25


*/


/*
 * SPOJ Maratona de programação
 * By Eliseu Torres
 */
 
#include <stdio.h>
#include <stdlib.h>

#define TAM 1000
#define max(m, n) ((m) > (n) ? (m) : (n))


int mochila(int cartao, int palavras[], int val[], int n)
{
   int i, j;
   int X[n+1][cartao+1];
 
   for (i = 0; i <= n; i++){
       for (j = 0; j <= cartao; j++){
           if (i==0 || j==0)
               X[i][j] = 0;
           else if (palavras[i-1] <= j)
                 X[i][j] = max(val[i-1] + X[i-1][j-palavras[i-1]],  X[i-1][j]);
           else
                 X[i][j] = X[i-1][j];
       }
   }
 
   return X[n][cartao];
}

int main ()
{   
   int tam_cartao = 0;
   int frases = 0;
   int val[TAM], palavras[TAM];
   int i,teste = 1;
   
   
   while (1){
       scanf ("%i",&tam_cartao);
       scanf ("%i",&frases);
       if (tam_cartao == 0 || frases == 0) break;
       for ( i = 0; i < frases; i++){
            scanf ("%i%i",&palavras[i],&val[i]);
       }     
       printf("Teste %i\n%i\n\n",teste++, mochila(tam_cartao, palavras, val, frases));
      
   }
   return 0;
}

