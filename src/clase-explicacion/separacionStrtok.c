#include <stdio.h>
#include <string.h>


int main(void){
    char cadena[] = {"Hola como estas"};
    char *token;
    char *token1;
    char *token2;

    token = strtok(cadena," "); 
    token1 = strtok(NULL," ");
    token2 = strtok(NULL," ");
    printf("%s %s %s\n",token,token1,token2);   
}