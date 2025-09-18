//fr
#include <stdio.h>
#include <math.h>

typedef struct {
    double x;
    double y;
} Point;

double getDistance(Point *p1, Point *p2) {
    return sqrt((p1->x - p2->x) * (p1->x - p2->x) +
                (p1->y - p2->y) * (p1->y - p2->y));
}

int main() {
    Point a, b;

    scanf("%lf %lf", &a.x, &a.y);
    scanf("%lf %lf", &b.x, &b.y);

    printf("%.2f\n", getDistance(&a, &b));

    return 0;
}
