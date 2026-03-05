#include <stdio.h>
#include <string.h>

/*
 * Q16 — Valid Parentheses
 *
 * Given a string containing '(', ')', '{', '}', '[', ']',
 * return 1 if the input string is valid, 0 otherwise.
 * Uses an array-based char stack.
 */
int is_valid(const char *s)
{
    char stack[256];
    int top = 0;
    int len = strlen(s);

    for (int i = 0; i < len; i++) {
        char c = s[i];
        if (c == '(' || c == '{' || c == '[') {
            stack[top++] = c;
        } else {
            if (top == 0)
                return 0;
            char open = stack[--top];
            if ((c == ')' && open != '(') ||
                (c == '}' && open != '{') ||
                (c == ']' && open != '['))
                return 0;
        }
    }
    return top == 0 ? 1 : 0;
}

int main(void)
{
    int pass = 0;
    int fail = 0;

    /* Test 1: "()->{}" -> 1 (using "()" since -> is not a bracket) */
    {
        int result = is_valid("(){}");
        if (result == 1) {
            printf("PASS: \"(){}\" -> %d\n", result);
            pass++;
        } else {
            printf("FAIL: \"(){}\" -> %d (expected 1)\n", result);
            fail++;
        }
    }

    /* Test 2: "([)]" -> 0 */
    {
        int result = is_valid("([)]");
        if (result == 0) {
            printf("PASS: \"([)]\" -> %d\n", result);
            pass++;
        } else {
            printf("FAIL: \"([)]\" -> %d (expected 0)\n", result);
            fail++;
        }
    }

    /* Test 3: "{[]}" -> 1 */
    {
        int result = is_valid("{[]}");
        if (result == 1) {
            printf("PASS: \"{[]}\" -> %d\n", result);
            pass++;
        } else {
            printf("FAIL: \"{[]}\" -> %d (expected 1)\n", result);
            fail++;
        }
    }

    /* Test 4: "" -> 1 (empty string is valid) */
    {
        int result = is_valid("");
        if (result == 1) {
            printf("PASS: \"\" -> %d\n", result);
            pass++;
        } else {
            printf("FAIL: \"\" -> %d (expected 1)\n", result);
            fail++;
        }
    }

    /* Test 5: "(" -> 0 (unclosed) */
    {
        int result = is_valid("(");
        if (result == 0) {
            printf("PASS: \"(\" -> %d\n", result);
            pass++;
        } else {
            printf("FAIL: \"(\" -> %d (expected 0)\n", result);
            fail++;
        }
    }

    /* Test 6: ")" -> 0 (no matching open) */
    {
        int result = is_valid(")");
        if (result == 0) {
            printf("PASS: \")\" -> %d\n", result);
            pass++;
        } else {
            printf("FAIL: \")\" -> %d (expected 0)\n", result);
            fail++;
        }
    }

    printf("\n%d passed, %d failed\n", pass, fail);
    return fail ? 1 : 0;
}
