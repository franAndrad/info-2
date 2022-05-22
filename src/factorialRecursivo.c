/*
--------------------------------------------------------------------
    Programa que calcula el numero factorial
--------------------------------------------------------------------
    DESCRIPCION: 

    AUTHOR: Francisco Andrade
*/

#include <stdio.h>

int factorial(int n){
    if(n==0)
        return 1;
    else if (n==1)
        return 1;
    else if (n==2)
        return 2;
    else
        return (n*factorial(n-1)); 
}   

int main(void){
    int num;
    printf("Ingrese un numero para calcular el factorial: ");
    if(num>=0)
        printf("El factorial es: %d\n",factorial(5));
    else 
        puts("Ingrese un numero valido");
}