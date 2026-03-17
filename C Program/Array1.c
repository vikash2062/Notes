#include<stdio.h>

int main(){
    int arr[5];
    int i;

    printf("Enter Element of the array\n");

    for(i=0;i<5;i++){
        scanf("%d",&arr[i]);
    }

    printf("contend of the array \n");
    for(i=0;i<5;i++){
        printf("%d\n",arr[i]);
    }
    return 0;
}