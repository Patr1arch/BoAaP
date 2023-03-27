#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int value;
    struct Node *next;
} Node;

typedef struct List {
    Node *head;
} List;


void push(List* list, int data) {
    Node *tmp = (Node*) malloc(sizeof(Node));
    tmp->value = data;
    tmp->next = list->head;
    list->head = tmp;
}

int pop(List* list) {
    Node* prev = NULL;
    int val;
    if (list == NULL || list->head == NULL) {
        exit(-1);
    }
    prev = list->head;
    val = prev->value;
    list->head = list->head->next;
    free(prev);
    return val;
}

bool find(List* list, int value_find) {
    if (list == NULL || list->head == NULL) {
        return false;
    }

    Node* node = list->head;

    while(node != NULL) {
        if (node->value == value_find) {
            return true;
        }
        node = node->next;
    }

    return false;
}

void list_print(List* list) {
    if (list == NULL || list->head == NULL) {
        return;
    }

    Node* node = list->head;

    printf("-------------START OF LIST-------------\n");
    while(node != NULL) {
        printf("%d\n", node->value);
        node = node->next;
    }
    printf("-------------END OF LIST-------------\n");
}
int length (List *list)
{
    if((list == NULL) || (list->head == NULL)) return 0;
    int k = 0;
    Node *temp = list->head;
    while (temp != NULL)
    {
        k++;
        temp = temp->next;
    }
    return k;
}

Node* get_last(List* list) {
    if((list == NULL)||(list->head == NULL)) {
        return NULL;
    }
    Node *temp = list->head;
    while (temp->next != NULL){
        temp = temp->next;
    }
    return temp;
}
Node* get_nth(List* list, int pos){
    if((list == NULL) || (list->head == NULL) || (pos < 0)){
        return NULL;
    }
    if(pos > length(list))
}
void insert(List *list, int pos, int value){
    if ((pos <= 0) || (list == NULL)) {
        return;
    }
    if (list->head == NULL) {
       push(list, value);
       return;
    }

    Node *tmp = (Node *) malloc (sizeof(Node));
    tmp->value = value;
    int len = length(list);
    if (len < pos)
    {
        Node* last = get_last(list);
        last->next = tmp;
        tmp->next = NULL;
        return;
    }
    
}

