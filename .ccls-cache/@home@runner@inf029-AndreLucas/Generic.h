#ifndef GENERIC_H
#define GENERIC_H

typedef struct Person {
  int registration;
  char name[50];
  char sex[2];
  int dateOfBirth[3];
  char cpf[15];
  int status;
  int date;
} Person;

#endif