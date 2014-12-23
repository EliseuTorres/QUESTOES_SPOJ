/*
Os números proibidos são números que possuem alguma representação problemática, por exemplo, número do azar, de algo ruim, e até números que são senhas do governo. 

O número proibido mais conhecido é um númeroprimo\footnote{http://en.wikipedia.org/wiki/Illegal\_prime} que foidescoberto em 2001 e representa o arquivo binário da versão compactada docódigo C que implementa o algoritmo DeCSS, que pode ser utilizado paralograr o sistema de proteção do DVD.Luan, um rapaz que tem muito receio de ser procurado por agências espiãsinternacionais coletou um conjunto de números ilegais e está filtrando essesnúmeros de todos os seus arquivos no computador.Infelizmente, Luan ainda não sabe programar muito bem e pediu a sua ajudapara implementar um programa que receba um conjunto de números ilegais eresponda se um outro conjunto de números fazem parte dos números ilegais.
O número proibido mais conhecido é um número primo[1] que foi descoberto em 2001 e representa o arquivo binário da versão compactada do código C que implementa o algoritmo DeCSS, que pode ser utilizado para lograr o sistema de proteção do DVD.

Luan, um rapaz que tem muito receio de ser procurado por agências espiãs internacionais coletou um conjunto de números ilegais e está filtrando esses números de todos os seus arquivos no computador.

Infelizmente, Luan ainda não sabe programar muito bem e pediu a sua ajuda para implementar um programa que receba um conjunto de números ilegais e responda se um outro conjunto de números fazem parte dos números ilegais.

[1]http://en.wikipedia.org/wiki/Illegal_prime

 

Entrada

A entrada é composta por um único caso teste que possui diversas linhas. A primeira linha possui um número N ( 1 <= N <= 140000 ) que representa a quantidade de números proibidos existentes. A segunda linha do caso de teste possui N números Pi ( 0 <= Pi <= 231 ) representando os números proibidos.

Depois existirão diversas linhas contendo um único número que se quer saber se é proibido ou não.

A entrada termina em EOF.

Saída

Para cada número da consulta deve-se imprimir uma única linha contendo a palavra sim se o número for proibido, ou nao caso o número não seja proibido.

Exemplo

Entrada:
7
10 0 50 25 121 0 3000
1
2
3
10
0

Saída:
nao
nao
nao
sim
sim

*/


/*
 * SPOJ Maratona de programação
 * By Eliseu Torres
 */

#include <stdio.h>
#include <stdlib.h>

void troca(int X[], int i, int j)
{
   int aux;
   aux = X[i];
   X[i] = X[j];
   X[j] = aux;
}

int particao(int X[], int p, int r)
{
   int i, j;
   int pivo;
   
   pivo = X[(p + r)/ 2];
   i = p - 1;
   j = r + 1;
   while(i < j){
      do{
         j--;
      }while(X[j] > pivo);
      
      do{
         i++; 
      }while(X[i] < pivo);
      if(i < j)
         troca(X, i, j);
   }
   
   return j;
}

void quicksort(int X[], int p, int r)
{
   int q;
   if(p < r){
      q = particao(X, p, r);
      quicksort(X,p, q);
      quicksort(X, q+1, r);
   }
}

int busca_binaria(int X[], int N, int valor)
{
   int baixo, alto, meio;
   baixo = 0;
   alto = N - 1;
   while(baixo <= alto){
      meio = (baixo + alto) / 2;
      if(valor < X[meio])
         alto = meio - 1;
      else if(valor > X[meio])
         baixo = meio + 1;
      else
         return 1;      
   }
   return 0;
}



int main()
{
   int i, j, N;
   
   scanf("%i", &N);
   if((N < 1) || (N > 140000)){
      return 2;
   }
   
   int proib[N], num;
   
   for(i = 0; i < N; i++){
      scanf("%i", &proib[i]);
   } 
   
                

   
   quicksort(proib, 0, N);
   
   
   while(scanf("%i", &num) != EOF){     
      if(busca_binaria(proib, N, num))
         printf("sim\n");
      else
         printf("nao\n");   
   }   
   
   
  return 0; 
}
