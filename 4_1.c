#include <stdio.h>

struct Box {
    float length;
    float width;
    float height;
};

void calculateVolumeAndSurfaceArea(struct Box* box) {
    float volume = box->length * box->width * box->height;
    float surfaceArea = 2 * ((box->length * box->width) + (box->length * box->height) + (box->width * box->height));

    printf("Volume: %.2f\n", volume);
    printf("Surface Area: %.2f\n", surfaceArea);
}

int main() {
    struct Box myBox;
    struct Box* boxPtr;

    boxPtr = &myBox;

    printf("Enter the dimensions of the box:\n");
    printf("Length: ");
    scanf("%f", &(boxPtr->length));
    printf("Width: ");
    scanf("%f", &(boxPtr->width));
    printf("Height: ");
    scanf("%f", &(boxPtr->height));

    printf("\nUsing (*) Asterisk and (.) Dot Operators:\n");
    calculateVolumeAndSurfaceArea(&myBox);

    printf("\nUsing (->) Arrow Operator:\n");
    calculateVolumeAndSurfaceArea(boxPtr);

    return 0;
}
