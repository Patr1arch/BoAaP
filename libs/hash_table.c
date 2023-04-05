#include "list.c"

typedef struct HashTable {
    List* array;
    int capacity;
} HashTable;

HashTable* init_hash_table(int capacity) {
    HashTable* table = (HashTable*) malloc(sizeof(HashTable));
    table->capacity = capacity;
    table->array = (List*) malloc(sizeof(List*) * capacity);
    return table;
}

void delete_hash_table(HashTable* hash_table) {
    free(hash_table->array);
    free(hash_table);
}

int hash(int key, HashTable* table) {
    return key % table->capacity;
}

bool find_element(HashTable* hash_table, int value) {
    bool res = find(hash_table->array + hash(value, hash_table), value);
    return res;
}

void add_element(HashTable* hash_table, int value) {
    if (find_element(hash_table, value)) {
        return;
    }
    List * ptr = (hash_table->array + hash(value, hash_table));
    push(ptr, value);
}

void delete_element(HashTable* hash_table, int value) {
    if (find_element(hash_table, value)) {
        List * ptr = (hash_table->array + hash(value, hash_table));
        pop(ptr);
    }
}


