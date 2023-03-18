#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "libs/heap-sort.c"
#include "libs/list.c"

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

int main(int argc, char** argv) {
    //int arr_size = 6;
    //int arr_lenght = arr_size - 1;

    //int* arr = (int *) malloc(sizeof(int) * arr_size);

    //array_init(arr);
    //array_print(arr, arr_lenght);

    //heap_sort(arr, arr_lenght);

    //array_print(arr, arr_lenght);

    // for (int i = 0; i <= arr_lenght; i++) {
    //     free((arr + i));
    // }

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

    res = find(list, 42);

    return 0;
}