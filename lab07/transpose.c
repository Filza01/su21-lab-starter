// Copyright [2023] <Filza Shahid>
#include "transpose.h"

/* The naive transpose function as a reference. */
void transpose_naive(int n, int blocksize, int *dst, int *src) {
    for (int x = 0; x < n; x++) {
        for (int y = 0; y < n; y++) {
            dst[y + x * n] = src[x + y * n];
        }
    }
}

/* Implement cache blocking below. You should NOT assume that n is a
 * multiple of the block size. */
void transpose_blocking(int n, int blocksize, int *dst, int *src) {
    // YOUR CODE HERE
    int x = 0, y = 0, i = 0, j = 0, k = 0;
    int c = n % blocksize;

    for (x = 0; x < (n-c); x += blocksize) {
        for (y = 0; y < (n-c); y += blocksize) {
            for (i = 0; i < blocksize; i++) {
                for (j = 0; j < blocksize; j++) {
                    dst[(j + i * n) + (y + x * n)] = src[(i + j * n) + (x + y * n)];
                }
            }
        }
    }

    if (c != 0) {
        for (x = (n-c); x < n; x++) {
            for (k = 0; k < n; k++) {
                dst[k + x * n] = src[x + k * n];
            }
        }
        for (y = (n-c); y < n; y++) {
            for (k = 0; k < n; k++) {
                dst[y + k * n] = src[k + y * n];
            }
        }
    }
}
