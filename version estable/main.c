#include <stdio.h>
#include <string.h>
#include "header.h"


	
int main() {
	
	
	
    char arreglo[3][30] = {"\n\n1. Login", "2. Registrar Usuario", "3. Exit\n"};
    int opcion = 0;
	persona p;
	
    while (opcion != 3) {
        opcion = imprimirMenu(arreglo, 3);
        if (opcion == 1) {
            login(&p);
        } else if (opcion == 2) {
            registrarUsuario(&p);
        }
    }

    return 0;
}