/**
  *@file Lógica principal
  */
#include "mapa.h"
#include "barco.h"
#include "eventos.h"
#include <stdio.h>

#ifdef DEBUG
#include "debug.h"
#endif

/**
  * Lógica principal do programa
  * @param argc		
  * @param argv
  * @return 
  */


/** Sugestão (o que acham?)
  *
  * posiciona_barco
  * turno = 0
  * emboscada = 0
  * while(!fimDoJogo)
  *   exibe mapa na tela completado por '-' da linha ocupada pelo barco até (linha mapa->altura - 1)
  *   rema barco
  *   dispara tiros
  *	  se (posicao atual do barco == posicao anterior do barco) emboscada++
  *   se (barco foi atingido || barco->linha == mapa.altura - 1 || emboscada == 3) fimDoJogo
  *
  */

#define BECO_SEM_SAIDA 3 /**< Quantidade de jogadas sem o barco se mover até que o jogo pare.*/

int main(int argc, char* argv[])
{
	Mapa* mapa;
	static Barco lbarco;
	Barco* barco = &lbarco;
	int naoAtingido, naoRemou, travado = 0;
	char* caminho_mapa;
	#ifdef DEBUG
	char funcname[] = "main(%d)\n";
	debug_message(funcname, argc);
	#endif
	
	if (argc < 2)
	{
		fprintf(stdout, "Uso: %s caminho_para_mapa.dat\n", argv[0]);
		return 1;
	}
	
	caminho_mapa = argv[1];
	
	if (leia_mapa(&mapa, caminho_mapa))
	{	
		fprintf(stdout, "Erro ao ler o mapa.\n");
		return 2;
	}
	posiciona_barco(mapa, barco);
	escreva_mapa_tela(mapa);
	
	do
	{
		naoRemou = rema_barco(mapa, barco);
		naoAtingido = dispara_tiros(mapa);
		escreva_mapa_tela(mapa);
		travado = (travado + naoRemou)*naoRemou;
	} while (naoAtingido && travado < BECO_SEM_SAIDA && !ganhou_jogo(mapa, barco));
	
	destroi_mapa(&mapa);
	
	if      (!naoAtingido)              fprintf(stdout, "Seu barco foi atingido. Sad music\n");
	else if (travado >= BECO_SEM_SAIDA) fprintf(stdout, "Seu barco ficou preso. Sad music\n");
	else                                fprintf(stdout, "Você ganhou (a box of fucking nothing)\n");
	
	return 0;
}
