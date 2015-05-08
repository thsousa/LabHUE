/**
  * @file 
  * @brief Arquivo contendo os escopos das funções e estruturas que lidam com operações eventuais
  */
 

#ifndef EVENTOS_H
#define EVENTOS_H

#include "mapa.h"
#include "barco.h"

/**
  * Função inline. 
  *
  * Sorteia com a seguinte regra matemática:
  *
  * 1 + (rand()/RAND_MAX+1.0))*k
  *
  */
#define sorteia(k) ((int)(1 + (rand()/RAND_MAX+1.0))*(k))

/**
  * Determina os três tiros a serem disparados pelo computador, a cada remada. Imprime as
  * mensagens correspondentes ao efeito de cada tiro, e atualiza a matriz representando o mapa.
  *
  * @param mapa		Mapa alocado dinamicamente.
  * @return		Sucesso?
  */
int dispara_tiros(Mapa* mapa);

/**
  * Determina as coordenadas de um tiro, utilizando a função sorteia.
  *
  * @param mapa		Mapa alocado dinamicamente.
  * @param i		Linha sorteada passada por referência.
  * @param j		Coluna sorteada passada por referência.
  * @return 		Sucesso?
  */
void coordenadas_tiro(const Mapa* mapa, int* i, int* j);

/**
 * Imprime as coordenadas de um tiro e a mensagem correspondente ao efeito desse tiro.
 * Se o tiro acerta uma embarcação, especifica-se o seu tipo.
 * Além disso, atualiza na matriz a posição atingida pelo tiro, com um dos seguintes caracteres:
 * '=' se o tiro atingiu a água;
 ∗ '*' se o tiro atingiu alguma embarcacão;
 * '!' se o tiro atingiu o barco;
 * '+' se o tiro atingiu alguma posicão do caminho percorrido pelo barco, exceto a posisão atual.
 *
 * @param mapa		Mapa alocado dinamicamente.
 */
void identifica_alvo_atingido(Mapa* mapa, int i, int j);

/**
 * Afunda totalmente a embarcacao atingida por um tiro; ou seja, atribui '∗' a todas as posições
 * da matriz ocupadas por essa embarcaçao.
 * funcao chamada por identifica_alvo_atingido()
 * a funcao acima deve passar a posicao que o tiro atingiu e o tipo de embarcação atingida
 * Afunda recursivamente: afunda posição atual e busca pelas partes adjacentes
 * Obs: afunda todos os tipos de embarcação, exceto o submarino
 *
 * @param mapa		Mapa alocado dinamicamente
 * @param tipo Tipo de embarcação atingida
 * @param i		Linha
 * @param j		Coluna
 */
void afunda_embarcacao(Mapa* mapa, char tipo, int linha, int coluna)

/**
  * Verifica se o jogo foi ganho.
  * @param mapa		Mapa alocado dinamicamente.
  * @param barco	Barquinho do jogador.
  * @return		1, se o jogo foi ganho.<p>
  *			0, caso contrário.
  */
int ganhou_jogo(const Mapa* mapa, const Barco* barco);

#endif
