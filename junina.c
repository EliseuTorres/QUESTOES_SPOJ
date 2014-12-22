/*
Conforme a tradição da sua escola, os alunos do último ano do ensino médio organizarão uma festa junina no colégio. Porém, o diretor da escola tem tido problemas nos últimos anos com a organização desta festa, e ele percebeu que a causa destes problemas é a presença de alunos que não se toleram na comissão organizadora. Assim, neste ano, o diretor resolveu que ele mesmo designaria a comissão organizadora da festa junina, de forma que não haja inimizades entre os membros da comissão. Para isto, o diretor distribuiu um formulário a todos alunos da turma; cada aluno deve listar os alunos com os quais ele não gostaria de participar da comissão organizadora. A partir destas informações, o diretor deseja montar uma comissão organizadora para a festa com o maior número possível de alunos, de forma a não sobrecarregar os seus integrantes.

Tarefa

Dadas as informações retiradas dos formulários de todos os alunos, sua tarefa é determinar qual o número máximo de alunos que a comissão organizadora pode ter.

Entrada

A entrada é composta de vários conjuntos de teste. A primeira linha de um conjunto de teste contém um número inteiro N, que indica o número de alunos na turma (N <= 20). Os alunos são identificados seqüencialmente pelos números de 1 a N. A seguir, para cada um dos N alunos, seguindo a ordem dos números de identificação, há uma linha contendo a lista dos alunos com os quais este aluno não gostaria de participar na comissão organizadora. O final de uma lista é indicado pelo número zero, e o final da entrada é indicado por um conjunto de teste com N = 0.

Exemplo de entrada
5
2 4 0
1 0
0
5 3 0
4 0
6
6 0
6 0
6 0
6 0
6 0
0
0
Saída

Para cada conjunto de teste da entrada seu programa deve produzir três linhas na saída. A primeira linha deve conter um identificador do conjunto de teste, no formato "Teste n", onde n é numerado seqüencialmente a partir de 1. A segunda linha deve conter o número máximo de alunos que podem participar em uma mesma comissão organizadora, conforme calculado pelo seu programa.

A terceira linha deve ser deixada em branco. A grafia mostrada no Exemplo de Saída, abaixo, deve ser seguida rigorosamente.

Exemplo de Saída
Teste 1
3

Teste 2
5
(esta saída corresponde ao exemplo de entrada acima)

Restrições

0 <= N <= 20 (N = 0 apenas para indicar o fim da entrada)

*/

/*
 * SPOJ Maratona de programação
 * By Eliseu Torres
 */


#include <stdio.h>
#include <stdlib.h>

#define TAM 20

int N, particao[TAM], gosta[TAM][TAM], melhor;

void backtracking(int m, int n) 
{ 
	int participante;
   particao[n++] = m;
   
   if(n > melhor)
   	melhor = n;
   
   for(participante = m + 1; participante < N; participante++)
   	if(verifica_preferencia(participante, n))
   		backtracking(participante, n);
}


int verifica_preferencia(int proximo, int quantidade) 
{
	int i;	
		  	
   for(i = 0; i < quantidade; i++)
   	if(!gosta[particao[i]][proximo])
   		return 0;
   		
   return 1;
}

int maior_particao() 
{
	int i;        
   int melhor_solucao = 0;
        
   for(i = 0; i < N; i++){
   	melhor = 0;
      backtracking(i, 0);
      if(melhor > melhor_solucao)
      	melhor_solucao = melhor;
      if(melhor_solucao == N)
      	break;
	}
  
  return melhor_solucao;
}

int main() 
{
	int i, j, m, v, count = 1;

   while(scanf("%i", &N) && N > 0){
   	for(i = 0; i < N; i++)
      	for(j = 0; j < N; j++)
         	gosta[i][j] = 1;

      for(m = 0; m < N; m++)
      	while(scanf("%i", &v) && v > 0)
         	gosta[m][v - 1] = gosta[v - 1][m] = 0;

   	printf("Teste %i\n%i\n\n", count++, maior_particao());
  }

   return 0;
}
