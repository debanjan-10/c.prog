#include<stdio.h>
#include<string.h>
struct student{
    int id;
    char name[50];
    int pin;
};
void swap(struct student *a, struct student *b){
    struct student temp=*a;
    *a=*b;
    *b=temp;
}
int partition(struct student arr[],int low, int high){
    int pivot=arr[high].pin;
    int i=low-1;
    for(int j=low;j<high;j++){
        if(arr[j].pin<pivot){
            i++;
            swap(&arr[i],&arr[j]);
        }
    }
    swap(&arr[i+1],&arr[high]);
    return i+1;
}
void quicksort(struct student arr[],int low,int high){
    if(low<high){
        int pi=partition(arr,low,high);
        quicksort(arr,low,pi-1);
        quicksort(arr,pi+1,high);
    }
}
int main(){
    int n,i;
    printf("enter no of students:");
    scanf("%d",&n);
    struct student s[n];
    for(i=0;i<n;i++){
        printf("enter %d student id",i+1);
        scanf("%d",&s[i].id);
        printf("enter %d student name",i+1);
        scanf("%s",&s[i].name);
        printf("enter %d student pin",i+1);
        scanf("%d",&s[i].pin);
    }
    quicksort(s,0,n-1);
    printf("student pins\n");
    for(i=0;i<n;i++){
        printf("id: %d\t name:%s\t pins:%d\n",s[i].id,s[i].name,s[i].pin);
    }
    return 0;
}