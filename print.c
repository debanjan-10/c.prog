#include <stdio.h>
int main(){
    int a=10;
    printf("the value of a is: %d\n", a);
    printf("the address of a is: %p\n",&a);
    printf("the size of a is: %d\n", sizeof(a));
    int *p=&a;
    printf("the value of p is: %p\n", p);
    return 0;
}