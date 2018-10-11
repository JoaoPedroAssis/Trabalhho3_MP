#include "../include/contador.h"
#include <stdio.h>

/*********************************************************************
Função contador

Descrição:

A função abaixo é o "Cérebro" do programa. Ela trata o arquivo todo como uma string
e compara cada uma de suas posições para saber do que se trata. A função irá manter
um contador geral do número de linhas, e irá contar quantas linhas comentads e 
vazias o arquivo de texto tem.

Parâmetros:

char nomeArquivo[] - nome do arquivo que será aberto e analisado
int linhas_comentadas - flag para controle do programa
int linhas_vazias - flag para controle do programa

Assertiva de entrada:

A função deve receber uma string que contém o nome do programa a ser analisado

Assertiva de saída:

A função deve retornar um inteiro que simboliza o número de linhas válidas existentes

**********************************************************************************/ 

int contador(char nomeArquivo[], int linhas_comentadas, int linhas_vazias){
  FILE *pArquivo;
  unsigned int Num_linhas_tot = 0, count = 0, c, bCom = 0, i, num_Com = 0;
  unsigned int Com_flag = 0, linhaVaz = 0, ContVaz = 0, num_vazias = 0;
  // Obter a quantidade de caracteres contidas no arquivo
  char texto[sizeof(pArquivo)*1024];
  pArquivo = fopen(nomeArquivo, "r");
  if (pArquivo != NULL) {  // Se arquivo existe
    do {
      c = fgetc(pArquivo);
      if (c == '\n') {  // Verifica se a linha acabou
        Num_linhas_tot++;
      }
      texto[count] = c;
      count++;
    } while (c != EOF);
    fclose(pArquivo);
  }

  for (i = 0; i < count-1; i++) {

  	//--------- contando comentários-------------------------

    if (texto[i] == '/' && texto[i+1] == '*') {  // Inicio do comentario
      bCom = 1;
      num_Com++;
    }
    // Quebra de linha no bloco de comentario
    if (bCom == 1 && texto[i] == '\n') {
      num_Com++;
    }
    if (texto[i] == '*' && texto[i+1] == '/') {  // Fim do comentario em bloco
      bCom = 0;
    }
    // Comentario feito apos algum codigo (mesma linha)
    // Posição atual de texto e próxima posição
    if (texto[i] == '/' && texto[i+1] == '/') {
      if (Com_flag == 1 && texto[i] != ' ') {
        num_Com++;
      } else {
        Com_flag = 0;
      }
    }
    if (texto[i] == '\n') {
      Com_flag = 1;
    }

    // ---------------Contar Vazias---------------
    // Se for linha vazia e houver quebra de linha, acrescenta numero de vazias
    if (linhaVaz == 1 && ContVaz == 1 && texto[i] == '\n') {
      num_vazias++;
      linhaVaz = 0;
    }
    if (linhaVaz == 1 && texto[i] != ' ' && texto[i] != '\n') {
      ContVaz = 0;
    }
    if (texto[i] == '\n') {
      linhaVaz = 1;
      ContVaz = 1;
    }
}
  // Garantindo o não acesso de uma posição negativa do array
  if (count > 3) {
    if (texto[count-2] == '\n') {
      num_vazias++;
    }
  }
  return Num_linhas_tot + 1 - num_vazias - num_Com;
}
