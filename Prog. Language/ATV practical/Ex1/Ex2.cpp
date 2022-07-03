/*
UNINTER - ENGENHARIA DA COMPUTAÇÃO
Disciplina de Linguagem de Programação
Exercício 1 - Atividade prática

Autor: Paulo Vinicius Pereira Pinheiro
RU: 3760288

Início: 02/07/2022
Fim:
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>


void titulo() {
	printf("###############    Exercicio 1 - Atividade Pratica     ###############\n");
	printf("Aluno: Paulo Vinicius P. Pinheiro\n");
	printf("RU: 3760288\n\n");
};


struct dados
{
	char nome[30];
	char endereco[50];
	char telefone[12];

};

int main()
{
	int i = 0;
	struct dados pessoa{};
	const int tam_total = sizeof(pessoa.nome) + sizeof(pessoa.endereco) + sizeof(pessoa.telefone);
	char dados_total[tam_total]{};

	printf("\nDigite o seu nome completo: ");
	gets_s(pessoa.nome, 29);

	printf("\nDigite o seu endereco completo: ");
	gets_s(pessoa.endereco, 49);

	printf("\nDigite o seu telefone completo: ");
	gets_s(pessoa.telefone, 12);


	strcat(dados_total, pessoa.nome);
	strcat(dados_total, pessoa.endereco);
	strcat(dados_total, pessoa.telefone);
	
	printf(dados_total);

	return 0;
}