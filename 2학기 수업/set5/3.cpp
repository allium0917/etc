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

void insertFront(Node** head, const char* data) {
    Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

void insertMiddle(Node** head, const char* data) {
    // 길이 구하기
    int len = 0;
    Node* temp = *head;
    while (temp != NULL) {
        len++;
        temp = temp->next;
    }

    int mid = len / 2; // 정가운데
    if (mid == 0) {
        insertFront(head, data);
        return;
    }

    temp = *head;
    for (int i = 0; i < mid - 1; i++) temp = temp->next;

    Node* newNode = createNode(data);
    newNode->next = temp->next;
    temp->next = newNode;
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

    int cmd;
    printf("1: 앞, 2: 중 ");
    scanf("%d", &cmd);

    char data[100];
    scanf("%s", data);

    if (cmd == 1) insertFront(&head, data);
    else if (cmd == 2) insertMiddle(&head, data);
    else printf("잘못된 입력\n");

    printList(head);
    return 0;
}