#include<stdio.h>
#include "header.h"
#include <string.h>



void clean(char *str, int tam) { // Entran valores tipo string de Persona y salen ya "limpios" con direccion de memoria '\0' 
    for (int i = 0; i < tam; i++) {
        str[i] = '\0';
    }
}

int login(persona *p) {// se ingresan username y password y se validan con los mismos de persona y se retorna si ingreso o no
    char username[15] = {0};
    char password[15] = {0};
	char usuarioPass[100];
	
	      printf("\n\n\t\tLogin\n");
	      
	   FILE *archivo = fopen("usuarios.txt", "r");
	  
	     if(archivo==NULL){
	     	   printf("\nEl archivo no se abrio correctamente \n");
		 }
		       printf("\nEl archivo se abrio correctamente! \n");
		       
    
    printf("\nUsername: ");
    scanf("%s", username);

    printf("Password: ");
    scanf("%s", password);

	  
      while(fgets(usuarioPass,sizeof(usuarioPass),archivo) != NULL){ // cuando no se usa fgets (fscanf) se usa "EOL" END OF LINE, al usar EOL en fgets daba error. 
	               char usernameTXT[15];
	               char passwordTXT[15];
	                char nameTXT[15];
	                char lastTXT[15];
	               
	                 sscanf(usuarioPass, "%s %s %s %s", usernameTXT, passwordTXT,nameTXT,lastTXT);
	 
	 
	 
	 
    	if (strcmp(username, usernameTXT) == 0 && strcmp(password,passwordTXT) == 0) {
        printf("Has iniciado sesion correctamente\n Bienvenido %s %s",nameTXT,lastTXT);
        fclose(archivo);
        return 0;
    } 
    
    
    
    
}
	printf("El usuario ingresado o passsena no existe");
	   fclose(archivo);
	      return 1;



}

    



int registrarUsuario(persona *p) {// se ingresan todos los dtos necesarios y se guardan en el struct persona
	clean(p->password, 15);
    clean(p->username, 15);
    
    
    printf("\n\n\t\tRegistrar Cuenta\n\n");

    printf("Ingrese su Nombre: \n");
    scanf("%s", p->name);

    while (nameValid(p->name) == 1) {
        printf("\n\nIntente de nuevo: \n");
        scanf("%s", p->name);
    }

    printf("\n\n");

    printf("Ingrese su Apellido: \n");
    scanf("%s", p->apellido);

    while (apellidoValid(p->apellido) == 1) {
        printf("\n\nIntente de nuevo: \n");
        scanf("%s", p->apellido);
    }

    printf("\n\n");

    printf("Ingrese su edad: \n");
    scanf("%d", &(p->edad));

    while (edadValid(p->edad) == 1) {
        printf("\n\nIntente de nuevo: \n");
        scanf("%d", &(p->edad));
    }

    printf("\n\n");

    printf("Ingrese su Username: \n");
    scanf("%s", p->username);

    printf("\n\n");

    printf("Cree una passsena (Minimo 8 caracteres, un caracter especial y una mayuscula)\n");
    scanf("%s", p->password);

    while (passwordValid(p->password) == 1) {
        printf("\n\nIntente de nuevo: \n");
scanf("%s", p->password);
    }
    
    FILE *archivo = fopen("usuarios.txt", "a");   //append, "agregar"
    fprintf(archivo, "%s %s %s %s\n", p->username,p->password,p->name,p->apellido);
    fclose(archivo);
    printf("Usuario creado con Exito! \n\n");

    printf("\n\n");

    return 0;
}

int imprimirMenu(char arreglo[][30], int tam) {// se despliega el menu
    int opcion = 0;
    for (int x = 0; x < tam; x++) {
        printf("\n%s", arreglo[x]);
    }
    while (opcion <= 0 || opcion > tam) {
        printf("\nIngrese la opcion:");
        scanf("%d", &opcion);
    }
    printf("Opcion Seleccionada: %d\n", opcion);
    return opcion;
}

int nameValid(char *nameV) { // se valida si el nombre ingresado no contenga algun caracter especial
    for (int i = 0; nameV[i] != '\0'; i++) {
        if (((nameV[i] >= 'a' && nameV[i] <= 'z') || (nameV[i] >= 'A' && nameV[i] <= 'Z'))) {
            printf("Nombre Valido! \n");
            return 0;
        }
    }
    printf("Nombre Invalido! \n");
    return 1;
}

int apellidoValid(char *apellidoV) { // se valida si el apellido no contiene ningun caracter especial
    for (int i = 0; apellidoV[i] != '\0'; i++) {
        if (((apellidoV[i] >= 'a' && apellidoV[i] <= 'z') || (apellidoV[i] >= 'A' && apellidoV[i] <= 'Z'))) {
            printf("Apellido Valido! \n");
            return 0;
        }
    }
    printf("Apellido Invalido! \n");
    return 1;
}

int edadValid(int edadV){ // el input es la edad que esta almacenada en el struct, y se valida si esta en el rango de 12-99  (investigar sobre atoi,isdigit)

    if (edadV <= 99 && edadV >= 12) {
        printf("Edad Valida \n");
        return 0;
    } else {
        printf("Edad Invalida \n");
        return 1;
    }
}


int passwordValid(char *passwordV) {// con la password almacenada en struct, se valida las caracteristicas anteriormente escritas
    int length = strlen(passwordV);
    int lengthV;
    int specialV = 0;
    int valid = 0;
    int passValid;
    int numero = 0;

    if (length >= 8) {
        lengthV = 1;
    } else {
        lengthV = 0;
    }

    for (int i = 0; passwordV[i] != '\0'; i++) {
        if (passwordV[i] >= 'A' && passwordV[i] <= 'Z') {
            valid = 1;
        }

        if ((passwordV[i] >= 33 && passwordV[i] <= 47) || (passwordV[i] >= 58 && passwordV[i] <= 64)) {
            specialV = 1;
        }

        if (passwordV[i] >= '0' && passwordV[i] <= '9') {
            numero = 1;
        }
    }

    if ((valid == 1) && (lengthV == 1) && (specialV == 1) && (numero == 1)) {
        printf("passsena Valida! \n");
        passValid = 0;
    } else {
        printf("passsena Invalida! \n");
        passValid = 1;
    }

    return passValid;
}