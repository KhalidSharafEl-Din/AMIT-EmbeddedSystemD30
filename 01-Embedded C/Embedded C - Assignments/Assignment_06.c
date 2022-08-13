/*
==================================================================================
Author: Khalid Gamal Sharaf El-Din
Name: Assignment 06
Target: User Defined data types 
==================================================================================
Description:
+ Create a data base for 5 students in a school using array of struct, each struct contain 4 memebers : 
    - stuendt name
    - stundet age 
    - student degree 
    - stufent section 
+ Fill the data inside main function and print it 
++ Point : Fill all the data inside the main function and pass the address of the array to a void function called print.
==================================================================================
*/
#include<stdlib.h>
#include<stdio.h>
#include<string.h>

#define STRMAX 20
#define CLASSSIZE 5

struct student{

    char name[STRMAX];
    unsigned int age:8;
    unsigned int degree:8;
    unsigned int section:8; 

}group_1[CLASSSIZE];

typedef struct student student; 

void initStudebt(student* stu, char arr[], unsigned int age, unsigned int degree, unsigned int section); // Init the each student 
void printStudent(student* stu);        // Print Each studnet information
void print(student* stu, int size);     // print a whole array of studenta 

int main(int argc, char const *argv[])
{
    // Initalizing the students data base  
    initStudebt(&group_1[0], "Khalid", 24, 99, 30);
    initStudebt(&group_1[1], "Nihal" , 27, 95, 10);
    initStudebt(&group_1[2], "Nada"  , 20, 80, 20);
    initStudebt(&group_1[3], "Ahmed" , 16, 99, 32);
    initStudebt(&group_1[4], "Asmaa" , 25, 81, 31);

    // Printing the student data base  
    print(group_1, CLASSSIZE);              //+Point >> Printing using passing of address of the array to the function print
    
    return EXIT_SUCCESS;

}

void initStudebt(student* stu, char arr[], unsigned int age, unsigned int degree, unsigned int section){

    strncpy(stu->name, arr,STRMAX);  //Using strncpy instead of strcpy for safety reasons. 
    stu->age = age;
    stu->degree = degree;
    stu->section = section;
}

void printStudent(student* stu){
   
   printf("Name: %s\t\tAge: %d\t\tDegree: %d\t\tSection: %d\n", stu->name,stu->age,stu->degree,stu->section);
}

void print(student* stu, int size){

    // Looping in the array and print each student information on a new line 
    for(int i=0; i< size; i++){
        printf("Student[%d] ==> ", i+1);
        printStudent(stu+i);
    }

}