/*************************************************************************
        > File Name: unique-number-of-occurrences.c
      > Author: Xiaohui Jiang
      > Mail: jiang_xiaohui@163.com 
      > Created Time: Sun Mar  8 17:49:35 2020
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>

typedef enum { false, true }bool;

bool uniqueOccurrences(int* arr, int arrSize){
    int * count = malloc(sizeof(int) * arrSize);
    if (count == NULL) return false;

    for (int i = 0; i < arrSize; i++){
        count[i] = 1;
    }

    for (int i = 0; i < arrSize; i++){
        if (count[i] == 0) continue;

        for (int j = i+1; j < arrSize; j++){
            if (count[j] == 0) continue;
            if (arr[j] == arr[i]){
                count[i]++;
                count[j] = 0;
            }
        }
    }
    for (int i = 0; i < arrSize; i++){
        if (count[i] == 0) continue;

        for (int j = i+1; j < arrSize; j++){
            if (count[j] == 0) continue;
            if (count[j] == count[i]){
                return false;
            }
        }
    }
    return true;
}

int main ()
{
	int arr[] = {1,2,2,1,1,3,2,};
    if (uniqueOccurrences(arr, sizeof(arr)/sizeof(int)))
		printf("true\n");
	else
		printf("false\n");
}
