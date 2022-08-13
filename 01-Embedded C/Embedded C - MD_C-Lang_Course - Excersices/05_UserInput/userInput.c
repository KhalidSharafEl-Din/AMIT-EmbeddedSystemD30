#include <stdlib.h>
#include <stdio.h>

int main (){
    
    // Integers 
    int userAge = 0;
    printf("Enter Your Age : \n");
    scanf("%d", &userAge);
    printf("You are %d years old !! \n", userAge);
    
    // Doubles
    double userGPA = 0;
    printf("Enter Your GPA : ");
    scanf("%lf", &userGPA);
    printf("and %f is your GPA !! \n", userGPA);
    
    // Characters 
    char userGrade = 'F';
    printf("Enter Your Grade : ");
    fflush(stdin);// This is require to flush the standard input from the previous inupt left because we will get the first char their and if we don't flush it will be a \n
    scanf("%c", &userGrade);
    printf("and %c is your Grade !! \n", userGrade);
    
    // C strings 
    char userName[20];
    printf("Enter Your Name : ");
    fflush(stdin);// This is require to flush the standard input from the previous inupt left because we will get the first char their and if we don't flush it will be a \n
    scanf("%s", userName); // with stings just need to give it the varibale not the address 
    printf("That's AWOSOME %s !! \n", userName);
    // The problem with scanf when inputing a string is that it only take input till it encounters a space character !! so we have fgets()
    
    // C strings with fgets()
    char userName2[20];
    printf("Sorry I didn't get your full name please enter it again : ");
    fflush(stdin);// This is require to flush the standard input from the previous inupt left because we will get the first char their and if we don't flush it will be a \n
    fgets(userName2, 20, stdin); // with stings just need to give it the varibale not the address 
    printf("It's my pleasure to meet you, %s !! \n", userName2);

    return 0;
}