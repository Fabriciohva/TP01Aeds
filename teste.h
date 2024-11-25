#ifndef TESTE_H
#define TESTE_H
#include "ListaSondas.h"

typedef struct {
    float x;
    float y;
    Mineral mine;
} RochaS;

float distanciaS(float x1, float y1, float x2, float y2);
void coletarS(TLista_de_Sondas *lista, RochaS *rocha, int num, FILE* arquivo);
void imprimeS(TLista_de_Sondas *lista);
void redistribui(TLista_de_Sondas *lista);
Sonda_Espacial* EncontrarSondaMaisProxima(TLista_de_Sondas *lista, float latitude, float longitude);
void AdicionarRochaNaSondaMaisProxima(Sonda_Espacial *sondaMaisProxima, RochaS *milist);
void operacaoE(TLista_de_Sondas* lista, float Qsondas);
void OperacaoI(TLista_de_Sondas* lista);
#endif
