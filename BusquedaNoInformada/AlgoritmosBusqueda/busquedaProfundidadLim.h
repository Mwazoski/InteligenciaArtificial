#ifndef __BUSQUEDAPROFUNDIDADLIM_H
#define __BUSQUEDAPROFUNDIDADLIM_H

#include "busquedaBase.h"

/*  Busqueda en profundidad */
int busquedaProfundidadLim(int limit){
    int objetivo = 0, visitados = 0;

    tNodo *Actual = (tNodo*) calloc(1,sizeof(tNodo));
    tNodo *Inicial = nodoInicial();

    LISTA Abiertos = VACIA;
    LISTA Sucesores = VACIA;
    LISTA Cerrados = VACIA;

    InsertarPrimero(&Abiertos,(tNodo*) Inicial,sizeof(tNodo));

    while (!esVacia(Abiertos) && !objetivo){    
        Actual=(tNodo*) calloc(1,sizeof(tNodo));
        ExtraerPrimero(Abiertos,Actual, sizeof(tNodo));
        EliminarPrimero(&Abiertos);
        
        objetivo = testObjetivo(Actual->estado);
        if (!objetivo && (Actual->profundidad < limit) && !esCerrado(Cerrados,Actual)){
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