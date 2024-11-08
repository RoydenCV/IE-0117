#include <stdio.h>
#include <stdlib.h>
#include "todo_list.h"

void show_menu() {
    printf("1. Add Task\n");
    printf("2. Remove Task\n");
    printf("3. List Tasks\n");
    printf("4. Exit\n");
}

int main() {
    TodoList* list = create_todo_list();
    int choice, index;
    char description[256];

    while (1) {
        show_menu();
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter task description: ");
                scanf(" %[^\n]", description);
                add_task(list, description);
                break;
            case 2:
                printf("Enter task index to remove: ");
                scanf("%d", &index);
                remove_task(list, index);
                break;
            case 3:
                list_tasks(list);
                break;
            case 4:
                destroy_todo_list(list);
                return 0;
            default:
                printf("Invalid option. Please try again.\n");
                break;
        }
    }
}
