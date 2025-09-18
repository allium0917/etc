#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char name[50];
    int kor;
    int math;
    int eng;
    int total;
} Student;

int compare(const void *a, const void *b) {
    Student *s1 = (Student *)a;
    Student *s2 = (Student *)b;

    if (s1->total != s2->total) {
        return s2->total - s1->total;
    } else {
        return strcmp(s1->name, s2->name);
    }
}

int main() {
    int N;
    scanf("%d", &N);

    Student students[N];

    for (int i = 0; i < N; i++) {
        scanf("%s %d %d %d", students[i].name,
              &students[i].kor,
              &students[i].math,
              &students[i].eng);
        students[i].total = students[i].kor + students[i].math + students[i].eng;
    }

    qsort(students, N, sizeof(Student), compare);

    for (int i = 0; i < N; i++) {
        printf("%s %d %d %d\n",
               students[i].name,
               students[i].kor,
               students[i].math,
               students[i].eng);
    }

    return 0;
}
