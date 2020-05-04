/*************************************************************************
      > File Name: two-sum.c
      > Author: Xiaohui Jiang
      > Mail: jiang_xiaohui@163.com
      > Created Time: Sat Mar 14 11:13:50 2020
 ************************************************************************/
//https://leetcode-cn.com/problems/two-sum/

#include<stdio.h>
#include <stdlib.h>

/**
 *  * Note: The returned array must be malloced, assume caller calls free().
 *   */
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int *r = malloc(2 * sizeof(int));
    if(r == NULL) return r;
    *returnSize = 2;

    for (int i = 0; i < numsSize-1; i++ ){
        //if (nums[i] > target) continue; //removed incase  handle negative numbers
	for (int j = i + 1; j < numsSize; j++ ){
	    if (nums[i] + nums[j] == target){
	        r[0] = i;
		r[1] = j;
		return r;
	    }
	}
    }
no_result:
    free(r);
    return NULL;
}

void end_test(int* r, int rSize){
    if (r == NULL) {
	printf("no result!\n");
	return;
    }
    for (int i = 0; i < rSize; i++ ){
        printf("%d ", r[i]);
    }
    printf("\n");
    free(r);
}

int test1()
{
    int numsSize = 4;
    int nums[] = { 9, 11,0, 15};
    int target = 9;
    int rSize;
    int * r = NULL;

    r = twoSum(nums, numsSize, target, &rSize);

    end_test(r, rSize);
    return 0;
}

int test2()
{
    int numsSize = 4;
    int nums[] = { 2, 11,7, 5};
    int target = 9;
    int rSize;
    int * r = NULL;

    r = twoSum(nums, numsSize, target, &rSize);

    end_test(r, rSize);
    return 0;
}

int test3()
{
    int numsSize = 4;
    int nums[] = { -2, 11,-7, 15};
    int target = -9;
    int rSize;
    int * r = NULL;

    r = twoSum(nums, numsSize, target, &rSize);

    end_test(r, rSize);
    return 0;
}

int test4()
{
    int numsSize = 4;
    int nums[] = { 9, 11, -1, 15};
    int target = 8;
    int rSize;
    int * r = NULL;

    r = twoSum(nums, numsSize, target, &rSize);

    end_test(r, rSize);
    return 0;
}

int test5()
{
    int numsSize = 4;
    int nums[] = { 9, 11, -1, 15};
    int target = 100;
    int rSize;
    int * r = NULL;

    r = twoSum(nums, numsSize, target, &rSize);

    end_test(r, rSize);
    return 0;
}



int main()
{
    test1();
    test2();
    test3();
    test4();
    test5();
}
