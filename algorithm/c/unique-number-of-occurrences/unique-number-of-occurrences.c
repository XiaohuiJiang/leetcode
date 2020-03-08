/*************************************************************************
      > File Name: unique-number-of-occurrences.c
      > Author: Xiaohui Jiang
      > Mail: jiang_xiaohui@163.com
      > Created Time: Sun Mar  8 17:49:35 2020
 ************************************************************************/
/*****************************************************************************************************
*	Given an array of integers arr, write a function that returns true if and only if the number of occurrences of each value in the array is unique.
*
*
*
*	Example 1:
*
*	Input: arr = [1,2,2,1,1,3]
*	Output: true
*	Explanation: The value 1 has 3 occurrences, 2 has 2 and 3 has 1. No two values have the same number of occurrences.
*	Example 2:
*
*	Input: arr = [1,2]
*	Output: false
*	Example 3:
*
*	Input: arr = [-3,0,1,-3,1,1,1,-3,10,0]
*	Output: true
*
*
*	Constraints:
*
*	1 <= arr.length <= 1000
*	-1000 <= arr[i] <= 1000
 ******************************************************************************************************/

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
