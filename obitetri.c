/*
A sua turma do colégio resolveu organizar um campeonato de tetris. Após discussão sobre as regras, ﬁcou deﬁnido que cada aluno jogaria um total de 12 partidas. Das 12 pontuações obtidas por um aluno, a maior e a menor são descartadas, e as demais são somadas, resultando na pontuação ﬁnal do aluno.

Tarefa

Como você possui conhecimentos de programação, acabou sendo designado pela turma para escrever um programa para imprimir a classiﬁcação ﬁnal do campeonato, a partir das pontuações de cada jogador.

Entrada

A entrada é composta de vários conjuntos de teste. A primeira linha de um conjunto de testes contém um número inteiro J, que indica o número de jogadores que participaram do campeonato. A seguir, para cada jogador há duas linhas na entrada: a primeira possui o nome do jogador (formado apenas por letras, sendo apenas a inicial em maiúscula, e com no máximo 15 letras), e a segunda possui as 12 pontuações que o jogador obteve, separadas por espaço. As pontuações são inteiros entre 0 e 1000. O ﬁnal da entrada é indicado por um conjunto de teste com J = 0.

Saída

Para cada conjunto de teste, o seu programa deve escrever uma linha contendo o identiﬁcador do conjunto de teste, no formato “Teste n”, onde n é numerado seqüencialmente a partir de 1. A seguir, o seu programa deve escrever a classiﬁcação ﬁnal no campeonato, utilizando uma linha para cada participante. Cada linha deve conter três informações, separadas por um espaço em branco: a classiﬁcação do jogador, a sua pontuação ﬁnal, e o seu nome. A classiﬁcação de um jogador é igual a 1 mais o número de jogadores que obtiveram pontuação maior do que a sua. Em caso de empate, os jogadores devem ser ordenados em ordem alfabética. Depois de toda a classiﬁcação, deve ser deixada uma linha em branco. O formato do exemplo de saída abaixo deve ser seguido rigorosamente.

Exemplo

Entrada:
4
Zezinho
100 123 133 333 400 300 129 200 360 340 200 600
Luizinho
60 50 120 250 170 190 190 220 260 270 290 300
Carlinhos
10 10 20 10 10 10 10 20 20 20 20 20
Joaozinho
200 300 400 400 500 500 500 600 650 650 700 810
3
Pedrinho
100 100 200 200 300 300 400 400 500 500 600 600
Huguinho
50 100 200 200 300 300 500 500 400 400 600 700
Zezinho
100 100 100 100 100 100 100 100 100 100 100 100
0

Saída:
Teste 1
1 5200 Joaozinho
2 2518 Zezinho
3 2020 Luizinho
4 150 Carlinhos

Teste 2
1 3500 Huguinho
1 3500 Pedrinho
3 1000 Zezinho

Restrições

0 <= J <= 1000 (J = 0 apenas para indicar ﬁnal da entrada)
0 <= pontuação em uma partida <= 1000 
1 <= tamanho dos nomes, em número de letras <= 15


/*
/*
 * SPOJ Maratona de programação
 * By Eliseu Torres
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define TAM 1000

typedef struct jogador{   
   char nome[16];   
   int pontos;
   int colocacao;
}jogador;

int ler_pontos()
{
   int i, maior, menor, pontos, valor;
   
   pontos = maior = 0;
   menor = TAM + 1;
   
   for(i = 0; i < 12; i++){
      scanf("%i", &valor);
      pontos += valor;
      
      if(valor > maior)
         maior = valor;
         
      if(valor < menor)
         menor = valor;   
   }
   
   return (pontos -= (maior + menor));   
}

void imprimir(jogador jogo[], int N, int cont)
{
   int i;
   
   printf("Teste %i\n", cont);
   for(i = 0; i < N; i++){      
      printf("%d %d %s\n",jogo[i].colocacao, jogo[i].pontos, jogo[i].nome);
   }
   
}

void ordenar_pontos(jogador jogo[], int p, int r)
{
   int i, j, q;
   jogador pivo, aux;
   
   q = (p + r) / 2;
   
   pivo = jogo[q];
   
   i = p;
   j = r;
   
   while(i < j){
      while(jogo[i].pontos > pivo.pontos) i++;
      
      while(jogo[j].pontos < pivo.pontos) j--;
      
      if(i <= j){
         aux = jogo[i];
         jogo[i] = jogo[j];
         jogo[j] = aux;
         i++;
         j--;
      }         
  } 
  
  if(p < j)
   ordenar_pontos(jogo, p, j); 
  if(i < r)
   ordenar_pontos(jogo, i, r);    
}

void ordenar_nome(jogador jogo[], int p, int r)
{
   int i, j, q;
   jogador pivo, aux;
   
   q = (p + r) / 2;
   
   pivo = jogo[q];
   
   i = p;
   j = r;
   
   while(i < j){
      while(strcmp(jogo[i].nome, pivo.nome) < 0) i++;
      
      while(strcmp(jogo[j].nome, pivo.nome) > 0) j--;
      
      if(i <= j){
         aux = jogo[i];
         jogo[i] = jogo[j];
         jogo[j] = aux;
         i++;
         j--;
      }         
  } 
  
  if(p < j)
   ordenar_nome(jogo, p, j); 
  if(i < r)
   ordenar_nome(jogo, i, r);    
}


void classificar(jogador jogo[], int N)
{
   int i, j, pontos = 0, fim, classificacao = 0;
   
   ordenar_pontos(jogo, 0, N - 1);
   
   for(i = 0; i < N; i++){
      if(jogo[i].pontos == jogo[i - 1].pontos){
         fim = i;
         for(j = i + 1; j < N; j++){
            if(jogo[j].pontos == jogo[i].pontos)
               fim = j;
         }
         
         ordenar_nome(jogo, i - 1, fim);
         fim = i;
      }   
   }
   
   for(i = 0; i < N; i++){
      if(jogo[i].pontos == pontos)
         jogo[i].colocacao = classificacao;
      else
         jogo[i].colocacao = i + 1;
         
      pontos = jogo[i].pontos;
      classificacao = jogo[i].colocacao;      
   }
}


int main()
{
   int i, N, cont;
   
   cont = 1;
   
   scanf("%i", &N);
   while(N != 0 && N < 1001){
      jogador jogo[N];
      
      for(i = 0; i < N; i++){
         scanf("%15s", jogo[i].nome);
         jogo[i].pontos = ler_pontos();
      }
      classificar(jogo, N);
      imprimir(jogo, N, cont);
      cont++;
      scanf("%i", &N);   
   }
   
   
   
   
   return 0;
}
