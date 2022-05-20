/*
--------------------------------------------------------------------
    Programa para separar una cadena con diferentes delimitadores
--------------------------------------------------------------------
    DESCRIPCION: Se realizo una separacion mediante comillas o con espacios segun sea el caso del ingreso. Se utilizo la fgets que devuelve la cadena de caracteres completa y la copia en una variable. Para separar usamos el strtok que separa segun un delimitador.

    AUTHOR: Francisco Andrade
*/

#include <stdio.h>
#include <string.h>

void separar(char*);
int verificar_dato(char *, char *, int);

int main (void){
    const int TAM = 40;
    char entrada[TAM];
    fgets(entrada, TAM ,stdin);
    separar(entrada);
}

// Separa la cadena en tres argumentos si hay doble comilla lo separa en dos
void separar(char *cadena){
    int tam = strlen(cadena);
    char delimitador[20];
    char *token; //puntero donde vamos a asignar los valores

    // Segun la cantidad de comillas hacemos
    int cant_Comillas = verificar_dato(cadena,"\"",tam);
    if(cant_Comillas == 2)
        strcpy(delimitador, "\",\n");
    else
        strcpy(delimitador, " ,\n");
    
    //Definido el delimitador separamos
    token = strtok(cadena,delimitador);
    while(token != NULL){ 
            printf("%s\n",token);
            token = strtok(NULL,delimitador);        
    }
}

//Funcion que devuelve la cantidad de datos que quieramos saber de una cadena de caracteres
int verificar_dato(char *cadena, char *dato, int tam){
    int cantidad=0;
    for(int i=0; i<tam-1 ;i++){
        if(cadena[i]==*dato){
            cantidad++;
        }
    }
    return cantidad;
}