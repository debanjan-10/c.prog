#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *data;
    int front, rear, size, capacity;
} CircularQueue;

// Create queue
CircularQueue* createQueue(int capacity) {
    CircularQueue *q = (CircularQueue*)malloc(sizeof(CircularQueue));
    q->capacity = capacity;
    q->size = 0;
    q->front = 0;
    q->rear = -1;
    q->data = (int*)malloc(capacity * sizeof(int));
    return q;
}

// Resize queue
void resizeQueue(CircularQueue *q) {
    int newCapacity = q->capacity * 2;
    int *newData = (int*)malloc(newCapacity * sizeof(int));

    for (int i = 0; i < q->size; i++) {
        newData[i] = q->data[(q->front + i) % q->capacity];
    }

    free(q->data);
    q->data = newData;
    q->capacity = newCapacity;
    q->front = 0;
    q->rear = q->size - 1;
}

// Enqueue (user input)
void enqueue(CircularQueue *q) {
    int value;
    printf("Enter value to insert: ");
    scanf("%d", &value);

    if (q->size == q->capacity) {
        resizeQueue(q);
    }

    q->rear = (q->rear + 1) % q->capacity;
    q->data[q->rear] = value;
    q->size++;

    printf("Inserted %d\n", value);
}

// Dequeue
void dequeue(CircularQueue *q) {
    if (q->size == 0) {
        printf("Queue is empty\n");
        return;
    }

    printf("Deleted %d\n", q->data[q->front]);
    q->front = (q->front + 1) % q->capacity;
    q->size--;
}

// Display
void display(CircularQueue *q) {
    if (q->size == 0) {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue elements: ");
    for (int i = 0; i < q->size; i++) {
        printf("%d ", q->data[(q->front + i) % q->capacity]);
    }
    printf("\n");
}

// Free memory
void freeQueue(CircularQueue *q) {
    free(q->data);
    free(q);
}

// Main (menu-driven)
int main() {
    int choice;
    CircularQueue *q = createQueue(2); // initial capacity

    while (1) {
        printf("\n--- Circular Queue Menu ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                enqueue(q);
                break;
            case 2:
                dequeue(q);
                break;
            case 3:
                display(q);
                break;
            case 4:
                freeQueue(q);
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
}
