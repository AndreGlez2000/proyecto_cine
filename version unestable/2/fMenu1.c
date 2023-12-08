#include<stdio.h>
#include "header.h"
#include <string.h>



void clean(char *str, int tam) { 
    for (int i = 0; i < tam; i++) {
        str[i] = '\0';
    }
}

int login(persona *p) {
    char password[15] = {0};
    char username[15] = {0};
    char *userPass;
	persona *aux=NULL;
    int n=0;
    int i=0;
	
	      printf("\n\n\t\tLogin\n");
	      
	   FILE *archivo = fopen("users.txt", "r");
	  
	     if(archivo==NULL){
	     	   printf("\nEl archivo no se abrio correctamente \n");
		 }
		       printf("\nEl archivo se abrio correctamente! \n");
		       
    
    printf("\nUsername: ");
    scanf("%s", username);

    printf("Password: ");
    scanf("%s", password);

	  
      while(fgets(userPass,sizeof(userPass),archivo) != NULL){ // cuando no se usa fgets (fscanf) se usa "EOL" END OF LINE, al usar EOL en fgets daba error. 
	               char usernameTXT[15];
	               char passwordTXT[15];
	                char nameTXT[15];
	                char lastTXT[15];
                    int ageTXT;
	               
	                 sscanf(userPass, "%s %s %d %s %s", nameTXT, lastTXT ,&ageTXT,usernameTXT,passwordTXT);
	 
        printf("%s %s %d %s %s", nameTXT, lastTXT ,ageTXT,usernameTXT,passwordTXT);
	 
	 
	 
    	if (strcmp(username, usernameTXT) == 0 && strcmp(password,passwordTXT) == 0) {
        printf("Has iniciado sesion correctamente\n Bienvenido %s %s",nameTXT,lastTXT);
        fclose(archivo);
        return 0;
    } 
    
    
    
    
}
	printf("El user ingresado o passwordsena no existe");
	   fclose(archivo);
	      return 1;



}

    



int registraruser(persona *p) {// se ingresan todos los dtos necesarios y se guardan en el struct persona
	int n=0;
    int i=0;
   
    

    FILE *archivo = fopen("users.txt", "a");
    if(archivo==NULL){
         	   printf("\nEl archivo no se abrio correctamente \n");
    }
    printf("\nEl archivo se abrio correctamente! \n");
    
    printf("\n\n\t\tRegistrar Cuenta\n\n");

    printf("Ingrese su name: \n");
    scanf("%s", p->name);
   

    while (nameValid(p->name) == 1) {
        printf("\n\nIntente de nuevo: \n");
        scanf("%s", p->name);
    }
    
    fprintf(archivo,"%s ",p->name);

    printf("\n\n");

    printf("Ingrese su Apellido: \n");
    scanf("%s", p->apellido);

    while (apellidoValid(p->apellido) == 1) {
        printf("\n\nIntente de nuevo: \n");
        scanf("%s", p->apellido);
    }
    
    fprintf(archivo,"%s ",p->apellido);

    printf("\n\n");

    printf("Ingrese su edad: \n");
    scanf("%d", &(p->edad));

    while (edadValid(p->edad) == 1) {
        printf("\n\nIntente de nuevo: \n");
        scanf("%d", &(p->edad));
    }
    
    fprintf(archivo,"%d ",p->edad);

    printf("\n\n");

    printf("Ingrese su Username: \n");
    scanf("%s", p->username);

    fprintf(archivo,"%s ",p->username);

    printf("\n\n");

    printf("Cree una passwordsena (Minimo 8 caracteres, un caracter especial y una mayuscula)\n");
    scanf("%s", p->password);

    while (passwordValid(p->password) == 1) {
        printf("\n\nIntente de nuevo: \n");
    scanf("%s", p->password);
    }
    
    fprintf(archivo,"%s\n",p->password);

   
   
    fclose(archivo);

    printf("\n\n");

    return 0;
}

int imprimirMenu(char arreglo[][30], int tam) {
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

int nameValid(char *nameV) { 
    for (int i = 0; nameV[i] != '\0'; i++) {
        if (((nameV[i] >= 'a' && nameV[i] <= 'z') || (nameV[i] >= 'A' && nameV[i] <= 'Z'))) {
            printf("name Valido! \n");
            return 0;
        }
    }
    printf("name Invalido! \n");
    return 1;
}

int apellidoValid(char *apellidoV) { 
    for (int i = 0; apellidoV[i] != '\0'; i++) {
        if (((apellidoV[i] >= 'a' && apellidoV[i] <= 'z') || (apellidoV[i] >= 'A' && apellidoV[i] <= 'Z'))) {
            printf("Apellido Valido! \n");
            return 0;
        }
    }
    printf("Apellido Invalido! \n");
    return 1;
}

int edadValid(int edadV){ 

    if (edadV <= 99 && edadV >= 12) {
        printf("Edad Valida \n");
        return 0;
    } else {
        printf("Edad Invalida \n");
        return 1;
    }
}


int passwordValid(char *passwordV) {
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
        printf("passwordsena Valida! \n");
        passValid = 0;
    } else {
        printf("passwordsena Invalida! \n");
        passValid = 1;
    }

    return passValid;
}