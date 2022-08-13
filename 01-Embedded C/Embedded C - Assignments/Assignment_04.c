/*
==================================================================================
Author: Khalid Gamal Sharaf El-Din
Name: Assignment 04
Target: Pointers
==================================================================================
Description:
+ Ask the user to enter the value of int x.
+ Pass the address of x to a function called edit. 
+ increment the value of x by 1 inside the function. 
+ print the value of x in the main function before and after calling the function edit.
++ Store these numbers [5,20,80] inside x without over writing. then print them
==================================================================================
*/

#include<stdlib.h>
#include<stdio.h>


typedef struct num{
    int num1:8;
    int num2:8;
    int num3:8;
    int num4:8;
}num;


void edit(num* x){
    x->num1++;
}

int main(int argc, char const *argv[])
{
    
    num x; 
    x.num1=0;
    x.num2=5;
    x.num3=20;
    x.num4=80;

    // Taking the user input 
    int value =0; 
    printf("Enter the value of x \n");
    scanf("%d", &value);
    
    // Storing the user input in x 
    x.num1=value;

    // Printing the number before passing it to the function.
    printf("Before Calling edit x = %d\t",x.num1);
    printf("We also got theose numbers inside x [%d, %d, %d]\n", x.num2,x.num3,x.num4);

    //Call edit function
    edit(&x);

    // Printing the number after passing it ot the function.
    printf("After  Calling edit x = %d\t",x.num1);
    printf("Also the other numbbers inside x  are still present and intact [%d, %d, %d]\n", x.num2,x.num3,x.num4);

    return 0;
}
