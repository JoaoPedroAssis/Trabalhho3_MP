#ifndef _HOME_JOAOPEDROASSIS_UNNB_MP_TRABALHO3_MP_170146367_JOAOPEDRO_
#define _HOME_JOAOPEDROASSIS_UNNB_MP_TRABALHO3_MP_170146367_JOAOPEDRO_INCLUDE_CONTADOR_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// "Copyright [2018] <Copyright João Pedro Assis dos Santos>"

/**
* @file contador.h
*
* @brief Módulo que contém a função que faz a contagem de linhas de um programa. A devida
* especificação de como a função o faz está explicada por meio de código claro e comentado.
* Assertivas de entrada e saída também foram escritas, para que se possa entender melhor o que a função faz como um todo.
*
* @author João Pedro Assis dos Santos - 17/0146367
*
*/


/**
* @brief Função que conta quantas linhas de código útil existem em um programa. Para efeitos matemáticos, também
* é calculado o número de linhas que possuem comentários, bem como o número de linhas vazias. Por fim, após contar
* o número total de linhas, os comentários e linhas em brancos são descontados desse quantitativo.
*
* @param char nomeArquivo[] - nome do arquivo de entrada, que será inicializado dentro da função
* @param int linhas_comentadas - flag verificadora
* @param int linhas_vazias - flag verificadora
*
* @return - retorna o número de linhas úteis da função
*
*/

int contador(char nomeArquivo[], int linhas_comentadas, int linhas_vazias);

#endif  // _HOME_JOAOPEDROASSIS_UNB_MP_TRABALHO3_170156367_JOAOPEDRO_INCLUDE_CONTADOR_H_
