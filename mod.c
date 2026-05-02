#include <stdio.h>
int main(){
    int a, b;
    printf("Enter two numbers:\n");
    scanf("%d %d", &a, &b);
    while(a%2 != 0 && b%2 != 0){
        printf("both numbers are odd.\n");
        break;
    }
    while(a%2 == 0 && b%2 == 0){
        printf("both numbers are even.\n");
        break;
    }
    if((a%2 == 0 && b%2 != 0) || (a%2 != 0 && b%2 == 0)){
        printf("one number is even and the other is odd.\n");
        printf("the odd number is %d.\n", (a%2 != 0) ? a : b);//condition ? value if true : value if false (syntax of ternary operator)
        printf("the even number is %d.\n", (a%2 == 0) ? a : b);
    }
    printf("the numbers are: (%d, %d)\n", a, b);
    return 0;
}