#include <stdio.h>

typedef struct Queue {
    char *head;
    struct Queue *tail;
} Queue;

Queue newQueue() {
    static Queue temp;
    temp.head = NULL;
    temp.tail = NULL;
    return temp;
}

void push(Queue *queue, char *data) {
    if (queue->head == NULL) {
        queue->head = data;
        return;
    }
    if (queue->tail == NULL) {
        Queue ns = newQueue();
        ns.head = data;
        queue->tail = &ns;
    } else {
        push(queue->tail, data);
    }
}

char *pop(Queue *queue) {
    char *temp = queue->head;
    if (queue->tail) {
        queue->head = queue->tail->head;
        queue->tail = queue->tail->tail;
    } else {
        queue->head = NULL;
    }
    return temp;
}

int main(void) {
    Queue a = newQueue();
    push(&a, "h");
    push(&a, "w");
    printf("%p\n", pop(&a));
    printf("%p\n", pop(&a));
    printf("%s\n", pop(&a));
    return 0;
}