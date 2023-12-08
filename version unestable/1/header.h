#include<stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 10

typedef struct persona{
    char name[10];
    char apellido[10];
    int edad;
    char username[15];
    char password[15];

}persona;

typedef struct aPersona{
    persona *usuarios;
    int numUsuarios;
}aPersona;


void leerArchivo(aPersona *aP);
void clean(char *str, int tam);
int login(persona *p);
int registrarUsuario(persona *p);
int imprimirMenu(char arreglo[][30], int tam);
int nameValid(char *nameV);
int apellidoValid(char *apellidoV);
int edadValid(int edadV);
int passwordValid(char *passwordV);
int usernameValid(const char* username);




void leerArchivo(aPersona *aP){
    FILE *archivo = fopen("usuarios.txt", "r");
    if(archivo==NULL){
        printf("\nEl archivo no se abrio correctamente \n");
        return;
    }
    printf("\nEl archivo se abrio correctamente! \n");
    
    int numUsuarios = 0;
    char c;
    
    while((c = fgetc(archivo)) != EOF){
        if(c == '\n'){
            numUsuarios++;
        }
    }
    
    if(numUsuarios > aP->numUsuarios){
        aP->usuarios = (persona *)realloc(aP->usuarios, sizeof(persona)*numUsuarios);
    }
    
    rewind(archivo);
    for(int i = aP->numUsuarios; i < numUsuarios; i++){
        fscanf(archivo, "%s %s %d %s %s", aP->usuarios[i].name, aP->usuarios[i].apellido, &(aP->usuarios[i].edad), aP->usuarios[i].username, aP->usuarios[i].password);
    }
    
    aP->numUsuarios = numUsuarios;
    
    
    for(int i = 0; i < aP->numUsuarios; i++){
        printf("%s %s %d %s %s\n", aP->usuarios[i].name, aP->usuarios[i].apellido, aP->usuarios[i].edad, aP->usuarios[i].username, aP->usuarios[i].password);
    }
    fclose(archivo);
    
}
    
void clean(char *str, int tam) { 
    for (int i = 0; i < tam; i++) {
        str[i] = '\0';
    }
}

int login(persona *p) {
    
    char username[15];
    char password[15];
    char c;
   
    FILE *archivo = fopen("usuarios.txt", "r");
    if(archivo==NULL){
        printf("\nEl archivo no se abrio correctamente \n");
        return 0;
    }
    printf("\nEl archivo se abrio correctamente! \n");
    
    printf("\n\n\t\tLogin\n\n");
    printf("Ingrese su Username: \n");
    scanf("%s", username);
    printf("Ingrese su passsena: \n");
    scanf("%s", password);
    
    

    while ((c = fgetc(archivo)) != EOF) {
        if (c == ' ') {
            if (strcmp(username, p->username) == 0) {
                printf("Username Valido! \n");
                if (strcmp(password, p->password) == 0) {
                    printf("Password Valido! \n");
                    return 1;
                }
            }
        }
    }
    //si es valido te conecta a otro menu
    //si no, te regresa al menu principal
    fclose(archivo);
    return 0;
    
    
    
}

int registrarUsuario(persona *p) {
    
    char name[10];
    char apellido[10];
    int edad;
    char username[15];
    char password[15];
    char c;
    int flag = 0; //flag para saber si se esta leyendo el username
    int flag2 = 0;//flag para saber si se esta leyendo el password
    int flag3 = 0;
    int flag4 = 0;
    int flag5 = 0;
    int i = 0;
    int n = 0;
    
    FILE *archivo = fopen("usuarios.txt", "a");// se abre el archivo "usuarios.txt" en modo append
    if(archivo==NULL){
        printf("\nEl archivo no se abrio correctamente \n");
        return 0;
    }
    printf("\nEl archivo se abrio correctamente! \n");
    
    printf("\n\n\t\tRegistro de Usuario\n\n");
   
    printf("Ingrese su Nombre: \n");
    scanf("%s", name);
    while (nameValid(name) == 1) {
        printf("Ingrese su Nombre: \n");
        scanf("%s", name);
    }
   
    printf("Ingrese su Apellido: \n");
    scanf("%s", apellido);
    while (apellidoValid(apellido) == 1) {
        printf("Ingrese su Apellido: \n");
        scanf("%s", apellido);
    }
    
    printf("Ingrese su Edad: \n");
    scanf("%d", &edad);
    while (edadValid(edad) == 1) {
        printf("Ingrese su Edad: \n");
        scanf("%d", &edad);
    }
    
    printf("Ingrese su Username: \n");
    scanf("%s", username);
   
    

    
    printf("Ingrese su passsena: \n");
    scanf("%s", password);
    while (passwordValid(password) == 1) {
        printf("Ingrese su passsena: \n");
        scanf("%s", password);
    }
    
    fprintf(archivo, "%s %s %d %s %s\n", name, apellido, edad, username, password);
    
    strcpy(p->name, name);
    strcpy(p->apellido, apellido);
    p->edad = edad;
    strcpy(p->username, username);
    strcpy(p->password, password);
    fclose(archivo);
    return 1;
}

int imprimirMenu(char arreglo[][30], int tam) {
    int opcion = 0;
    for (int i = 0; i < tam; i++) {
        printf("\n%s", arreglo[i]);
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

int edadValid(int edadV){ 

    if(edadV>=12 && edadV<=99){
        printf("Edad Valida! \n");
        return 0;
    }
    printf("Edad Invalida! \n");
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
