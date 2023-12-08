#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

typedef struct persona{
    char nombre[30];
    char apellido[30];
    char usuario[30];
    char pass[30];
    int edad;
} persona;


void inicializar(persona *p);
void valName(persona *p);
void validEdad(persona *p);
void validUser(persona *p);
void validPass(persona *p);
int mostrar_menu(char arreglo[][30], int tam);
void guardar_datos(persona *p);
int validUserPass(char *usuario, char *pass, persona *fUser);
void mis_datos(persona *p);


int main(void) {
    persona p;
    char arreglo[3][30] = {"1. Registrar", "2. Login","3.Salir"};
    char opciones[4][30] = {"1. Reservar película", "2. Mis reservaciones", "3. Mis datos", "4. Salir"};
    char login[30];
    char pass2[30];
    int n = 0;

    while (n < 1) {
        int opcion1 = mostrar_menu(arreglo, 3);
        if (opcion1 == 1) {
            inicializar(&p);
            valName(&p);
            validEdad(&p);
            validUser(&p);
            validPass(&p);

            guardar_datos(&p);

            
            
        } else if (opcion1 == 2) {
            printf("Ingrese su usuario: ");
            fgets(login, sizeof(login), stdin);
            login[strcspn(login, "\n")] = '\0';  

            printf("Ingrese su password: ");
            fgets(pass2, sizeof(pass2), stdin);
            pass2[strcspn(pass2, "\n")] = '\0';  
            persona fUser;
            int validacion = validUserPass(login, pass2, &fUser);
            if (validacion == 1) {
                printf("Login Correcto bienvenid@ %s %s, \n");
                while (n < 1) {
                    int opcion = mostrar_menu(opciones, 4);
                    switch (opcion) {
                    case 1: {
                        
                        
                        
                        
                        break;
                    }
                    case 2:
                        //reservaciones
                        break;
                    case 3:
                        mis_datos(&fUser);
                        break;
                    case 4:
                        
                        break;
                    default:
                        
                    }
                }
            } else {
                printf("Credenciales Incorrectas\n");
            }
        } else {
            return 1;
        }
    }
    return 0;
}

int mostrar_menu(char arreglo[][30], int tam) {
    int opcion = 0;
    for (int x = 0; x < tam; x++) {
        printf("\n%s", arreglo[x]);
    }
    while (opcion <= 0 || opcion > tam) {
        printf("\nSeleccione una opcion:");
        scanf("%d", &opcion);
        getchar();
    }
    return opcion;
}

void inicializar(persona *p) {
    p->apellido[0] = 0;
    p->nombre[0] = 0;
    p->usuario[0] = 0;
    p->pass[0] = 0;
    p->edad = 0;
}

void valName(persona *p) {
    while (1) {
        printf("Ingrese su nombre: ");
        fgets(p->nombre, sizeof(p->nombre), stdin);
        p->nombre[strcspn(p->nombre, "\n")] = '\0';  

        if (p->nombre[0] != '\0') {
            break;  
        }
        printf("Error al ingresar nombre\n");
    }

    while (1) {
        printf("Ingrese su apellido: ");
        fgets(p->apellido, sizeof(p->apellido), stdin);
        p->apellido[strcspn(p->apellido, "\n")] = '\0';  

        if (p->apellido[0] != '\0') {
            break;  
        }
        printf("Error al ingresar apellido.\n");
    }
}

void validEdad(persona *p) {
    while (p->edad < 12 || p->edad > 100) {
        printf("Ingrese su edad: ");
        scanf("%d", &p->edad);
        getchar();
        if (p->edad >= 12 && p->edad <= 100) {
            break;
        } else if (p->edad < 12 || p->edad > 100) {
            printf("Ingrese una edad (mayor a 12 y menor a 100): ");
            scanf("%d", &p->edad);
        }
    }
}

void validUser(persona *p) {
    while (p->usuario[0] == ' ' || p->usuario[0] == '\n' || p->usuario[0] == 0) {
        if (p->usuario[0] == 0) {
            printf("Ingrese su usuario: ");
            fgets(p->usuario, 30, stdin);
        } else if (p->usuario[0] == ' ' || p->usuario[0] == '\n') {
            printf("Ierror al seleccionar usuario\n");
            fgets(p->usuario, 30, stdin);
        }
    }
}

void validPass(persona *p) {
    int mayuscula = 0;
    int numero = 0;
    int especial = 0;
    int n = 0;
    while (mayuscula == 0 || numero == 0 || especial == 0) {
        while (strlen(p->pass) <= 8) {
            printf("Ingrese su contrasena: ");
            fgets(p->pass, 30, stdin);
            if (strlen(p->pass) < 8) {
                printf("Ingrese una contrasena con minimo 8 caracteres, un numero y uno especial\n");
            }
        }
        for (int i = 0; p->pass[i] != '\0'; i++) {
            if (isupper(p->pass[i])) {
                mayuscula = 1;
            } else if (isdigit(p->pass[i])) {
                numero = 1;
            } else if (ispunct(p->pass[i])) {
                especial = 1;
            }
        }
        if (mayuscula == 1 && numero == 1 && especial == 1) {
            n++;
        } else {
            printf("Ingrese un numero, una mayuscula o un caracter especial\n");
            printf("Ingrese su contrasena: ");
            fgets(p->pass, 30, stdin);
        }
    }
}

void guardar_datos(persona *p) {
    FILE *archivo = fopen("datos.txt", "a");   //append, "agregar"
    fprintf(archivo, "%s\n%s\n%s\n%d\n", p->usuario, p->nombre, p->apellido, p->edad);
    fclose(archivo);
    
}

int validUserPass(char *usuario, char *pass, persona *fUser) {
    FILE *archivo;
    char buffer[30];
    int enpassdo = 0;
    archivo = fopen("datos.txt", "r");
    if (archivo == NULL) {
        fprintf(stderr, "Error al abrir el archivo\n");
        return 0;
    }
    while (fgets(buffer, sizeof(buffer), archivo) != NULL) {
        buffer[strcspn(buffer, "\n")] = '\0';
        if (strcmp(buffer, usuario) == 0) {
            fgets(fUser->nombre, sizeof(fUser->nombre), archivo);
            fUser->nombre[strcspn(fUser->nombre, "\n")] = '\0';

            fgets(fUser->apellido, sizeof(fUser->apellido), archivo);
            fUser->apellido[strcspn(fUser->apellido, "\n")] = '\0';

            fgets(buffer, sizeof(buffer), archivo);
            fUser->edad = atoi(buffer);

            strcpy(fUser->usuario, usuario);
            strcpy(fUser->pass, pass);

            enpassdo = 1;
            break;
        }
    }
    fclose(archivo);
    return enpassdo;
}

void mis_datos(persona *p) {
    printf("Mis datos:\n");
    printf("Nombre: %s\n", p->nombre);
    printf("Apellido: %s\n", p->apellido);
    printf("Edad: %d\n", p->edad);
    printf("Usuario: %s\n", p->usuario);
    
}


