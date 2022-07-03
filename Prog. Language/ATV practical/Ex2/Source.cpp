/*
UNINTER - ENGENHARIA DA COMPUTAÇÃO
Disciplina de Linguagem de Programação
Exercício 2 - Atividade prática

Autor: Paulo Vinicius Pereira Pinheiro
RU: 3760288

Início: 02/07/2022			Fim: 02/07/2022
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>


void titulo() 
{
	printf("###############    Exercicio 2 - Atividade Pratica     ###############\n");
	printf(" Aluno: Paulo Vinicius P. Pinheiro\n");
	printf(" RU: 3760288\n\n");
};


struct dados
{
	char nome[30];
	char endereco[50];
	char telefone[15];

};

int main()
{
	int cont_car = 0, cont_dig = 0, cont = 0;
	struct dados pessoa {};
	const int tam_total = sizeof(pessoa.nome) + sizeof(pessoa.endereco) + sizeof(pessoa.telefone);
	char dados_total[tam_total]{};

	titulo();

	printf("\n Digite o seu nome completo: ");
	gets_s(pessoa.nome, 29);

	printf("\n Digite o seu endereco completo: ");
	gets_s(pessoa.endereco, 49);

	printf("\n Digite o seu telefone completo: ");
	gets_s(pessoa.telefone, 15);

	strcat_s(dados_total, pessoa.nome);
	strcat_s(dados_total, pessoa.endereco);
	strcat_s(dados_total, pessoa.telefone);

	for (int i = 0; i < strlen(dados_total); i++)
	{
		/*if (isalpha(dados_total[i])) printf("\n %c ok\n", dados_total[i]);
		else printf("\n %c not ok\n", dados_total[i]);*/

		if (isalpha(dados_total[i]))
		{
			cont_car++;
			cont++;
		}
		
		if (isdigit(dados_total[i]))
		{
			cont_dig++;
			cont++;
		}
	}

	printf("\n\n ## Resultado ##\n\n");
	printf("\n Quantidade de caracteres do alfabeto: %d \n", cont_car);
	printf("\n Quantidade de caracteres numericos: %d \n", cont_dig);
	printf("\n Quantidade total de caracteres alfanuméricos: %d \n", strlen(dados_total));

	return 0;
}