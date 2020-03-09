/*************************************************************************
      > File Name: unique-number-of-occurrences.c
      > Author: Xiaohui Jiang
      > Mail: jiang_xiaohui@163.com
      > Created Time: Sun Mar  8 17:49:35 2020
 ************************************************************************/
// https://leetcode-cn.com/problems/unique-number-of-occurrences/

#include<stdio.h>
#include <stdlib.h>

typedef enum { false, true }bool;

bool uniqueOccurrences(int* arr, int arrSize){
    int * count = malloc(sizeof(int) * arrSize);
    if (count == NULL) return false;
    //init counter
    for (int i = 0; i < arrSize; i++){
        count[i] = 1;
    }
    //sum counter of the same elements
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
    // check if there is equal counters
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

int main(){
	int arr1[] = {1,2,2,1,1,3,2,};
	int arr2[] = {1,2,2,1,1,3,1,};

	if (uniqueOccurrences(arr1, sizeof(arr1)/sizeof(int)))
		printf("Failed arr1\n");
	else
		printf("Passed arr1\n");

	if (uniqueOccurrences(arr2, sizeof(arr2)/sizeof(int)))
		printf("Passed arr2\n");
	else
		printf("Failed arr2\n");
}
