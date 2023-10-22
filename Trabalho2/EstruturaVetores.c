#include <stdio.h>
#include <stdlib.h>
#define TAM 10

#include "EstruturaVetores.h"

typedef struct No {
  int tam;
  int *aux;
  int qtd;
} Elemento;

Elemento vetorPrincipal[TAM];

/*
Objetivo: criar estrutura auxiliar na posição 'posicao'.
com tamanho 'tamanho'

Rertono (int)
    SUCESSO - criado com sucesso
    JA_TEM_ESTRUTURA_AUXILIAR - já tem estrutura na posição
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
    SEM_ESPACO_DE_MEMORIA - Sem espaço de memória
    TAMANHO_INVALIDO - o tamanho deve ser maior ou igual a 1
*/
int criarEstruturaAuxiliar(int posicao, int tamanho) {

  if (posicao < 1 || posicao > TAM)
    return POSICAO_INVALIDA;

  posicao--;

  if (vetorPrincipal[posicao].aux != NULL)
    return JA_TEM_ESTRUTURA_AUXILIAR;

  if (tamanho < 1)
    return TAMANHO_INVALIDO;

  vetorPrincipal[posicao].aux = (int *)malloc(tamanho * sizeof(int));

  if (vetorPrincipal[posicao].aux == NULL)
    return SEM_ESPACO_DE_MEMORIA;

  vetorPrincipal[posicao].tam = tamanho;
  return SUCESSO;
}

/*
Objetivo: inserir número 'valor' em estrutura auxiliar da posição 'posicao'
Rertono (int)
    SUCESSO - inserido com sucesso
    SEM_ESPACO - não tem espaço
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
CONSTANTES
*/
int inserirNumeroEmEstrutura(int posicao, int valor) {

  if (posicao < 1 || posicao > TAM)
    return POSICAO_INVALIDA;
  else {
    posicao--;
    if (vetorPrincipal[posicao].aux != NULL) {
      if (vetorPrincipal[posicao].qtd < vetorPrincipal[posicao].tam) {
        vetorPrincipal[posicao].aux[vetorPrincipal[posicao].qtd] = valor;
        vetorPrincipal[posicao].qtd++;
        return SUCESSO;
      } else {
        return SEM_ESPACO;
      }
    }
    return SEM_ESTRUTURA_AUXILIAR;
  }
}

/*
Objetivo: excluir o numero 'valor' da estrutura auxiliar no final da estrutura.
ex: suponha os valores [3, 8, 7, 9,  ,  ]. Após excluir, a estrutura deve ficar
da seguinte forma [3, 8, 7,  ,  ,  ]. Obs. Esta é uma exclusão lógica

Rertono (int)
    SUCESSO - excluido com sucesso
    ESTRUTURA_AUXILIAR_VAZIA - estrutura vazia
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int excluirNumeroDoFinaldaEstrutura(int posicao) {
  if (posicao < 1 || posicao > TAM)
    return POSICAO_INVALIDA;

  posicao--;

  if (vetorPrincipal[posicao].aux == NULL)
    return SEM_ESTRUTURA_AUXILIAR;

  if (vetorPrincipal[posicao].qtd == 0)
    return ESTRUTURA_AUXILIAR_VAZIA;

  vetorPrincipal[posicao].qtd--;
  return SUCESSO;
}

/*
Objetivo: excluir o numero 'valor' da estrutura auxiliar da posição 'posicao'.
Caso seja excluido, os números posteriores devem ser movidos para as posições
anteriores ex: suponha os valores [3, 8, 7, 9,  ,  ] onde deve ser excluido o
valor 8. A estrutura deve ficar da seguinte forma [3, 7, 9,  ,  ,  ] Obs. Esta é
uma exclusão lógica Rertono (int) SUCESSO - excluido com sucesso 'valor' da
estrutura na posição 'posicao' ESTRUTURA_AUXILIAR_VAZIA - estrutura vazia
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    NUMERO_INEXISTENTE - Número não existe
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar

*/
int excluirNumeroEspecificoDeEstrutura(int posicao, int valor) {
  if (posicao < 1 || posicao > TAM)
    return POSICAO_INVALIDA;

  posicao--;

  if (vetorPrincipal[posicao].aux == NULL)
    return SEM_ESTRUTURA_AUXILIAR;

  if (vetorPrincipal[posicao].qtd == 0)
    return ESTRUTURA_AUXILIAR_VAZIA;

  for (int i = 0; i < vetorPrincipal[posicao].qtd; i++) {
    if (vetorPrincipal[posicao].aux[i] == valor) {
      for (int j = i; j < vetorPrincipal[posicao].qtd - 1; j++) {
        vetorPrincipal[posicao].aux[j] = vetorPrincipal[posicao].aux[j + 1];
      }
      vetorPrincipal[posicao].qtd--;
      return SUCESSO;
    }
  }
  return NUMERO_INEXISTENTE;
}

