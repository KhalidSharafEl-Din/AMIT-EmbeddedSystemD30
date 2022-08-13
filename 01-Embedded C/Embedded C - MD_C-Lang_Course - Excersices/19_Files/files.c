#include <stdlib.h>
#include<stdio.h>

int main(){

    FILE * fpointer = fopen("employees.txt", "a" ); // r, w, a,

    fprintf(fpointer, "Kelly, Customer Service\n");

    fclose(fpointer);



    char line[255];

    FILE * fpointer2 = fopen("employees.txt", "r" ); // r, w, a,
    // First line
    fgets(line, 255, fpointer2);
    printf("%s", line);
    // Second line 
    fgets(line, 255, fpointer2);
    printf("%s", line);

    fclose(fpointer2);


    return 0;
}