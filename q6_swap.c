#include <stdio.h>

/*
 * Q6 — Swap Two Variables Without a Temporary
 *
 * Provide two implementations:
 *   swap_xor       — using XOR
 *   swap_arithmetic — using addition/subtraction
 */
void swap_xor(int *a, int *b)
{
    /* TODO: implement this using XOR */
}

void swap_arithmetic(int *a, int *b)
{
    /* TODO: implement this using addition/subtraction */
}

int main(void)
{
    int pass = 0;
    int fail = 0;

    /* --- XOR swap tests --- */

    /* Test 1: basic swap */
    {
        int a = 5, b = 10;
        swap_xor(&a, &b);
        if (a == 10 && b == 5) {
            printf("PASS: xor swap(5,10) -> (%d,%d)\n", a, b);
            pass++;
        } else {
            printf("FAIL: xor swap(5,10) -> (%d,%d) (expected 10,5)\n", a, b);
            fail++;
        }
    }

    /* Test 2: negative numbers */
    {
        int a = -3, b = 7;
        swap_xor(&a, &b);
        if (a == 7 && b == -3) {
            printf("PASS: xor swap(-3,7) -> (%d,%d)\n", a, b);
            pass++;
        } else {
            printf("FAIL: xor swap(-3,7) -> (%d,%d) (expected 7,-3)\n", a, b);
            fail++;
        }
    }

    /* Test 3: zeros */
    {
        int a = 0, b = 42;
        swap_xor(&a, &b);
        if (a == 42 && b == 0) {
            printf("PASS: xor swap(0,42) -> (%d,%d)\n", a, b);
            pass++;
        } else {
            printf("FAIL: xor swap(0,42) -> (%d,%d) (expected 42,0)\n", a, b);
            fail++;
        }
    }

    /* --- Arithmetic swap tests --- */

    /* Test 4: basic swap */
    {
        int a = 5, b = 10;
        swap_arithmetic(&a, &b);
        if (a == 10 && b == 5) {
            printf("PASS: arith swap(5,10) -> (%d,%d)\n", a, b);
            pass++;
        } else {
            printf("FAIL: arith swap(5,10) -> (%d,%d) (expected 10,5)\n", a, b);
            fail++;
        }
    }

    /* Test 5: negative numbers */
    {
        int a = -3, b = 7;
        swap_arithmetic(&a, &b);
        if (a == 7 && b == -3) {
            printf("PASS: arith swap(-3,7) -> (%d,%d)\n", a, b);
            pass++;
        } else {
            printf("FAIL: arith swap(-3,7) -> (%d,%d) (expected 7,-3)\n", a, b);
            fail++;
        }
    }

    /* Test 6: zeros */
    {
        int a = 0, b = 42;
        swap_arithmetic(&a, &b);
        if (a == 42 && b == 0) {
            printf("PASS: arith swap(0,42) -> (%d,%d)\n", a, b);
            pass++;
        } else {
            printf("FAIL: arith swap(0,42) -> (%d,%d) (expected 42,0)\n", a, b);
            fail++;
        }
    }

    printf("\n%d passed, %d failed\n", pass, fail);
    return fail ? 1 : 0;
}