// se posição é um valor válido {entre 1 e 10}
int ehPosicaoValida(int posicao) {
  int retorno = 0;
  if (posicao < 1 || posicao > 10) {
    retorno = POSICAO_INVALIDA;
  } else
    retorno = SUCESSO;

  return retorno;
}
/*
Objetivo: retorna os números da estrutura auxiliar da posição 'posicao (1..10)'.
os números devem ser armazenados em vetorAux

Retorno (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição
'posicao' SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar POSICAO_INVALIDA -
Posição inválida para estrutura auxiliar
*/
int getDadosEstruturaAuxiliar(int posicao, int vetorAux[]) {

  if (posicao < 1 || posicao > TAM)
    return POSICAO_INVALIDA;

  posicao--;

  if (vetorPrincipal[posicao].aux == NULL)
    return SEM_ESTRUTURA_AUXILIAR;

  for (int i = 0; i < vetorPrincipal[posicao].qtd; i++) {
    vetorAux[i] = vetorPrincipal[posicao].aux[i];
  }
  return SUCESSO;
}

/*
Objetivo: retorna os números ordenados da estrutura auxiliar da posição 'posicao
(1..10)'. os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao
(1..10)' SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar POSICAO_INVALIDA -
Posição inválida para estrutura auxiliar
*/
void ordenarVetor(int vetorAux[], int tam) {
  for (int i = 1; i < tam; i++) {
    int atual = vetorAux[i];
    int j = i - 1;
    while (j >= 0 && vetorAux[j] > atual) {
      vetorAux[j + 1] = vetorAux[j];
      j--;
    }
    vetorAux[j + 1] = atual;
  }
}

int getDadosOrdenadosEstruturaAuxiliar(int posicao, int vetorAux[]) {
  int retorno;
  retorno = getDadosEstruturaAuxiliar(posicao, vetorAux);
  if (retorno == SUCESSO) {
    posicao--;
    ordenarVetor(vetorAux, vetorPrincipal[posicao].qtd);
  }
  return retorno;
}

/*
Objetivo: retorna os números de todas as estruturas auxiliares.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição
'posicao' TODAS_ESTRUTURAS_AUXILIARES_VAZIAS - todas as estruturas auxiliares
estão vazias
*/
int getDadosDeTodasEstruturasAuxiliares(int vetorAux[]) {

  int count = 0;
  for (int posicao = 0; posicao < TAM; posicao++) {
    if (vetorPrincipal[posicao].aux == NULL) {
      continue;
    }
    for (int j = 0; j < vetorPrincipal[posicao].qtd; j++) {
      vetorAux[count] = vetorPrincipal[posicao].aux[j];
      count++;
    }
  }
  if (count == 0)
    return TODAS_ESTRUTURAS_AUXILIARES_VAZIAS;

  return SUCESSO;
}

/*
Objetivo: retorna os números ordenados de todas as estruturas auxiliares.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição
'posicao' TODAS_ESTRUTURAS_AUXILIARES_VAZIAS - todas as estruturas auxiliares
estão vazias
*/
int getDadosOrdenadosDeTodasEstruturasAuxiliares(int vetorAux[]) {

  int count = 0;
  for (int posicao = 0; posicao < TAM; posicao++) {
    if (vetorPrincipal[posicao].aux == NULL) {
      continue;
    }
    for (int j = 0; j < vetorPrincipal[posicao].qtd; j++) {
      vetorAux[count] = vetorPrincipal[posicao].aux[j];
      count++;
    }
  }
  if (count == 0)
    return TODAS_ESTRUTURAS_AUXILIARES_VAZIAS;

  ordenarVetor(vetorAux, count);
  return SUCESSO;
}

/*
Objetivo: modificar o tamanho da estrutura auxiliar da posição 'posicao' para o
novo tamanho 'novoTamanho' + tamanho atual Suponha o tamanho inicial = x, e novo
tamanho = n. O tamanho resultante deve ser x + n. Sendo que x + n deve ser
sempre >= 1

Rertono (int)
    SUCESSO - foi modificado corretamente o tamanho da estrutura auxiliar
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
    NOVO_TAMANHO_INVALIDO - novo tamanho não pode ser negativo
    SEM_ESPACO_DE_MEMORIA - erro na alocação do novo valor
*/
int modificarTamanhoEstruturaAuxiliar(int posicao, int novoTamanho) {
  if (posicao < 1 || posicao > TAM)
    return POSICAO_INVALIDA;

  posicao--;

  if (vetorPrincipal[posicao].aux == NULL)
    return SEM_ESTRUTURA_AUXILIAR;

  novoTamanho += vetorPrincipal[posicao].tam;
  
  if (novoTamanho < 1)
    return NOVO_TAMANHO_INVALIDO;

  vetorPrincipal[posicao].aux =
      (int *)realloc(vetorPrincipal[posicao].aux, novoTamanho * sizeof(int));

  if (vetorPrincipal[posicao].aux == NULL)
    return SEM_ESPACO_DE_MEMORIA;

  vetorPrincipal[posicao].tam = novoTamanho;
  
  if(vetorPrincipal[posicao].qtd > vetorPrincipal[posicao].tam)
    vetorPrincipal[posicao].qtd = vetorPrincipal[posicao].tam;
  
  return SUCESSO;
}

