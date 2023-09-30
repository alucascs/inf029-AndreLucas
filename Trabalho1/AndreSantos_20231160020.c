// #################################################
//  Instituto Federal da Bahia
//  Salvador - BA
//  Curso de Análise e Desenvolvimento de Sistemas http://ads.ifba.edu.br
//  Disciplina: INF029 - Laboratório de Programação
//  Professor: Renato Novais - renato@ifba.edu.br

//  ----- Orientações gerais -----
//  Descrição: esse arquivo deve conter as questões do trabalho do aluno.
//  Cada aluno deve renomear esse arquivo para Aluno<MATRICULA>.c
//  O aluno deve preencher seus dados abaixo, e implementar as questões do trabalho

//  ----- Dados do Aluno -----
//  Nome: André Lucas Coelho dos Santos
//  email: andrebr889@gmai.com
//  Matrícula: 20231160020
//  Semestre: 2023-2

//  Copyright © 2016 Renato Novais. All rights reserved.
// Última atualização: 07/05/2021 - 19/08/2016

// #################################################

#include <stdio.h>
#include "AndreSantos_20231160020.h" // Substitua pelo seu arquivo de header renomeado
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
/*
## função utilizada para testes  ##

 somar = somar dois valores
@objetivo
    Somar dois valores x e y e retonar o resultado da soma
@entrada
    dois inteiros x e y
@saida
    resultado da soma (x + y)
 */
int somar(int x, int y)
{
    int soma;
    soma = x + y;
    return soma;
}

/*
## função utilizada para testes  ##

 fatorial = fatorial de um número
@objetivo
    calcular o fatorial de um número
@entrada
    um inteiro x
@saida
    fatorial de x -> x!
 */
int fatorial(int x)
{ //função utilizada para testes
  int i, fat = 1;
    
  for (i = x; i > 1; i--)
    fat = fat * i;
    
  return fat;
}

int teste(int a)
{
    int val;
    if (a == 2)
        val = 3;
    else
        val = 4;

    return val;
}



DataQuebrada quebraData(char data[]){
  DataQuebrada dq;
  char sDia[3];
	char sMes[3];
	char sAno[5];
	int i; 

	for (i = 0; data[i] != '/'; i++){
		sDia[i] = data[i];	
	}
	if(i == 1 || i == 2){ // testa se tem 1 ou dois digitos
		sDia[i] = '\0';  // coloca o barra zero no final
	}else {
		dq.valido = 0;
    return dq;
  }  
	

	int j = i + 1; //anda 1 cada para pular a barra
	i = 0;

	for (; data[j] != '/'; j++){
		sMes[i] = data[j];
		i++;
	}

	if(i == 1 || i == 2){ // testa se tem 1 ou dois digitos
		sMes[i] = '\0';  // coloca o barra zero no final
	}else {
		dq.valido = 0;
    return dq;
  }
	

	j = j + 1; //anda 1 cada para pular a barra
	i = 0;
	
	for(; data[j] != '\0'; j++){
	 	sAno[i] = data[j];
	 	i++;
	}

	if(i == 2 || i == 4){ // testa se tem 2 ou 4 digitos
		sAno[i] = '\0';  // coloca o barra zero no final
	}else {
		dq.valido = 0;
    return dq;
  }

  dq.iDia = atoi(sDia);
  dq.iMes = atoi(sMes);
  dq.iAno = atoi(sAno);
  if(dq.iAno < 100){
    dq.iAno += 2000;
  }

	dq.valido = 1;
    
  return dq;
}

int isLeapYear(int year) {
    if ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0)) {
        return 1;
    } else {
        return 0;
    }
}

/*
 Q1 = validar data
@objetivo
    Validar uma data
@entrada
    uma string data. Formatos que devem ser aceitos: dd/mm/aaaa, onde dd = dia, mm = mês, e aaaa, igual ao ano. dd em mm podem ter apenas um digito, e aaaa podem ter apenas dois digitos.
@saida
    0 -> se data inválida
    1 -> se data válida
 @restrições
    Não utilizar funções próprias de string (ex: strtok)   
    pode utilizar strlen para pegar o tamanho da string
 */
