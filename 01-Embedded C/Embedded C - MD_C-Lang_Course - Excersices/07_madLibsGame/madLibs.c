#include<stdlib.h>
#include<stdio.h>

int main(){

    char color[20];
    char pluralNoun[20];
    char celebrity[20];

    printf("Enter a color : ");
    scanf("%s", color);

    printf("Enter a Plural noun : ");
    scanf("%s", pluralNoun);

    printf("Enter a Celebrity name : ");
    fflush(stdin);
    fgets(celebrity, 20, stdin);

    printf("Roses are %s\n", color);
    printf("%s are blue\n", pluralNoun);
    printf("I love %s\n", celebrity);
    return 0;
}