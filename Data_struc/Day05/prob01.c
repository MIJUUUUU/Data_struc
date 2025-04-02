#include <stdio.h>
#include <stdlib.h>
#define SIZE 100

typedef char element;

typedef struct {
    element data[SIZE];
    int front;
    int rear;
} QueueType;

void init(QueueType *q) {
    q->front = -1;
    q->rear = -1;
}

int is_empty(QueueType *q) {
    return q->front == q->rear;
}

int is_full(QueueType *q) {
    return q->rear == SIZE - 1;
}

void enqueue(QueueType *q, element item) {
    if (is_full(q)) {
        printf("Queue is full!\n");
        return;
    }
    q->rear++;
    q->data[q->rear] = item;
}

element dequeue(QueueType *q) {
    if (is_empty(q)) {
        printf("Queue is empty!\n");
        exit(1);
    }
    q->front++;
    return q->data[q->front];
}

void print(QueueType *q) {
    printf("Front Pos : %d, Rear Pos : %d\n", q->front, q->rear);
    for (int i = q->front + 1; i <= q->rear; i++) {
        printf("[%c] ", q->data[i]);
    }
    printf("\n");
}

int main() {
    QueueType Q;
    init(&Q);

    enqueue(&Q, 'A');
    enqueue(&Q, 'B');
    enqueue(&Q, 'C');

    print(&Q);                         // 첫 줄 + 큐 내용 출력
    printf("[%c]\n", dequeue(&Q));    // 꺼낸 값만 출력

    return 0;
}
