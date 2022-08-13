#include<stdlib.h>
#include<stdio.h>

int main(){
    //intialize it right away
    int luckyNumbers [] = {1,2,3,4,5,6,7};
    luckyNumbers[1] = 200;
    printf("%d", luckyNumbers[1]);

    // leave it empty then assign
    double unluckyNumbers[10];
    unluckyNumbers[1] = 200;
    printf("%d", unluckyNumbers[1]);
    
    return 0;

}