int rob(int* nums, int numsSize) {
        //nums is the worth of each thing you can grab
        //adjacent choose only one
        if(numsSize == 0)
                return 0;
        if(numsSize == 1)
                return nums[0];
        //base case 
        int list[numsSize+5];
        //the maximux you can get by robbing the first i houses
        //base case
        list[0] = nums[0];
        list[1] = (nums[1]>nums[0])?nums[1]:nums[0];
        for(int i = 2;i<numsSize;i++){
                if(list[i-1] >list[i-2] + nums[i] ){
                        //do not rob the new house
                        list[i] = list[i-1];
                        printf("Max %d houses,not rob house %d\n",i,i);
                }else{
                        //rob the new hous都
                        list[i] = list[i-2] + nums[i];
                        printf("Max %d houses, rob house %d\n",i,i);

                }
        }

        return list[numsSize-1];
}