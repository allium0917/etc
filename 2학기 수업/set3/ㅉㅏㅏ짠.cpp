//1번~
#include <stdio.h>
#include <string.h>

#define MAX_LEN 50

typedef struct {
    char name[MAX_LEN];
    char phone[MAX_LEN];
} Person;

int main() {
    int N;
    scanf("%d", &N);

    Person people[N];

    for (int i = 0; i < N; i++) {
        scanf("%s %s", people[i].name, people[i].phone);
    }

    int Q;
    scanf("%d", &Q);

    char query[MAX_LEN];
    for (int q = 0; q < Q; q++) {
        scanf("%s", query);

        int found = 0;
        for (int i = 0; i < N; i++) {
            if (strcmp(people[i].name, query) == 0) {
                printf("%s\n", people[i].phone);
                found = 1;
                break;
            }
        }

        if (!found) {
            printf("Not found\n");
        }
    }

    return 0;
}
