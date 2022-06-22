/*
--------------------------------------------------------------------
    Programa para separar una cadena con diferentes delimitadores
--------------------------------------------------------------------
    DESCRIPCION: Se realizo una separacion mediante comillas o con espacios segun sea el caso del ingreso. Se utilizo la fgets que devuelve la cadena de caracteres completa y la copia en una variable. Para separar usamos el strtok que separa segun un delimitador. Devuelve a la funcion main los valores separados mediante arreglo de punteros.

    AUTHOR: Francisco Andrade
*/

#include <stdio.h>
#include <string.h>

void separar(char*,char**);
int verificar_dato(char *, char *, int);

int main (void){
    char *cadena_separada[4];
    const int TAM = 40;
    char entrada[TAM];
    fgets(entrada, TAM ,stdin);
    separar(entrada,cadena_separada);

}

// Separa la cadena en tres argumentos si hay doble comilla lo separa en dos
void separar(char *cadena,char **separada){
    int tam = strlen(cadena);
    char delimitador[20];
    // Segun la cantidad de comillas hacemos
    int cant_Comillas = verificar_dato(cadena,"\"",tam);
    if(cant_Comillas == 2)
        strcpy(delimitador, "\",\n");
    else
        strcpy(delimitador, " ,\n");
    
    //Definido el delimitador separamos
    char *token = strtok(cadena,delimitador);
    for(int i=0; token != NULL; i++){
        // Solo tomamos los primeros 3 argumentos el resto los obviamos
        if(i<3){
            *(separada+i) = token;   
            token = strtok(NULL,delimitador);
        }
    }

    //Recordar

    // Asignacion arreglo de punteros -> *(cadena_separada+1) = "hola";
    // Acceder a su contenido -> printf("%s",*(cadena_separada+1));
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
