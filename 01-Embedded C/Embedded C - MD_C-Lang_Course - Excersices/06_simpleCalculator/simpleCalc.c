#include <stdlib.h>
#include <stdio.h>

int main(){
    
    double num1, num2;
    char op;
    // Get the first number 
    printf("Enter first number :");
    scanf("%lf", &num1);
    // Get the seocnd number 
    printf("Enter Second number :");
    scanf("%lf", &num2);
    // Get the opreator 
    printf("Entert the operation symblo :");
    fflush(stdin);
    scanf("%c", &op);

    switch(op){
        case '+':
            printf("%.2f + %.2f = %.2f\n", num1, num2, num1 + num2); break;

        case '-':
            printf("%.2f - %.2f = %.2f\n", num1, num2, num1 - num2); break;
        case '*':
            printf("%.2f * %.2f = %.2f\n", num1, num2, num1 * num2); break;
        case '/':
            printf("%.2f / %.2f = %.2f\n", num1, num2, num1 / num2); break;
        default :
            printf("Dude, come on you had one job and you fucked it up !! \n");
    }


    return 0;
}