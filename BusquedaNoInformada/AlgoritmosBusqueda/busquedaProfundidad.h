#ifndef __BUSQUEDAPROFUNDIDAD_H
#define __BUSQUEDAPROFUNDIDAD_H

#include "busquedaBase.h"

/*  Busqueda en profundidad */
int busquedaProfundidad(){
    int objetivo = 0, visitados = 0;
    
    tNodo *Actual = (tNodo*) calloc(1,sizeof(tNodo));
    tNodo *Inicial = nodoInicial();

    LISTA Abiertos = VACIA;
    LISTA Sucesores = VACIA;
    LISTA Cerrados = VACIA;

    InsertarPrimero(&Abiertos,(tNodo*) Inicial,sizeof(tNodo));

    while (!esVacia(Abiertos) && !objetivo){    
        Actual = (tNodo*) calloc(1,sizeof(tNodo));
        ExtraerPrimero(Abiertos,Actual, sizeof(tNodo));
        EliminarPrimero(&Abiertos); // AQUI EN VEZ DE ELIMINARLO, PASARLO A CERRADO.

        objetivo = testObjetivo(Actual->estado);
        if (!objetivo && !esCerrado(Cerrados,Actual)){
            Sucesores = expandir(Actual);
            visitados++;
            Abiertos = Concatenar(Sucesores,Abiertos);
            InsertarPrimero(&Cerrados,(tNodo*) Actual,sizeof(tNodo));
        }
    }
  
    if (objetivo)
        dispSolucion(Actual);
    printf("Visitados = %d\n\n", visitados);

    free(Sucesores);
    free(Inicial);
    free(Actual);
    return objetivo;
}

#endif