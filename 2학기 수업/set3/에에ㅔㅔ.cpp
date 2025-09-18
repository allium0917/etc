//five
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char name[50];
    int score;
} Student;

int main() {
    int n;

    scanf("%d", &n);

    Student *students = (Student *)malloc(n * sizeof(Student));

    if (students == NULL) {
        printf("메모리 할당에 실패했습니다.\n");
        return 1;
    }

    double total_score = 0.0;

    for (int i = 0; i < n; i++) {
        scanf("%s %d", students[i].name, &students[i].score);
        total_score += students[i].score;
    }

    double average = total_score / n;
    free(students);

    return 0;
}