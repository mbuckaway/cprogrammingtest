#include <stdio.h>
#include <ctype.h>

/*
 * Q13 — Basic Calculator II
 *
 * Evaluate a string expression containing +, -, *, / and spaces.
 * No parentheses. Integer division truncates toward zero.
 * Uses a manual array-based stack (no STL).
 */
int calculate(const char *s)
{
    int stack[256];
    int top = 0;
    int num = 0;
    char op = '+';

    for (int i = 0; s[i] != '\0'; i++) {
        char c = s[i];

        if (isdigit(c)) {
            num = num * 10 + (c - '0');
        }

        if ((!isdigit(c) && c != ' ') || s[i + 1] == '\0') {
            switch (op) {
            case '+':
                stack[top++] = num;
                break;
            case '-':
                stack[top++] = -num;
                break;
            case '*':
                stack[top - 1] *= num;
                break;
            case '/':
                stack[top - 1] /= num;
                break;
            }
            op = c;
            num = 0;
        }
    }

    int result = 0;
    for (int i = 0; i < top; i++)
        result += stack[i];
    return result;
}

int main(void)
{
    int pass = 0;
    int fail = 0;

    /* Test 1: "3+2*2" -> 7 */
    {
        int result = calculate("3+2*2");
        if (result == 7) {
            printf("PASS: \"3+2*2\" -> %d\n", result);
            pass++;
        } else {
            printf("FAIL: \"3+2*2\" -> %d (expected 7)\n", result);
            fail++;
        }
    }

    /* Test 2: " 3/2 " -> 1 */
    {
        int result = calculate(" 3/2 ");
        if (result == 1) {
            printf("PASS: \" 3/2 \" -> %d\n", result);
            pass++;
        } else {
            printf("FAIL: \" 3/2 \" -> %d (expected 1)\n", result);
            fail++;
        }
    }

    /* Test 3: " 3+5 / 2 " -> 5 */
    {
        int result = calculate(" 3+5 / 2 ");
        if (result == 5) {
            printf("PASS: \" 3+5 / 2 \" -> %d\n", result);
            pass++;
        } else {
            printf("FAIL: \" 3+5 / 2 \" -> %d (expected 5)\n", result);
            fail++;
        }
    }

    /* Test 4: "14-3/2" -> 13 */
    {
        int result = calculate("14-3/2");
        if (result == 13) {
            printf("PASS: \"14-3/2\" -> %d\n", result);
            pass++;
        } else {
            printf("FAIL: \"14-3/2\" -> %d (expected 13)\n", result);
            fail++;
        }
    }

    /* Test 5: single number "42" -> 42 */
    {
        int result = calculate("42");
        if (result == 42) {
            printf("PASS: \"42\" -> %d\n", result);
            pass++;
        } else {
            printf("FAIL: \"42\" -> %d (expected 42)\n", result);
            fail++;
        }
    }

    printf("\n%d passed, %d failed\n", pass, fail);
    return fail ? 1 : 0;
}
