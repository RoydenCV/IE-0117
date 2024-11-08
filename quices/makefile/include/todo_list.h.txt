#ifndef TODO_LIST_H
#define TODO_LIST_H

#include "task.h"

typedef struct {
    Task* tasks;
    int count;
    int capacity;
} TodoList;

TodoList* create_todo_list();
void destroy_todo_list(TodoList* list);
void add_task(TodoList* list, const char* description);
void remove_task(TodoList* list, int index);
void list_tasks(const TodoList* list);

#endif // TODO_LIST_H
