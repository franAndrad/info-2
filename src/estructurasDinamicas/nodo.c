#include <stdio.h>
#include <string.h>

struct nodo{
    char color[10];
    struct nodo *ptr; //Esto es por que contiene la direccion del dato que guardo
};

//Funcion para crear un nodo nuevo

struct nodo * CrearNodo(char *dato){
    struct nodo * pnodo = (struct nodo *) malloc(sizeof(struct nodo);
            if(pnodo != NULL){
                strcpy(pnodo->color,dato);
                pnodo ->ptr = NULL;
            }
            return pnodo;
}

int main(void){
    
}
