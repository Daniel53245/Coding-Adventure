#include<stdio.h>
#include<stdlib.h>
#include<string.h>
// it is good enough
//return index of first occurence of needle in haystack
//return -1 if needle is not part of haystack
int strStr(char* haystack, char* needle) {
    for(int i=0;i<strlen(haystack);i++){
        int j=0;
        while(haystack[i+j]==needle[j]){
            j++;
            if(j==strlen(needle)){
                return i;
            }
        }
    }
    return -1;
}