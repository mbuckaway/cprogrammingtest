#include <stdio.h>
#include <stdint.h>

/*
 * Q8 — Count Set Bits (Hamming Weight)
 *
 * Return the number of 1-bits in an unsigned 32-bit integer.
 * Optimize using Brian Kernighan's trick: n & (n-1) clears the
 * lowest set bit, so loop iterations = number of set bits.
 */
int count_set_bits(uint32_t n)
{
    /* TODO: implement this */
    return -1;
}

int main(void)
{
    int pass = 0;
    int fail = 0;

    struct { uint32_t input; int expected; } tests[] = {
        { 0x00000000,  0 },
        { 0x00000001,  1 },
        { 0x00000003,  2 },   /* 0b11 */
        { 0x0000000F,  4 },   /* 0b1111 */
        { 0x000000FF,  8 },
        { 0xFFFFFFFF, 32 },
        { 0x80000000,  1 },   /* just the high bit */
        { 0x7FFFFFFF, 31 },   /* all but the high bit */
        { 0x00010000,  1 },
        { 0xAAAAAAAA, 16 },   /* alternating bits */
        { 0x55555555, 16 },   /* alternating bits (shifted) */
    };
    int n = sizeof(tests) / sizeof(tests[0]);

    for (int i = 0; i < n; i++) {
        int result = count_set_bits(tests[i].input);
        if (result == tests[i].expected) {
            printf("PASS: count_set_bits(0x%08X) = %d\n",
                   tests[i].input, result);
            pass++;
        } else {
            printf("FAIL: count_set_bits(0x%08X) = %d (expected %d)\n",
                   tests[i].input, result, tests[i].expected);
            fail++;
        }
    }

    printf("\n%d passed, %d failed\n", pass, fail);
    return fail ? 1 : 0;
}
