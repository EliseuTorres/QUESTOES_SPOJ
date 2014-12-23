/*
Com a proximidade da Copa do Mundo, o fluxo de pessoas nas filas para compra de ingressos aumentou consideravelmente. Como as filas estão cada vez maiores, pessoas menos pacientes tendem a desistir da compra de ingressos e acabam deixando as filas, liberando assim vaga para outras pessoas. Quando uma pessoa deixa a fila, todas as pessoas que estavam atrás dela dão um passo a frente, sendo assim nunca existe um espaço vago entre duas pessoas. A fila inicialmente contém N pessoas, cada uma com um identificador diferente. Joãozinho sabe o estado inicial dela e os identificadores em ordem das pessoas que deixaram a fila. Sabendo que após o estado inicial nenhuma pessoa entrou mais na fila, Joãozinho deseja saber o estado final da fila.

Entrada
A primeira linha contém um inteiro N representando a quantidade de pessoas inicialmente na fila. A segunda linha contém N inteiros representando os identificadores das pessoas na fila. O primeiro identificador corresponde ao identificador da primeira pessoa na fila. É garantido que duas pessoas diferentes não possuem o mesmo identificador. A terceira linha contém um inteiro M representando a quantidade de pessoas que deixaram a fila. A quarta linha contém M inteiros representando os identificadores das pessoas que deixaram a fila, na ordem em que elas saíram. É garantido que um mesmo identificador não aparece duas vezes nessa lista.

Saída
Seu programa deve imprimir uma linha contendo N − M inteiros com os identificadores das pessoas que permaneceram na fila, em ordem de chegada.

Restrições
• 1 ≤ N ≤ 50000
• 1 ≤ M ≤ 50000 e M < N
• Cada identificador está entre 1 e 100000

Exemplos

Entrada
8
5 100 9 81 70 33 2 1000
3
9 33 5

Saída
100 81 70 2 1000

Entrada
4
10 9 6 3
1
3

Saída
10 9 6

*/

/*
 * SPOJ Maratona de programação
 * By Eliseu Torres
 */

   
   #include <stdio.h>
   #include <stdlib.h>

   typedef struct lista{
      int num;
      struct lista *prox;
   }lista;

   lista *fila, *final;
   
  

   void incluir(int num)
   {
      lista *novo, *aux;
      
      novo = (lista *)malloc(1 * sizeof(lista));
      
      novo->num = num;
      novo->prox = NULL;
      

      
      if(!fila){
         fila = novo;
         final = fila;
         return;
      }else{
            aux = final;
            if(aux != NULL){
               if(aux->num == num){
                  printf("Numero Já existe");
                  return;
               }               
            }
            aux->prox = novo;
            final = aux->prox; 
            return;
      }   
      
   }


   void excluir(int num)
   {
      lista *ultimo, *aux;
      ultimo = fila;
      aux = NULL;
      
      while((ultimo != NULL ) && (ultimo->num != num)){
         aux = ultimo;
         ultimo = ultimo->prox;
      }
      if(ultimo == NULL){
         printf("Esse numero não existe\n");
         return;
      }else{
         if(aux == NULL){      
            aux = ultimo->prox;
            fila = aux;
            free(ultimo);       
            return;
         }else{
            aux->prox = ultimo->prox;         
            free(ultimo);
            return;             
         }   
      }      
   }

   void display(lista *ultimo)
   {
      if(ultimo != NULL){
         printf("%d ", ultimo->num);
         if(ultimo->prox != NULL)      
            display(ultimo->prox);
      }
      return;
   }
   
   
    void ingresso(int N)
   {
      int num;
      
      if(N < 2){
         scanf("%i", &num);
         if(num <= 100000){
            incluir(num);            
            return;
         }
         printf("Valor muito alto");
         exit(2);   
      }else{
         scanf("%i", &num);
         if(num <= 100000){
            incluir(num);
            N--;
            ingresso(N);
            return;
         }
         printf("Valor muito alto");
         exit(2);          
      } 
   }
   
   void remover(int N)
   {
      int num;
      
      if(N < 2){
         scanf("%i", &num);
         if(num <= 100000){
            excluir(num);
            return;
         }
         printf("Valor muito alto");
         exit(2);   
      }else{
         scanf("%i", &num);
         if(num <= 100000){
            excluir(num);
            N--;
            remover(N);
            return;
         }
         printf("Valor muito alto ");
         exit(2);
      }
   }

   int main()
   {
      int i, num, N, M;
      

      scanf("%i", &N);
      
      if(N <= 50000){
         ingresso(N);
      }else{
         printf("Valor muito alto");
         return 2;
      }
               
      
      
      scanf("%i", &M);     
      if(M <= N){
         
         remover(M);
      }else{
         printf("Valor muito alto");
         return 2;
      }
      
      N -= M;
      
      lista *ultimo;
      
      ultimo = fila;
      
      
      display(ultimo);
      printf("\n");
      
      free(fila);

      return 0;
   }

