#include<stdlib.h>

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

int dict_exist(struct dictionary* dict, int key){
        int index = hash(key);
        struct dict_node* node = dict->head[index];
        while(node != NULL){
                if(node->key == key){
                        return 1;
                }
                node = node->next;
        }
        return 0;
}

int deleteAndEarn(int* nums, int numsSize) {
    //pick any nums[i] and delete3 to earn nums[i] points
    //after you need to dele every element equal to nums[i] -1  and nums[i] + 1;
    //return the maximum possible points

    //picking num N and discarding N+1 and N-1
    //use hash set to log all appreance of N 
    //create dict
    struct dictionary dict;
    dict_init(&dict);
    //add count all number to the dict
    for(int i = 0; i < numsSize; i++){
        dict_increment(&dict, nums[i]);
    }
}