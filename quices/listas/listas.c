// Royden Contreras Vallejos
// C12260

// Listas
#include <stdio.h>
#include <stdlib.h>

// Definition of the node structure
typedef struct node {
    int val;
    struct node *next;
} node_t;

// Function to print the list
void print_list(node_t *head) {
    node_t *current = head;
    while (current != NULL) {
        printf("%d ->", current->val);
        current = current->next;
    }
}

// Function to append a node to the end of the list
void append(node_t *head, int val) {
    node_t *current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = (node_t *) malloc(sizeof(node_t));
    current->next->val = val;
    current->next->next = NULL;
}

// Function to prepend a node to the beginning of the list
node_t *prepend(node_t *head, int val) {
    node_t *new_node = (node_t *) malloc(sizeof(node_t));
    new_node->val = val;
    new_node->next = head;
    return new_node;
}

// Function to delete the first node
node_t *delete_first(node_t *head) {
    if (head == NULL) return NULL;
    node_t *new_head = head->next;
    free(head);
    return new_head;
}



// Function to delete a node by value
void delete_by_value(node_t **head, int val) {
    // En caso que la lista este vacia
    if (*head == NULL) return;

    // Como se divide entre current y previous primero debemos asegurarnos que
    // el primer valor (current) no sea el valor que se selecciono, para ello:
    if ((*head)->val == val) {
        node_t *temp = *head;
        *head = (*head)->next;
        free(temp);
        return;
    }

    // En caso que no haya sido el primer valor continuamos con los que le 
    // siguen los cuales son los que denominamos como "current"
    node_t *current = *head;
    while (current->next != NULL) {
        if (current->next->val == val) {
            node_t *temp = current->next;
            current->next = current->next->next; 
            free(temp);
            return;
        }
        current = current->next;
    }

    // Si no se encuentra el valor, no hacemos nada.
}





int main() {
    node_t *head = NULL;
    head = (node_t *) malloc(sizeof(node_t));
    head->val = 1;
    head->next = NULL;

    append(head, 2);
    append(head, 3);

    // Vamos a agregar comentarios para diferenciar en terminal las listas 

    printf("Original List: ");
    print_list(head);
    printf("\n");


    head = prepend(head, 0);
    printf("List after prepending 0: ");
    print_list(head);
    printf("\n");


    head = delete_first(head);
    printf("List after deleting the first node: ");
    print_list(head);
    printf("\n");


    
    delete_by_value(&head, 2);
    printf("Impresion de lista eliminando 2: ");
    print_list(head);
    printf("\n");

    return 0;
}