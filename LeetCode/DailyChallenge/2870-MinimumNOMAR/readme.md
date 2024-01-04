//you are given 0-indexed arry nums consisting of  positive ints
//2 types of operation you can apply on the arry any number of times
//1: choose 2 elements with equal values and delete them from the array
//2: choose 3 elements with equal values and delete them from the array
//returen the minimal numebr of operations needed to remove all elements from the array
//return -1 when it is impossible to clear the array
//1 <= nums.length <= 10^5
//1 <= nums[i] <= 10^9

The sol1.c uses a hashset implemntation and exceed in the running time, but uses load of memory

the sol2.c sorts the array first and the interate through it (should be faster) yet meets the time limit
might be the problem of recursive calll of sorting algorithnm