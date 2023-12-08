#include <stdio.h>
#include "header.h"

int main(){
     char menu[3][30] = {"1.- Login", "2.- Registro", "3.- Salir"};
    int opcion=0;
    persona p; // Declarar la inicializar p de tipo persona

    do{
        opcion = imprimirMenu(menu,3);//imprimirMenu(menu,3);
        switch(opcion){
            case 1:
                login(&p);
                break;
            case 2:
                registrarUsuario(&p);
                break;
            case 3:
                printf("Saliendo del programa...\n");
                break;
            default:
                printf("Opcion no valida\n");
                break;
        }
    } while(opcion != 3);

    return 0;
}