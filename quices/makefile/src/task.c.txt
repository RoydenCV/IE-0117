#include <stdio.h>
#include <string.h>
#include "task.h"

Task create_task(const char* description) {
    Task task;
    strncpy(task.description, description, sizeof(task.description) - 1);
    task.description[sizeof(task.description) - 1] = '\0';
    return task;
}

void print_task(const Task* task) {
    printf("%s\n", task->description);
}
