/* 
    Author : Khalid G. Sharaf El-Din 
    Description : An impelemation of a function that swaps 2 numbers using XOR.
*/
#include<stdlib.h>
#include<stdio.h>

void swap(int x,int y){
    
    // Printing the numbers before swaping 
    printf("Before Swaping : x = %d, y = %d\n",x,y);
    
    // Swaping using XOR
    x^=y;      // x == a xor b
    y^=x;      // y == b xor (a xor b) -> a
    x^=y;      // x == (a xor b) xor a -> b

    // Printing after swaping
    printf("After Swaping : x = %d, y = %d\n",x,y);

}

int main (int argc, char ** argv){

    // Taking the inputs from the user
    int x, y; 
    printf("Please enter a number : ");
    scanf("%d", &x);    
    printf("Please enter another number : ");
    scanf("%d", &y);   

    // Calling the function
    swap(x, y);

    return 0;
}