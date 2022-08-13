#include<stdlib.h>
#include<stdio.h>
 
// function prototype = only the function signture; 
// Returntype functionName(theArguments, ar1, ar2);

// A Void returtn type function with no paramters
void sayHi(){
    printf("Hi, would you like to be friends !");
}
// A void return type function with all by value paramters 
void sayHi2(char name[], int age){
    printf("Hello, %s you are %d years old ?.", name, age);
}

// Return statemets gives back information the one who called it. 
double cube(double num){
    return num * num * num;
} 
int main(){
    
    // Function call, where we can use them !!
    sayHi();
    sayHi2("Khalid", 24);
    printf("%f", cube(7.55));
    return 0;
} 