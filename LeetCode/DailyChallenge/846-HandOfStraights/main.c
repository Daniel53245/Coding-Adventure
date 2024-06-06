#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main() {
    printf("Hello World\n");
}

/**
 * @brief decide if it is possible to regroup the cards in hand to consecutive groups
 * with size groupSize
 * 
 * @param hand int[handSize] the numbers on cards
 * @param handSize number of cards on hand
 * @param groupSize size of group after tidying
 * @return true if the arrange is possible
 * @return false if the arrange is not
 */
bool isNStraightHand(int* hand, int handSize, int groupSize) {
    if(handSize % groupSize != 0){
        return false;
    }
    //sorting the hand(get a better one if possibel)
    for(int i = 0; i < handSize; i++){
        for(int j = i + 1; j < handSize; j++){
            if(hand[i] > hand[j]){
                int temp = hand[i];
                hand[i] = hand[j];
                hand[j] = temp;
            }
        }
    }
    //counting the occurence of each number
    int* occurence = (int*)malloc(handSize * sizeof(int));
    int* number = (int*)malloc(handSize * sizeof(int));
    int occurenceSize = 0;
 



}
//note 
// the thing that mater is only the numebr where the consecutive groups start
// the basic algorithm may take 3*n*(erifycation time)
// 123 234 345 worst case for the algorithm 
// while looking for first group 
// log the things you see for next group

