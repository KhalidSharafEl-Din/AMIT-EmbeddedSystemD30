/*
==================================================================================
Author: Khalid Gamal Sharaf El-Din
Name: Assignment 05
Target: Array
==================================================================================
Description:
+ Ask the user to enter 5 numbers and store it in an array called arr_1 using for loop then : 
    - Print the following 
        * Print the 5 elements of arr_1
        * The Max number in arr_1 and its position in the array.
        * The Min number in arr_1 and its position in the array.
++ Sort elements of the arry in asending order 
==================================================================================
*/

#include<stdlib.h>
#include<stdio.h>

int main(int argc, char const *argv[])
{
    int arr_1 [5];
    int max = 0;
    int min = 2147483647;
    int maxPos, minPos; 

    // Taking the input from the user 
    printf("Please enter 5 numbers : ");
    for(int i = 0; i<5; i++){
        scanf("%d", arr_1+i);
    }

    // printing the input the elements of the array :
    for(int i = 0; i<5; i++){
        printf("%d\t", arr_1[i]);
        if(arr_1[i] > max) {max =arr_1[i]; maxPos = i;}   // Finding the max value and its position
        if(arr_1[i] < min) {min =arr_1[i]; minPos = i;}   // Finding the mix value and its position
    }
    printf("\nThe Max number is %d in position %d.", max, maxPos);
    printf("\nThe Min number is %d in position %d.", min, minPos);


    // +Point: Sorting the array ascending [bubble sort]
    int swapped =1;
    for(int i =0; i <5; i++){
        for(int j=0; j<5-i-1; j++){
            if(arr_1[j]>arr_1[j+1]){
                int temp = arr_1[j];
                arr_1[j]= arr_1[j+1];
                arr_1[j+1] = temp;
            }
        }
    }
    // Printing the array after sorting it
    printf("\nThe given numbers after sorting in an ascending order : ");
    for(int i = 0; i<5; i++){
        printf("%d\t", arr_1[i]);
    }

    return 0;
}
