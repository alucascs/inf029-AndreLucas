#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>


void printTab(int jogadas[3][3]){
  printf("  A   B   C \n");
  int linha = 1;
  for(int i = 0; i<3; i++){
    for(int j = 0; j<3; j++){
      if(jogadas[i][j] == 1){
        if(j == 0)
          printf("%d X |", linha);
        if(j == 1)
          printf(" X |");
        if(j == 2)
          printf(" X");
      }
      else if(jogadas[i][j] == 2){
        if(j == 0)
          printf("%d O |", linha);
        if(j == 1)
          printf(" O |");
        if(j == 2)
          printf(" O");
      }
      else{
        if(j == 0)
          printf("%d   |", linha);
        if(j == 1)
          printf("   |");
        if(j == 2)
          printf("  ");
      }
    }
    if(i != 2)
     printf("\n  ---------\n");
    linha++;
  }
  printf("\n");
}

bool terminou(int jogadas[3][3]){
  for(int i = 0; i<3; i++){
    if(jogadas[i][0] == 1 && jogadas[i][1] == 1 && jogadas[i][2] == 1){
      return true;
    }
    if(jogadas[i][0] == 2 && jogadas[i][1] == 2 && jogadas[i][2] == 2){
      return true;
    }
  }
  for(int i = 0; i<3; i++){
    if(jogadas[0][i] == 1 && jogadas[1][i] == 1 && jogadas[2][i] == 1){
      printf("Jogador 1 venceu!\n");
      return true;
    }
    if(jogadas[0][i] == 2 && jogadas[1][i] == 2 && jogadas[2][i] == 2){
      printf("Jogador 2 venceu!\n");
      return true;
    }
  }
  if(jogadas[0][0] == 1 && jogadas[1][1] == 1 && jogadas[2][2] == 1){
      printf("Jogador 1 venceu!\n");
      return true;
  }
  if(jogadas[0][0] == 2 && jogadas[1][1] == 2 && jogadas[2][2] == 2){
      printf("Jogador 2 venceu!\n");
      return true;
  }
  if(jogadas[2][0] == 1 && jogadas[1][1] == 1 && jogadas[0][2] == 1){
      printf("Jogador 1 venceu!\n");
      return true;
  }
  if(jogadas[2][0] == 2 && jogadas[1][1] == 2 && jogadas[0][2] == 2){
      printf("Jogador 2 venceu!\n");
      return true;
  }
  int count = 0;
  for(int i = 0; i<3; i++){
    for(int j = 0; j<3; j++){
      if(jogadas[i][j] != 0){
        count++;
      }
    }
  }
  if(count > 8){
    printf("Deu velha!\n");
    return true;
  }
  
  return false;
}

void q7(){
  int jogadas[3][3];
  int vez = 0;
  char jog[3];
  bool valida, fim = false;
  for (int i=0; i < 3; i++){
    for (int j=0; j < 3; j++){
      jogadas[i][j] = 0;
    }
  }
  while(!fim){
    printTab(jogadas);
    valida = true;
    do{
      if(!valida)
        printf("Jogada Invalida!");
      valida = false;
      if(vez%2==0){
        printf("\n\nvez do jogador 1, digite sua jogada(A2): ");
        fgets(jog, 3, stdin);
        getchar();
        if(jog[0] >= 'a' && jog[0] <= 'z'){
          jog[0] -= 32;
        }
        printf("\n\n");
        if(jog[0] == 'A'){
          if(jog[1] == '1' && jogadas[0][0] == 0){
            jogadas[0][0] = 1;
            valida = true;
          }
          if(jog[1] == '2' && jogadas[1][0] == 0){
            jogadas[1][0] = 1;
            valida = true;
          }
          if(jog[1] == '3' && jogadas[2][0] == 0){
            jogadas[2][0] = 1;
            valida = true;
          }
        }
        if(jog[0] == 'B'){
          if(jog[1] == '1' && jogadas[0][1] == 0){
            jogadas[0][1] = 1;
            valida = true;
          }
          if(jog[1] == '2' && jogadas[1][1] == 0){
            jogadas[1][1] = 1;
            valida = true;
          }
          if(jog[1] == '3' && jogadas[2][1] == 0){
            jogadas[2][1] = 1;
            valida = true;
          }
        }
        if(jog[0] == 'C'){
          if(jog[1] == '1' && jogadas[0][2] == 0){
            jogadas[0][2] = 1;
            valida = true;
          }
          if(jog[1] == '2' && jogadas[1][2] == 0){
            jogadas[1][2] = 1;
            valida = true;
          }
          if(jog[1] == '3' && jogadas[2][2] == 0){
            jogadas[2][2] = 1;
            valida = true;
          }
        }
      }
      else{
        printf("\n\nvez do jogador 2, digite sua jogada(A2): ");
        fgets(jog, 3, stdin);
        getchar();
        if(jog[0] >= 'a' && jog[0] <= 'z'){
          jog[0] -= 32;
        }
        printf("\n\n");
        if(jog[0] == 'A'){
            if(jog[1] == '1' && jogadas[0][0] == 0){
              jogadas[0][0] = 2;
              valida = true;
            }
            if(jog[1] == '2' && jogadas[1][0] == 0){
              jogadas[1][0] = 2;
              valida = true;
            }
            if(jog[1] == '3' && jogadas[2][0] == 0){
              jogadas[2][0] = 2;
              valida = true;
            }
          }
          if(jog[0] == 'B'){
            if(jog[1] == '1' && jogadas[0][1] == 0){
              jogadas[0][1] = 2;
              valida = true;
            }
            if(jog[1] == '2' && jogadas[1][1] == 0){
              jogadas[1][1] = 2;
              valida = true;
            }
            if(jog[1] == '3' && jogadas[2][1] == 0){
              jogadas[2][1] = 2;
              valida = true;
            }
          }
          if(jog[0] == 'C'){
            if(jog[1] == '1' && jogadas[0][2] == 0){
              jogadas[0][2] = 2;
              valida = true;
            }
            if(jog[1] == '2' && jogadas[1][2] == 0){
              jogadas[1][2] = 2;
              valida = true;
            }
            if(jog[1] == '3' && jogadas[2][2] == 0){
              jogadas[2][2] = 2;
              valida = true;
            }
          }
      }
    }while(!valida);
    
    vez++;
    fim = terminou(jogadas);
  }
  printf("O jogo terminou!!!\n\n");
  printTab(jogadas);
}