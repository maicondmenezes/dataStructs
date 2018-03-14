/**
 * Descrição|Description:
 *O arquivo a seguir implementa um Lista Linear, baseada na aula de
 *Estruturas de Dados do curso de Engenharia da Computação da UNESP.  
 *As listas gerenciadas podem ter MAX elementos (posicoes de 0 a MAX-1 no
 *arranjo Array). Alocamos MAX+1 posicoes no arranjo para possibilitar a 
 *criacao de um elemento sentinela.
 * 
 *The following file implements a Sequential Linear List, based on the
 *Data Structures of the Computer Engineering course of UNESP
 *Link para a video aula(video lesson link):
 * https://youtu.be/g_nbG7L5ou0
 * 
 * File:   LinearList.h
 * Author: Maicon de Menezes <mdmoliveira@inf.ufpel.edu.br>
 *
 * Created on 13 de Março de 2018, 23:57
 */
#include <stdio.h>
#define MAX 50
#define ERRO -1
#define true 1
#define false 0

typedef int boolean;
typedef int KEYTYPE;

typedef struct{
  KEYTYPE key;
  // outros campos...
} RECORD;

typedef struct {
  RECORD Array[MAX+1];
  int ElementsAmount;
} LinearList;

/* Inicialização da lista sequencial (a lista já está criada e é apontada 
pelo endereço em ThisList) */
void LinearList_Initialize(LinearList* ThisList){
  ThisList->ElementsAmount = 0;
} /* InitializeList */

/* Exibição da lista sequencial */
void LinearList_Show(LinearList* ThisList){
    int i;
    printf("Lista:[ ");
    for (i=0; i < ThisList->ElementsAmount; i++)
        printf("%i ", ThisList->Array[i].key); // Esta linha deve ser alterada com o parametro de comparação da estrutura implementada
    printf(" ]\n");
} /* ShowLinearList */ 

/* Retornar o tamanho da lista (numero de elementos "validos") */
int LinearList_Size(LinearList* ThisList) {
  return ThisList->ElementsAmount;
} /* tamanho */

/* Retornar o tamanho em bytes da lista. Neste caso, isto nao depende do numero
   de elementos que estao sendo usados, pois a alocacao de memoria eh estatica.
   Array priori, nao precisariamos do ponteiro para a lista, vamos utiliza-lo apenas
   porque teremos as mesmas funcoes para listas ligadas.   
*/
int LinearList_BytesSize(LinearList* ThisList) {
  return sizeof(LinearList);
} /* tamanhoEmBytes */

/* Retornar a key do primeiro elemento da lista sequencial (caso haja) e ERRO
   caso a lista esteja vazia */
KEYTYPE LinearList_First(LinearList* ThisList){
  if(ThisList->ElementsAmount > 0) 
      return ThisList->Array[0].key;
  else return ERRO; // lista vazia
} /* primeiroElem */

/* Retornar a key do ultimo elemento da lista sequencial (caso haja) e ERRO
   caso a lista esteja vazia */
KEYTYPE LinearList_Last(LinearList* ThisList) {
  if(ThisList->ElementsAmount > 0)
      return ThisList->Array[ThisList->ElementsAmount-1].key;
  else return ERRO; // lista vazia
} /* ultimoElem */

/* Retornar a key do elemento que está na posição n da LinearList. Lembre-se que as posicoes do
   arranjo Array vao de 0 a MAX-1  */
KEYTYPE LinearList_Select(LinearList* ThisList, int index) {
  if((n >= 0) && (n < ThisList->ElementsAmount)) 
      return ThisList->Array[index].key ;
  else 
      return ERRO;
} /* enesimoElem */

/* Reinicializar a estrutura */
void LinearList_Reinitialize(LinearList* ThisList) {
  ThisList->ElementsAmount = 0;
} /* reInitializeList */

/* Inserção "direta" na iésima posição (posicao i do arranjo Array).
   Funciona da mesma maneira de um insertionSort: deve-se deslocar todos os
   elementos a partir da iesima posicao e entao se insere o novo elemento. */
boolean LinearList_InsertInPosition(LinearList* ThisList, RECORD reg, int Position){
  int j;
  if ((ThisList->ElementsAmount >= MAX) || (Position < 0) || (Position > ThisList->ElementsAmount)) 
     return(false); // lista cheia ou índice inválido
  for (j = ThisList->ElementsAmount; j > i; j--) 
      ThisList->Array[j] = ThisList->Array[j-1];
  ThisList->Array[Position] = reg;
  ThisList->ElementsAmount++;
  return true;
} /* inserirElemLista */

