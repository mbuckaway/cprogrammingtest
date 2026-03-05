#include <stdio.h>

/*
 * Q15 — Top K Frequent Elements (No STL)
 *
 * Given an array of integers, return the k most frequent elements.
 * Uses a frequency count with parallel arrays and selection sort.
 */
int top_k_frequent(int *nums, int n, int k, int *result)
{
    /* TODO: implement this */
    (void)nums;
    (void)n;
    (void)k;
    (void)result;
    return 0;
}

int main(void)
{
    int pass = 0;
    int fail = 0;

    /* Test 1: [1,1,1,2,2,3] k=2 -> [1,2] */
    {
        int nums[] = {1, 1, 1, 2, 2, 3};
        int result[2];
        int count = top_k_frequent(nums, 6, 2, result);
        if (count == 2 && result[0] == 1 && result[1] == 2) {
            printf("PASS: [1,1,1,2,2,3] k=2 -> [%d,%d]\n", result[0], result[1]);
            pass++;
        } else {
            printf("FAIL: [1,1,1,2,2,3] k=2 -> [%d,%d] (expected [1,2])\n",
                   result[0], result[1]);
            fail++;
        }
    }

    /* Test 2: [1] k=1 -> [1] */
    {
        int nums[] = {1};
        int result[1];
        int count = top_k_frequent(nums, 1, 1, result);
        if (count == 1 && result[0] == 1) {
            printf("PASS: [1] k=1 -> [%d]\n", result[0]);
            pass++;
        } else {
            printf("FAIL: [1] k=1 -> [%d] (expected [1])\n", result[0]);
            fail++;
        }
    }

    /* Test 3: [4,4,4,3,3,2,2,1] k=3 -> [4,3,2] */
    {
        int nums[] = {4, 4, 4, 3, 3, 2, 2, 1};
        int result[3];
        int count = top_k_frequent(nums, 8, 3, result);
        if (count == 3 && result[0] == 4 && result[1] == 3 && result[2] == 2) {
            printf("PASS: [4,4,4,3,3,2,2,1] k=3 -> [%d,%d,%d]\n",
                   result[0], result[1], result[2]);
            pass++;
        } else {
            printf("FAIL: [4,4,4,3,3,2,2,1] k=3 -> [%d,%d,%d] (expected [4,3,2])\n",
                   result[0], result[1], result[2]);
            fail++;
        }
    }

    printf("\n%d passed, %d failed\n", pass, fail);
    return fail ? 1 : 0;
}
