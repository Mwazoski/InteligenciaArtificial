#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "puzle.h"

tEstado *crearEstado(int puzle[N][N] , int fila , int col){
   tEstado *estado = (tEstado *) malloc(sizeof(tEstado));
   int i, j, ficha;

   for (i=0;i<N;i++)
      for (j=0;j<N;j++)
      {
         ficha=puzle[i][j];
         estado->celdas[i][j]=ficha;
          
      /* RELLENAR ADECUADAMENTE*/
         estado->fila=fila;
         estado->col=col;
      }
   return estado;
}


/* Creacion de un estado Inicial */
tEstado *estadoInicial(){
   return crearEstado(puzle_inicial,2,2);
}

/* Creacion de un estado objetivo*/
tEstado *estadoObjetivo(){
   return crearEstado(puzle_final,2,1);
}

/* Definicion de la funcion coste, que en este
   caso sera constante */
int coste(unsigned op, tEstado *estado){
   return 1;
}

/* Mostrar estado */
void dispEstado(tEstado *estado){
   int i,j;

   for (i=0; i<N; i++){
      for (j=0; j<N; j++)
         printf("%d",estado->celdas[i][j]);
      printf("\n");
   }
   printf("\n");
}

/* Mostrar operadores posibles*/
void dispOperador(unsigned op){
   switch(op){
      case ARRIBA:    printf("Movimiento ARRIBA:\n"); break;
      case ABAJO:     printf("Movimiento ABAJO:\n"); break;
      case IZQUIERDA: printf("Movimiento IZQUIERDA:\n"); break;
      case DERECHA:   printf("Movimiento DERECHA:\n"); break;
   }
}


/* Funcion auxiliar para comprobar si dos puzles tienen las 
   fichas colocadas en el mismo orden en el tablero */
int iguales(tEstado *s, tEstado *t){
   for(size_t i = 0 ; i<3 ; ++i){
      for(size_t j = 0 ; j < 3 ; ++j){
         if(s->celdas[i][j] != t->celdas[i][j]){
            return 0;
         }
      }
   }
   return 1;  // Si igual = 0 significa que no son iguales, si igual = 1 significa que si.
}

/* Devuelve verdad si el estado actual es igual
   al estado objetivo */
int testObjetivo(tEstado *estado){
   tEstado *final;
   final=estadoObjetivo();
   return(iguales(estado, final));
}

/* Comprueba si el movimiento a realizar es valido*/
int esValido(unsigned op, tEstado *estado){
   int valido=0;
   switch(op){
   case ARRIBA: valido = estado->fila > 0;
      break;
      case ABAJO: valido = estado->fila < N-1;
      break;
      case IZQUIERDA: valido = estado->col > 0;
      break;
      case DERECHA: valido = estado->col < N-1;
      break;
      default: valido=0;
   }
return valido;
}

/* Realiza el movimiento segun el operador */
tEstado *aplicaOperador(unsigned op, tEstado *estado){
   tEstado *t = (tEstado *) malloc(sizeof(tEstado));
   memcpy(t,estado,sizeof(tEstado));
   int aux;
   switch(op){
   case ARRIBA:   aux = t->celdas[t->fila-1][t->col]; 
                  t->celdas[t->fila-1][t->col] = 0; 
                  t->celdas[t->fila][t->col] = aux;
                  t->fila--;
                  break;

   case ABAJO: 
                  aux = t->celdas[t->fila+1][t->col];
                  t->celdas[t->fila+1][t->col] = 0; 
                  t->celdas[t->fila][t->col] = aux;
                  t->fila++; 
                  break;

   case IZQUIERDA: 
                  aux = t->celdas[t->fila][t->col-1];
                  t->celdas[t->fila][t->col-1] = 0; 
                  t->celdas[t->fila][t->col] = aux;
                  t->col--;
                  break;

   case DERECHA: 
                  aux = t->celdas[t->fila][t->col+1];
                  t->celdas[t->fila][t->col+1] = 0; 
                  t->celdas[t->fila][t->col] = aux;
                  t->col++;
                  break;
   }
   return t;
}




