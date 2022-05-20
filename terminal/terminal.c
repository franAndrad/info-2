/*
--------------------------------------------------------------------
    Programa para separar una cadena con diferentes delimitadores
--------------------------------------------------------------------
    DESCRIPCION: Se realizo una separacion mediante comillas o con espacios segun sea el caso del ingreso. Se utilizo la fgets que devuelve la cadena de caracteres completa y la copia en una variable. Para separar usamos el strtok que separa segun un delimitador. Devuelve a la funcion main los valores separados mediante arreglo de punteros. Valores a ingresar:

    
    COMANDOS:

        version : Imprime la version de la terminal
        echo [arg]: Imprime lo igresado en arg, si se ingresa una cadena entre comillas imprime la cadena enter
        set[posicion][valor]: Asigna a una posicion de memoria un valor
        get[posicion]: Devuelve el valor en esa posicion de memoria
        reset: Pone en 0 toda la memoria           

    AUTHOR: Francisco Andrade
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Colores para la terminal
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_RESET   "\x1b[0m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RED     "\x1b[31m"

void separar(char*,char**,int);
int verificar_dato(char*,char*,int);
int verificacionReservadas(char**);
int gset(char**,int*,int);
int verificacionRango(int,int,int);

int main (void){

    //variables para almacenar la memoria
    int valor;
    int posicion;
    int memoria[40]={0};

    while(1){

        printf(ANSI_COLOR_MAGENTA);
        printf("\nterminal$ ");
        printf(ANSI_COLOR_RESET);

        // Variables para la entrada
        const int TAM = 40;
        char entrada[TAM];
        fgets(entrada, TAM ,stdin);

        //Copia para el echo
        char *cadena_echo[2];
        char entrada_echo[TAM];
        strcpy(entrada_echo,entrada);

        // Devuelva la cadena separada (0) en el arreglo de punteros 
        char *cadena_separada[3]={"0","0","0"};
        separar(entrada,cadena_separada,0);

        switch(verificacionReservadas(cadena_separada)){ //Esto me esta dando   problemas
 
            // Si el valor ingresado es incorrecto
            case -1:
                puts("\nEl comando no funciona\n");
            break;

            // Imprime la version
            case 0:
                puts("\nversion 0.0.1");
            break;

            // Funcion echo
            case 1:
                separar(entrada_echo,cadena_echo,1);
                puts(*(cadena_echo+1));
            break;

            // Funcion set
            case 2:
                posicion = atoi(*(cadena_separada+1));
                valor = atoi(*(cadena_separada+2));
                //Si validamos guarda sino imprime error
                if (verificacionRango(posicion,0,64) == 1 && verificacionRango(valor,0,64) == 1){
                    memoria[posicion]=valor;
                    puts("\nAsigando");
                }
                else
                    printf("\nComando no funciona: set [posicion] [valor]\n\n\t [posicion]: de 0 a 64\n[valor]: de 0 a 64\n");
            break;

            // Funcion get
            case 3:
                posicion = atoi(*(cadena_separada+1));
                if (verificacionRango(posicion,0,64) == 1)
                    printf("\nvar[%d] : %d\n", posicion, memoria[posicion]);
                else
                    printf("\nComando no funciona: get [posicion] \n\n\t [posicion]: de 0 a 64\n");
            break;

            //Funcion todo a 0
            case 4:
                for(int i=0; i<TAM ;i++){
                    memoria[i]=0;
                }
                puts("okey\n");
            
        }
    }
}

//Funcion que devuelve la posicion de la palabra reservada
int verificacionReservadas(char **separada){
    char *reservadas[]={"version","echo","set","get","reset"};
    for(int i=0;i<5;i++){
        if(strcmp(*(separada+0),*(reservadas+i)) == 0){
            return i;
        }
    }
    return -1;
}

// Separa la cadena en tres argumentos si hay doble comilla lo separa en dos
void separar(char *cadena,char **separada,int opcion){

    //Esta variable controla la cantidad de veces que va a recorrer el arreglo 
    int cant = 0;  

    int tam = strlen(cadena);
    char delimitador[20];

    //Si la opcion es 1 separa con comillas o espacio el segundo argumento
    if(opcion==1){
        int cant_Comillas = verificar_dato(cadena,"\"",tam);
        if(cant_Comillas == 2 )
            strcpy(delimitador, "\",\n");
        else
            strcpy(delimitador, " ,\n");
        cant=2;
    }
    //Si la opcion es 0 separa con espacios todos los argumentos, entra a esta por defecto
    else{
        strcpy(delimitador, " ,\n");
        cant=3;
    }
    
    //Definido el delimitador separamos
    char *token = strtok(cadena,delimitador);
    for(int i=0; token != NULL; i++){
        // Solo tomamos los primeros 3 argumentos el resto los obviamos
        if(i<cant){
            *(separada+i) = token;   
            token = strtok(NULL,delimitador);
        }
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

// Funcion que verifica si el valor esta en cierto rango 
int verificacionRango(int a1, int rangMin, int rangMax){
    // Hacemos una verificacion y asignamos el valor a la memoria
    if (a1>= rangMin && a1<=rangMax)
        return 1;
    else
        return 0;
}