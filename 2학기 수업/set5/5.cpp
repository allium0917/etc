#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char data[100];
    struct Node* next;
} Node;

Node* createNode(const char* data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->data, data);
    newNode->next = NULL;
    return newNode;
}

void printList(Node* head) {
    Node* cur = head;
    while (cur != NULL) {
        printf("%s ", cur->data);
        cur = cur->next;
    }
    printf("\n");
}

void printReverse(Node* node) {
    if (node == NULL) return;
    printReverse(node->next);
    printf("%s ", node->data);
}

int main() {
    int n;
    scanf("%d", &n);

    Node* head = NULL;
    Node* tail = NULL;

    for (int i = 0; i < n; i++) {
        char str[100];
        scanf("%s", str);
        Node* newNode = createNode(str);
        if (head == NULL) head = tail = newNode;
        else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    printReverse(head);
    printf("\n");
    return 0;
}