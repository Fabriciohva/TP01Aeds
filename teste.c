#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "teste.h"


void OperacaoI(TLista_de_Sondas* lista) {
    Apontador pAux = lista->pPrimeiro->pProx;
    while (pAux != NULL) {
        Apontador rochaAtual = pAux->Sonda.compartimento->prox;
        while (rochaAtual != NULL) {
            printf("%s %f\n", rochaAtual->Sonda.compartimento->compartimento->categoria, rochaAtual->Sonda.compartimento->compartimento->peso);
            rochaAtual = rochaAtual->pProx;
        }
        pAux = pAux->pProx;
    }
}
void operacaoE(TLista_de_Sondas* lista, float Qsondas) {
    // Chama a função pesoc para obter o peso total das sondas
    float total = pesoc(lista);

    // Zera a latitude e longitude de todas as sondas
    Apontador atual = lista->pPrimeiro;  // Começa no primeiro elemento da lista
    for (int i = 0; i < Qsondas && atual != NULL; i++) {
        atual->Sonda.latitude = 0;
        atual->Sonda.longitude = 0;
        atual = atual->pProx;  // Move para o próximo elemento da lista de sondas
    }

    // Calcula o peso médio e o peso remanescente a ser distribuído
    int peso_medio = total / Qsondas;

    float peso_remanescente = fmod(total, Qsondas);

    // Distribui o peso para cada sonda
    atual = lista->pPrimeiro;  // Volta para o início da lista de sondas
    for (int i = 0; i < Qsondas && atual != NULL; i++) {
        if (i < peso_remanescente) {
            atual->Sonda.peso = peso_medio + 1;
        } else {
            atual->Sonda.peso = peso_medio;
        }
        atual = atual->pProx;  // Move para o próximo elemento da lista de sondas
    }}
float distanciaS(float x1, float y1, float x2, float y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}
Sonda_Espacial* EncontrarSondaMaisProxima(TLista_de_Sondas *lista, float latitude, float longitude){
    float menorDistancia = __FLT_MAX__;
    Sonda_Espacial* sondaMaisProxima = NULL;
    Apontador pAux;
    pAux = lista->pPrimeiro->pProx;
    int i=0;

    while (pAux != NULL)
        {Sonda_Espacial* sondaAtual = pAux;
        float x1 = get_latitudeSonda(&sondaAtual);
        float y1 = get_longitudeSonda(&sondaAtual);
        float distanciaS1 = distanciaS(x1, y1, latitude, longitude);
        if (distanciaS1 < menorDistancia) {
            menorDistancia = distanciaS1;
            sondaMaisProxima = sondaAtual;
            }
            pAux = pAux->pProx;
        }
        return sondaMaisProxima;
}
void AdicionarRochaNaSondaMaisProxima(Sonda_Espacial *sondaMaisProxima, RochaS *milist){

}
/*void coletarS(TLista_de_Sondas *lista, RochaS *rocha, int num, FILE *arquivo) {// num = numero de sondas
    // receber localização das rochas e comparar com localização de cada sonda usando for.
    Sonda_Espacial* sondaMaisProxima = NULL;
    char linha[20];
    float LatP, LongP;
    fgets(linha, sizeof(linha), arquivo);//pega a linha do arquivo
    sscanf(linha, "%f %f", &LatP, &LongP);//pega localização da pedra
    float menorDistancia = __FLT_MAX__;//variavel com o maior valor possivel de float
    for(int i=0;i<num; i++){
        Sonda_Espacial* sondaAtual = &lista->sondas[i];
        float x1 = get_latitudeSonda;
        float y1 = get_longitudeSonda;
        float distanciaS1 = distanciaS(x1, y1, LatP, LongP);
        if (distanciaS1 < menorDistancia) {
            menorDistancia = distanciaS1;
            sondaMaisProxima = sondaAtual;
    }
}*/
void imprimeS(TLista_de_Sondas *lista) {
    Apontador pAux = lista->pPrimeiro->pProx;
    int index = 1;
    while (pAux != NULL) {
        printf("%d\n", index++);
        imprimec(&pAux->Sonda.compartimento);
        pAux = pAux->pProx;
    }
}
void redistribui(TLista_de_Sondas *lista) {
    Apontador aux = lista->pPrimeiro->pProx;
    float total = 0;
    int N = 0;
    while (aux != NULL) {
        total += pesoc(&aux->Sonda.compartimento);
        N++;
        aux = aux->pProx;
    }
    float mpeso = total / N;
    aux = lista->pPrimeiro->pProx;
    TLista_de_Sondas temporaria;
    FLSondaVazia(&temporaria);
    while (aux != NULL) {
        if (pesoc(&aux->Sonda.compartimento) > mpeso) {
            while (pesoc(&aux->Sonda.compartimento) > mpeso) {
                Mineral mineral;
                retirac(&aux->Sonda.compartimento, &mineral);
                LSondaInsere(&temporaria, &aux->Sonda);
            }
        }
        aux = aux->pProx;
    }
    aux = lista->pPrimeiro->pProx;
    while (aux != NULL) {
        if (pesoc(&aux->Sonda.compartimento) < mpeso) {
            while (pesoc(&aux->Sonda.compartimento) < mpeso && !LSondaEhVazia(&temporaria)) {
                Mineral mineral;
                LSondaRetira(&temporaria, &mineral);
                inserec(&aux->Sonda.compartimento, &mineral, 100);
            }
        }
        aux = aux->pProx;
    }
}
