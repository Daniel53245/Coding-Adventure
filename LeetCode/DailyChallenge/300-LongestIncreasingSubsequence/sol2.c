#include <stdio.h>
#include <stdlib.h>

int lengthOfLIS(int* nums, int numsSize) {

        //handle base case
        switch(numsSize){
                case 0:
                        return 0;
                case 1:
                        return 1;
                case 2:
                        return nums[0] < nums[1] ? 2 : 1;
        }
        
        //find the middel 
        int middel = numsSize / 2;

        //find the longest increasing subsequence that includes the middel
        //check if 2 elements meeting in the middel incresing
        int middel_length = 1;
        //check decremently to the left numSzie 3 middel 1
        printf("Chekking to left numsize:%d middel:%d\n",numsSize,middel);
        int dec_index = middel; //1
        while(dec_index-1 >= 0 && nums[dec_index] > nums[dec_index-1]){
                printf("left\n");
                middel_length++;
                dec_index--;
        }
        //check incermently to the right                        3       1
        printf("Chekking to right numsize:%d middel:%d\n",numsSize,middel);
        int inc_index = middel ; //1 size =3
                //breks here incindex = numSize
        while(inc_index+1 < numsSize && nums[inc_index] < nums[inc_index + 1]){
                printf("right");
                middel_length++;
                inc_index++;
        }
                printf("find %d on left and %d on right\n",dec_index,inc_index);

        //return the largest of the 3
        int left_length = lengthOfLIS(nums, middel);
        int right_length = lengthOfLIS(nums + middel, numsSize - middel);

        //print the lengths
                printf("numsSize:%d\n",numsSize);
        //print the array
        for(int i = 0; i < numsSize; i++){
                printf("%d ",nums[i]);
        }
        printf("\n");
        printf("left:%d right:%d middel:%d numsSize:%d\n", left_length, right_length, middel_length,numsSize);
        int ret = left_length;
        if(right_length > ret){
                ret = right_length;
        }
        if(middel_length > ret){
                ret = middel_length;
        }
        return ret;
}
