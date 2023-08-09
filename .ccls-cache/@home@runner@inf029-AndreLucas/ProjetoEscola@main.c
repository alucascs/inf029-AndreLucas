#include <stdio.h>

int main(void){
  int idade[10], i;
  float media;

  media = 0;
  
  for(i=0;i<10;i++){
    printf("digite a idade numero %d: ", i+1);
    scanf("%d", &idade[i]);
    media += idade[i];
  }
  
  media = media/10;

  printf("A media das idades e igual a %.2f\n", media);
  printf("As idades que sao maiores que a media sao:\n");
  
  for(i=0;i<10;i++){
    if(idade[i]>media){
      printf("%d\n", idade[i]);
    }
  }
}