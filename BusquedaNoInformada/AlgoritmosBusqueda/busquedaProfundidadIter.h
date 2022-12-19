#ifndef __BUSQUEDAPROFUNDIDADITER_H
#define __BUSQUEDAPROFUNDIDADITER_H

#include "busquedaProfundidadLim.h"

/*  Busqueda en profundidad */
int busquedaProfundidadIter(){
    int limit = 0, objetivo = 0;

    while (!objetivo){
        objetivo = busquedaProfundidadLim(limit);
        limit++;
    }
    return objetivo;
}

#endif

