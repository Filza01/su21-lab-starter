// Copyright [2023] <Filza Shahid>

#include <stdio.h>

int odd_occurence(int a[], int n) {
    int x = a[0];
    for (int i = 1; i < n; i++) {
        x = x ^ a[i];
    }
    return x;
}

int main(int argc, char *argv[]) {
    int arr[] = {12, 12, 14, 90, 14, 14, 14};
    int size = sizeof(arr)/4;
    int odd_occur;
    printf("Given array is:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    odd_occur = odd_occurence(arr, size);
    printf("Odd occurring element is %d.\n", odd_occur);
    return 0;
}

