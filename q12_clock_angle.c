#include <stdio.h>
#include <math.h>

/*
 * Q12 — Clock Angle Problem
 *
 * Given integers h (0-23) and m (0-59), return the smaller angle
 * between the hour and minute hands of a 12-hour clock.
 * Output: floating-point degrees in range [0.0, 180.0].
 * Treat h=0 and h=12 as the same; h=13 as 1, etc.
 */
double clock_angle(int h, int m)
{
    h = h % 12;
    double hour_deg = h * 30.0 + m * 0.5;
    double min_deg = m * 6.0;
    double angle = fabs(hour_deg - min_deg);
    if (angle > 180.0)
        angle = 360.0 - angle;
    return angle;
}

int main(void)
{
    int pass = 0;
    int fail = 0;

    /* Test 1: 12:00 -> 0.00 */
    {
        double result = clock_angle(12, 0);
        if (fabs(result - 0.00) < 0.001) {
            printf("PASS: (12,0) -> %.2f\n", result);
            pass++;
        } else {
            printf("FAIL: (12,0) -> %.2f (expected 0.00)\n", result);
            fail++;
        }
    }

    /* Test 2: 3:00 -> 90.00 */
    {
        double result = clock_angle(3, 0);
        if (fabs(result - 90.00) < 0.001) {
            printf("PASS: (3,0) -> %.2f\n", result);
            pass++;
        } else {
            printf("FAIL: (3,0) -> %.2f (expected 90.00)\n", result);
            fail++;
        }
    }

    /* Test 3: 6:00 -> 180.00 */
    {
        double result = clock_angle(6, 0);
        if (fabs(result - 180.00) < 0.001) {
            printf("PASS: (6,0) -> %.2f\n", result);
            pass++;
        } else {
            printf("FAIL: (6,0) -> %.2f (expected 180.00)\n", result);
            fail++;
        }
    }

    /* Test 4: 3:30 -> 75.00 */
    {
        double result = clock_angle(3, 30);
        if (fabs(result - 75.00) < 0.001) {
            printf("PASS: (3,30) -> %.2f\n", result);
            pass++;
        } else {
            printf("FAIL: (3,30) -> %.2f (expected 75.00)\n", result);
            fail++;
        }
    }

    /* Test 5: 1:57 -> 76.50 */
    {
        double result = clock_angle(1, 57);
        if (fabs(result - 76.50) < 0.001) {
            printf("PASS: (1,57) -> %.2f\n", result);
            pass++;
        } else {
            printf("FAIL: (1,57) -> %.2f (expected 76.50)\n", result);
            fail++;
        }
    }

    /* Test 6: 0:00 same as 12:00 -> 0.00 */
    {
        double result = clock_angle(0, 0);
        if (fabs(result - 0.00) < 0.001) {
            printf("PASS: (0,0) -> %.2f\n", result);
            pass++;
        } else {
            printf("FAIL: (0,0) -> %.2f (expected 0.00)\n", result);
            fail++;
        }
    }

    /* Test 7: 13:00 same as 1:00 -> 30.00 */
    {
        double result = clock_angle(13, 0);
        if (fabs(result - 30.00) < 0.001) {
            printf("PASS: (13,0) -> %.2f\n", result);
            pass++;
        } else {
            printf("FAIL: (13,0) -> %.2f (expected 30.00)\n", result);
            fail++;
        }
    }

    printf("\n%d passed, %d failed\n", pass, fail);
    return fail ? 1 : 0;
}
