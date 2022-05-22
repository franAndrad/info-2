/*
--------------------------------------------------------------------
    Funcion recursiva ejercicio 4
--------------------------------------------------------------------
    DESCRIPCION: probar para N=17 y M=5

    AUTHOR: Francisco Andrade
*/
#include <stdio.h>

int recu(int N,int M){
    if(N>=0 && M>0){
        if(N<M)
            return N;
        if(N>=M)
            return recu(N-M,M);
    }
}

int main(void){
        printf("El resultado es: %d\n",recu(17,5));
}