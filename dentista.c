/*
Os dentistas são extremamente meticulosos em seu trabalho, tendo que agir com muita precisão em todas as suas atividades. Pedro é um dentista meticuloso como todos os outros. Infelizmente sua secretária não é muito organizada e, com o intuito de ajudar sempre os pacientes, aceita que eles marquem consultas no horário que quiserem, sem se preocupar com os demais horários marcados, ocasionando vários coníitos de horários que muito incomodaram Pedro e os pacientes. Por exemplo, se uma consulta começar às 9 horas e durar 2 horas, nenhuma outra consulta deveria ser marcada para iniciar as 10 horas.

Ao perceber que sua agenda tinha coníito de horários, Pedro pediu sua ajuda para descobrir a maior quantidade de consultas que podem ser atendidas sem sobreposição.

Tarefa

Você deve escrever um programa que, dados os horários de início e término das consultas agendadas pela secretária, responda a quantidade máxima de consultas que podem ser atenditas sem sobreposição.

Entrada

A primeira linha da entrada contém um inteiro N (1 ≤ N ≤ 10.000) que indica quantas consultas a secretária marcou. Cada uma das N linhas seguintes contém um par de inteiros X e Y separados por um espaço em branco (0 ≤ X < Y ≤ 1.000.000) que representam, respectivamente, o horário de início e de término da consulta. Considere que se uma consulta inicia no exato instante em que outra termina não há sobreposição. Os horários de início são fornecidos em ordem, podendo haver mais de uma consulta que inicie no mesmo horário.

Saída

Seu programa deve imprimir uma única linha, contendo um inteiro que representa a quantidade máxima de consultas que podem ser atendidas sem que haja qualquer sobreposição.

Exemplo

Entrada
3
10 100
40 130
120 200

Saída
2

Entrada

4
10 20
20 30
30 40
40 50

Saída
4

Entrada
5
10 30
20 40
30 60
40 80
60 100

Saída
3

*/

/*
 * SPOJ Maratona de programação
 * By Eliseu Torres
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct consultas{
  int inicio;
  int fim;  
}consultas;

void troca(consultas X[], int i, int j)
{
   consultas aux;
   aux = X[i];
   X[i] = X[j];
   X[j] = aux;
}

int particao(consultas X[], int p, int r)
{
   int i, j;
   consultas pivo;
   
   pivo = X[(p + r)/ 2];
   i = p - 1;
   j = r + 1;
   while(i < j){
      do{
         j--;
      }while(X[j].fim > pivo.fim);
      
      do{
         i++; 
      }while(X[i].fim < pivo.fim);
      if(i < j)
         troca(X, i, j);
   }
   
   return j;
}

void quicksort(consultas X[], int p, int r)
{
   int q;
   if(p < r){
      q = particao(X, p, r);
      quicksort(X,p, q);
      quicksort(X, q+1, r);
   }
}



int main()
{
  int i, j, N, count = 1;
  
  scanf("%i", &N);
  consultas paciente[N];
  
  for(i = 0; i < N; i++){
    scanf("%i", &paciente[i].inicio);
    scanf("%i", &paciente[i].fim);    
        
  }
  
  quicksort(paciente, 0, N);
  
  for(i = 1, j = 0; i < N; i++){
      if(i > 0){
	if(paciente[j].fim <= paciente[i].inicio){
	  count++;
	  j = i;
	}  
    }
  }
  
  printf("%i\n", count);  
  
  return 0;
}
