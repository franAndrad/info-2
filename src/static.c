/*
--------------------------------------------------------------------
    Programa de prueba de variable static
--------------------------------------------------------------------
    DESCRIPCION: Se realizo la primera prueba de como funciona la variable static.

    AUTHOR: Francisco Andrade
*/

#include <stdio.h>

void func() {
	static int x = 0; // x es inicializada solo una vez durante las tres llamadas a func()
	printf("%d\n", x); // muestra el valor de x
	x = x + 1;
}

int main(int argc, char * const argv[]) {
	func(); // muestra 0
	func(); // muestra 1
	func(); // muestra 2
	return 0;
}