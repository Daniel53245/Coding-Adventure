#include<stdio.h>
#include<stdlib.h>

int fib(int n){
    if(n ==0 ){
        return 0;
    }
    if(n==1){
        return 1;
    }

    int* list = malloc(n*sizeof(int)+1);
    list[0] = 0;
    list[1] = 1;
    for(int i=2; i<=n; i++){
        list[i]= list[i-1] + list[i-2];
    }
    return list[n];
}

int main(){
        printf("%d\n",fib(100));
}