/*
Objetivo: retorna a quantidade de elementos preenchidos da estrutura auxiliar da
posição 'posicao'.

Retorno (int)
    POSICAO_INVALIDA - posição inválida
    SEM_ESTRUTURA_AUXILIAR - sem estrutura auxiliar
    ESTRUTURA_AUXILIAR_VAZIA - estrutura auxiliar vazia
    Um número int > 0 correpondente a quantidade de elementos preenchidos da
estrutura
*/
int getQuantidadeElementosEstruturaAuxiliar(int posicao) {

  if (posicao < 1 || posicao > TAM)
    return POSICAO_INVALIDA;

  posicao--;

  if (vetorPrincipal[posicao].aux == NULL)
    return SEM_ESTRUTURA_AUXILIAR;

  if (vetorPrincipal[posicao].qtd == 0)
    return ESTRUTURA_AUXILIAR_VAZIA;

  return vetorPrincipal[posicao].qtd;
}

/*
Objetivo: montar a lista encadeada com cabeçote com todos os números presentes
em todas as estruturas.

Retorno (No*)
    NULL, caso não tenha nenhum número nas listas
    No*, ponteiro para o início da lista com cabeçote
*/
No *criarNo(int vetAux[], int atual) {
    No *novo = (No*)malloc(sizeof(No));
    novo->conteudo = vetAux[atual];
    novo->prox = NULL;
    return novo;
}

No *montarListaEncadeadaComCabecote() { 
  int qtd=0;
  No *inicio;
  for(int i =0; i<TAM; i++){
    if(vetorPrincipal[i].aux != NULL)
      qtd += vetorPrincipal[i].qtd;
  }
  int vetAux[qtd];
  qtd = 0;
  for(int i =0; i<TAM; i++){
    if(vetorPrincipal[i].qtd != 0){
      for(int j=0; j < vetorPrincipal[i].qtd; j++){
        vetAux[qtd] = vetorPrincipal[i].aux[j];
        qtd++;
      }
    }
  }
  if(qtd == 0)
    return NULL; 

  inicio = (No*)malloc(sizeof(No));
  inicio->conteudo = vetAux[0];
  if(qtd == 1){
    inicio->prox = NULL;
  }
  else{
    No *aux;
    for(int i = 1; i < qtd; i++){
      No *atual, *novo;
      if(i == 1)
        atual = inicio;
      else
        atual = aux;
      novo = criarNo(vetAux, i);
      atual->prox = novo;
      aux = novo;
    }
    aux->prox = NULL;
  }
  return inicio;
}

/*
Objetivo: retorna os números da lista enceada com cabeçote armazenando em
vetorAux. Retorno void
*/
void getDadosListaEncadeadaComCabecote(No *inicio, int vetorAux[]) {
  for(int i = 0; inicio != NULL; i++){
    vetorAux[i] = inicio->conteudo;
    inicio = inicio->prox;
  }
}

/*
Objetivo: Destruir a lista encadeada com cabeçote a partir de início.
O ponteiro inicio deve ficar com NULL.

Retorno
    void.
*/
void destruirListaEncadeadaComCabecote(No **inicio) {
  No *temp;
  while (*inicio != NULL) {
    temp = *inicio;
    *inicio = (*inicio)->prox;
    free(temp);
  }
}


/*
Objetivo: inicializa o programa. deve ser chamado ao inicio do programa

*/

void inicializar() {
  for (int i = 0; i < TAM; i++) {
    vetorPrincipal[i].tam = 0;
    vetorPrincipal[i].aux = NULL;
    vetorPrincipal[i].qtd = 0;
  }
}

/*
Objetivo: finaliza o programa. deve ser chamado ao final do programa
para poder liberar todos os espaços de memória das estruturas auxiliares.

*/

void finalizar() {
  for (int i = 0; i < TAM; i++) {
    if(vetorPrincipal[i].aux != NULL) {
      free(vetorPrincipal[i].aux);
      vetorPrincipal[i].aux = NULL;
    }
  }
}
