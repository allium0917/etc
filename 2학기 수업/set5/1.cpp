//1. 노드의 개수를 입력받고 연결리스트 생성, 데이터 입력받아서 저장, 정수 입력받고 입력 받은 수가 저장되어 있는 노드 위치 출력

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

int main() {
    int n, value, target;
    Node *head = NULL, *current = NULL, *temp = NULL;

    printf("노드 개수 입력: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        temp = (Node*)malloc(sizeof(Node));
        printf("%d", i + 1);
        scanf("%d", &value);
        temp->data = value;
        temp->next = NULL;

        if (head == NULL) {
            head = temp;
            current = temp;
        } else {
            current->next = temp;
            current = temp;
        }
    }

    scanf("%d", &target);

    current = head;
    int posi = 1;
    int found = 0;

    while (current != NULL) {
        if (current->data == target) {
            printf(" %d → %d번째\n", target, posi);
            found = 1;
            break;
        }
        current = current->next;
        posi++;
    }

    if (!found) {
        printf("%d \n", target);
    }

    current = head;
    while (current != NULL) {
        temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}