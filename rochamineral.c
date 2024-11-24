#include <stdio.h>
#include <string.h>
#include "rochamineral.h"
void inicializar(mineral* milist,float peso,float latitude,float longitude,char *data,int Identificador){
    set_latitude(milist,latitude);
    set_longitude(milist,longitude);
    strcpy(milist->data, data);
    set_Identificador(milist, Identificador);
    set_peso(milist,peso);
}

int get_Identificador(mineral* milist){
    return(*milist).Identificador;
}
float get_peso(mineral* milist){
    return(*milist).peso;
}
float get_latitude(mineral* milist){
    return(*milist).latitude;
}
float get_longitude(mineral* milist){
    return(*milist).longitude;
}
char* get_data(mineral* milist){
    return(*milist).data;
}

void set_Identificador(mineral* milist,int Identificador){
    (*milist).Identificador = Identificador;
}
void set_peso(mineral* milist, float peso){
    (*milist).peso = peso;
}
void set_latitude(mineral* milist, float latitude){
    (*milist).latitude = latitude;
}
void set_longitude(mineral* milist, float longitude){
    (*milist).longitude = longitude;
}
void set_data(mineral* milist, char *data){
    strcpy((*milist).data,data);
}

void listminerais(mineral* milist,Mineral* listminerais){
    milist->listminerais = listminerais;
}
void classificacao(mineral* milist, char *mineral01, char *mineral02, char *mineral03) {
    char* minerais[] = {mineral01, mineral02, mineral03};

    int ferrolita = 0, aquavitae = 0, calaris = 0, solarium = 0, terranita = 0;

    for (int i = 0; i < 3; i++) {
        if (strcmp(minerais[i], "Ferrolita") == 0) ferrolita = 1;
        if (strcmp(minerais[i], "Aquavitae") == 0) aquavitae = 1;
        if (strcmp(minerais[i], "Calaris") == 0) calaris = 1;
        if (strcmp(minerais[i], "Solarium") == 0) solarium = 1;
        if (strcmp(minerais[i], "Terranita") == 0) terranita = 1;
    }

    if (ferrolita && aquavitae && calaris) {
        strcpy(milist->categoria, "Aquacalis");
    } else if (ferrolita && aquavitae) {
        strcpy(milist->categoria, "Aquaferro");
    } else if (ferrolita && solarium) {
        strcpy(milist->categoria, "Solarisfer");
    } else if (ferrolita && terranita) {
        strcpy(milist->categoria, "Terralis");
    } else if (ferrolita) {
        strcpy(milist->categoria, "Ferrom");
    } else if (solarium && terranita) {
        strcpy(milist->categoria, "Terrasol");
    } else if (solarium) {
        strcpy(milist->categoria, "Solaris");
    } else if (terranita && aquavitae) {
        strcpy(milist->categoria, "Aquaterra");
    } else if (terranita && calaris) {
        strcpy(milist->categoria, "Terrolis");
    } else if (calaris && aquavitae) {
        strcpy(milist->categoria, "Calquer");
    }
}
