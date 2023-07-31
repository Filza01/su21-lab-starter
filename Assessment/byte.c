// Copyright [2023] <Filza Shahid>

#include <stdio.h>
#include <string.h>

int mystrlen(char *str) {
    //int n = sizeof(str)-1;
    int count = 0;
    while(*str != '\0') {
        count++;
        str++;
    }
    return count;
}

int main(int argc, char *argv[]) {
    char my_str[] = "hello hello world.";
    printf("%s\n", my_str); 
    int size = mystrlen(my_str);
    printf("Size of the given string is %d bytes.\n", size);
    return 0;
}

