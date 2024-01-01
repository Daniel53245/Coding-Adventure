#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int climbStairs(int n) {
        int* sol = (int*) malloc(sizeof(int) * (n + 1));
        sol[0] = 1;
        sol[1] = 1;
        for(int i = 2;i <= n;i++){
                sol[i] = sol[i - 1] + sol[i - 2];
        }
        return sol[n];
}

int main(){
        printf("%d\n",climbStairs(2));
        printf("%d\n",climbStairs(45));
        return 0;
}