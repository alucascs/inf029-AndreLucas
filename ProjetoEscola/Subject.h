#ifndef SUBJECT_H
#define SUBJECT_H
#define Len_dis 50
#include "Generic.h"
#include "Teacher.h"

typedef struct {
  char nome[50];
  int codigo;
  int Active;
  char semestre[7];
  Teacher teacher;
  Person student[LEN_STUDENTS];
} Disciplina;


void menuSubject();

void Add_subject(Disciplina *A, int qtd);

void Remove_subject(Disciplina *A, int qtd);

void Edit_subject(Disciplina *A, int qtd);

void List_subject(Disciplina *A, int qtd);

int getDataTeacher(Disciplina *A, int qtd);

void getDataStudent(Disciplina *A, int dis, int *qtd_std, int std);

void SemAlunos(Disciplina *A, int qtd, int *qtd_std);

void Sobrecarregadas(Disciplina *A, int qtd, int *qtd_std);

void DetalharDisciplina(Disciplina *A, int qtd, int *qtd_std);

#endif