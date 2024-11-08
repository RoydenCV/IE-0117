#ifndef TASK_H
#define TASK_H

typedef struct {
    char description[256];
} Task;

Task create_task(const char* description);
void print_task(const Task* task);

#endif // TASK_H
