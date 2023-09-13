
#include "hash.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//TABLA HASH SE COMPORTA COMO UN VECTOR!!!!!!!!!!

TablaHashing * newTablaHashing(int capacidad){
    TablaHashing *mitabla= malloc(sizeof (TablaHashing));
    mitabla->capacidad=capacidad;
    mitabla->tamanio=0;
    mitabla->bandera=malloc(sizeof(int) * capacidad);
    mitabla->tabla= malloc(sizeof (char*)*capacidad);// ej pido 5punteros a char*(q contienen la direc de una palabra)

    for (int i=0;i<capacidad;i++){
        mitabla->tabla[i]=NULL;
    }
    return mitabla;
}

//const no modifica
int hash(TablaHashing * tabla,const char * nombre){
    int suma=0;
    for(int i=0;nombre[i] !='\0';i++){        //[j][o][a][n][a]'\0'
        suma+=nombre[i];
    }
    return suma%tabla->capacidad;  //ME DA UNA POSICION!!!
}

int completa(TablaHashing * tabla){
    if (tabla->capacidad==tabla->tamanio){
        return 1; //verdadero
    }
    return 0;//falso
}
void agregar(TablaHashing * tabla, char * nombre) {
    if (completa(tabla)) {
        printf("No se puede agregar, la tabla esta completa");
        return;

        //SINO SI TENGO LUGAR INSERTO / SI COLISION LE PIDO LUGAR A LA REDISPERSION
    } else {
        int posicion = hash(tabla,nombre);
        if (tabla->tabla[posicion] == NULL) {
            tabla->tabla[posicion] = nombre;
            tabla->tamanio++;
        } else {
            redispersion(tabla, nombre, posicion);
        }
    }
}

void redispersion(TablaHashing *tabla,char *nombre,int posicion){
    int i=posicion+1;

    while (i<tabla->capacidad && tabla->tabla[i]!=NULL ){
        i++;
    }
    if(i==tabla->capacidad){ //si llego al final de la lista,arranco de cero
        i=0;
        while (i<posicion && tabla->tabla[i]!=NULL){
            i++;
        }
    }
}
//OJO ESTOY X COMPARAR 2NOMBRES!! STRCMP

int existe(TablaHashing *tabla, char *nombre) {
    int posicion = hash(tabla, nombre);

    if (tabla->tabla[posicion] != NULL) {
        if (strcmp(tabla->tabla[posicion], nombre) == 0) { //si el contenido de lla posicion hash es igual al nombre q me pasan
            return 1; //  (EXISTE)
        } else if (tabla->bandera[posicion] == 1) {
            return 0; //  (ELIMINADO)
        }
    }
    return -1; // (NO EXISTE))
}


void eliminar(TablaHashing *tabla, char *nombre) {
    int posicion = hash(tabla, nombre);
    if (tabla->tabla[posicion] != NULL && strcmp(tabla->tabla[posicion], nombre) == 0) {
        //si  la pos hash en la tabla tienga algo y es igual al nombre
        tabla->bandera[posicion] = 1;  //marco eliminado con 1
        tabla->tamanio--;   //achico tamaño
    }
}
void imprimir(TablaHashing * tabla) {
    for (int i = 0; i < tabla->capacidad; i++) {
        if (tabla->tabla[i] != NULL && tabla->bandera[i] !=1 ) {   //0=eliminado( quiero q muestre eliminado tb) ,   1=existe
            printf("[%s]\n", tabla->tabla[i]);
        }
    }
}





