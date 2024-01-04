//you are given 0-indexed arry nums consisting of  positive ints
//2 types of operation you can apply on the arry any number of times
//1: choose 2 elements with equal values and delete them from the array
//2: choose 3 elements with equal values and delete them from the array
//returen the minimal numebr of operations needed to remove all elements from the array
//return -1 when it is impossible to clear the array
//1 <= nums.length <= 10^5
//1 <= nums[i] <= 10^9
#include <stdio.h>
#include <stdlib.h>

int minOp(int amount){
        if(amount == 1) return -1;
        if(amount == 2) return 1;
        //each time we can decrease the amount by 3 or 2
        //find the lest time for reducing aount to 0
        int count = 0;
        switch(amount % 3){
                case 0:
                        return amount/3;
                        break;
                case 1:
                        return amount/3+1;
                        break;
                case 2:
                        return amount/3 + 1;
                        break;
        }
        return count;
}

void quick_sort(int*nums,int numSize){
        //quick sort
        if(numSize <= 1) return;
        int pivot = numSize/2;
        int pivot_val = nums[pivot];
        //swap pivot to the end
        int temp = nums[pivot];
        nums[pivot] = nums[numSize-1];
        nums[numSize-1] = temp;
        //partition
        int i = 0;
        int j = numSize - 2;
        while(i <= j){
                if(nums[i] <= pivot_val){
                        i++;
                        continue;
                }
                if(nums[j] > pivot_val){
                        j--;
                        continue;
                }
                //swap
                temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
                i++;
                j--;
        }
        //swap pivot back
        temp = nums[i];
        nums[i] = nums[numSize-1];
        nums[numSize-1] = temp;
        //recursively sort
        quick_sort(nums, i);
        quick_sort(nums+i+1, numSize-i-1);
}

void inplace_rand_quick_sort(int* nums,int numSize){
        //inplace random quick sort
        if(numSize <= 1) return;
        int pivot = rand() % numSize;
        int pivot_val = nums[pivot];
        //swap pivot to the end
        int temp = nums[pivot];
        nums[pivot] = nums[numSize-1];
        nums[numSize-1] = temp;
        //partition
        int i = 0;
        int j = numSize - 2;
        while(i <= j){
                if(nums[i] <= pivot_val){
                        i++;
                        continue;
                }
                if(nums[j] > pivot_val){
                        j--;
                        continue;
                }
                //swap
                temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
                i++;
                j--;
        }
        //swap pivot back
        temp = nums[i];
        nums[i] = nums[numSize-1];
        nums[numSize-1] = temp;
        //recursively sort
        inplace_rand_quick_sort(nums, i);
        inplace_rand_quick_sort(nums+i+1, numSize-i-1);

}


int minOperations(int* nums, int numsSize){
        //sorting 
        quick_sort(nums, numsSize);

        //count the number of each element
        int acc = 0;
        int current_num = nums[0];
        int current_index = 0;
        int num_count = 1;
        for(int i = 1; i < numsSize; i++){
                if(nums[i] == current_num){
                        num_count++;
                        continue;
                }
                //nums[i] != current_num
                int min_op = minOp(num_count);
                printf("Minimal step for eliminate %d is %d\n", current_num, min_op);
                if(min_op == -1) return -1;
                acc += min_op;
                current_num = nums[i];
                num_count = 1;
        }
        //slve the last = numSize ignore number
        int min_op = minOp(num_count);
        printf("Minimal step for eliminate %d is %d\n", current_num, min_op);
        if(min_op == -1) return -1;
        acc += min_op;
        return acc;
}

int main(){
        int nums[] = {1,1,2,2,2,3,3};
        int numsSize = 7;
        //test the sorting
        inplace_rand_quick_sort(nums, numsSize);
        for(int i = 0; i < numsSize; i++){
                printf("%d ", nums[i]);
        }
}