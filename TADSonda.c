#include "./TADSonda.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Inicializa_Sonda(Sonda_Espacial *sonda, int Identificador, Mponto* compartimento, float latitude,float longitude){
         set_IdentificadorSonda(sonda, Identificador);
         set_latitudeSonda(sonda,latitude);
         set_longitudeSonda(sonda,longitude);
         Desliga(sonda);
}
void Liga(Sonda_Espacial *sonda){
    strcpy(sonda->EstaLigada, "Sim!");
}
void Desliga(Sonda_Espacial *sonda){
    strcpy(sonda->EstaLigada, "Nao!");
}

int get_IdentificadorSonda(Sonda_Espacial *sonda){
    return (sonda->Identificador);
}
float get_latitudeSonda(Sonda_Espacial *sonda){
    return (sonda->latitude);
}
float get_longitudeSonda(Sonda_Espacial *sonda){
    return (sonda->longitude);
}

void set_IdentificadorSonda(Sonda_Espacial *sonda, int identificador){
    sonda->Identificador = identificador;
}
void set_latitudeSonda(Sonda_Espacial *sonda, float latitude){
    sonda->latitude = latitude;
}
void set_longitudeSonda(Sonda_Espacial *sonda, float longitude){
    sonda->longitude = longitude;
}
void Move(Sonda_Espacial *sonda, float latitude, float longitude){
    set_latitudeSonda(sonda,latitude);
    set_longitudeSonda(sonda,longitude);
}
void imprime_Sonda(Sonda_Espacial *sonda){
    printf("[Sonda: %s\n", sonda->Identificador);
    printf(" Localizacao(Latidude,Longitude): (%f,%f)\n", sonda->latitude, sonda->longitude);
    printf(" Esta ligada?: %s\n", sonda->EstaLigada);
    imprimec(&(sonda->compartimento));
    printf(" ]\n");
}
