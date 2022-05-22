
#include <stdio.h>

int main(int n){
    static int cuenta=1;
    cuenta++;
    return main(cuenta);
}