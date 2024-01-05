//sorting ?
//problem the initial posistion for the sequence
//find the best position begining
//linearly iterate the array
#include <stdio.h>
#include <stdlib.h>

typedef
struct node {
    int val;
    int position;
} node;

//algorithm for sorting node based on their value
void rand_quick_sort(node* list, int list_size){
        //pick a random pivot
        //swap the pivot with the last element
        //iterate through the list
        //if the element is less than the pivot swap it with the first element greater than the pivot
        //swap the pivot with the first element greater than the pivot
        //recurse on the two sublists
        //base case is when the list size is 1
        if(list_size == 0){
                return;
        }
        if(list_size == 1){
                return;
        }
        int pivot = rand() % list_size;
        node temp = list[pivot];
        list[pivot] = list[list_size - 1];
        list[list_size - 1] = temp;
        int i = 0;
        int j = 0;
        for(i = 0; i < list_size - 1; i++){
                if(list[i].val < list[list_size - 1].val){
                temp = list[i];
                list[i] = list[j];
                list[j] = temp;
                j++;
                }
        }
        temp = list[list_size - 1];
        list[list_size - 1] = list[j];
        list[j] = temp;
        rand_quick_sort(list, j);
        rand_quick_sort(list + j + 1, list_size - j - 1);
}

int lengthOfLIS(int* nums, int numsSize) {
        if(numsSize == 0){
                return 0;
        }
    //find the best position begining
    //keep trak of longes for each postiion
    //m^2
    //lieanrly interate array
    //creat a list of nodes for the nums keeping track of value andp osition
    struct node* list = malloc(sizeof(node) * numsSize);
    //log nuims into list
    for(int i=0; i < numsSize; i++){
            list[i].val = nums[i];
            list[i].position = i;
    }
    rand_quick_sort(list, numsSize);
    //print sorted array
        int i = 0;
        for(i = 0; i < numsSize; i++){
                printf("%d ", list[i].val);
        }
    //the listed is of nodes sorted in their vaslues
    
}