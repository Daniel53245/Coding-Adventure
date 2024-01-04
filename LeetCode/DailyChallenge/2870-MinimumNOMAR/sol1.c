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

//make a dictionary implementation
#define CAPACITY 10000
struct dict_node{
        int key;
        int value;
        struct dict_node *next;
};

struct dictionary{
        struct dict_node* head[CAPACITY];
};
int hash(int key){
        return key % CAPACITY;
}
void dict_init(struct dictionary* dict){
        for(int i = 0; i < CAPACITY; i++){
                dict->head[i] = NULL;
        }
}

void dict_increment(struct dictionary* dict, int key){
        //if key is not in the dictionary, add it
        //if key is in the dictionary, increment its value
        int index = hash(key);
        struct dict_node* node = dict->head[index];
        while(node != NULL){
                if(node->key == key){
                        node->value++;
                        return;
                }
                node = node->next;
        }
        //if key is not in the dictionary
        struct dict_node* new_node = (struct dict_node*)malloc(sizeof(struct dict_node));
        new_node->key = key;
        new_node->value = 1;
        new_node->next = dict->head[index];
        dict->head[index] = new_node;
}

int dic_read(struct dictionary* dict, int key){
        int index = hash(key);
        struct dict_node* node = dict->head[index];
        while(node != NULL){
                if(node->key == key){
                        return node->value;
                }
                node = node->next;
        }
        return 0;
}


int minOperations(int* nums, int numsSize){
        //crete a dictorynary
        struct dictionary* dict = (struct dictionary*)malloc(sizeof(struct dictionary));
        dict_init(dict);
        //count the occurence of each number
        int max = 0;
        for(int i = 0; i < numsSize; i++){
                dict_increment(dict, nums[i]);
                if(nums[i] > max) max = nums[i];
        }
        //find the minimal step to remove each number c
        int acc =0;
        for(int c = 1; c <= max; c++){
                int amount = dic_read(dict, c);
                if(amount == 0) continue;
                int min_op = minOp(amount);
                if(min_op == -1) return -1;
                acc += min_op;
        }
        return acc;
}

int main(){
        int nums[] = {1,1,2,2,2,3,3};
        int numsSize = 7;
        //test the minOperations
        int min_op = minOperations(nums, numsSize);
        printf("The minimal step is %d\n", min_op);
}