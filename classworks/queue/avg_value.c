#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

struct Queue {
    int front, rear, size;
    int capacity;
    int* array;
};

struct Queue* createQueue(int capacity) {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->capacity = capacity;
    queue->front = queue->size = 0;
    queue->rear = capacity - 1;
    queue->array = (int*)malloc(queue->capacity * sizeof(int));
    return queue;
}

int isFull(struct Queue* queue) {
    return (queue->size == queue->capacity);
}

int isEmpty(struct Queue* queue) {
    return (queue->size == 0);
}

void enqueue(struct Queue* queue, int item) {
    if (isFull(queue))
        return;

    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->array[queue->rear] = item;
    queue->size = queue->size + 1;
}

int dequeue(struct Queue* queue) {
    if (isEmpty(queue))
        return -1;

    int item = queue->array[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size = queue->size - 1;
    return item;
}

double findQueueAverage(struct Queue* queue) {
    if (isEmpty(queue))
        return 0.0;

    int sum = 0;
    for (int i = 0; i < queue->size; i++) {
        sum += queue->array[(queue->front + i) % queue->capacity];
    }

    return (double)sum / queue->size;
}

int main() {
    struct Queue* queue = createQueue(MAX_SIZE);

    enqueue(queue, 5);
    enqueue(queue, 10);
    enqueue(queue, 3);

    printf("Average value of elements in the queue: %.2f\n", findQueueAverage(queue));

    printf("Dequeued element: %d\n", dequeue(queue));
    printf("Dequeued element: %d\n", dequeue(queue));

    printf("Average value of elements in the modified queue: %.2f\n", findQueueAverage(queue));

    return 0;
}
