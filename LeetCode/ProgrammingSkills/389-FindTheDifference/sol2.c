#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//hash set ? 
char findTheDifference(char* s,char* t){
        int s_count[26] = {};
        int t_count[26] = {};
        //zerofy the list
        for(int i = 0;i < 26;i++){
                s_count[i] = 0;
                t_count[i] = 0;
        }
        for(int i = 0;i < strlen(s);i++){
                s_count[s[i] - 'a']++;
        }
        for(int i = 0;i < strlen(t);i++){
                t_count[t[i] - 'a']++;
        }
        for(int i = 0;i < 26;i++){
                if(s_count[i] != t_count[i]){
                        return 'a' + i;
                }
        }
        printf("error");
        return 'a';
}

int main(){
        return 0;
}