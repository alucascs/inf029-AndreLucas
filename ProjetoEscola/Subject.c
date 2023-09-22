#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Subject.h"
#include "Teacher.h"
#include "Generic.h"

#define Len_dis 50

int MenuDis() {

  int opcao = -1;

  printf("\n\n#### Modulo de Disciplinas ####\n\n");

  printf("0 - Voltar para o menu geral\n");
  printf("1 - Adicionar Disciplina\n");
  printf("2 - Excluir Disciplina\n");
  printf("3 - Editar Disciplina\n");
  printf("4 - Listar Disciplinas\n");
  printf("5 - Adicionar Alunos a Disciplina\n");
  printf("6 - Detalhar Disciplina\n");
  printf("7 - Listar Disciplinas com mais de 40 alunos\n");
  printf("8 - Listar Disciplinas sem alunos matriculados\n");
  printf("=> ");
  scanf("%d", &opcao);

  return opcao;
}

int AdicionarAluno(Disciplina *A, Person *B, int qtd, int  *qtd_std){
  int cod, back, exist_dis, exist_alu, i;
  back = exist_dis = exist_alu = 0;
  printf("Digite o codigo da disciplina: ");
  scanf("%d", &cod);
  for(i = 0; i<qtd; i++){
    if(A[i].codigo == cod){
      exist_dis = 1;
      while(!back){
        printf("\nDisciplina: %s\n\n", A[i].nome);
        printf("0 - Voltar\n");
        printf("1 - Confirmar\n");
        printf("=> ");
        scanf("%d", &cod);
        switch(cod){
          case 0:
            back = 1;
            break;
          case 1:
            printf("Digite a matricula do aluno: ");
            scanf("%d", &cod);
            for(int j = 0; j<LEN_STUDENTS; j++){
               if(B[j].registration == cod){
                 exist_alu = 1;
                 A[i].student[qtd_std[i]];
                 getDataStudent(A , i, qtd_std, j);
                 qtd_std[i]++;
               }
            }
            if(!exist_alu){
              printf("\nmatricula nao encontrada!\n");
            }
          break;
          default:
            printf("Opcao invalida!\n");
            break;
      }
      } 
    }
  }
  if(!exist_dis){
    printf("\nCodigo da disciplina nao foi encontrado!\n");
  }
}

int VereficarCod (Disciplina *A, int qtd, int codigo){
  int Usado = 0;
  for(int i = 0; i<qtd; i++){
    if(A[i].codigo == codigo){
      Usado = 1;
    }
  }
  if(!Usado){
    return 1;
  }
  return 0;
}

void Add_subject(Disciplina *A, int qtd) {
  printf("\n#### Adicionar Disciplina ####\n");
  getchar();
  int cod = -1;
  int op = 0;
  printf("\nDigite o nome da disciplina: ");
  fgets(A[qtd].nome, 49, stdin);
  int fim = strlen(A[qtd].nome);
  if (A[qtd].nome[fim - 1] == '\n')
    A[qtd].nome[fim - 1] = '\0';
  while(!op){
    printf("Digite o codigo da disciplina: ");
    scanf("%d", &cod);
    op = VereficarCod(A, qtd, cod);
    if(op){
      A[qtd].codigo = cod;
    }
    else{
      printf("\nCodigo da disciplina ja foi ultilizado!\n\n");
    }
  }
  getchar();
  printf("Digite o semestre da disciplina(AaAa-P): ");
  fgets(A[qtd].semestre, 7, stdin);
  fim = strlen(A[qtd].semestre);
  if (A[qtd].semestre[fim - 1] == '\n')
    A[qtd].semestre[fim - 1] = '\0';

  printf("digite a matricula do professor: ");
  scanf("%d", &A[qtd].teacher.registration);
  int exist = getDataTeacher(A, qtd);
  if (!exist){
    printf("\nProfessor não encontrado, adicione em *Editar Disciplina* mais tarde!\n\n");
  }
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
    int codOp = 0;
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
        while(!op)
        printf("Digite o codigo da disciplina: ");
        scanf("%d", &cod);
        op = VereficarCod(A, qtd, cod);
        if(op){
          A[qtd].codigo = cod;
        }
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
        printf("digite a matricula do novo professor: ");
        scanf("%d", &A[qtd].teacher.registration);
        int exist = getDataTeacher(A, qtd);
        if (!exist){
          printf("\nProfessor não encontrado, adicione em *Editar Disciplina* mais tarde!\n");
  }
        else{
        }
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
      printf("Nome do professor: %s\n\n", A[i].teacher.name);
      dis++;
    }
  }
  if (dis == 1) {
    printf("\nAinda sem disciplinas regisitradas");
  }
}

