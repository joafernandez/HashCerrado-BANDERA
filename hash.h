//
// Created by joana on 12/9/2023.
//

#ifndef HAHCERRADO_BANDERA_ALEATORIO_HASH_H
#define HAHCERRADO_BANDERA_ALEATORIO_HASH_H

#endif //HAHCERRADO_BANDERA_ALEATORIO_HASH_H
#include <stdio.h>

typedef struct tabla {
    int capacidad;
    int tamanio;
    char**tabla;  //*tabla->[*char nombre]  //coleccion
    int *bandera;
} TablaHashing;

TablaHashing * newTablaHashing(int capacidad);
int hash(TablaHashing * tabla,const char * nombre);
int completa(TablaHashing * tabla);
void agregar( TablaHashing * tabla, char * nombre);
void redispersion(TablaHashing *tabla,char *nombre,int posicion);
int existe(TablaHashing *tabla, char *nombre);
void eliminar(TablaHashing *tabla, char *nombre);
void imprimir(TablaHashing * tabla);

/*



                       Tabla->
               tabla->[  pos/i]
               nombre [   i  ]
                      [joana]'\0'


void eliminaraleatorio(char*tabla[10],char *nombre, int permutacion[10]);*/