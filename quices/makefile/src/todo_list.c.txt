#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "todo_list.h"

#define INITIAL_CAPACITY 10

TodoList* create_todo_list() {
    TodoList* list = (TodoList*)malloc(sizeof(TodoList));
    list->tasks = (Task*)malloc(INITIAL_CAPACITY * sizeof(Task));
    list->count = 0;
    list->capacity = INITIAL_CAPACITY;
    return list;
}

void destroy_todo_list(TodoList* list) {
    free(list->tasks);
    free(list);
}

void add_task(TodoList* list, const char* description) {
    if (list->count >= list->capacity) {
        list->capacity *= 2;
        list->tasks = (Task*)realloc(list->tasks, list->capacity * sizeof(Task));
    }
    list->tasks[list->count++] = create_task(description);
}

void remove_task(TodoList* list, int index) {
    if (index < 0 || index >= list->count) {
        printf("Invalid task index.\n");
        return;
    }
    for (int i = index; i < list->count - 1; i++) {
        list->tasks[i] = list->tasks[i + 1];
    }
    list->count--;
}

void list_tasks(const TodoList* list) {
    for (int i = 0; i < list->count; i++) {
        printf("%d: ", i);
        print_task(&list->tasks[i]);
    }
}
