#include <stdio.h>
#include <stdlib.h>
// Define the structure for a circular linked list node
typedef struct Node {
    int data;
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
    newNode->next = newNode; // Initialize next as circular
    return newNode;
}
// Function to insert a node at the beginning of the circular list
void insertAtBeginning(Node** head, int data) {
    Node* newNode = createNode(data);
    if (!newNode) return;
    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* temp = *head;
        while (temp->next != *head) {
            temp = temp->next;
        }
        newNode->next = *head;
        temp->next = newNode;
        *head = newNode;
    }
}

// Function to insert a node at the end of the circular list
void insertAtEnd(Node** head, int data) {
    Node* newNode = createNode(data);
    if (!newNode) return;
    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* temp = *head;
        while (temp->next != *head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = *head;
    }
}

// Function to insert a node after a specific node in the circular list
void insertAfter(Node* head, int key, int data) {
    Node* temp = head;
    do {
        if (temp->data == key) {
            Node* newNode = createNode(data);
            if (!newNode) return;
            newNode->next = temp->next;
            temp->next = newNode;
            return;
        }
        temp = temp->next;
    } while (temp != head);
    printf("Node with data %d not found\n", key);
}

// Function to delete a node from the beginning of the circular list
void deleteFromBeginning(Node** head) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
    Node* temp = *head;
    if (temp->next == *head) {
        free(temp);
        *head = NULL;
    } else {
        Node* last = *head;
        while (last->next != *head) {
            last = last->next;
        }
        last->next = temp->next;
        *head = temp->next;
        free(temp);
    }
}
// Function to delete a node from the end of the circular list
void deleteFromEnd(Node** head) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
    Node* temp = *head;
    if (temp->next == *head) {
        free(temp);
        *head = NULL;
    } else {
        Node* prev = NULL;
        while (temp->next != *head) {
            prev = temp;
            temp = temp->next;
        }
        prev->next = *head;
        free(temp);
    }
// Function to delete a node after a specific node in the circular list
void deleteAfter(Node* head, int key) {
    Node* temp = head;
    do {
        if (temp->data == key) {
            Node* delNode = temp->next;
            if (delNode == head) {
                printf("Cannot delete the head node after itself\n");
                return;
            }
            temp->next = delNode->next;
            free(delNode);
            return;
        }
        temp = temp->next;
    } while (temp != head);
    printf("Node with data %d not found\n", key);
}

// Function to search for a given element in the circular list
Node* search(Node* head, int key) {
    Node* temp = head;
    do {
        if (temp->data == key) {
            return temp;
        }
        temp = temp->next;
    } while (temp != head);
    return NULL;
}

// Function to display the elements of the circular list
void displayList(Node* head) {
    if (head == NULL) {
        printf("Circular linked list: NULL\n");
        return;
    }
    Node* temp = head;
    printf("Circular linked list: ");
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(head)\n");
}
// Main function with menu-driven interaction
int main() {
    Node* head = NULL;
    int choice, data, key;
    Node* result;
while (1) {
        printf("\n1. Insert at beginning\n");
        printf("2. Insert at end\n");
        printf("3. Insert after a specific node\n");printf("4. Delete from beginning\n");
        printf("5. Delete from end\n");
        printf("6. Delete after a specific node\n");
        printf("7. Search for an element\n");
        printf("8. Display the circular list\n");
        printf("9. Exit\n");
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
                printf("Enter the key after which to insert: ");
                scanf("%d", &key);
                printf("Enter data to insert after node %d: ", key);
                scanf("%d", &data);
                insertAfter(head, key, data);
                break;
            case 4:
                deleteFromBeginning(&head);
                break;
            case 5:
                deleteFromEnd(&head);
                break;
            case 6:
                printf("Enter the key after which to delete: ");
                scanf("%d", &key);
                deleteAfter(head, key);
                break;
            case 7:
                printf("Enter data to search: ");
                scanf("%d", &data);
                result = search(head, data);
                if (result != NULL) {
                    printf("Node with data %d found\n", data);
                } else {
                    printf("Node with data %d not found\n", data);
                }
                break;
            case 8:
                displayList(head);
                break;
            case 9:
                exit(0);
            default:
                printf("Invalid choice, please try again\n");
        }
    }
    return 0;
}