int q1(char data[])
{
  int datavalida = 1, i = 0, aux = 0;

  for(i=0;data[i]!='\0';i++){
    if(isdigit(data[i]))
      aux++;
  }
  if(strlen(data) != aux+2){
    return 0;
  }
  DataQuebrada dq = quebraData(data);
  if(!dq.valido){
    return 0;
  }
  switch(dq.iMes){
    case 1:
      if(dq.iDia < 1 || dq.iDia > 31)
        datavalida = 0;
      break;
    case 2:
      if (isLeapYear(dq.iAno)){
        if(dq.iDia < 1 || dq.iDia > 29)
            datavalida = 0;
      }
      else{
        if(dq.iDia < 1 || dq.iDia > 28)
            datavalida = 0;
      }
    case 3:
      if(dq.iDia < 1 || dq.iDia > 31)
        datavalida = 0;
      break;
    case 4:
      if(dq.iDia < 1 || dq.iDia > 30)
        datavalida = 0;
      break;
    case 5:
      if(dq.iDia < 1 || dq.iDia > 31)
        datavalida = 0;
      break;
    case 6:
      if(dq.iDia < 1 || dq.iDia > 30)
        datavalida = 0;
      break;
    case 7:
      if(dq.iDia < 1 || dq.iDia > 31)
        datavalida = 0;
      break;
    case 8:
      if(dq.iDia < 1 || dq.iDia > 31)
        datavalida = 0;
      break;
    case 9:
      if(dq.iDia < 1 || dq.iDia > 30)
        datavalida = 0;
      break;
    case 10:
      if(dq.iDia < 1 || dq.iDia > 31)
        datavalida = 0;
      break;
    case 11:
      if(dq.iDia < 1 || dq.iDia > 30)
        datavalida = 0;
      break;
    case 12:
      if(dq.iDia < 1 || dq.iDia > 31)
        datavalida = 0;
      break;
    default:
      datavalida = 0;
      break;
  }

  return datavalida;
}



/*
 Q2 = diferença entre duas datas
 @objetivo
    Calcular a diferença em anos, meses e dias entre duas datas
 @entrada
    uma string datainicial, uma string datafinal. 
 @saida
    Retorna um tipo DiasMesesAnos. No atributo retorno, deve ter os possíveis valores abaixo
    1 -> cálculo de diferença realizado com sucesso
    2 -> datainicial inválida
    3 -> datafinal inválida
    4 -> datainicial > datafinal
    Caso o cálculo esteja correto, os atributos qtdDias, qtdMeses e qtdAnos devem ser preenchidos com os valores correspondentes.
 */

DiasMesesAnos q2(char datainicial[], char datafinal[])
{

  //calcule os dados e armazene nas três variáveis a seguir
  DiasMesesAnos dma;
  
  if (q1(datainicial) == 0){
    dma.retorno = 2;
    return dma;
  }
  else if (q1(datafinal) == 0){
    dma.retorno = 3;
    return dma;
  }
    
  DataQuebrada dataIn = quebraData(datainicial);
  DataQuebrada dataFim = quebraData(datafinal);
  //verifique se a data final não é menor que a data inicial
  if(dataFim.iAno < dataIn.iAno){
    dma.retorno = 4;
    return dma;
  }
  else if(dataFim.iMes < dataIn.iMes && dataFim.iAno == dataIn.iAno){
    dma.retorno = 4;
    return dma;
  }
  else if (dataFim.iDia < dataIn.iDia && dataFim.iMes == dataIn.iMes && dataFim.iAno == dataIn.iAno){
    dma.retorno = 4;
    return dma;
  }
  //calcule a distancia entre as datas
  //Anos
  if (dataFim.iAno > dataIn.iAno + 1){
    dma.qtdAnos = dataFim.iAno - dataIn.iAno - 1;
    if(dataFim.iMes > dataIn.iMes)
      dma.qtdAnos++;
    else if(dataFim.iMes == dataIn.iMes && dataFim.iDia >= dataIn.iDia)
      dma.qtdAnos++;
  }
  else if(dataFim.iAno > dataIn.iAno){
    if(dataFim.iMes > dataIn.iMes)
      dma.qtdAnos = 1;
    else if(dataFim.iMes == dataIn.iMes && dataFim.iDia >= dataIn.iDia)
      dma.qtdAnos = 1;
    else
      dma.qtdAnos = 0;
  }
  else{
    dma.qtdAnos = 0;
  }
  //Meses
  if(dataFim.iMes < dataIn.iMes){
    dma.qtdMeses = dataIn.iMes - dataFim.iMes;
    dma.qtdMeses = (dma.qtdMeses - 11) * (-1);
    if(dataFim.iDia >= dataIn.iDia){
      dma.qtdMeses++;
    }
  }
  else if(dataFim.iMes == dataIn.iMes){
    if(dataFim.iDia < dataIn.iDia){
      dma.qtdMeses = 12;
    }
    else{
      dma.qtdMeses = 0;
    }
  }
  else if(dataFim.iMes > dataIn.iMes + 1){
    dma.qtdMeses = dataFim.iMes - dataIn.iMes - 1;
    if(dataFim.iDia >= dataIn.iDia){
      dma.qtdMeses++;
    }
  }
  else if(dataFim.iMes > dataIn.iMes){
    if(dataFim.iDia >= dataIn.iDia){
      dma.qtdMeses = 1;
    }
    else{
      dma.qtdMeses = 0;
    }
  }  
  //dia
  int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  
  if(isLeapYear(dataFim.iAno) && (dataIn.iMes == 2 && dataFim.iMes == 3)){
    days[1] = 29;
  }
  if(dataFim.iDia < dataIn.iDia){
    dma.qtdDias = days[dataIn.iMes -1] - dataIn.iDia;
    dma.qtdDias = (dma.qtdDias + dataFim.iDia);
  }
  else{
    dma.qtdDias = dataFim.iDia - dataIn.iDia;
  }

  //se tudo der certo
  dma.retorno = 1;
  return dma;
}
    

