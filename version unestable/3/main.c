
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



typedef struct persona{
    char name[10];
    char apellido[10];
    char edad[3];
    char username[15];
    char password[15];

} persona;

typedef struct arreglo_personas{
    persona *personas;
    int numero_personas;
} arreglo_personas;




void clean(char *str, int tam);
int login(persona *p);
int registrarUsuario(persona *p);
int imprimirMenu(char arreglo[][30], int tam); 	
int nameValid(char *nameV);
int apellidoValid(char *apellidoV);
int edadValid(char *edadV);
int passwordValid(char *passwordV);
void capturarDatos(arreglo_personas arreglo_users);
void inicializar(persona *p);
int validUserPass(char *usuario, char *pass, persona *fUser);


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




void inicializar(persona *p) {
    p->apellido[0] = 0;
    p->name[0] = 0;
    p->username[0] = 0;
    p->password[0] = 0;
    p->edad[0] = 0;
}

void clean(char *str, int tam) { // Entran valores tipo string de Persona y salen ya "limpios" con direccion de memoria '\0' 
    for (int i = 0; i < tam; i++) {
        str[i] = '\0';
    }
}

int login(persona *p) {
    char username[15];
    char password[15];
	arreglo_personas arreglo_users;

	      printf("\n\n\t\tLogin\n");
	      
            printf("Ingrese su Username: \n");
            fgets(username, sizeof(username), stdin);
            username[strcspn(username, "\n")] = '\0';
            printf("\n\n");
            printf("Ingrese su Password: \n");
            fgets(password, sizeof(password), stdin);
            password[strcspn(password, "\n")] = '\0';
            printf("\n\n");
            //abrir archivo
            FILE *archivo = fopen("usuarios.txt", "r");
            if(archivo==NULL){
                printf("\nEl archivo no se abrio correctamente \n");
            }
            printf("\nEl archivo se abrio correctamente! \n");

	   int i;
       int n=0;
    char *arreglo_datos[15];

    for(i=0;i<15;i++){
        fscanf(archivo,"%s",arreglo_datos[i]);
    }


    arreglo_users.personas=NULL;
    arreglo_users.numero_personas=0;
    persona *aux=NULL;
    
    for(i=0;i<15;i++){
        if(arreglo_users.personas==NULL && i%5==0){

            n++;
            arreglo_users.personas=malloc(sizeof(persona)*n);
            arreglo_users.personas[n-1].username, arreglo_datos[i];
           
        }
        else if(i%5==0){//AGREGAR MAS USUARIOS
            n++;
            aux=NULL;
            while(aux==NULL){
                aux=realloc(arreglo_users.personas,sizeof(persona)*n);
            }
            arreglo_users.personas=aux;
            strcpy(arreglo_users.personas[n-1].username, arreglo_datos[i]);
            
        }
        else if(i%5==1){//name
            strcpy(arreglo_users.personas[n-1].name, arreglo_datos[i]);
            
        }
        else if(i%5==2){//apellido
            strcpy(arreglo_users.personas[n-1].apellido, arreglo_datos[i]);
            
        }
        else if(i%5==3){//edad
            strcpy(arreglo_users.personas[n-1].edad,arreglo_datos[i]);
            
        }
        else if(i%5==4){//password
            strcpy(arreglo_users.personas[n-1].password, arreglo_datos[i]);
            
        }
    
    }
    arreglo_users.numero_personas=n;
    
    for(i=0;i<arreglo_users.numero_personas;i++){
        if(strcmp(arreglo_users.personas[i].username,username)==0){
            if(strcmp(arreglo_users.personas[i].password,password)==0){
                printf("\n\n\n\r Usuario y Password Correctos! \n");
                printf("\n\n\n\r ");
                printf("\n\n\n\r ");
                printf("\n\n\n\r ");
}
        }
    }
}
    
    
    
    






    



int registrarUsuario(persona *p) {// se ingresan todos los dtos necesarios y se guardan en el struct persona
	clean(p->password, 15);
    clean(p->username, 15);
    clean(p->name, 10);
    clean(p->apellido, 10);
    clean(p->edad, 3);

    
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
    fprintf(archivo, "%s %s %s %s %s\n", p->username,p->name,p->apellido,p->edad,p->password);
    fclose(archivo);
    printf("Usuario creado con Exito! \n\n");

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
            printf("Nombre Valido! \n");
            return 0;
        }
    }
    printf("Nombre Invalido! \n");
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
        printf("passsena Valida! \n");
        passValid = 0;
    } else {
        printf("passsena Invalida! \n");
        passValid = 1;
    }

    return passValid;
}

