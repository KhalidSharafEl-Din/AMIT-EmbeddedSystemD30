#include<stdlib.h>
#include<stdio.h>

int main(){

    double num1, num2;
    char operator; 

    printf("Please enter a number :");
    scanf("%lf", &num1);

    printf("Please enter another number :");
    scanf("%lf", &num2);

    printf("Please enter the operation symbol:");
    fflush(stdin);
    scanf("%c", &operator);

    switch (operator)
    {
    case '+':
        printf("%.2f + %.2f = %.2f", num1, num2, num1+num2); break;
    case '-':
        printf("%.2f - %.2f = %.2f", num1, num2, num1-num2); break;
    case '*':
        printf("%.2f * %.2f = %.2f", num1, num2, num1*num2); break;
    case '/':
        printf("%.2f / %.2f = %.2f", num1, num2, num1/num2); break;
    case '%':
        printf("%.2f %% %.2f = %d", num1, num2, (int)num1%(int)num2); break;
    default:
        break;
    }
    return 0;
}