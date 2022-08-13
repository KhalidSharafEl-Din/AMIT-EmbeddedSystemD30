#include <stdlib.h>
#include <stdio.h>

int main (){

    int age = 30; 
    int * pAge = &age;

    double gpa = 3.4;
    double *Gpa = &gpa;

    char grade = 'A';
    char *pGrade = &grade;

    printf("age's memory address: %p\n", pAge);
    // Derefrence the pointer 
    printf("%d", *pAge);
    return 0;
}