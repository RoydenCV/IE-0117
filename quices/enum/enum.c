// Royden Contreras Vallejos 
// C12260
// Durante esta prueba corta se desarrollara un codigo para poner a prueba las
// funciones de enum.

// Agregamos librerias 
#include <stdio.h>


// Primeramente cramos el enum para los niveles de log
typedef enum { DEBUG, INFO, WARN, ERROR } LogNivel;

// Ahora debemos realizar la funcion para imprimir 
void logMensaje(LogNivel nivel, const char *mensaje) { 
    // vamos a usar el sistema switch en esta ocasión:
    switch (nivel) {
        case DEBUG:
            printf("[DEBUG] %s\n", mensaje);
            break;
        case INFO:
            printf("[INFO] %s\n", mensaje);
            break;
        case WARN:
            printf("[WARN] %s\n", mensaje);
            break;
        case ERROR:
            printf("[ERROR] %s\n", mensaje);
            break;
        default:
            printf("Estado desconocido\n");
    }
}

// Main para imprimir la informacion
int main() {
    logMensaje(DEBUG, "Variable x inicializada a 0");
    logMensaje(INFO, "Inicio del programa");
    logMensaje(WARN, "La conexion es inestable");
    logMensaje(ERROR, "Archivo no encontrado");

    return 0;
}