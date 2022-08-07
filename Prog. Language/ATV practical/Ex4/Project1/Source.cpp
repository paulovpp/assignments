/*
UNINTER - ENGENHARIA DA COMPUTA��O
Disciplina de Linguagem de Programa��o
Exerc�cio 4 - Atividade pr�tica

Autor : Paulo Vinicius Pereira Pinheiro
RU : 3760288

*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <clocale>

int maior(int vet[], int tam, int num_maior);
int menor(int vett[], int tamm, int num_menor);

void titulo()
{
	printf("###############    Exerc�cio 4 - Atividade Pr�tica     ###############\n");
	printf(" Aluno: Paulo Vinicius P. Pinheiro\n");
	printf(" RU: 3760288\n\n");
	printf("===  Programa para verificar maior e menor d�gito de um RU  ===\n");
};

int main() 
{
	setlocale(LC_ALL, "");

	int cont = 0, n_maior = 0, n_menor = 0;
	int ru[7]{};
	char c;

	titulo();
	printf("\n\nDigite seu RU d�gito a d�gito.\n\n ");

	while (cont <= 6)
	{
		printf("\nDigite o d�gito numero %i: ", cont + 1);
		scanf_s("%d", &ru[cont]);
		c = getchar();
		cont++;
	}
	n_menor = menor(ru, 7, 9);
	printf("\nO menor d�gito do RU digitado � %d.\n\n", n_menor);

	n_maior = maior(ru, 7, 0);
	printf("\nO maior d�gito do RU digitado � %d.\n\n", n_maior);
	
	return 0;
}

int maior(int vet[], int tam, int num_maior)
{
	if (tam == 0)
	{
		return num_maior;
	}
	else
	{
		if (vet[tam] > num_maior) 
		{
			num_maior = vet[tam];
			return maior(vet, tam - 1, num_maior);
		}
		else
		{
			return maior(vet, tam - 1, num_maior);
		}
	}
}

int menor(int vett[], int tamm, int num_menor)
{
	if (tamm == 0)
	{
		return num_menor;
	}
	else
	{
		if (vett[tamm-1] < num_menor)
		{
			num_menor = vett[tamm-1];
			return menor(vett, tamm - 1, num_menor);
		}
		else
		{
			return menor(vett, tamm - 1, num_menor);
		}
	}
}