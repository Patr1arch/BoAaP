#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "libs/heap-sort.c"
#include "libs/heap-sort-min.c"
#include "libs/hash_table.c"

void array_init(int* arr) {
    *(arr + 0) = 4;
    *(arr + 1) = 6;
    *(arr + 2) = 2;
    *(arr + 3) = 5;
    *(arr + 4) = 1;
    *(arr + 5) = 3;
}

void array_print(int* arr, int arr_lenght) {
    for (int i = 0; i <= arr_lenght; i++) {
        printf("%d\n", *(arr + i));
    }
    printf("\n\n\n");
}

void test_heaps() {
    int arr_size = 6;
    int arr_lenght = arr_size - 1;

    int* arr = (int *) malloc(sizeof(int) * arr_size);

    array_init(arr);
    array_print(arr, arr_lenght);

    max_heap_sort(arr, arr_lenght);

    array_print(arr, arr_lenght);

    min_heap_sort(arr, arr_lenght);

    array_print(arr, arr_lenght);

    free(arr);
}

void test_lists() {
    List* list = (List*) malloc(sizeof(List));
    bool res = find(list, 42);
    push(list, 42);
    push(list, 5);
    list_print(list);
    res = find(list, 42);

    int deb = pop(list);
    list_print(list);
    deb = pop(list);
    list_print(list);
}

void test_hash_table() {
    HashTable* table = init_hash_table(10);
    printf("%d\n", find_element(table, 42));
    add_element(table, 42);
    add_element(table, 52);
    add_element(table, 42);
    
    printf("%d\n", find_element(table, 42));
    list_print((table->array+2));

    delete_hash_table(table);
}

int main(int argc, char** argv) {
    test_heaps();

    test_lists();

    test_hash_table();

    return 0;
}