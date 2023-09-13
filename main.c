
#include "hash.h"
#include <stdio.h>


int main() {

    TablaHashing * tabla = newTablaHashing(5);

    agregar(tabla, "estructuras");     // hash: 1
    agregar(tabla, "MatematicA");     // hash: 2
    agregar(tabla, "tipos de datos"); // hash: 3
    agregar(tabla, "algoritmos");   // hash: 4

    printf("\nTABLA ORIGINAL:\n");
    imprimir(tabla);

    eliminar(tabla,"estructuras");
    printf("\nTABLA DESPUES DE ELIMINAR 'estructuras':\n");
    imprimir(tabla);


    int resultado= existe(tabla,"estructuras");

    if (resultado == 1) {
        printf("La materia que ingresaste existe en la tabla hash.\n");
    } else if (resultado == 0) {
        printf(" La materia que ingresasteeliminado en la tabla hash.\n");
    } else if (resultado == -1) {
        printf(" La materia que ingresaste no existe en la tabla hash.\n");
    }

    return 0;
}