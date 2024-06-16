#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 10
#define LOAD_FACTOR_THRESHOLD 0.75

typedef struct {
    int key;
    int value;
    int is_occupied;
} HashItem;

typedef struct {
    HashItem* table;
    int size;
    int count;
} HashTable;

HashTable* create_table(int size) {
    HashTable* ht = (HashTable*) malloc(sizeof(HashTable));
    ht->size = size;
    ht->count = 0;
    ht->table = (HashItem*) malloc(size * sizeof(HashItem));
    for (int i = 0; i < size; i++) {
        ht->table[i].is_occupied = 0;
    }
    return ht;
}

unsigned int hash(int key, int size) {
    return key % size;
}

void insert(HashTable* ht, int key, int value) {
    if ((float)ht->count / ht->size > LOAD_FACTOR_THRESHOLD) {
        // Perform rehashing
    }

    int index = hash(key, ht->size);
    while (ht->table[index].is_occupied) {
        index = (index + 1) % ht->size; // Linear probing
    }
    ht->table[index].key = key;
    ht->table[index].value = value;
    ht->table[index].is_occupied = 1;
    ht->count++;
}

int search(HashTable* ht, int key) {
    int index = hash(key, ht->size);
    while (ht->table[index].is_occupied) {
        if (ht->table[index].key == key) {
            return ht->table[index].value;
        }
        index = (index + 1) % ht->size; // Linear probing
    }
    return -1; // Not found
}

void delete(HashTable* ht, int key) {
    int index = hash(key, ht->size);
    while (ht->table[index].is_occupied) {
        if (ht->table[index].key == key) {
            ht->table[index].is_occupied = 0;
            ht->count--;
            return;
        }
        index = (index + 1) % ht->size; // Linear probing
    }
}

void rehash(HashTable* ht) {
    int old_size = ht->size;
    HashItem* old_table = ht->table;

    ht->size *= 2;
    ht->count = 0;
    ht->table = (HashItem*) malloc(ht->size * sizeof(HashItem));
    for (int i = 0; i < ht->size; i++) {
        ht->table[i].is_occupied = 0;
    }

    for (int i = 0; i < old_size; i++) {
        if (old_table[i].is_occupied) {
            insert(ht, old_table[i].key, old_table[i].value);
        }
    }
    free(old_table);
}

int main() {
    HashTable* ht = create_table(TABLE_SIZE);
    insert(ht, 1, 10);
    insert(ht, 2, 20);
    insert(ht, 12, 30); // This will cause a collision and be resolved by linear probing

    printf("Search key 1: %d\n", search(ht, 1));
    printf("Search key 12: %d\n", search(ht, 12));

    delete(ht, 1);
    printf("Search key 1 after deletion: %d\n", search(ht, 1));

    free(ht->table);
    free(ht);
    return 0;
}
