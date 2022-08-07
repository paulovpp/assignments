/*
UNINTER - ENGENHARIA DA COMPUTAÇÃO
Disciplina de Linguagem de Programação
Exercício 3 - Atividade prática

Autor: Paulo Vinicius Pereira Pinheiro
RU: 3760288

Início: 02/08/2022			Fim: 02/08/2022
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <clocale>

void CalulaArea(float* comprimento, float* largura, float* area);
float Lampada(int tipo, float area);

void titulo()
{
	printf("###############    Exercício 3 - Atividade Prática     ###############\n");
	printf(" Aluno: Paulo Vinicius P. Pinheiro\n");
	printf(" RU: 3760288\n\n");
	printf("===  Programa para cálculo do número de lâmpadas  ===");
};


struct dados
{
	int tipo_de_comodo;
	float comprimento;
	float largura;

};

int main()
{
	setlocale(LC_ALL, "");
	
	int l = 0;
	char c = 0;
	float area;
	struct dados comodo{};

	titulo();

	while (true)
	{
		printf("\n\nDigite o tipo do comodo [0 - 4] ou -1 para sair: ");
		scanf_s("%d", &comodo.tipo_de_comodo);
		c = getchar();

		if (comodo.tipo_de_comodo == -1) break;

		printf("\nDigite o comprimento do comodo (em m^2): ");
		scanf_s("%f", &comodo.comprimento);
		c = getchar();

		printf("\nDigite a largura do comodo (em m^2): ");
		scanf_s("%f", &comodo.largura);
		c = getchar();

		CalulaArea(&comodo.comprimento, &comodo.largura, &area);
		
		printf("\n\nO comodo tem %.2f m^2 e deve possuir %.0f lâmpadas.", area, Lampada(comodo.tipo_de_comodo, area));
		printf("\n----------------------------------------------------------------------\n\n");
	}
	printf("\n\nObrigado por utilizar este programa.\n\n");
}

void CalulaArea(float* comprimento, float* largura, float* area)
{
	*area = *comprimento * *largura;
}

float Lampada(int tipo, float area)
{
	float numero_de_lampadas = 0;

	switch (tipo)
	{
		case 0:
			numero_de_lampadas = ceilf(area / 12);
			return numero_de_lampadas;
		case 1:
			numero_de_lampadas = ceilf(area / 15);
			return numero_de_lampadas;
		case 2:
			numero_de_lampadas = ceilf(area / 18);
			return numero_de_lampadas;
		case 3:
			numero_de_lampadas = ceilf(area / 20);
			return numero_de_lampadas;
		case 4:
			numero_de_lampadas = ceilf(area / 22);
			return numero_de_lampadas;
	default:
		break;
	}
	return 0;
}