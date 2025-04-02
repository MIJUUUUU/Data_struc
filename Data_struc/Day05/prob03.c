#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 5

typedef int element;

typedef struct {
    element data[MAX_QUEUE_SIZE];
    int front, rear;
} QueueType;

void error(char *message) {
    fprintf(stderr, "%s\n", message);
    exit(1);
}

void init_queue(QueueType *q) {
    q->front = 0;
    q->rear = 0;
}

int is_empty(QueueType *q) {
    return q->front == q->rear;
}

int is_full(QueueType *q) {
    return (q->rear + 1) % MAX_QUEUE_SIZE == q->front;
}

void queue_print(QueueType *q) {
    printf("QUEUE(front=%d,rear=%d)=", q->front, q->rear);
    if (!is_empty(q)) {
        int i = q->front;
        do {
            i = (i + 1) % MAX_QUEUE_SIZE;
            printf("%d|", q->data[i]);
            if (i == q->rear) break;
        } while (i != q->front);
    }
    printf("\n");
}

void enqueue(QueueType *q, element item) {
    if (is_full(q)) {
        printf("The queue is filled to capacity.\n");
        return;
    }
    q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
    q->data[q->rear] = item;
    queue_print(q);
}

element dequeue(QueueType *q) {
    if (is_empty(q)) {
        printf("The queue has no items.\n");
        return -1;
    }
    q->front = (q->front + 1) % MAX_QUEUE_SIZE;
    queue_print(q);
    return q->data[q->front];
}

int main(void) {
    QueueType q;
    init_queue(&q);


    for (int i = 0; i < 4; i++) {
        int value;
        scanf("%d", &value);
        enqueue(&q, value);
    }


    if (is_full(&q)) {
        printf("The queue is filled to capacity.\n");
    }


    for (int i = 0; i < 5; i++) {
        dequeue(&q);
    }

    return 0;
}
