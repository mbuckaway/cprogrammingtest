#include <stdio.h>
#include <string.h>

/*
 * Q10 — Rotate an Array by K Positions
 *
 * Rotate an integer array of size n to the right by k positions
 * IN PLACE with O(1) extra space.
 *
 * Hint: three-reverse trick.
 */
void rotate_array(int *arr, int n, int k)
{
    /* TODO: implement this */
}

static int arrays_equal(int *a, int *b, int n)
{
    return memcmp(a, b, n * sizeof(int)) == 0;
}

static void print_array(int *arr, int n)
{
    printf("[");
    for (int i = 0; i < n; i++) {
        if (i) printf(",");
        printf("%d", arr[i]);
    }
    printf("]");
}

int main(void)
{
    int pass = 0;
    int fail = 0;

    /* Test 1: basic rotation */
    {
        int arr[] = { 1, 2, 3, 4, 5 };
        int expected[] = { 4, 5, 1, 2, 3 };
        rotate_array(arr, 5, 2);
        if (arrays_equal(arr, expected, 5)) {
            printf("PASS: [1,2,3,4,5] k=2 -> ");
            print_array(arr, 5);
            printf("\n");
            pass++;
        } else {
            printf("FAIL: [1,2,3,4,5] k=2 -> ");
            print_array(arr, 5);
            printf(" (expected [4,5,1,2,3])\n");
            fail++;
        }
    }

    /* Test 2: k == 0 (no rotation) */
    {
        int arr[] = { 1, 2, 3 };
        int expected[] = { 1, 2, 3 };
        rotate_array(arr, 3, 0);
        if (arrays_equal(arr, expected, 3)) {
            printf("PASS: k=0 -> no change\n");
            pass++;
        } else {
            printf("FAIL: k=0 -> ");
            print_array(arr, 3);
            printf(" (expected [1,2,3])\n");
            fail++;
        }
    }

    /* Test 3: k == n (full rotation = no change) */
    {
        int arr[] = { 1, 2, 3 };
        int expected[] = { 1, 2, 3 };
        rotate_array(arr, 3, 3);
        if (arrays_equal(arr, expected, 3)) {
            printf("PASS: k=n -> no change\n");
            pass++;
        } else {
            printf("FAIL: k=n -> ");
            print_array(arr, 3);
            printf(" (expected [1,2,3])\n");
            fail++;
        }
    }

    /* Test 4: k > n (should handle modulo) */
    {
        int arr[] = { 1, 2, 3, 4, 5 };
        int expected[] = { 4, 5, 1, 2, 3 };
        rotate_array(arr, 5, 7);  /* 7 % 5 == 2 */
        if (arrays_equal(arr, expected, 5)) {
            printf("PASS: k=7 (k>n) -> ");
            print_array(arr, 5);
            printf("\n");
            pass++;
        } else {
            printf("FAIL: k=7 (k>n) -> ");
            print_array(arr, 5);
            printf(" (expected [4,5,1,2,3])\n");
            fail++;
        }
    }

    /* Test 5: single element */
    {
        int arr[] = { 42 };
        int expected[] = { 42 };
        rotate_array(arr, 1, 5);
        if (arrays_equal(arr, expected, 1)) {
            printf("PASS: single element -> no change\n");
            pass++;
        } else {
            printf("FAIL: single element -> ");
            print_array(arr, 1);
            printf("\n");
            fail++;
        }
    }

    /* Test 6: rotate by 1 */
    {
        int arr[] = { 1, 2, 3, 4 };
        int expected[] = { 4, 1, 2, 3 };
        rotate_array(arr, 4, 1);
        if (arrays_equal(arr, expected, 4)) {
            printf("PASS: [1,2,3,4] k=1 -> ");
            print_array(arr, 4);
            printf("\n");
            pass++;
        } else {
            printf("FAIL: [1,2,3,4] k=1 -> ");
            print_array(arr, 4);
            printf(" (expected [4,1,2,3])\n");
            fail++;
        }
    }

    printf("\n%d passed, %d failed\n", pass, fail);
    return fail ? 1 : 0;
}
