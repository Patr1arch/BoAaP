#pragma once    // Из-за того, что в heap-sort and heap-sort-min используется эта библиотека
                // необходимо сообщить компилятору, что эту библиотку подключаем только один раз

int parent(int i) {
    return i / 2;
}

int left(int i) {
    return 2 * i + 1;
}

int right(int i) {
    return 2 * i + 2;
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}