/* Busca sequencial em lista ordenada ou não SEM SENTINELA */
int LinearList_Search(LinearList* ThisList, KEYTYPE key) {
  int i = 0;
  while (i < ThisList->ElementsAmount){
    if(key == ThisList->Array[i].key) return i; // achou
    else i++;
  }
  return ERRO; // não achou
} /* buscaSequencial */


/* Exclusão do elemento cuja key seja igual a key */
boolean LinearList_Delete(LinearList* ThisList, KEYTYPE key) { 
  int position, j;
  position = buscaSequencial(ThisList,key);
  if(position == ERRO) 
      return false; // não existe
  for(j = position; j < ThisList->ElementsAmount-1; j++)
      ThisList->Array[j] = ThisList->Array[j+1];
  ThisList->ElementsAmount--;
  return true;
} /* excluirElemLista */


/* Busca sequencial em lista COM SENTINELA (vetor criado com MAX+1 posições) */
int LinearList_SentinelSearch(LinearList* ThisList, KEYTYPE key) {
  int i = 0;
  ThisList->Array[ThisList->ElementsAmount].key = key; // sentinela
  while(ThisList->Array[i].key != key) 
      i++;
  if (i > ThisList->ElementsAmount -1) 
      return ERRO; // não achou
  else
      return i;
} /* buscaSentinela */
/* Busca sequencial em lista COM SENTINELA (vetor criado com MAX+1 posições) 
   considerando o arranjo ordenado */
int LinearList_SortedSentinel(LinearList* ThisList, KEYTYPE key) {
  int i = 0;
  ThisList->Array[ThisList->ElementsAmount].key = key; // sentinela
  while(ThisList->Array[i].key < key) 
      i++;
  if (i == ThisList->ElementsAmount || ThisList->Array[i].key != key) 
      return ERRO; // não achou
  else 
      return i;
} /* buscaSentinela */
/* Busca binaria em lista ordenada */
int LinearList_BinarySearch(LinearList* ThisList, KEYTYPE key){
  int left, right, center;
  left = 0;
  right = ThisList->ElementsAmount-1;
  while(left <= right){
      center = ((left + right) / 2);
      if(ThisList->Array[center].key == key) 
          return center; // achou
      else{
          if(ThisList->Array[center].key < key) 
              left = center + 1;
          else 
              right = center - 1;
      }
  }
  return ERRO;
} /* buscaBinaria */
/* Exclusão do elemento cuja key seja igual a key em lista ordenada*/
bool LinearList_DeleteInSortedList(LinearList* ThisList, KEYTYPE key) { 
  int position, j;
  position = LinearList_BinarySearch(ThisList,key);
  if(position == ERRO) 
      return false; // não existe
  for(j = position; j < ThisList->ElementsAmount-1; j++) 
      ThisList->Array[j] = ThisList->Array[j+1];
  ThisList->ElementsAmount--;
  return true;
} /* excluirElemListaOrd */
/* Inserção em lista ordenada usando busca binária permitindo duplicação */
bool LinearList_InsertInSortedList(LinearList* ThisList, RECORD reg) {
  if(ThisList->ElementsAmount >= MAX)
      return false; // lista cheia
  int position = ThisList->ElementsAmount;
  while(position > 0 && ThisList->Array[position-1].key > reg.key){
      ThisList->Array[position] = ThisList->Array[position-1];
      position--;
  }
  ThisList->Array[position] = reg;
  ThisList->ElementsAmount++;
  return true;
} /* inserirElemListaOrd */
/* Inserção em lista ordenada usando busca binária sem duplicação */
bool LinearList_InsertInSortedListWithOutDuplication(LinearList* ThisList, RECORD reg) {
  if(ThisList->ElementsAmount >= MAX) return false; // lista cheia
  int position;
  position = LinearList_BinarySearch(ThisList,reg.key);
  if(position != ERRO)
      return false; // elemento já existe
  position = ThisList->ElementsAmount-1;
  while(position>0 && ThisList->Array[position].key > reg.key){
      ThisList->Array[position+1] = ThisList->Array[position];
      position--;
  }
  ThisList->Array[position+1] = reg;
  ThisList->ElementsAmount++;
  return true;
} /* inserirElemListaOrd */


