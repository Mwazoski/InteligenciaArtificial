#include <stdio.h>
#include "puzle.h"

/*  Realiza todos los diferentes movimientos
    - si encuentra solucion termina antes.
    - sino solo realiza los cuatro posibles movimientos
*/
int main() {
    int op;
    tEstado *n,*c;
    n = estadoInicial();
    c = estadoObjetivo();
    
    for (op=1; op<=NUM_OPERADORES; op++) {
        if (esValido(op, n)){
            n = aplicaOperador(op,n);
            dispOperador(op);
            dispEstado(n);
            if(iguales(n,c) == 1){
                printf("Ha llegado al objetivoo!! \n");
                return 0;
            }
            }
        }
    }