#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100

typedef struct {
    int r;
    int c;
} element;

element here, entry;
char maze[MAX_SIZE][MAX_SIZE];

typedef struct {
    element data[MAX_SIZE];
    int top;
} StackType;

void init_stack(StackType* s) {
    s->top = -1;
}

int is_empty(StackType* s) {
    return (s->top == -1);
}

int is_full(StackType* s) {
    return (s->top == (MAX_SIZE * MAX_SIZE - 1));
}

void push(StackType* s, element data) {
    if (is_full(s)) {
        printf("Stack Overflow\n");
        return;
    } else {
        s->data[++(s->top)] = data;
    }
}

element pop(StackType* s) {
    if (is_empty(s)) {
        printf("Stack Underflow\n");
        exit(1);
    } else {
        return s->data[(s->top)--];
    }
}

void push_loc(StackType* s, int r, int c) {
    if (r < 0 || c < 0) return;
    if (maze[r][c] != '1' && maze[r][c] != '.') {
        element tmp;
        tmp.r = r;
        tmp.c = c;
        push(s, tmp);
    }
}

void findStartPosition(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (maze[i][j] == 'e') {
                entry.r = i;
                entry.c = j;
                return;
            }
        }
    }
}

int main() {
    int n; 
    int r, c;
    StackType s;

    init_stack(&s);

    scanf("%d", &n);
 
    for (r = 0; r < n; r++) {
        for (c = 0; c < n; c++) {
            scanf(" %c", &maze[r][c]);
        }
    }

    findStartPosition(n);
    here = entry;


    while (maze[here.r][here.c] != 'x') {
        maze[here.r][here.c] = '.';

        push_loc(&s, here.r - 1, here.c); // 위
        push_loc(&s, here.r + 1, here.c); // 아래
        push_loc(&s, here.r, here.c - 1); // 왼쪽
        push_loc(&s, here.r, here.c + 1); // 오른쪽

        if (is_empty(&s)) {
            printf("fail\n");
            return 0;
        } else {
            here = pop(&s);
        }
    }

    printf("success\n");
    return 0;
}