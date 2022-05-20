/*
--------------------------------------------------------------------
    Programa para asignar un espacio de memoria mediante Array
--------------------------------------------------------------------
    DESCRIPCION: 

    AUTHOR: Francisco Andrade
*/

#include <stdio.h>
#include <stdlib.h>

// Funcion que verifica si el valor esta en cierto rango 
int verificacionRango(int a1, int rangMin, int rangMax){
    // Hacemos una verificacion y asignamos el valor a la memoria
    if (a1>= rangMin && a1<=rangMax)
        return 1;
    else
        return 0;
}

//Funcion que le asigna un valor a la memoria y devuelve -1 si hay error y 1 si no hay error
int set(char *a1,char *a2, int *memoria){

    // Convertimos a entero
    int posicion = atoi(a1);
    int valor = atoi(a2);

    //Verifiacamos y Asignamos
    if (verificacionRango(posicion,0,64) == 1 && verificacionRango(valor,0,64)){
        memoria[posicion]=valor;
        printf("\tvar[%d] : %d\n\n",posicion,memoria[posicion]);
        return 1;
    }else{
        return -1;
    }
}

int main(void){
    int memoria[40];
    char a1[40];
    char a2[40];
    scanf("%s",a1);
    scanf("%s",a2);

    //Asignacion de memoria
    set(a1,a2,memoria);
}