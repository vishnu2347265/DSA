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

int findQueueSum(struct Queue* queue) {
    int sum = 0;
    for (int i = 0; i < queue->size; i++) {
        sum += queue->array[(queue->front + i) % queue->capacity];
    }
    return sum;
}

int main() {
    struct Queue* queue = createQueue(MAX_SIZE);

    enqueue(queue, 5);
    enqueue(queue, 10);
    enqueue(queue, 3);

    printf("Sum of elements in the queue: %d\n", findQueueSum(queue));

    printf("Dequeued element: %d\n", dequeue(queue));
    printf("Dequeued element: %d\n", dequeue(queue));

    printf("Sum of elements in the modified queue: %d\n", findQueueSum(queue));

    return 0;
}
