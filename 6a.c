#include <stdio.h>
#include <stdlib.h>

// Structure for a node
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function to insert a node at the beginning of the list
void insertAtBeginning(Node** head, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

// Function to insert a node after a specified node
void insertAfter(Node* prev, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = prev->next;
    prev->next = newNode;
}

// Function to insert a node at the end of the list
void insertAtEnd(Node** head, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}
// Function to find an element in the list
Node* findElement(Node* head, int data) {
    while (head != NULL) {
        if (head->data == data) {
            return head;
        }
        head = head->next;
    }
    return NULL;
}
// Function to find the next node of a specified node
Node* findNext(Node* node) {
    return node->next;
}

// Function to find the previous node of a specified node
Node* findPrevious(Node* head, Node* node) {
    if (node == head) {
        return NULL;
    }
    Node* temp = head;
    while (temp->next != node) {
        temp = temp->next;
    }
    return temp;
}

// Function to check if a node is the last node in the list
int isLast(Node* node, Node* head) {
    while (head->next != NULL) {
        head = head->next;
    }
    return head == node;
}

// Function to check if the list is empty
int isEmpty(Node* head) {
    return head == NULL;
}


/

// Function to delete a node from the beginning of the list
void deleteFromBeginning(Node** head) {
    Node* temp = *head;
    *head = (*head)->next;
    free(temp);
}

// Function to delete a node after a specified node
void deleteAfter(Node* prev) {
    Node* temp = prev->next;
    prev->next = temp->next;
    free(temp);
}

// Function to delete a node from the end of the list
void deleteFromEnd(Node** head) {
    if (*head == NULL) {
        return;
    }
    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }
    Node* temp = *head;
    while (temp->next->next != NULL) {
        temp = temp->next;
}
    free(temp->next);
    temp->next = NULL;
}

// Function to delete the entire list
void deleteList(Node** head) {
    Node* temp = *head;
    while (temp != NULL) {
        Node* next = temp->next;
        free(temp);
        temp = next;
    }
    *head = NULL;
}

// Function to display theelements of the list
void display(Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    Node* head = NULL;
    int choice, data;
    while (1) {
        printf("\n1. Insert at beginning\n2. Insert after a node\n3. Insert at end\n4. Find an element\n5. Find next\n6. Find previous\n7. Check if last\n8. Check if empty\n9. Delete from beginning\n10. Delete after a node\n11. Delete from end\n12. Delete the list\n13. Display\n14. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
switch (choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                insertAtBeginning(&head, data);
                break;
            case 2:
                printf("Enter data and node data: ");
                scanf("%d%d", &data, &data);
                Node* node = findElement(head, data);
                if (node != NULL) {
                    insertAfter(node, data);
                } else {
                    printf("Node not found\n");
                }
                break;
case 3:
                printf("Enter data: ");
                scanf("%d", &data);
                insertAtEnd(&head, data);
                break;
            case 4:
                printf("Enter data: ");
                scanf("%d", &data);
                Node* found = findElement(head, data);
                if (found != NULL) {
                    printf("Element found\n");
                } else {
                    printf("Element not found\n");
                }
                break;
            case 5:
                printf("Enter node data: ");
                scanf("%d", &data);
                Node* next = findNext(findElement(head, data));
                if (next != NULL) {
                    printf("Next node: %d\n", next->data);
                } else {
                    printf("No next node\n");
                }
                break;
            case 6:
                printf("Enter node data: ");
                scanf("%d", &data);
                Node* prev = findPrevious(head, findElement(head, data));
                if (prev != NULL) {
                    printf("Previous node: %d\n", prev->data);
                } else {
                    printf("No previous node\n");
                }
                break;
            case 7:
                printf("Enter node data: ");
                scanf("%d", &data);
                Node* last = findElement(head, data);
                if (isLast(last, head)) {
                    printf("Last node\n");
                } else {
                    printf("Not last node\n");
                }
                break;
            case 8:
                if (isEmpty(head)) {
                    printf("List is empty\n");
                } else {
                    printf("List is not empty\n");
                }
                break;
                  case 9:
                deleteFromBeginning(&head);
                break;
            case 10:
                printf("Enter node data: ");
                scanf("%d", &data);
                Node* delAfter = findElement(head, data);
                if (delAfter != NULL && delAfter->next != NULL) {
                    deleteAfter(delAfter);
                } else {
                    printf("No node to delete after\n");
                }
                break;
            case 11:
                deleteFromEnd(&head);
                break;
            case 12:
                deleteList(&head);
                break;
            case 13:
                display(head);
                break;
            case 14:
                exit(0);
            default:
                printf("Invalid choice\n");
                break;
        }
    }
    return 0;
}

