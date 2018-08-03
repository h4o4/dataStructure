#include <stdio.h>

typedef struct Stack {
    char *head;
    struct Stack *tail;
} Stack;

Stack newStack() {
    static Stack temp;
    temp.head = NULL;
    temp.tail = NULL;
    return temp;
}

void push(Stack *stack, char *data) {
    if (stack->head == NULL) {
        stack->head = data;
        return;
    }
    if (stack->tail == NULL) {
        Stack ns = newStack();
        ns.head = data;
        stack->tail = &ns;
    } else {
        push(stack->tail, data);
    }
}

char *pop(Stack *stack) {
    char *temp;
    if (stack->tail == NULL) {
        temp = stack->head;
        stack->head = NULL;
        return temp;
    } else {
        if (stack->tail->tail == NULL) {
            temp = stack->tail->head;
            stack->tail = NULL;
            return temp;
        } else {
            return pop(stack->tail);
        }
    }
}

int main(void) {

    Stack a = newStack();
    push(&a, "12");
    push(&a, "232123213");
    // char *ptr = a.head;
    printf("%s\n", pop(&a));
    printf("%s\n", pop(&a));

    return 0;
}