#include <stdio.h>
#include <limits.h>

/*
 * Q5 — Implement my_atoi
 *
 * Convert a string to an integer, handling:
 * - Leading whitespace
 * - Optional +/- sign
 * - Overflow (clamp to INT_MAX / INT_MIN)
 * - Stop at first non-digit character
 */
int my_atoi(const char *str)
{
    /* TODO: implement this */
    return 0;
}

int main(void)
{
    int pass = 0;
    int fail = 0;

    struct { const char *input; int expected; } tests[] = {
        { "42",              42 },
        { "   -42",          -42 },
        { "   -42abc",       -42 },
        { "4193 with words", 4193 },
        { "+1",              1 },
        { "   +0 123",       0 },
        { "",                0 },
        { "   ",             0 },
        { "words",           0 },
        { "-91283472332",    INT_MIN },   /* overflow negative */
        { "2147483647",      INT_MAX },   /* exact INT_MAX */
        { "2147483648",      INT_MAX },   /* overflow positive */
        { "-2147483648",     INT_MIN },   /* exact INT_MIN */
        { "0",               0 },
        { "-0",              0 },
        { "  0012",          12 },        /* leading zeros */
    };
    int n = sizeof(tests) / sizeof(tests[0]);

    for (int i = 0; i < n; i++) {
        int result = my_atoi(tests[i].input);
        if (result == tests[i].expected) {
            printf("PASS: my_atoi(\"%s\") = %d\n",
                   tests[i].input, result);
            pass++;
        } else {
            printf("FAIL: my_atoi(\"%s\") = %d (expected %d)\n",
                   tests[i].input, result, tests[i].expected);
            fail++;
        }
    }

    printf("\n%d passed, %d failed\n", pass, fail);
    return fail ? 1 : 0;
}
