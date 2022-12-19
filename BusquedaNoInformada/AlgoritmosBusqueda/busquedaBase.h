#ifndef __BUSQUEDABASE_H
#define __BUSQUEDABASE_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "puzle.h"
#include "listaia.h"

typedef struct NodoBusqueda_{
    tEstado *estado;                //  Estado del nodo
    unsigned operador;              //  Valores de las decisiones que se toman.
    int costeCamino;                //  Coste del camino hasta el nodo.
    int profundidad;                //  Profundidad del nodo.
    int valHeuristica;              //  Valor de la heuristica (sin uso de momento)
    struct NodoBusqueda_ *padre;    //  Puntero a padre.
} tNodo;


/*  Avisar cuando se termine la busqueda */
void solucionFin(int res){
    printf("Fin de la busqueda\n");
    if(res){
      printf("Se ha llegado al objetivo\n");
    }
    else{
      printf("No se ha llegado al objetivo\n");
    }
}

/*  Imprime el estado del nodo */
void dispNodo(tNodo *nodo){
    dispEstado(nodo->estado);
    printf("\n");
}

/*  Imprime por pantalla el camino */
void dispCamino(tNodo *nodo){
    if (nodo->padre==NULL){
        printf("\n Desde el inicio\n");
        dispEstado(nodo->estado);
    }
    else {
        dispCamino(nodo->padre);
         dispOperador(nodo->operador);
        dispEstado(nodo->estado);
    }
}

/*  Imprime por pantalla la solucion */
void dispSolucion(tNodo *nodo){
    dispCamino(nodo);
    printf("Profundidad = %d\n",nodo->profundidad);
    printf("Coste = %d\n",nodo->costeCamino);
   
}

/* Crea el nodo raiz. */
tNodo *nodoInicial(){
   tNodo *inicial=(tNodo *) malloc(sizeof(tNodo));
   inicial->estado = estadoInicial();
   inicial->padre = NULL;
   inicial->costeCamino = 0;
   inicial->profundidad = 0;
   return inicial;
}

/*  Expande los nodos */
LISTA expandir(tNodo *nodo){
    unsigned op;
    LISTA sucesores=VACIA;
    tNodo *nuevo=calloc(1,sizeof(tNodo));
    tEstado *s;
    for (op=1; op<=NUM_OPERADORES;op++){
      if (esValido(op,nodo->estado)){
          s=aplicaOperador(op,nodo->estado);
          nuevo->estado=s;
          nuevo->padre=nodo;
          nuevo->operador=op;
          nuevo->costeCamino=nodo->costeCamino + coste(op,nodo->estado);
          nuevo->profundidad=nodo->profundidad + 1;
          InsertarUltimo(&sucesores , (tNodo*)nuevo , (sizeof(tNodo)));
      }
  }
return sucesores;
}

/*  Control de estados repetidos
    1 = esRepetido
    0 = No esRepetido
*/
int esCerrado(LISTA Cerrados, tNodo *Actual)
{
    int repetido = 0;
    tNodo auxNodo;

    while (!esVacia(Cerrados) && !repetido)
    {
        ExtraerPrimero(Cerrados, &auxNodo, sizeof(auxNodo));
        repetido = iguales(Actual->estado, auxNodo.estado);
        Cerrados = Cerrados->next;
    }
    return repetido;
}

#endif
