// Royden Contreras Vallejos
// C12260
// Esto es el segundo examen parcial de Porgramacion Bajo Plataformas Abiertas el
// cual consiste en definir una serie de variables para que el programa funcione 
// correctamente como nos indican en las intrucciones. 


#ifndef INVENTARIO_H
#define INVENTARIO_H

typedef struct {
    char nombre[50];
    int cantidad;
    float precio;
} producto_t;

typedef struct {
    producto_t* productos;
    // Capacidad total del inventario
    int tamano;   
    // Número actual de productos
    int ocupado;  
} inventario_t;

// Declaración de funciones
inventario_t* crearInventario();

// TODO: Declarar el resto de funciones
void agregarProducto(inventario_t* inventario, const char* nombre, int cantidad, float precio);
void eliminarProducto(inventario_t* inventario, const char* nombre);
void imprimirInventario(const inventario_t* inventario);
void vaciarInventario(inventario_t* inventario);


#endif // INVENTARIO_H