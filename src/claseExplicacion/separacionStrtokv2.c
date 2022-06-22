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
     printf("%s %s %s\n",token,token1,token2);   
}