#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

// 1. Insert at beginning
void insert_begin() {
    int value;
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));

    printf("Enter value: ");
    scanf("%d", &value);

    newNode->data = value;
    newNode->next = head;
    head = newNode;
}

// 2. Insert at end
void insert_end() {
    int value;
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    struct Node *temp;

    printf("Enter value: ");
    scanf("%d", &value);

    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        return;
    }

    temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

// 3. Insert at position
void insert_position() {
    int value, pos, i = 1;
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    struct Node *temp = head;

    printf("Enter value and position: ");
    scanf("%d %d", &value, &pos);

    if (pos == 1) {
        newNode->data = value;
        newNode->next = head;
        head = newNode;
        return;
    }

    while (i < pos - 1 && temp != NULL) {
        temp = temp->next;
        i++;
    }

    if (temp == NULL) {
        printf("Invalid position\n");
        free(newNode);
        return;
    }

    newNode->data = value;
    newNode->next = temp->next;
    temp->next = newNode;
}

// 4. Delete from beginning
void delete_begin() {
    struct Node *temp;

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    temp = head;
    head = head->next;
    printf("Deleted %d\n", temp->data);
    free(temp);
}

// 5. Delete from end
void delete_end() {
    struct Node *temp = head, *prev = NULL;

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    if (head->next == NULL) {
        printf("Deleted %d\n", head->data);
        free(head);
        head = NULL;
        return;
    }

    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }

    prev->next = NULL;
    printf("Deleted %d\n", temp->data);
    free(temp);
}

// 6. Delete by value
void delete_value() {
    int value;
    struct Node *temp = head, *prev = NULL;

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    printf("Enter value to delete: ");
    scanf("%d", &value);

    if (head->data == value) {
        temp = head;
        head = head->next;
        free(temp);
        return;
    }

    while (temp != NULL && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Value not found\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
}

// 7. Search
void search() {
    int value, pos = 1;
    struct Node *temp = head;

    printf("Enter value to search: ");
    scanf("%d", &value);

    while (temp != NULL) {
        if (temp->data == value) {
            printf("Found at position %d\n", pos);
            return;
        }
        temp = temp->next;
        pos++;
    }

    printf("Not found\n");
}

// 8. Display
void display() {
    struct Node *temp = head;

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    printf("Linked list: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// 9. Count nodes
void count() {
    int cnt = 0;
    struct Node *temp = head;

    while (temp != NULL) {
        cnt++;
        temp = temp->next;
    }

    printf("Total nodes: %d\n", cnt);
}

// Main menu
int main() {
    int choice;

    while (1) {
        printf("\n--- Linked List Operations ---\n");
        printf("1. Insert at beginning\n");
        printf("2. Insert at end\n");
        printf("3. Insert at position\n");
        printf("4. Delete from beginning\n");
        printf("5. Delete from end\n");
        printf("6. Delete by value\n");
        printf("7. Search\n");
        printf("8. Display\n");
        printf("9. Count nodes\n");
        printf("10. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: insert_begin(); break;
            case 2: insert_end(); break;
            case 3: insert_position(); break;
            case 4: delete_begin(); break;
            case 5: delete_end(); break;
            case 6: delete_value(); break;
            case 7: search(); break;
            case 8: display(); break;
            case 9: count(); break;
            case 10: exit(0);
            default: printf("Invalid choice\n");
        }
    }
}
