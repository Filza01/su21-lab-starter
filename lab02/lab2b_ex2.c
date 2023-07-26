// Copyright [2023] <Filza Shahid>

#include <stdio.h>

static inline int no_of_CLA(int n) { return n;}

int main(int argc, char *argv[]) {
    printf("No. of Command Line arguments are %d\n.", no_of_CLA(argc));
    return 0;
}
