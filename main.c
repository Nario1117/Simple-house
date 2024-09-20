#include <stdio.h>
#include <stdlib.h>

bool static fanceMaker = false;

int drawRoof(int size) {
    for (int i = 0; i <= size; ++i) {
        for (int j = size - i; j >= 1; --j) {
            printf(" ");
        }
        for (int k = 0; k < i; ++k) {
            if (k == 0 || k == i - 1) {
                printf("* ");
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }
}

int drawWalls(int size, int height, int fenceLength) {
    for (int i = height - 2; i >= 1; --i) {
        printf("* ");
        for (int j = size - 2; j >= 1; --j) {
            if (fanceMaker) {
                printf("* ");
                fanceMaker = !fanceMaker;
            } else {
                printf("# ");
                fanceMaker = !fanceMaker;
            }
        }

        printf("* ");

        for (int i = 0; i < fenceLength; ++i) {
            printf("--|");
        }
        printf("\n");
        if (size % 2 == 0) {
            fanceMaker = !fanceMaker;
        }
    }
}

int drawFloor(int size, int fenceLength) {
    for (int i = 0; i < size; ++i) {
        printf("* ");
    }
    for (int i = 0; i < fenceLength; ++i) {
        printf("--|");
    }
    printf("\n");
}


int main(void) {
    printf("Tell me size of the house\n");
    int size;

    // int validInput = scanf("%f", &size);
    scanf("%d", &size);

    // printf("valid: <%d>",validInput);

    printf("Tell me the height of the house\n");
    int height;
    scanf("%d", &height);

    printf("Tell me the length of the fence\n");
    int fenceLength;
    scanf("%d", &fenceLength);
    if (size < 2) {
        exit(1);
    }

    drawRoof(size);
    drawFloor(size, 0);
    drawWalls(size, height, fenceLength);
    drawFloor(size, fenceLength);
    return 0;
}
