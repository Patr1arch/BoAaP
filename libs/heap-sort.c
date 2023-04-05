#include "heap.c"

void max_heapify(int* arr, int i, int heap_size) {
    int l = left(i);
    int r = right(i);
    int largest;

    if (l <= heap_size && *(arr + l) > *(arr + i)) {
        largest = l;
    }
    else {
        largest = i;
    }

    if (r <= heap_size && *(arr + r) > *(arr + largest)) {
        largest = r;
    }

    if (largest != i) {
        swap((arr + i), (arr + largest));
        max_heapify(arr, largest, heap_size);
    }
}

void build_max_heap(int* arr, int arr_lenght) {
    int heap_size = arr_lenght;
    for (int i = arr_lenght; i >= 0; i--) {
        max_heapify(arr, i, heap_size);
    }
}

void max_heap_sort(int* arr, int arr_lenght) {
    build_max_heap(arr, arr_lenght);
    int heap_size = arr_lenght;
    for (int i = arr_lenght; i >= 1; i--) {
        swap(arr, (arr + i));
        //heap_size = heap_size - 1;
        //max_heapify(arr, 0, heap_size);
        max_heapify(arr, 0, --heap_size);
    }
}