void DetalharDisciplina(Disciplina *A, int qtd, int *qtd_std){
  int cod, exist = 0;
  printf("\nDigite o codigo da disciplina: ");
  scanf("%d", &cod);
  getchar();
  for(int i=0; i<qtd; i++){
    if(A[i].codigo == cod){
      exist = 1;
      printf("Disciplina: %s\n", A[i].nome);
      printf("Professor: %s\n", A[i].teacher.name);
      printf("\nAlunos:\n");
      for(int j=0; j<qtd_std[i]; j++){
        printf("%d - %s\n", j+1, A[i].student[j].name);
      }
      if(qtd_std[i]==0){
        printf("Disciplina sem alunos matriculados!");
      }
    }
  }
  if(!exist){
    printf("Codigo da disciplina não encontrado!");
  } 
}

void Sobrecarregadas(Disciplina *A, int qtd, int *qtd_std){
  int exist = 0;
  for(int i=0; i<qtd; i++){
    if(qtd_std[i]>40){
      exist = 1;
      printf("\nA disciplina %s tem mais de 40 alunos matriculados!\n", A[i].nome);
    }
  }
  if(!exist){
    printf("\nNão tem disciplinas com mais de 40 alunos\n");
  }
}

void SemAlunos(Disciplina *A, int qtd, int *qtd_std){
  int exist = 0;
  for(int i=0; i<qtd; i++){
    if(qtd_std[i] == 0){
      exist = 1;
      printf("\nA disciplina %s não tem alunos matriculados!\n", A[i].nome);
    }
  }
  if(!exist){
    printf("\nNão tem disciplinas sem alunos\n");
  }
}

int getDataTeacher(Disciplina *A, int qtd)
{
	int x = 0;

	for (x = 0; x < LEN_TEACHER; x++)
	{
		if (teachers[x].registration == A[qtd].teacher.registration)
		{
			strcpy(A[qtd].teacher.cpf, teachers[x].cpf);
			strcpy(A[qtd].teacher.name, teachers[x].name);
			strcpy(A[qtd].teacher.sex, teachers[x].sex);
			A[qtd].teacher.dateOfBirth[0] = teachers[x].dateOfBirth[0];
			A[qtd].teacher.dateOfBirth[1] = teachers[x].dateOfBirth[1];
			A[qtd].teacher.dateOfBirth[2] = teachers[x].dateOfBirth[2];
			return 1;
		}
	}
  return 0;
}


void getDataStudent(Disciplina *A, int dis, int *qtd_std, int std){

    strcpy(A[dis].student[qtd_std[dis]].cpf, students[std].cpf);
    strcpy(A[dis].student[qtd_std[dis]].name, students[std].name);
    strcpy(A[dis].student[qtd_std[dis]].sex, students[std].sex);
    A[dis].student[qtd_std[dis]].dateOfBirth[0] = students[std].dateOfBirth[0];
    A[dis].student[qtd_std[dis]].dateOfBirth[1] = students[std].dateOfBirth[1];
    A[dis].student[qtd_std[dis]].dateOfBirth[2] = students[std].dateOfBirth[2];
  
}

int main(void)
{
	Disciplina *subject = calloc(Len_dis, sizeof(Disciplina));
	int optionDis;
  int *qtd_alu = calloc(Len_dis, sizeof(int));
	int SairDis = 0;
	int qtd_Dis = 0;
	while (!SairDis)
	{
		optionDis = MenuDis();
		switch (optionDis)
		{
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
      case 5:
        AdicionarAluno(subject, students, qtd_Dis, qtd_alu);
        break;
      case 6:
        DetalharDisciplina(subject, qtd_Dis, qtd_alu);
        break;
      case 7:
        Sobrecarregadas(subject, qtd_Dis, qtd_alu);
        break;
      case 8:
        SemAlunos(subject, qtd_Dis, qtd_alu);
        break;
  		default:
  			printf("Opcao invalida!\n");
  			break;
		}
  }
}