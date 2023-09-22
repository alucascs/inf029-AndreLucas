#ifndef GENERIC_H
#define GENERIC_H
#define LEN_STUDENTS 50

typedef struct Person {
  int registration;
  char name[50];
  char sex[2];
  int dateOfBirth[3];
  char cpf[15];
  int status;
  int date;
} Person;

Person students[LEN_STUDENTS];

#endif