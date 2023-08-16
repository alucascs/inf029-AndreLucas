#include <stdio.h>
#include <string.h>
#define LEN_TEACHER 50

typedef struct Teacher{
    int Registration;
    char Name [50];
    char Sex [2];
    int Date_Of_Birth[3];
    char CPF [15];
}Teacher;

Teacher Teachers[LEN_TEACHER];

void GetTeacher(int matricula);

int Menu();

void APP();

void DeleteTeacher(int matricula);

void ChangeTeacher(int matricula);