#include <stdio.h>
void preinpost(int n){
    if(n==0) return;
    printf("%d",n);
    preinpost(n-1);
    printf("%d",n);
    preinpost(n-1);
    printf("%d",n);
    // preinpost(n-1);
    return;

}
int main(){
    int n;
    printf("enter a number : ");
    scanf("%d",&n);
    preinpost(n);
    return 0;
}