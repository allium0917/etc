#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

int main() {
    Node* head = NULL;
    Node* temp = NULL;
    Node* p = NULL;
    int i, value, sum = 0;
    float avg;

    for (i = 0; i < 4; i++) {
        scanf("%d", &value);

        temp = (Node*)malloc(sizeof(Node));
        temp->data = value;
        temp->next = NULL;

        if (head == NULL) {
            head = temp;
            p = head;
        } else {
            p->next = temp;
            p = p->next;
        }

        sum += value;
    }

    avg = sum / 4.0;
    printf("%.2f\n", avg);

    return 0;
}
