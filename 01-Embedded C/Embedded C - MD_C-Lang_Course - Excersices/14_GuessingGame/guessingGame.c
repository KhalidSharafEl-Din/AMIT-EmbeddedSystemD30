#include<stdlib.h>
#include<stdio.h>

int main(){

    int secretNum =5; 
    int guess;
    int guessCount = 0;
    int guessLimit = 5;
    int outOFGuesses = 0; 

    while(secretNum != guess && outOFGuesses == 0)
    {
        if(guessCount < guessLimit ){
            printf("Please enter a number :");
            scanf("%d", &guess);  
        }else{
            outOFGuesses = 1;
        }
        guessCount++;
    }

    if (outOFGuesses == 1 ){printf("You Lost!!");}
    else {printf("Hey, You win!!");}
    return 0; 
}