// Royden Contreras Vallejos
// C12260
// Este es un programa el cual en su inicio desplegara diferentes opciones de las
// cuales el usuario sera capaz de seleccionarlas las veces que quiera hasta que
// el mismo desee salir. Este laboratorio este nefocado a listas por lo que se
// realizara es una elaboracion de las mismas, donde el usuario podra 
// selleccionar si agregar un elemento, eliminarlo o imprimir los elementros que
// se encuentran contenidos en la lista. Cabe mencior que la filosofia al 
// eliminar un elementro de la lista esta dada por el "First in first out",por
// lo que al seleccionar la opcion de eliminar elemento de la lista,, lo que se
// realizara sera eliminar el primer elemento que se halla ingresado. Una vez 
// Hecho esto pasamos a la elaboracion del codigo:


// Ingresamos las librerias correspondintes. 
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


// Definición de la estructura nodo que almacena un entero y un puntero al 
// siguiente nodo.
typedef struct nodo
{
    // Valor almacenado en el nodo.
    int dato; 
    // Puntero al siguiente nodo en la cola.
    struct nodo *sgte; 
} nodo;


// Definición de la estructura cola que almacena punteros al frente y al 
// final de la cola.
typedef struct
{
    // Puntero al primer nodo de la cola.
    nodo *frente; 
    // Puntero al último nodo de la cola.
    nodo *final; 
} cola;


// Función para crear un nuevo nodo con un dato específico.
// Parámetro: dato - el valor a almacenar en el nodo.
// Retorna: un puntero al nuevo nodo creado.
nodo *nodonuevo(int dato)
{
    // Asignación dinámica de memoria para el nuevo nodo.
    nodo *nuevoNodo = (nodo *)malloc(sizeof(nodo)); 
    // Establece el valor del dato.
    nuevoNodo->dato = dato; 
    // El siguiente nodo es NULL, ya que es el último nodo actualmente.
    nuevoNodo->sgte = NULL; 
    // Retorna el nuevo nodo.
    return nuevoNodo; 
}


// Función para crear una cola vacía.
// Retorna: un puntero a la cola recién creada.
cola *crearcola()
{
    // Asignación dinámica de memoria para la cola.
    cola *nuevaCola = (cola *)malloc(sizeof(cola)); 
    // Inicializa la cola vacía.
    nuevaCola->frente = nuevaCola->final = NULL; 
    // Retorna la nueva cola.
    return nuevaCola; 
}


// Función para agregar elementos al final de la cola (enqueue).
// Parámetros: cola - un puntero a la cola donde se agregará el elemento.
//             dato - el valor a agregar a la cola.
void enqueue(cola *cola, int dato)
{
    // Crea un nuevo nodo con el dato.
    nodo *new_node = nodonuevo(dato); 
    // Si la cola está vacía.
    if (cola->frente == NULL) 
    {
        // El nuevo nodo es ahora el frente y el final de la cola.
        cola->frente = new_node; 
        cola->final = new_node;
    }
    else
    {
        // Enlaza el nuevo nodo al final de la cola.
        cola->final->sgte = new_node; 
        // Actualiza el final de la cola al nuevo nodo.
        cola->final = new_node; 
    }
}


// Función para quitar elementos del frente de la cola.
// Parámetro: cola - un puntero a la cola de la cual se quitará el elemento.
void dequeue(cola *cola)
{
    // Si la cola está vacía.
    if (cola->frente == NULL) 
    {
        printf("La cola esta vacía\n");
    }
    else
    {
        // Temporalmente guarda el nodo frente para liberarlo.
        nodo *tmp = cola->frente; 
        // Avanza el frente al siguiente nodo.
        cola->frente = cola->frente->sgte; 
        // Libera el nodo que estaba al frente.
        free(tmp); 

        // Si la cola queda vacía después de quitar el elemento.
        if (cola->frente == NULL) 
        {
            // Ajusta el final a NULL también.
            cola->final = NULL; 
        }
    }
}


// Función para imprimir todos los elementos de la cola.
// Parámetro: cola - un puntero a la cola que se imprimirá.
void imprimirCola(cola *cola)
{
    // Si la cola está vacía.
    if (cola->frente == NULL) 
    {
        printf("La cola está vacía.\n");
        return;
    }
    // Comienza desde el frente de la cola.
    nodo *tmp = cola->frente; 
    // Mientras haya nodos en la cola.
    while (tmp != NULL) 
    {
        // Imprime el valor del nodo.
        printf("%d ", tmp->dato); 
        // Avanza al siguiente nodo.
        tmp = tmp->sgte; 
    }
    // Nueva línea al final de imprimir todos los elementos.
    printf("\n"); 
}


// Función principal del programa.
int main()
{
    int option;
    bool salir = false;
    // Crea una nueva cola vacía.
    cola *nueva_cola=crearcola(); 

    // Mientras no se elija la opción de salir.
    while (!salir) 
    {
        printf("1. Imprimir cola\n");
        printf("2. Agregar elemento a la cola\n");
        printf("3. Quitar elemento de la cola\n");
        printf("4. Salir\n");
        printf("Ingrese una opción: ");
        // Lee la opción elegida por el usuario.
        scanf("%d", &option); 


        // Según la opción elegida.
        switch (option) 
        {
            // Si se elige la opción 1.
            case 1: 
            // Imprime todos los elementos de la cola.
            imprimirCola(nueva_cola); 
            break;

            // Si se elige la opción 2.
            case 2: 
            printf("Ingrese el valor a agregar a la cola: ");
            int valor;
            // Lee el valor a agregar.
            scanf("%d", &valor); 
            // Agrega el valor a la cola.
            enqueue(nueva_cola, valor); 
            break;

            // Si se elige la opción 3.
            case 3: 
            // Quita el elemento del frente de la cola.
            dequeue(nueva_cola); 
            break;

            // Si se elige la opción 4.
            case 4: 
            // Sale del bucle y finaliza el programa.
            salir = true; 
            break;

            // Si se elige una opción no válida.
            default: 
            printf("Opción no válida. Intente de nuevo.\n");
            break;
        }
        
    }   

    // Finaliza el programa.
    return 0; 
}