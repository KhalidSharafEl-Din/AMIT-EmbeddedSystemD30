#include<stdlib.h>
#include<stdio.h>
#include<string.h>

struct Student
{
    char name[50];
    char major[50];
    int age;
    double gpa;

};


int main(){

    struct Student student1;
    student1.age = 22;
    student1.gpa = 3.22;
    strcpy(student1.name, "Khalid Sharaf El-Din");
    strcpy(student1.major, "Electrical Engineering");

    printf("%s %s", student1.name, student1.major);
    return 0;
}