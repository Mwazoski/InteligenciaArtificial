#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "listaia.h"
#include "busquedaBase.h"
#include "busquedaAnchura.h"
#include "busquedaProfundidad.h"
#include "busquedaProfundidadLim.h"
#include "busquedaProfundidadIter.h"
#include "puzle.h"

void manual(){
    int op = 0;
    tEstado* e = estadoInicial();
    dispEstado(e);
    while(!testObjetivo(e)){
        printf("MOV: ");
        scanf("%d",&op);
        e = aplicaOperador(op,e);
        dispEstado(e);
    }
    solucionFin(1);
}

void automatico(){
    int opc = 0;
    printf("\nSelecciona el tipo de busqueda: \n 1. Busqueda en Anchura \n 2. Busqueda en profundidad \n 3. Busqueda en profundidad Limitada \n 4. Busqueda con profundidad Iterativa \n 5. Salir \n > ");
    scanf("%i", &opc);

    switch(opc){
        case 1: solucionFin(busquedaAnchura()); break;
        case 2: solucionFin(busquedaProfundidad()); break;
        case 3: solucionFin(busquedaProfundidadLim(5)); break;
        case 4: solucionFin(busquedaProfundidadIter()); break;
    }
    printf("\n\n");
    

}

int main(){
    
    int opc = 0;
    printf("Menu inteligente: \n 1. Jugar Manual \n 2. Jugar Automatico \n > ");
    scanf("%i",&opc);
    switch(opc){
        case 1: manual(); break;
        case 2: automatico(); break;
    }
    return 0;
}
