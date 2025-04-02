#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_SIZE 100

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


bool isMatchingPair(char open, char close) {
    if (open == '(' && close == ')') {
        return true;
    } else if (open == '{' && close == '}') {
        return true;
    } else if (open == '[' && close == ']') {
        return true;
    }
    return false;
}


bool isBalanced(char expression[]) {
    Stack s;
    initialize(&s);

 
    for (int i = 0; i < strlen(expression); i++) {
        char ch = expression[i];

    
        if (ch == '(' || ch == '{' || ch == '[') {
            push(&s, ch);
        } 
     
        else if (ch == ')' || ch == '}' || ch == ']') {
            if (isEmpty(&s) || !isMatchingPair(pop(&s), ch)) {
                return false;
            }
        }
    }

    return isEmpty(&s);
}

int main() {
    char expression[MAX_SIZE];
    scanf("%s", expression);

    if (isBalanced(expression)) {
        printf("Balanced\n");
    } else {
        printf("Not Balanced\n");
    }

    return 0;
}