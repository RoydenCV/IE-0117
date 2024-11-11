// Royden Contreras Vallejos 
// C12260
// Duarante este laboratorio se realizara un programa el cual al iniciarse 
// consulte al usuario cuantas personas desea registrar, de esta manera se 
// logra que el programa pueda reservar la memoria, una vez hecho esto se
// ingresara a un menu donde se podra elegir entre, agregar una nueva persona,
// buscar una persona en especifico y desplegar a todas la persona registradas.
// A continuacion se resarrollara el codigo que cumpla con estas condiciones.


// Primeramente agregamos la librerias. 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


// Definimos la variable para el numero de personas
int npersonas = 0;


// Vamos a definir cuantas personas van a estar en el arreglo, para ello se le
// debera preguntar al usuario por caracteristicas de la persona, entonces:
// Definimos la estructura para almacenar los datos
typedef struct {
    char nombre[20];
    char apellidos[50];
    int telefono;
    char carnet[10];
    char enfasis[30];
} datos_persona;


// Función para ingresar los datos de una persona
void setDatos(datos_persona *persona) {
    // Limpiar el buffer de entrada para evitar problemas con fgets después 
    // de scanf
    getchar(); 

    // Ingresar nombre
    printf("Ingrese el nombre: ");
    fgets(persona->nombre, sizeof(persona->nombre), stdin);
    persona->nombre[strcspn(persona->nombre, "\n")] = '\0';  
    if (strlen(persona->nombre) > 20) { 
        printf("El nombre no puede tener más de 20 caracteres\n");
        exit(1);
    }

    // Ingresar apellidos
    printf("Ingrese los apellidos: ");
    fgets(persona->apellidos, sizeof(persona->apellidos), stdin);
    persona->apellidos[strcspn(persona->apellidos, "\n")] = '\0';  
    if (strlen(persona->apellidos) > 50) {
        printf("Los apellidos no pueden tener más de 50 caracteres\n");
        exit(1);
    }

    // Ingresar teléfono
    int telefono_valido = 0;
    while (!telefono_valido) {
        printf("Ingrese el telefono (8 dígitos): ");
        char telefono_str[10];
        fgets(telefono_str, sizeof(telefono_str), stdin);
        if (sscanf(telefono_str, "%d", &persona->telefono) != 1 || persona->telefono < 10000000 || persona->telefono > 99999999) {
            printf("El telefono debe tener 8 dígitos. Intente nuevamente.\n");
        } else {
            telefono_valido = 1;  
        }
    }

    // Ingresar carnet
    printf("Ingrese el carnet: ");
    fgets(persona->carnet, sizeof(persona->carnet), stdin);
    persona->carnet[strcspn(persona->carnet, "\n")] = '\0';  
    if (strlen(persona->carnet) > 10) {
        printf("El carnet no puede tener más de 10 caracteres\n");
        exit(1);
    }

    // Ingresar énfasis
    printf("Ingrese el enfasis: ");
    fgets(persona->enfasis, sizeof(persona->enfasis), stdin);
    persona->enfasis[strcspn(persona->enfasis, "\n")] = '\0';  
}


// Función para imprimir los datos de una persona
void print_struct(datos_persona *persona) {
    printf("\n");
    printf("Nombre: %s\n", persona->nombre);
    printf("Apellidos: %s\n", persona->apellidos);
    printf("Telefono: %d\n", persona->telefono);
    printf("Carnet: %s\n", persona->carnet);
    printf("Enfasis: %s\n", persona->enfasis);
}


// Función para buscar una persona por su carnet
int buscarPersona(datos_persona *personas, int npersonas, const char *carnet) {
    for (int i = 0; i < npersonas; i++) {
        if (strcmp(personas[i].carnet, carnet) == 0) {
            return i;  
        }
    }
    return -1;  
}


// En esta seccion se va a construir el codigo encargado del menu de opciones,
// para ello:
int main(int argc, char const *argv[]) {
    // Variable encargada de contener la desicion del usuario
    int opcion;

    // Pedir al usuario cuántas personas quiere registrar
    printf("Ingrese el numero de personas que desea registrar: ");
    scanf("%d", &npersonas);

    // Asignar memoria para la cantidad indicada
    datos_persona *personas = malloc(npersonas * sizeof(datos_persona));
    if (personas == NULL) {
        printf("Error al asignar memoria\n");
        return 1;
    }


    // Contador de personas registradas
    int personasRegistradas = 0;  


    // Mensajes del menu de opciones 
    do {
        printf("\nMenú:\n");
        printf("1. Agregar persona\n");
        printf("2. Buscar persona\n");
        printf("3. Imprimir todas las personas\n");
        printf("4. Salir\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);


        // Parte encargada del menu de opciones, aqui se gestiona que pasara si
        // el usuario presiona uno u otro numero.
        switch(opcion) {
            case 1: {
                // Verificar si aún hay espacio para más personas
                if (personasRegistradas < npersonas) {
                    printf("Ingrese los datos de la persona %d\n", personasRegistradas + 1);
                    setDatos(&personas[personasRegistradas]);
                    // Variable encargada de incrementar el numero de personas 
                    // registradas
                    personasRegistradas++; 
                } else {
                    printf("Ya no hay espacio para más personas.\n");
                }
                break;
            }
            case 2: {
                // Buscar persona
                // Limpiar el buffer de entrada
                getchar();  
                char carnetBusqueda[10];
                printf("Ingrese el carnet a buscar: ");
                fgets(carnetBusqueda, sizeof(carnetBusqueda), stdin);
                carnetBusqueda[strcspn(carnetBusqueda, "\n")] = '\0';  

                int index = buscarPersona(personas, personasRegistradas, carnetBusqueda);
                if (index != -1) {
                    printf("Persona encontrada:\n");
                    print_struct(&personas[index]);
                } else {
                    printf("Persona no encontrada.\n");
                }
                break;
            }
            case 3: {
                // Imprimir todas las personas
                if (personasRegistradas == 0) {
                    printf("No hay personas registradas.\n");
                } else {
                    printf("Listado de personas registradas:\n");
                    for (int i = 0; i < personasRegistradas; i++) {
                        printf("Persona %d:\n", i + 1);
                        print_struct(&personas[i]);
                    }
                }
                break;
            }
            case 4: {
                // Salir
                printf("Saliendo del programa...\n");
                // para salir de manera adecuada debemos liberar la memoria, para
                // ello:
                free(personas); 
                break;
            }
            default: {
                printf("Opción no válida. Por favor seleccione una opción entre 1 y 4.\n");
                break;
            }
        }
    // Continuar el menú hasta que el usuario elija salir
    } while (opcion != 4);

    return 0;
}