#include<stdio.h>
int count=0;
void tower(int n,char s,char h,char d){
    if(n==0) return;
    
    tower(n-1,s,d,h);
    printf("%c -> %c\n",s,d);
    count++;
    tower(n-1,h,s,d);
    return;

}
int main(){
    int n;
    printf("enter the number of disk : ");
    scanf("%d",&n);
    tower(n,'a','b','c');
    printf("%d",count);
    return 0;
}