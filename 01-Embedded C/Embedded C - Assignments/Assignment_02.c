/* 
    Author : Khalid G. Sharaf El-Din 
    Description : A simple calculator using a switch statement.
*/
#include<stdlib.h>
#include<stdio.h>

int main(int argc, char *argv[]){

    // Taking the user input : 
    double num_1, num_2;
    char operator;
    // Getting the first number
    printf("Enter a number : ");
    scanf("%lf", &num_1); 
    fflush(stdin);          // Flushing the input buffer to avoid picking up the line return as the operator.

    // Getting the operator
    printf("Enter the opertaion symbol [+,-,*,/] : ");
    scanf("%c", &operator);

    // Getting the second number
    printf("Enter another number : ");
    scanf("%lf", &num_2);

    // Swtich of the operator and print the correct reponse to the console.
    switch(operator){
        case '+':   // Addtion
            printf("%.2f + %.2f = %.2f\n", num_1, num_2, num_1 + num_2); break;
        case '-':   // Subtraction
            printf("%.2f - %.2f = %.2f\n", num_1, num_2, num_1 - num_2); break;
        case '*':   // Multiplication
            printf("%.2f * %.2f = %.2f\n", num_1, num_2, num_1 * num_2); break;
        case '/':   // Division
            printf("%.2f / %.2f = %.2f\n", num_1, num_2, num_1 / num_2); break;
        default:
            printf("Come on, just entr the right operator."); // Error if the user enter an invalid operator. 
    }

    return 0;


}