/*
 Q3 = encontrar caracter em texto
 @objetivo
    Pesquisar quantas vezes um determinado caracter ocorre em um texto
 @entrada
    uma string texto, um caracter c e um inteiro que informa se é uma pesquisa Case Sensitive ou não. Se isCaseSensitive = 1, a pesquisa deve considerar diferenças entre maiúsculos e minúsculos.
        Se isCaseSensitive != 1, a pesquisa não deve  considerar diferenças entre maiúsculos e minúsculos.
 @saida
    Um número n >= 0.
 */
int q3(char *texto, char c, int isCaseSensitive)
{
    int qtdOcorrencias = 0;
    char aux[250];
    strcpy(aux, texto);
  
    if(isCaseSensitive != 1){
      if(c >= 'A' && c <= 'Z'){
        c += 32;
      }
      for(int i = 0; aux[i]!='\0'; i++){
        if(aux[i]>='A' && aux[i]<='Z'){
          aux[i] += 32;
        }
      }
    }

    for(int i = 0; aux[i]!='\0'; i++){
      if(aux[i] == c){
        qtdOcorrencias++;
      }
    }

    return qtdOcorrencias;
}

/*
 Q4 = encontrar palavra em texto
 @objetivo
    Pesquisar todas as ocorrências de uma palavra em um texto
 @entrada
    uma string texto base (strTexto), uma string strBusca e um vetor de inteiros (posicoes) que irá guardar as posições de início e fim de cada ocorrência da palavra (strBusca) no texto base (texto).
 @saida
    Um número n >= 0 correspondente a quantidade de ocorrências encontradas.
    O vetor posicoes deve ser preenchido com cada entrada e saída correspondente. Por exemplo, se tiver uma única ocorrência, a posição 0 do vetor deve ser preenchido com o índice de início do texto, e na posição 1, deve ser preenchido com o índice de fim da ocorrencias. Se tiver duas ocorrências, a segunda ocorrência será amazenado nas posições 2 e 3, e assim consecutivamente. Suponha a string "Instituto Federal da Bahia", e palavra de busca "dera". Como há uma ocorrência da palavra de busca no texto, deve-se armazenar no vetor, da seguinte forma:
        posicoes[0] = 13;
        posicoes[1] = 16;
        Observe que o índice da posição no texto deve começar ser contado a partir de 1.
        O retorno da função, n, nesse caso seria 1;

 */
int q4(char *strTexto, char *strBusca, int posicoes[30])
{
    int tam, aux, i, j, ver, k, qtd, neg;
    char text[250], busca[30];
    strcpy(text, strTexto);
    strcpy(busca, strBusca);
    int qtdOcorrencias = 0;
    for(tam = 0; busca[tam]!='\0'; tam++){}
    // printf("%d ", tam);
    qtd = 0;
    neg = 0;
    for(i=0; text[i]!='\0'; i++){
      if(text[i] == -61){
          neg++;
      }
      if(text[i] == busca[0]){
        k = 0;
        aux = i + 1 - neg;
        j = i;
        ver = 0;
        while(text[j]==busca[k]){
          ver++;
          j++;
          k++;
          i++;
        }
        if(ver == tam){
          posicoes[qtd] = aux;
          posicoes[qtd+1] = aux + tam - 1;
          qtdOcorrencias++;
          i--;
          qtd+=2;
        }
      }
    }

    return qtdOcorrencias;
}

/*
 Q5 = inverte número
 @objetivo
    Inverter número inteiro
 @entrada
    uma int num.
 @saida
    Número invertido
 */

int q5(int num)
{
  int tam, aux, div, mult;
  tam = 10;
  while(num%tam!=num){
    tam*= 10;
  }
  div = tam/10;
  mult = 1;
  aux = 0;
  while(tam>1){
    aux += (num%tam/div)*mult;
    mult *=10;
    tam /=10;
    div /= 10;
  }
    num = aux;
    return num;
}

/*
 Q6 = ocorrência de um número em outro
 @objetivo
    Verificar quantidade de vezes da ocorrência de um número em outro
 @entrada
    Um número base (numerobase) e um número de busca (numerobusca).
 @saida
    Quantidade de vezes que número de busca ocorre em número base
 */

int q6(int numerobase, int numerobusca)
{
    int qtdOcorrencias = 0;
    long long div, i, subdiv, casabusca, num;
    casabusca = 10;
    while(numerobusca/casabusca!=0){
      casabusca*=10;
    }
    div = 10;
    while(numerobase/div!=0){
      div*=10;
    }
    subdiv = div/casabusca;
    for(i = div; subdiv>0; i/=10){
      num = (numerobase%i)/subdiv;
      if(num==numerobusca){
        qtdOcorrencias++;
        i = i/casabusca*10;
        subdiv = subdiv/casabusca*10;
      }
      subdiv/=10;
    }
     return qtdOcorrencias;
}

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
