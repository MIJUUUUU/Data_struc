#include <stdio.h>
#define MAX_SIZE 100

typedef struct {
    int arr[MAX_SIZE];
    int top;
} Stack;

void initialize(Stack *s) {
    s->top = -1;
}

int isFull(Stack *s) {
    return s->top == MAX_SIZE - 1;
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

void push(Stack *s, int data) {
    if (isFull(s)) {
        printf("Stack Overflow\n");
    } else {
        s->arr[++(s->top)] = data;
    }
}

int pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack Underflow\n");
        return -1;  // Error value
    } else {
        return s->arr[(s->top)--];
    }
}

int peek(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty\n");
        return -1;  // Error value
    } else {
        return s->arr[s->top];
    }
}

int main() {
    Stack s;
    initialize(&s);

    // Stack이 비어 있다는 메시지를 먼저 출력
    if (isEmpty(&s)) {
        printf("Stack is empty.\n");
    }

    push(&s, 5);
    printf("Pushing: 5\n");

    push(&s, 10);
    printf("Pushing: 10\n");

    printf("Peek: %d\n", peek(&s));

    printf("Popping: %d\n", pop(&s));

    printf("Peek: %d\n", peek(&s));

    return 0;
}