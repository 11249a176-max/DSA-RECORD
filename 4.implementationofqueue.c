#include <stdio.h>
#include <stdlib.h>
typedef struct {
    int *arr;
    int front;
    int rear;
    int capacity;
    int size;
} Queue;
Queue* createQueue(int capacity) {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->capacity = capacity;
    queue->front = 0;
    queue->rear = capacity - 1;
    queue->size = 0;
    queue->arr = (int*)malloc(capacity * sizeof(int));
    return queue;
}
int isFull(Queue* queue) {
    return (queue->size == queue->capacity);
}
int isEmpty(Queue* queue) {
    return (queue->size == 0);
}
void enqueue(Queue* queue, int item) {
    if (isFull(queue)) {
        printf("Queue is full! Cannot enqueue %d\n", item);
        return;
    }
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->arr[queue->rear] = item;
    queue->size++;
    printf("%d enqueued to queue\n", item);
}
int dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty! Cannot dequeue\n");
        return -1;
    }
    int item = queue->arr[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size--;
    return item;
}
void display(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Queue elements: ");
    int i = queue->front;
    int count = queue->size;
    while (count--) {
        printf("%d ", queue->arr[i]);
        i = (i + 1) % queue->capacity;
    }
    printf("\n");
}
void freeQueue(Queue* queue) {
    free(queue->arr);
    free(queue);
}
int main() {
    int capacity;
    printf("Enter queue capacity: ");
    scanf("%d", &capacity);
    Queue* queue = createQueue(capacity);
    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);
    display(queue);
    printf("Dequeued element: %d\n", dequeue(queue));
    printf("Dequeued element: %d\n", dequeue(queue));
    display(queue);
    enqueue(queue, 50);
    enqueue(queue, 60);
    display(queue);
    freeQueue(queue);
    return 0;
}
