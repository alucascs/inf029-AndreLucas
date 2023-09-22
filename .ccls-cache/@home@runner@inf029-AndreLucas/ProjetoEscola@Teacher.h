#ifndef TEACHER_H
#define TEACHER_H
#include <stdlib.h>
#include "Subject.h"
#include <stdio.h>
#include <string.h>
#define LEN_TEACHER 50

typedef struct Teacher{
  int registration;
  char name[50];
  char sex[2];
  int dateOfBirth[3];
  char cpf[15];
  int status;
}Teacher;

Teacher teachers[50];

#endif