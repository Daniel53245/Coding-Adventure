#include <stdio.h>

//cost = [10, 15, 20] cost of ithe step on the stair
int minCostClimbingStairs(int* cost, int costSize) {
        switch (costSize){
                case 0:
                        return 0;
                case 1:
                        return 0;
        }
        int list[costSize+1];
        list[0] = 0;
        list[1] = 0;
    for(int i = 2;i<costSize+1;i++){
        if((list[i-1]+cost[i-1]) < (list[i-2]+cost[i-2])){
                list[i] = list[i-1] + cost[i-1];
                printf("Climbing 1 step to stair %d\n",i);
        }else{
                list[i] = list[i-2] + cost[i-2];
                printf("Climbing 2 step to stair %d\n",i);
        }
            //climbing to stair n
            //climb(n) = climb(n-1) + cost(n-1) 
            //climb(n) = climb(n-2) + cost(n-2) 
    }
    return list[costSize];
}