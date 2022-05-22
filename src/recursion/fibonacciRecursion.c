/*
--------------------------------------------------------------------
    Programa que calcula la serie de fibonacci con recursion
--------------------------------------------------------------------
    DESCRIPCION: 

    AUTHOR: Francisco Andrade
*/
#include <stdio.h>

int fibonacci(int n){
    if(n==0)
        return 0;
    else if(n==1)
        return 1;
    else 
        return (fibonacci(n-1)+fibonacci(n-2));
}

int main(void){
    int num;
    printf("Ingrese un numero para calcular fibonacci: ");
    scanf("%d",&num);
    if(num>=0)
        printf("El resultado es: %d\n",fibonacci(num));
    else
        puts("Ingrese un numero valido");
}