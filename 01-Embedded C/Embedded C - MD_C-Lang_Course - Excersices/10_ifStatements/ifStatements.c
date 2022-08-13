#include<stdlib.h>
#include<stdio.h>


int max(int num1, int num2){
    int result;
    if( num1 > num2){return num1;}
    else return num2;
}
 
int max3(int num1, int num2, int num3){
    if( num1 > num2 && num1 > num3){return num1;}
    else if (num2 >= num1 && num2 >= num3){return num2;}
    else return num3;
}

int main (){

    printf("The max is %d\n", max(40,19));
    printf("The mass is %d\n", max3(19,102,11));
    
    return 0;

}