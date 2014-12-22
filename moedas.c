/*
O rei de Pinelândia tinha alergia ao material que compunha o dinheiro de seu país, e por isso resolveu acabar com todas as células, e mandou fabricar, dali em diante, apenas moedas. Os valores destas, ao contrário do que se esperava, não eram, necessariamente, múltiplos de 5. Como os preços das mercadorias, em Pinelândia, eram caríssimos, o povo tinha sérios problemas em fazer comércio, pois, dependendo do valor do que seria comprado ou vendido, o número de moedas a ser utilizado poderia ser muito alto. Por exemplo, se as moedas fabricadas fossem apenas de 5 tostões (a unidade monetária do reinado), um cidadão deveria usar 200 moedas para comprar algo que custasse 1000 tostões. Entretanto, se houvesse moedas de 35 e de 150, a pessoa precisaria ter apenas 22 moedas: 20 de 35 e 2 de 150.

Você deve escrever um programa que, dados o preço de uma mercadoria e os valores das moedas disponíveis, calcule o menor número possível de moedas necessário para comprar o produto sem haver troco, ou seja, o menor número de moedas tal que o total seja exatamente o preço da mercadoria.

Entrada

O arquivo de entrada contém vários casos de teste. Cada caso inicia com dois inteiros, m (1 <= m <= 50000), correspondente ao preço da mercadoria, e n (1 <= n <= 100), o número de moedas. A seguir, há n inteiros, 0 < v_1 < v_2 < ... < v_n < 50000, que correspondem aos valores de cada moeda. Pode haver quebras de linha e espaços extras entre os números e após os mesmos.

A entrada termina quando m = 0, caso que não deve ser processado.

Saída

A saída consiste de tantas linhas quantos casos de teste houver. Em cada linha, deve ser impresso o menor número de moedas necessário para comprar o produto correspondente àquele caso. Se em algum caso não for possível utilizar as moedas para chegar exatamente ao valor solicitado, escreva Impossivel'' (sem aspas e sem acento).

Exemplo

Entrada:
1000 2
35 150
110 3 20 30 60
3 2 2 9
0

Saída:
22
3
Impossivel
*/

/*
 * SPOJ Maratona de programação
 * By Eliseu Torres
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define min(m,n) ((m < n) ? m : n)
#define V_MAX 50000
#define M_MAX 100 

int main()
{
	int i, j, val, nmoedas;
	int p_val[V_MAX];	
	int moedas[M_MAX];
	
	scanf("%i", &val);
	while (val){

		scanf("%i", &nmoedas);
		memset(p_val,0,sizeof(p_val));

		for (i = 0; i < nmoedas; i++){
			scanf("%i", &moedas[i]);
			p_val[moedas[i]] = 1;
		}

		for (i = 1; i <= val; i++){
			if (p_val[i])
				for (j = 0; j < nmoedas; j++){
					if (i + moedas[j] > val) break;
					if (p_val[i + moedas[j]] == 0) p_val[i + moedas[j]] = p_val[i] + 1;
					else p_val[i + moedas[j]] = min(p_val[i + moedas[j]],p_val[i] + 1);
			}
		}

		if (p_val[val]) 
			printf("%i",p_val[val]);
		else 
			printf("Impossivel");
		
		printf("\n");
		scanf("%i", &val);
	}

	return 0;
}
