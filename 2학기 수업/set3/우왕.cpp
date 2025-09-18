//third
#include <stdio.h>
#include <string.h>

typedef struct {
    int year;
    int month;
    int day;
} Date;

typedef struct {
    char name[50];
    int id;
    Date hireDate;
} Employee;

int compareDate(Date d1, Date d2) {
    if (d1.year != d2.year)
        return d1.year - d2.year;
    if (d1.month != d2.month)
        return d1.month - d2.month;
    return d1.day - d2.day;
}

int main() {
    Employee employees[3];
    for (int i = 0; i < 3; i++) {
        scanf("%s %d %d %d %d",
              employees[i].name,
              &employees[i].id,
              &employees[i].hireDate.year,
              &employees[i].hireDate.month,
              &employees[i].hireDate.day);
    }

    int oldestIndex = 0;
    for (int i = 1; i < 3; i++) {
        if (compareDate(employees[i].hireDate, employees[oldestIndex].hireDate) < 0) {
            oldestIndex = i;
        }
    }

    printf("%s %d %04d-%02d-%02d\n",
           employees[oldestIndex].name,
           employees[oldestIndex].id,
           employees[oldestIndex].hireDate.year,
           employees[oldestIndex].hireDate.month,
           employees[oldestIndex].hireDate.day);

    return 0;
}
