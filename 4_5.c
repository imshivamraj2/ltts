#include <stdio.h>

struct Point {
    int x;
    int y;
};

void swapPoints(struct Point* p1, struct Point* p2) {
    // Swap the x values
    int temp = p1->x;
    p1->x = p2->x;
    p2->x = temp;

    // Swap the y values
    temp = p1->y;
    p1->y = p2->y;
    p2->y = temp;
}

int main() {
    struct Point point1, point2;

    // Read values for point1
    printf("Enter values for point1 (x y): ");
    scanf("%d %d", &(point1.x), &(point1.y));

    // Read values for point2
    printf("Enter values for point2 (x y): ");
    scanf("%d %d", &(point2.x), &(point2.y));

    printf("\nBefore swapping:\n");
    printf("point1: x = %d, y = %d\n", point1.x, point1.y);
    printf("point2: x = %d, y = %d\n", point2.x, point2.y);

    // Swap the fields of point1 and point2
    swapPoints(&point1, &point2);

    printf("\nAfter swapping:\n");
    printf("point1: x = %d, y = %d\n", point1.x, point1.y);
    printf("point2: x = %d, y = %d\n", point2.x, point2.y);

    return 0;
}
