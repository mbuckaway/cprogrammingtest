#include <stdio.h>

/*
 * Q4 — Find the Single Non-Duplicate in an Array
 *
 * Every element appears twice except one. Find it.
 * O(n) time, O(1) space.
 */
int find_single(int *arr, int n)
{
    /* TODO: implement this */
    return 0;
}

int main(void)
{
    int pass = 0;
    int fail = 0;

    /* Test 1 */
    {
        int arr[] = { 2, 3, 5, 3, 2 };
        int result = find_single(arr, 5);
        if (result == 5) {
            printf("PASS: [2,3,5,3,2] -> %d\n", result);
            pass++;
        } else {
            printf("FAIL: [2,3,5,3,2] -> %d (expected 5)\n", result);
            fail++;
        }
    }

    /* Test 2: single element */
    {
        int arr[] = { 99 };
        int result = find_single(arr, 1);
        if (result == 99) {
            printf("PASS: [99] -> %d\n", result);
            pass++;
        } else {
            printf("FAIL: [99] -> %d (expected 99)\n", result);
            fail++;
        }
    }

    /* Test 3: unique at the beginning */
    {
        int arr[] = { 7, 1, 1, 4, 4 };
        int result = find_single(arr, 5);
        if (result == 7) {
            printf("PASS: [7,1,1,4,4] -> %d\n", result);
            pass++;
        } else {
            printf("FAIL: [7,1,1,4,4] -> %d (expected 7)\n", result);
            fail++;
        }
    }

    /* Test 4: unique at the end */
    {
        int arr[] = { 1, 1, 2, 2, 3 };
        int result = find_single(arr, 5);
        if (result == 3) {
            printf("PASS: [1,1,2,2,3] -> %d\n", result);
            pass++;
        } else {
            printf("FAIL: [1,1,2,2,3] -> %d (expected 3)\n", result);
            fail++;
        }
    }

    /* Test 5: larger array */
    {
        int arr[] = { 10, 20, 10, 30, 20, 40, 30 };
        int result = find_single(arr, 7);
        if (result == 40) {
            printf("PASS: [10,20,10,30,20,40,30] -> %d\n", result);
            pass++;
        } else {
            printf("FAIL: [10,20,10,30,20,40,30] -> %d (expected 40)\n", result);
            fail++;
        }
    }

    printf("\n%d passed, %d failed\n", pass, fail);
    return fail ? 1 : 0;
}
