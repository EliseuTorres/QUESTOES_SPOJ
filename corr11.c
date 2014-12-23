/*
Todo ano, os habitantes da Mlogônia, apesar das crises internas, reúnem-se em torno de um esporte que é a paixão nacional: as corridas de carros. A Grande Corrida anual é um enorme evento organizado pela Associação de Corridas da Mlogônia (ACM), sendo amplamente televisionado e reportado em jornais e revistas de todo o país. Os resultados da corrida são tema principal das rodas de conversa por semanas.

Por bastante tempo, os resultados da Grande Corrida eram compilados manualmente. Observadores especializados iam à pista medir o tempo de cada um dos N carros, numerados de 1 a N, em cada uma das M voltas, anotando então os resultados em tabelas para posterior análise por parte das equipes e dos jornalistas. Muitos erros eram introduzidos nesse processo, e a organização decidiu informatizar todo o sistema.

A ACM percebeu que o esforço necessário para a construção do sistema seria grande, e optou por contar com a ajuda de uma equipe de programadores. Percival foi contratado para escrever a parte do software que determina quais foram os carros vencedores, mas está com dificuldades e pede sua ajuda. A sua tarefa, neste problema, é determinar os três carros melhor colocados, fornecidos os tempos que cada carro levou para completar cada volta da corrida.

Entrada

A primeira linha da entrada contém dois inteiros N e M representando o número de carros e o número de voltas da corrida, respectivamente.

Cada uma das N linhas seguintes representa um carro: a primeira linha representa o primeiro carro, a segunda linha representa o segundo carro, e assim por diante. Cada linha contém M inteiros representando os tempos em cada volta da corrida: o primeiro inteiro é o tempo da primeira volta, o segundo inteiro é o tempo da segunda volta, e assim por diante.

Garante-se que não houve dois carros que gastaram o mesmo tempo para completar a corrida inteira.

Saída

A saída consiste de três linhas, contendo um único inteiro cada. A primeira linha contém o número do carro que ganhou a corrida, a segunda contém o número do segundo colocado e a terceira contém o número do terceiro colocado.

Restrições

3 ≤ N ≤ 100
1 ≤ M ≤ 100
1 ≤ qualquer número da entrada que represente o tempo de uma volta ≤ 106
Exemplos

Entrada
3 1
1
2
3

Saída
1
2
3

Entrada
5 2
3 7
2 5
1 1
15 2
2 2

Saída
3
5
2
*/


/*
 * SPOJ Maratona de programação
 * By Eliseu Torres
 */


#include <stdio.h>
#include <stdlib.h>

typedef struct carro{
   int num;
   int tempo;
}carro;

void troca(carro X[], int i, int j)
{
   carro aux;
   aux = X[i];
   X[i] = X[j];
   X[j] = aux;
}

int particao(carro X[], int p, int r)
{
   int i, j;
   carro pivo;
   
   pivo = X[(p + r)/ 2];
   i = p - 1;
   j = r + 1;
   while(i < j){
      do{
         j--;
      }while(X[j].tempo > pivo.tempo);
      
      do{
         i++; 
      }while(X[i].tempo < pivo.tempo);
      if(i < j)
         troca(X, i, j);
   }
   
   return j;
}

void quicksort(carro X[], int p, int r)
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
   int N, M, i, j, tempo;
   
   scanf("%i", &N);
   if((N < 3) || (N > 100)){
      return 2;
   }
   
   scanf("%i", &M);
   if((M < 1) || (M > 100)){
      return 2;
   }
   
   carro carros[N];

   for(i = 0; i < N; i++){
      carros[i].num = i + 1;
      carros[i].tempo = 0;
      for(j = 0; j < M; j++){
         scanf("%i", &tempo);
         carros[i].tempo += tempo;
      }
   }
   
   quicksort(carros, 0, N-1);
   
   printf("%i\n", carros[0].num);
   printf("%i\n", carros[1].num);
   printf("%i\n", carros[2].num);
   
   return 0;
}



