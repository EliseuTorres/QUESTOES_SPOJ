/*
Juliano é fã do programa de auditório Apagando e Ganhando, um programa no qual os participantes são selecionados atráves de um sorteio e recebem prêmios em dinheiro por participarem.

No programa, o apresentador escreve um número de N dígitos em uma lousa. O participante então deve apagar exatamente D dígitos do número que está na lousa; o número formado pelos dígitos que restaram é então o prêmio do participante.

Juliano finalmente foi selecionado para participar do programa, e pediu que você escrevesse um programa que, dados o número que o apresentador escreveu na lousa, e quantos dígitos Juliano tem que apagar, determina o valor do maior prêmio que Juliano pode ganhar.

Entrada

A entrada contém vários casos de teste. A primeira linha de cada caso de teste contém dois inteiros N e D (1 <= D < N <= 10^5), indicando a quantidade de dígitos do número que o apresentador escreveu na lousa e quantos dígitos devem ser apagados. A linha seguinte contém o número escrito pelo apresentador, que não contém zeros à esquerda.

O final da entrada é indicado por uma linha que contém apenas dois zeros, separados por um espaço em branco.

Saída

Para cada caso de teste da entrada seu programa deve imprimir uma única linha na saída, contendo o maior prêmio que Juliano pode ganhar.

Exemplo

Entrada:
4 2                
3759               
6 3                
123123
7 4
1000000
0 0

Saída:
79
323
100
*/

/*
 * SPOJ Maratona de programação
 * By Eliseu Torres
 */



#include <stdio.h>
#include <stdlib.h>

int acha_maior(char valor, char *premio, int inicio, int fim)
{
	int meio;
	
	while(inicio <= fim){
		meio = (inicio + fim) / 2;
		if(premio[meio] < valor)
			fim = meio - 1;
		else
		   inicio = meio + 1;	
	}
	
	return inicio;	
}

int main()
{
	int i, j, N, D, num, resto;
	
	scanf("%i", &N);
	scanf("%i", &D);	
		
	while(N > 0 && D > 0){	
	
		char valor[N + 1];
		scanf("%s", valor);
		
		resto = N - D;
		char premio[resto + 1];
	
		premio[0] = valor[0];
	
		for(i = 1, j = 0; i < N; i++){
			if(i <= D)
				num = acha_maior(valor[i], premio, 0, j);
			else
				num =	acha_maior(valor[i], premio, i-D, j);	
			
			if(num < resto){
				premio[num] = valor[i];
				j = num;
			}	
		}	
	
		premio[resto] = '\0';
		
		printf("%s\n", premio);	
		scanf("%i", &N);
		scanf("%i", &D);	
	}
	return 0;
}
