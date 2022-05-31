#include <stdio.h>
#include <string.h>

int main(void){
    char cadena[40];
    char copia[40];

    fgets(cadena,40,stdin);

    strcpy(copia,cadena);

    char *token;
    char *token1;
    char *token2;

    int almacenar[64];

    token = strtok(cadena," ,\n"); 
    token1 = strtok(NULL," \n");
    token2 = strtok(NULL," ,\n");

    if(strcmp(token,"version")==0){
        puts("La version es 0.0.1");   
    } 
    if(strcmp(token,"echo")==0){
        int cont=0;
        for(int i=0;copia[i] != '\0';i++){
            if(copia[i]=='\"')
                cont++;
        }
        if(cont==2){
            char *tokenEcho;
            char *tokenEcho1;
            tokenEcho = strtok(copia,"\",\n"); 
            tokenEcho1 = strtok(NULL,"\",\n"); 
            puts(tokenEcho1);
        }else{
            puts(token1);
        }
    }
    int pos = atoi(token1);
}