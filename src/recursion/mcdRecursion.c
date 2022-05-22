/*
--------------------------------------------------------------------
    Programa que calcula el maximo comun divisor entre dos numeros
--------------------------------------------------------------------
    DESCRIPCION: 

    AUTHOR: Francisco Andrade
*/
#include <stdio.h>

int MCD(int x,int y){
    if(y==0)
        return x;
    else
        return MCD(y,x%y);

}

int main(void){
    int num;
    printf("Ingrese un numero para calcular el factorial: \n");
    if(num>=0)
        printf("El factorial es: %d\n",MCD(8,4));
    else 
        puts("Ingrese un numero valido");
}