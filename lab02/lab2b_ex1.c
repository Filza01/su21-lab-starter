// Copyright [2023] <Filza Shahid>

#include <stdio.h>
#include <stdlib.h>
#define NAME_SIZE 20

struct student {
    char *name;
    int ID;
    int age;
};

int main(int argc, char *argv[]) {
    struct student std;
    std.name = ( char * )malloc(sizeof(char) * NAME_SIZE);
    printf("Enter student name: ");
    scanf("%[^\n]%*c", std.name);
    printf("Enter student ID: ");
    scanf("%d", &std.ID);
    printf("Enter student age: ");
    scanf("%d", &std.age);

    printf("Name of the student is %s.\n", std.name);
    printf("ID of the student is %d.\n", std.ID);
    printf("Age of the student is %d.\n", std.age);

    free(std.name);
    return 0;
}
