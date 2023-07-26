// Copyright [2023] <Filza Shahid>

#include <stdio.h>

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

int main(int argc, char *argv[]) {
    int x, y;

    printf("Enter 1st no.: ");
    scanf("%d", &x);
    printf("Enter 2nd no.: ");
    scanf("%d", &y);

    printf("Before swapping: x = %d, y = %d\n", x, y);

    swap(&x, &y);

    printf("After swapping: x = %d, y = %d\n", x, y);

    return 0;
}

