#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define Len_dis 50

#include "Subject.h"

int MenuDis() {

  int opcao;

  printf("\n\n#### Modulo de Disciplinas ####\n\n");

  printf("0 - Voltar para o menu geral\n");
  printf("1 - Adicionar Disciplina\n");
  printf("2 - Excluir Disciplina\n");
  printf("3 - Editar Disciplina\n");
  printf("4 - Listar Disciplinas\n");
  printf("=> ");
  scanf("%d", &opcao);

  return opcao;
}

void Add_subject(Disciplina *A, int qtd) {
  printf("\n#### Adcionar Disciplina ####\n");
  getchar();

  printf("\nDigite o nome da disciplina: ");
  fgets(A[qtd].nome, 49, stdin);
  int fim = strlen(A[qtd].nome);
  if (A[qtd].nome[fim - 1] == '\n')
    A[qtd].nome[fim - 1] = '\0';

  printf("Digite o codigo da disciplina: ");
  scanf("%d", &A[qtd].codigo);

  getchar();
  printf("Digite o semestre da disciplina(AaAa-P): ");
  fgets(A[qtd].semestre, 7, stdin);
  fim = strlen(A[qtd].semestre);
  if (A[qtd].semestre[fim - 1] == '\n')
    A[qtd].semestre[fim - 1] = '\0';

  printf("digite o codigo do professor: ");
  scanf("%d", &A[qtd].teacher.Registration);
  A[qtd].Active = 1;
  printf("\nDisciplina Cadastrada com Sucesso!\n");
}

void Remove_subject(Disciplina *A, int qtd) {
  int codigo, i, aux = 0;
  printf("\n#### Remover Disciplina ####\n\n");
  getchar();
  printf("Digite o codigo da disciplina: ");
  scanf("%d", &codigo);
  getchar();
  for (i = 0; i < qtd; i++) {
    if (A[i].codigo == codigo && A[i].Active) {
      A[i].Active = 0;
      printf("\nDisciplina Removida com Sucesso!");
      aux = 1;
      break;
    }
  }
  if (!aux)
    printf("\nCodigo digitado nao existe!");
}

void Edit_subject(Disciplina *A, int qtd) {
  int codigo, i, vet = -1;
  printf("\n#### Editar Disciplina ####\n\n");
  getchar();
  printf("Digite o codigo da disciplina que deseja editar: ");
  scanf("%d", &codigo);
  getchar();
  for (i = 0; i < qtd; i++) {
    if (A[i].codigo == codigo) {
      vet = i;
      break;
    }
  }
  if (A[vet].Active && vet != -1) {
    int op, fim, cod, back = 0;

    while (!back) {

      printf("\nDisciplina - %s\n\n", A[i].nome);
      printf("O que deseja editar?\n");
      printf("O - Voltar\n");
      printf("1 - Nome\n");
      printf("2 - Codigo\n");
      printf("3 - Semestre\n");
      printf("4 - Professor\n");
      scanf("%d", &op);
      getchar();
      switch (op) {
      case 0:
        back = 1;
        break;
      case 1:
        printf("Digite o novo nome da disciplina: ");
        fgets(A[vet].nome, 49, stdin);
        fim = strlen(A[vet].nome);
        if (A[i].nome[fim - 1] == '\n')
          A[i].nome[fim - 1] = '\0';
        printf("\nDisciplina editada com Sucesso!");
        back = 1;
        break;
      case 2:
        printf("Digite o novo codigo da disciplina: ");
        scanf("%d", &A[i].codigo);
        printf("\nDisciplina editada com Sucesso!");
        back = 1;
        break;
      case 3:
        printf("Digite o novo semestre da disciplina: ");
        fgets(A[vet].semestre, 7, stdin);
        fim = strlen(A[vet].semestre);
        if (A[qtd].semestre[fim - 1] == '\n')
          A[qtd].semestre[fim - 1] = '\0';
        printf("\nDisciplina editada com Sucesso!");
        back = 1;
        break;
      case 4:
        printf("digite o codigo do novo professor: ");
        scanf("%d", &cod);
        // função para verificar o codigo do professor
        // função para a partir do codigo consultar os outros dados do professor
        printf("\nDisciplina editada com Sucesso!");
        back = 1;
        break;
      default:
        printf("Opção invalida!");
        break;
      }
    }
  } else {
    printf("Codigo nao encontrado!");
  }
}

void List_subject(Disciplina *A, int qtd) {
  int dis = 1;
  for (int i = 0; i < qtd; i++) {
    if (A[i].Active) {
      printf("\nDisciplina #%d\n\n", dis);
      printf("Nome: %s\n", A[i].nome);
      printf("Codigo: %d\n", A[i].codigo);
      printf("Semestre: %s\n", A[i].semestre);
      printf("Nome do professor: %s\n\n", A[i].teacher.Name);
      dis++;
    }
  }
  if (dis == 1) {
    printf("\nAinda sem disciplinas regisitradas");
  }
}

int main(void) {
  Disciplina subject[Len_dis];
  int optionDis;
  int SairDis = 0;
  int qtd_Dis = 0;
  while (!SairDis) {
    optionDis = MenuDis();
    switch (optionDis) {
    case 0:
      SairDis = 1;
      break;
    case 1:
      Add_subject(subject, qtd_Dis);
      qtd_Dis++;
      break;
    case 2:
      Remove_subject(subject, qtd_Dis);
      break;
    case 3:
      Edit_subject(subject, qtd_Dis);
      break;
    case 4:
      List_subject(subject, qtd_Dis);
      break;
    default:
      printf("Opcao invalida!\n");
      break;
    }
  }
}