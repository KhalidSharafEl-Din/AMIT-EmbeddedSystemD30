#include <stdlib.h>
#include <stdio.h>

int main(){

    int age = 30;
    double gpa = 3.4;
    char grade = 'A';


    printf("%d, %p\n", age, &age);
    printf("%f, %p\n", gpa, &gpa);
    printf("%c, %p\n", grade, &grade);

    return 0;
}