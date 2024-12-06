// Royden Contreras Vallejos
// C12260
// Esto es el segundo examen parcial de Porgramacion Bajo Plataformas Abiertas el
// cual consiste en definir una serie de variables para que el programa funcione 
// correctamente como nos indican en las intrucciones. 


#include "inventario.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Implementación de funciones

// Crear el inventario (deben usar malloc para la memoria dinámica)
inventario_t* crearInventario() {
    // Reservar memoria para la estructura inventario_t
    inventario_t* inventario = (inventario_t*)malloc(sizeof(inventario_t));
    if (inventario == NULL) {
        // Si no se puede asignar memoria, devolver NULL
        return NULL;  
    }

    // Reservar memoria para el array dinámico de productos (10 productos iniciales)
    inventario->productos = (producto_t*)malloc(10 * sizeof(producto_t));
    if (inventario->productos == NULL) {
        // Liberar la memoria reservada para el inventario
        free(inventario);  
        // Si no se puede asignar memoria para los productos, devolver NULL
        return NULL;  
    }

    // Inicializar los valores del inventario
    // Capacidad inicial de 10 productos
    inventario->tamano = 10;   
    // No hay productos al principio
    inventario->ocupado = 0;   

    // Devolver el puntero al inventario creado
    return inventario;  
}




// Agregar un producto al inventario (usar realloc si se llena la capacidad)
void agregarProducto(inventario_t* inventario, const char* nombre, int cantidad, float precio) {
    // Verificar si el inventario está lleno
    if (inventario->ocupado == inventario->tamano) {
        // Duplicar el tamaño del inventario
        int nuevaCapacidad = inventario->tamano * 2;
        producto_t* productosReasignados = (producto_t*)realloc(inventario->productos, nuevaCapacidad * sizeof(producto_t));
        
        // Verificar si realloc falló
        if (productosReasignados == NULL) {
            printf("Error al redimensionar el inventario.\n");
            // Salir si no se pudo ampliar el inventario
            return;  
        }

        // Actualizar el puntero a los productos y el tamaño del inventario
        inventario->productos = productosReasignados;
        inventario->tamano = nuevaCapacidad;
    }

    // Agregar el nuevo producto en la siguiente posición disponible
    // Copiar el nombre
    strcpy(inventario->productos[inventario->ocupado].nombre, nombre);  
    // Asignar la cantidad
    inventario->productos[inventario->ocupado].cantidad = cantidad;   
    // Asignar el precio  
    inventario->productos[inventario->ocupado].precio = precio;         

    // Incrementar el contador de productos ocupados
    inventario->ocupado++;
}





// TODO: Implementar la función eliminarProducto
void eliminarProducto(inventario_t* inventario, const char* nombre) {
    // Buscar el producto por nombre
    int index = -1;
    for (int i = 0; i < inventario->ocupado; i++) {
        if (strcmp(inventario->productos[i].nombre, nombre) == 0) {
            index = i;
            // Si encontramos el producto, salimos del bucle
            break;  
        }
    }

    // Si el producto no se encontró, no hacemos nada
    if (index == -1) {
        printf("Producto no encontrado.\n");
        return;
    }

    // Mover los productos a la izquierda para cubrir el espacio
    for (int i = index; i < inventario->ocupado - 1; i++) {
        inventario->productos[i] = inventario->productos[i + 1];
    }

    // Reducir el contador de productos ocupados
    inventario->ocupado--;

    printf("Producto '%s' eliminado con éxito.\n", nombre);
}






// TODO: Implementar la función imprimirInventario
void imprimirInventario(const inventario_t* inventario) {
    // Verificar si el inventario está vacío
    if (inventario->ocupado == 0) {
        printf("El inventario está vacío.\n");
        return;
    }

    // Recorrer todos los productos y mostrarlos
    for (int i = 0; i < inventario->ocupado; i++) {
        printf("%d. %s - Cantidad: %d - Precio: ₡%.2f\n", 
               i + 1, 
               inventario->productos[i].nombre, 
               inventario->productos[i].cantidad, 
               inventario->productos[i].precio);
    }
}




// TODO: Implementar la función vaciarInventario
void vaciarInventario(inventario_t* inventario) {
    // Liberar el array de productos
    if (inventario->productos != NULL) {
        free(inventario->productos);
        // Opcional: evitar uso posterior del puntero
        inventario->productos = NULL;  
    }

    // Liberar la memoria de la estructura inventario_t
    free(inventario);
}