#include <stdio.h>

/*
 * Q14 — Coin Change (Minimum Coins)
 *
 * Given an array of coin denominations and a target amount, return the
 * minimum number of coins needed to make the amount, or -1 if impossible.
 * Uses bottom-up dynamic programming with a dp[] array.
 */
int coin_change(int *coins, int n, int amount)
{
    /* TODO: implement this */
    (void)coins;
    (void)n;
    (void)amount;
    return 0;
}

int main(void)
{
    int pass = 0;
    int fail = 0;

    /* Test 1: coins=[1,5,11] amount=15 -> 3 (5+5+5) */
    {
        int coins[] = {1, 5, 11};
        int result = coin_change(coins, 3, 15);
        if (result == 3) {
            printf("PASS: coins=[1,5,11] amount=15 -> %d\n", result);
            pass++;
        } else {
            printf("FAIL: coins=[1,5,11] amount=15 -> %d (expected 3)\n", result);
            fail++;
        }
    }

    /* Test 2: coins=[2] amount=3 -> -1 (impossible) */
    {
        int coins[] = {2};
        int result = coin_change(coins, 1, 3);
        if (result == -1) {
            printf("PASS: coins=[2] amount=3 -> %d\n", result);
            pass++;
        } else {
            printf("FAIL: coins=[2] amount=3 -> %d (expected -1)\n", result);
            fail++;
        }
    }

    /* Test 3: coins=[1] amount=0 -> 0 */
    {
        int coins[] = {1};
        int result = coin_change(coins, 1, 0);
        if (result == 0) {
            printf("PASS: coins=[1] amount=0 -> %d\n", result);
            pass++;
        } else {
            printf("FAIL: coins=[1] amount=0 -> %d (expected 0)\n", result);
            fail++;
        }
    }

    /* Test 4: coins=[1,2,5] amount=11 -> 3 (5+5+1) */
    {
        int coins[] = {1, 2, 5};
        int result = coin_change(coins, 3, 11);
        if (result == 3) {
            printf("PASS: coins=[1,2,5] amount=11 -> %d\n", result);
            pass++;
        } else {
            printf("FAIL: coins=[1,2,5] amount=11 -> %d (expected 3)\n", result);
            fail++;
        }
    }

    printf("\n%d passed, %d failed\n", pass, fail);
    return fail ? 1 : 0;
}
