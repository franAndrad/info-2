/*
--------------------------------------------------------------------
    Funcion recursiva ejercicio 5
--------------------------------------------------------------------
    DESCRIPCION: Probar con n=5

    AUTHOR: Francisco Andrade
*/
#include <stdio.h>

int recu(int n){
    if(n==1)
        return 1;
    else
        return recu(n-1)+2*n-1;
}

int main(void){
        printf("El resultado es: %d\n",recu(5));
}