#include <stdio.h>
#include <stdlib.h>

// Define the structure for a doubly linked list node
typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed\n");
        return NULL;
    }
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the beginning of the list
void insertAtBeginning(Node** head, int data) {
    Node* newNode = createNode(data);
    if (!newNode) return;
    if (*head != NULL) {
        (*head)->prev = newNode;
    }
    newNode->next = *head;
    *head = newNode;
}
// Function to insert a node at the end of the list
void insertAtEnd(Node** head, int data) {
    Node* newNode = createNode(data);
    if (!newNode) return;
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}
// Function to delete a node from the beginning of the list
void deleteFromBeginning(Node** head) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
    Node* temp = *head;
    *head = (*head)->next;
    if (*head != NULL) {
        (*head)->prev = NULL;
    }
    free(temp);
}

// Function to delete a node from the end of the list
void deleteFromEnd(Node** head) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
    Node* temp = *head;
    if (temp->next == NULL) {
        free(temp);
        *head = NULL;
        return;
    }
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->prev->next = NULL;
    free(temp);
}

// Function to search for an element in the list
Node* search(Node* head, int data) {
    Node* temp = head;
    while (temp != NULL) {
        if (temp->data == data) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}
// Function to display the elements of the list
void displayList(Node* head) {
    if (head == NULL) {
        printf("Doubly linked list: NULL\n");
        return;
    }
    Node* temp = head;
    printf("Doubly linked list: ");
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Main function with menu-driven interaction
int main() {
    Node* head = NULL;
    int choice, data;
    Node* result;

    while (1) {
        printf("\n1. Insert at beginning\n");
        printf("2. Insert at end\n");
        printf("3. Delete from beginning\n");
        printf("4. Delete from end\n");
        printf("5. Search\n");
        printf("6. Display\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert at beginning: ");
                scanf("%d", &data);
                insertAtBeginning(&head, data);
                break;
            case 2:
                printf("Enter data to insert at end: ");
                scanf("%d", &data);
                insertAtEnd(&head, data);
                break;
            case 3:
                deleteFromBeginning(&head);
                break;
            case 4:
                deleteFromEnd(&head);
                break;
            case 5:
                printf("Enter data to search: ");
scanf("%d", &data);
                result = search(head, data);
                if (result != NULL) {
                    printf("Node with data %d found\n", data);
                } else {
                    printf("Node with data %d not found\n", data);
                }
                break;
            case 6:
                displayList(head);
                break;
            case 7:
                exit(0);
            default:
                printf("Invalid choice, please try again\n");
        }
    }
    return 0;
}


