/* 
    Author : Khalid G. Sharaf El-Din 
    Description : A program that checks if the user input is EVEN or ODD and give back the proper responce.
*/
#include <stdlib.h>
#include <stdio.h>

// Prototypes :
int isEven(int num);

// Main function :
int main(int argc, char *argv[]){

    // Taking the input form the user 
    int userInput;
    printf("Enter a number : ");
    scanf("%d", &userInput);

    // Cheaking if it's Even or Odd and printing the proper response to the console.
    if(isEven(userInput)){
        printf("The number is odd  = 0\nThe number is Even = 1");
    } else {
        printf("The number is odd  = 1\nThe number is Even = 0"); 
    }

    return 0;
}

// Definitions :
int isEven(int num){
    return (((num/2)*2) == num); 
}
