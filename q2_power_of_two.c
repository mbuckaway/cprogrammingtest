#include <stdio.h>

/*
 * Q2 — Check if a Number is a Power of 2
 *
 * Return 1 if n is a power of 2, 0 otherwise.
 * Bitwise only — no loops or division.
 */
int is_power_of_two(unsigned int n)
{
    /* TODO: implement this */
    return -1;
}

int main(void)
{
    int pass = 0;
    int fail = 0;

    struct { unsigned int input; int expected; } tests[] = {
        {  0, 0 },
        {  1, 1 },
        {  2, 1 },
        {  3, 0 },
        {  4, 1 },
        {  5, 0 },
        { 16, 1 },
        { 18, 0 },
        { 64, 1 },
        { 1024, 1 },
        { 1023, 0 },
        { 2147483648U, 1 },  /* 2^31 */
    };
    int n = sizeof(tests) / sizeof(tests[0]);

    for (int i = 0; i < n; i++) {
        int result = is_power_of_two(tests[i].input);
        if (result == tests[i].expected) {
            printf("PASS: is_power_of_two(%u) = %d\n",
                   tests[i].input, result);
            pass++;
        } else {
            printf("FAIL: is_power_of_two(%u) = %d (expected %d)\n",
                   tests[i].input, result, tests[i].expected);
            fail++;
        }
    }

    printf("\n%d passed, %d failed\n", pass, fail);
    return fail ? 1 : 0;
}
