#include <stdio.h>
#include <string.h>
#define MAX_SIZE 30

typedef struct {
    char arr[MAX_SIZE];
    int top;
} Stack;

void initialize(Stack *s) {
    s->top = -1;
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

void push(Stack *s, char data) {
    if (s->top < MAX_SIZE - 1) {
        s->arr[++(s->top)] = data;
    }
}

char pop(Stack *s) {
    if (!isEmpty(s)) {
        return s->arr[(s->top)--];
    }
    return '\0'; 
}

int main() {
    char input[MAX_SIZE], reversed[MAX_SIZE];
    Stack s;
    initialize(&s);


    scanf("%s", input);


    for (int i = 0; i < strlen(input); i++) {
        push(&s, input[i]);
    }

    int index = 0;
    while (!isEmpty(&s)) {
        reversed[index++] = pop(&s);
    }
    reversed[index] = '\0'; 


    printf("%s\n", reversed);

    return 0;
}