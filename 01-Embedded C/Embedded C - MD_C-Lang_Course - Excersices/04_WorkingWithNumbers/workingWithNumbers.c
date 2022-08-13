#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main(){
    // We can do math also with variables 
    printf("%f\n", 5 + 4.5);
    printf("%f\n", 5 - 4.5);
    printf("%f\n", 5 * 4.5);
    printf("%f\n", 5 / 4.5);

    // Using fuctions 
    printf("%.2f\n", pow(10,2));
    printf("%.2f\n", sqrt(36));
    printf("%.2f\n", ceil(44.3));
    printf("%.2f\n", floor(10.123));

    // To know more about these functions just google "c math functions" 
    
    // This is a single line comment by the way, the compiler ignores this 

    /* 
        This is call a 
        multiline comment
     */

    // This is about Constants 
    const int NUM = 55;
    // now we can't change these !! we  generally give them all caps names to distenguish them ! 
    // Also a constant can be anytype of data
     
    return 0;
}