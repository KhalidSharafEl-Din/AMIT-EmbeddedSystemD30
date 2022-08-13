#include<stdlib.h>
#include<stdio.h>

int main (){
    
    int luckyNumbvers[] = {4, 8, 15, 16, 23, 42};

    int i = 0; 
    for (i=0; i <= 5; i++){
        printf("%d  %d\n", i, luckyNumbvers[i] );
    }
    return 0 ;
    
}