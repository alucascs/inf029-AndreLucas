#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "Subjects.h"
#include "Teacher.h"

int MenuDis(){

	int opcao;

	printf("\n#### Módulo de Disciplinas ####\n\n");

	printf("0 - Voltar para o menu geral\n");
	printf("1 - Adicionar Disciplina\n");
	printf("2 - Excluir Disciplina\n");
	printf("3 - Listar Disciplinas\n");
	scanf("%d",&opcao);

	return opcao;
}
