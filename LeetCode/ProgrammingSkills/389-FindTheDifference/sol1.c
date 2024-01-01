#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//94.47 memory 
//5.02 speed
//slow ? looped the string for each character, loop the string once and count each character

int character_count(char* str,char target){
        int count = 0;
        for(int i = 0;i < strlen(str);i++){
                if(str[i] == target){
                        count++;
                }
        }
        return count;
}

char findTheDifference(char* s,char* t){
        //for each char in alphabet count
        for(int i = 0;i < 26;i++){
                char target = 'a' + i;
                int s_count = character_count(s,target);
                int t_count = character_count(t,target);
                if(s_count != t_count){
                        return target;
                }
        }
        return 'a';
}

int main(){
        return 0;
}