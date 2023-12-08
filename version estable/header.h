typedef struct{
    char name[10];
    char apellido[10];
    int edad;
    char username[15];
    char password[15];

} persona;



void clean(char *str, int tam);
int login(persona *p);
int registrarUsuario(persona *p);
int imprimirMenu(char arreglo[][30], int tam); 	
int nameValid(char *nameV);
int apellidoValid(char *apellidoV);
int edadValid(int edadV);
int passwordValid(char *passwordV);