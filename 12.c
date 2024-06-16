#include <stdio.h>
#include <stdlib.h>
#define TABLE_SIZE 10
#define LOAD_FACTOR_THRESHOLD 0.7
// Open Addressing - Linear Probing
void insertLinearProbing(int table[], int size, int key) {
    int hash = key % size;
    int originalHash = hash;
    while (table[hash] != -1) {
        hash = (hash + 1) % size;
        if (hash == originalHash) {
            printf("Table is full!\n");
            return;
        }
    }
    table[hash] = key;
}
int searchLinearProbing(int table[], int size, int key) {
    int hash = key % size;
    int originalHash = hash;
    while (table[hash] != -1) {
        if (table[hash] == key)
            return hash;
        hash = (hash + 1) % size;
        if (hash == originalHash)
            break;
    }
    return -1;
}

// Closed Addressing (Chaining)
typedef struct Node {
    int key;
    struct Node* next;
} Node;

void insertChaining(Node* table[], int size, int key) {
    int hash = key % size;
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->next = table[hash];
    table[hash] = newNode;
}
int searchChaining(Node* table[], int size, int key) {
    int hash = key % size;
    Node* temp = table[hash];
    while (temp) {
        if (temp->key == key)
            return hash;
        temp = temp->next;
    }	
    return -1;
}

// Rehashing
typedef struct {
    int* table;
    int size;
    int count;
} HashTable;

HashTable* createHashTable(int size) {
    HashTable* ht = (HashTable*)malloc(sizeof(HashTable));
    ht->table = (int*)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        ht->table[i] = -1;
    }
    ht->size = size;
    ht->count = 0;
    return ht;
}
void rehash(HashTable* ht) {
    int oldSize = ht->size;
    int* oldTable = ht->table;

    ht->size *= 2;
    ht->table = (int*)malloc(ht->size * sizeof(int));
    for (int i = 0; i < ht->size; i++) {
        ht->table[i] = -1;
    }
    ht->count = 0;

    for (int i = 0; i < oldSize; i++) {
        if (oldTable[i] != -1) {
            insertLinearProbing(ht->table, ht->size, oldTable[i]);
            ht->count++;
        }
    }
free(oldTable);
}

void insertRehashing(HashTable* ht, int key) {
    if ((float)ht->count / ht->size > LOAD_FACTOR_THRESHOLD) {
        rehash(ht);
    }
    insertLinearProbing(ht->table, ht->size, key);
    ht->count++;
}

int searchRehashing(HashTable* ht, int key) {
    return searchLinearProbing(ht->table, ht->size, key);
}


// Print functions
void printTable(int table[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", table[i]);
    }

    printf("\n");
}

void printChainingTable(Node* table[], int size) {
    for (int i = 0; i < size; i++) {
        printf("[%d] -> ", i);
        Node* temp = table[i];
        while (temp) {
            printf("%d -> ", temp->key);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}
// Main function
int main() {
    int choice, key, result;
    int table[TABLE_SIZE];
    for (int i = 0; i < TABLE_SIZE; i++) {
        table[i] = -1;
    }
    Node* chainingTable[TABLE_SIZE] = { NULL };

    HashTable* rehashingTable = createHashTable(TABLE_SIZE);
    printf("Choose collision resolution technique:\n");
    printf("1. Open Addressing (Linear Probing)\n");
    printf("2. Closed Addressing (Chaining)\n");
    printf("3. Rehashing\n");
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            printf("Open Addressing (Linear Probing):\n");
            insertLinearProbing(table, TABLE_SIZE, 10);
            insertLinearProbing(table, TABLE_SIZE, 20);
            insertLinearProbing(table, TABLE_SIZE, 30);
            printTable(table, TABLE_SIZE);
            result = searchLinearProbing(table, TABLE_SIZE, 20);
            printf("Key 20 found at index %d\n", result);
            break;
        case 2:
            printf("Closed Addressing (Chaining):\n");
            insertChaining(chainingTable, TABLE_SIZE, 10);
            insertChaining(chainingTable, TABLE_SIZE, 20);
            insertChaining(chainingTable, TABLE_SIZE, 30);
            printChainingTable(chainingTable, TABLE_SIZE);
            result = searchChaining(chainingTable, TABLE_SIZE, 20);
            printf("Key 20 found at index %d\n", result);
            break;
        case 3:
            printf("Rehashing:\n");
            insertRehashing(rehashingTable, 10);
            insertRehashing(rehashingTable, 20);
            insertRehashing(rehashingTable, 30);
            printTable(rehashingTable->table, rehashingTable->size);
            result = searchRehashing(rehashingTable, 20);
            printf("Key 20 found at index %d\n", result);
            break;
        default:
            printf("Invalid choice!\n");
            break;
    }

    return 0;
}


