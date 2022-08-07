/*
UNINTER - ENGENHARIA DA COMPUTAÇÃO
Disciplina de Linguagem de Programação
Exercício 5 - Atividade prática

Autor : Paulo Vinicius Pereira Pinheiro
RU : 3760288

*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <clocale>

FILE* stream;

struct dados
{
	char nome[50]{};
	int codigo;
	float preco;
};

void titulo()
{
	printf("###############    Exercício 5 - Atividade Prática     ###############\n");
	printf(" Aluno: Paulo Vinicius P. Pinheiro\n");
	printf(" RU: 3760288\n\n");
	printf("===  Programa para armazenar dados em arquivos CSV  ===\n");
};

int main()
{
	setlocale(LC_ALL, ""); // permite usar a lingua atual de escrita

	errno_t err;
	char nome_arquivo[] = "3760288.csv";
	char c;
	const int num_prod = 7;
	struct dados produto[num_prod]{};

	// cria o arquivo .csv com o número do RU
	err = fopen_s(&stream, nome_arquivo, "w");
	if (err == 0)
	{
		printf("O arquivo criado com sucesso.\n");
		fprintf(stream, "código_produto; nome_produto; preco_produto\n");
	}
	else
	{
		printf("Erro ao criar o arquivo.\n");
		exit(1);
	}

	titulo();
	for (int i = 0; i < num_prod; i++)
	{
		printf("\n =====   Registro número %d   =====\n", i + 1);
		printf("\nDigite o código do produto: ");
		scanf_s("%d", &produto[i].codigo);
		while ((c = getchar()) != '\n' && c != EOF){}
		// trecho para evitar sobresalto ao digitar os valores

		printf("\nDigite o nome do produto: ");
		gets_s(produto[i].nome, 50);
		c = getchar();

		printf("\nDigite o preço do produto: ");
		scanf_s("%f", &produto[i].preco);
		while ((c = getchar()) != '\n' && c != EOF) {}

		// escreve no arquivo os dados de input
		fprintf(stream, "%d; %s; %.2f\n", produto[i].codigo, produto[i].nome, produto[i].preco);
	}
	// fecha o arquivo criado
	_fcloseall();
	return 0;
}