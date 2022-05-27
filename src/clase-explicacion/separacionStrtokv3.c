#include <stdio.h>
#include <string.h>


int main(void){
    char cadena[40];
    fgets(cadena,40,stdin);

    char *token;
    char *token1;
    char *token2;

    token = strtok(cadena," ,\n"); 
    token1 = strtok(NULL," \n");
    token2 = strtok(NULL," ,\n");

    if(strcmp(token,"version")==0){
        puts("La version es 0.0.1");   
    }
    
    if(strcmp(token,"echo")==0){
        puts(token2);
    }
}