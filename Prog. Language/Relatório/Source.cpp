/*
UNINTER - ENGENHARIA DA COMPUTACA
Disciplina de Linguagem de Programacao
Exercicio 1 - Atividade pratica

Autor: Paulo Vinicius Pereira Pinheiro
RU: 3760288

Inicio: 01/07/2022
Fim: 02/07/2022
*/

#include <stdlib.h>
#include <stdio.h>

void titulo();

struct dados
{
	char nome[50];
	int dia;
	int mes;
};
typedef struct dados;
void titulo() {
	printf("###############    Exercicio 1 - Atividade Pratica     ###############\n");
	printf("Aluno: Paulo Vinicius P. Pinheiro\n");
	printf("RU: 3760288\n\n");
};

int main()
{
	const int length = 8;
	const int m = 12;
	char c;
	int j = 0, k = 0;

	dados pessoas[length]{}, *p_pessoas;
	printf("##################    Registro de Funcionarios  ######################\n\n");
	// Etapa de coleta de dados

	for (int i = 0; i < length; i++)
	{
		titulo();
		printf("Registro no. %d\n\n\n", i+1);

		printf("Digite o nome: ");
		gets_s(pessoas[i].nome, 49);

		printf("\nDigite o dia do aniversario: ");
		scanf_s("%d", &pessoas[i].dia);
		c = getchar();

		printf("\nDigite o mes do aniversario: ");
		scanf_s("%d", &pessoas[i].mes);
		c = getchar();

		system("cls");
	}
	// Etapa de apresentacao dos aniversariantes do mes
	titulo();
	p_pessoas = &pessoas[0];
	printf("Lista de aniversariantes do mes\n");
	printf("Numero de registros: %d\n\n", length);

	for (j = 1; j < m+1; j++)
	{
		printf("\nAniversariantes do mes %d\n", j);
		while (k < 8) 
		{
			if (p_pessoas[k].mes == j)
			{
				printf("%s, no dia %d.\n",p_pessoas[k].nome, p_pessoas[k].dia);
			}
			k++;
		}
		k = 0;
	}
}