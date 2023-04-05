#include "heap.c"

void min_heapify(int* arr, int i, int heap_size) {
    int l = left(i);
    int r = right(i);
    int least;

    if (l <= heap_size && *(arr + l) < *(arr + i)) {
        least = l;
    }
    else {
        least = i;
    }

    if (r <= heap_size && *(arr + r) < *(arr + least)) {
        least = r;
    }

    if (least != i) {
        swap((arr + i), (arr + least));
        min_heapify(arr, least, heap_size);
    }
}

void build_min_heap(int* arr, int arr_lenght) {
    int heap_size = arr_lenght;
    for (int i = arr_lenght; i >= 0; i--) {
        min_heapify(arr, i, heap_size);
    }
}

void min_heap_sort(int* arr, int arr_lenght) {
    build_min_heap(arr, arr_lenght);
    int heap_size = arr_lenght;
    for (int i = arr_lenght; i >= 1; i--) {
        swap(arr, (arr + i));
        min_heapify(arr, 0, --heap_size);
    }
}