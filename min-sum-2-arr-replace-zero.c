#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//minimum-equal-sum-of-two-arrays-after-replacing-zeros
// https://leetcode.com/problems/minimum-equal-sum-of-two-arrays-after-replacing-zeros/
// 2198 

long long minSum(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    long long sum1 = 0, sum2 = 0;
    int zCnt1 = 0, zCnt2 = 0;
    int max = 1000000;
    int diff = 0;
    long long minSum =0;
    long long diffMinSum = 0;
    struct data {
        int *arr;
        int len;
        long long sum;
        long long zCnt;
    };

    struct data greater, lesser;

    for (int i = 0;i < nums1Size; i ++)
    {
        sum1 += nums1[i];
        if ( nums1[i] == 0){
            zCnt1 ++;
            sum1++;
        }
    }
    for (int i = 0;i < nums2Size; i ++)
    {
        sum2 += nums2[i];
        if ( nums2[i] == 0){
            zCnt2 ++;
            sum2++;
        }
    }

    diff = abs(sum1 - sum2);
    if ( sum1 >= sum2){
        greater.arr = nums1;
        greater.len = nums1Size;
        greater.sum = sum1;
        greater.zCnt = zCnt1;

        lesser.arr = nums2;
        lesser.len = nums2Size;
        lesser.sum = sum2;
        lesser.zCnt = zCnt2;
    }
    else{
        greater.arr = nums2;
        greater.len = nums2Size;
        greater.sum = sum2;
        greater.zCnt = zCnt2;

        lesser.arr = nums1;
        lesser.len = nums1Size;
        lesser.sum = sum1;
        lesser.zCnt = zCnt1;
    }

    printf("diff : %d\n", diff);
    printf("zcnt1 : %d,  zcnt2 : %d\n", zCnt1, zCnt2);
    printf("sum1 : %lld, sum2 : %lld\n", sum1, sum2);
     
    if (zCnt1 == 0 && sum2 > sum1 )
        return -1;
    else if ( zCnt2 == 0 && sum1 > sum2)
        return -1;
    
        if ( diff == 0){
            return sum1;
        }

    minSum = greater.sum; // replace 0 with 1.
    // diffMinSum = minSum - lesser.sum - lesser.zCnt;

   
    // printf("minSum %d, diffMinSum %d\n", minSum, diffMinSum);
    // if ( diffMinSum < lesser.zCnt)
    //     return -1;

    return minSum;
}

int main() {
    int nums1[] = {0,0,10,10,12,0,13,6,0,2,10};
    int nums2[] = {24,5,12,22};
    int nums1Size = sizeof(nums1) / sizeof(nums1[0]);
    int nums2Size = sizeof(nums2) / sizeof(nums2[0]);
    long long result = minSum(nums1, nums1Size, nums2, nums2Size);
    printf("Result: %lld\n", result);
    return 0;
}
