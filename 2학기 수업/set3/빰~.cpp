//second
#include <stdio.h>

#define MAX_LEN 50

typedef struct {
    char name[MAX_LEN];
    int birthYear;
} Author;

typedef struct {
    char title[MAX_LEN];
    int price;
    Author author;
} Book;

int main() {
    Book b1, b2;

    scanf("%s", b1.title);
    scanf("%d", &b1.price);
    scanf("%s", b1.author.name);
    scanf("%d", &b1.author.birthYear);

    scanf("%s", b2.title);
    scanf("%d", &b2.price);
    scanf("%s", b2.author.name);
    scanf("%d", &b2.author.birthYear);

    Book cheaper = (b1.price < b2.price) ? b1 : b2;

    printf("%s ", cheaper.title);
    printf("%d ", cheaper.price );
    printf("%s ", cheaper.author.name );
    printf("%d", cheaper.author.birthYear);

    return 0;
}
