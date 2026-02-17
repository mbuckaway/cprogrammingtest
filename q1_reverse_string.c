#include <stdio.h>
#include <string.h>

/*
 * Q1 — Reverse a String In-Place
 *
 * Reverse a null-terminated string in place.
 * No extra buffer, no library calls (strlen is OK for length).
 * Pointer arithmetic and swap only.
 */
void reverse_string(char *str)
{
    /* TODO: implement this */
}

int main(void)
{
    int pass = 0;
    int fail = 0;

    /* Test 1: normal string */
    {
        char s[] = "rivian";
        reverse_string(s);
        if (strcmp(s, "naivir") == 0) {
            printf("PASS: \"rivian\" -> \"%s\"\n", s);
            pass++;
        } else {
            printf("FAIL: \"rivian\" -> \"%s\" (expected \"naivir\")\n", s);
            fail++;
        }
    }

    /* Test 2: single character */
    {
        char s[] = "x";
        reverse_string(s);
        if (strcmp(s, "x") == 0) {
            printf("PASS: \"x\" -> \"%s\"\n", s);
            pass++;
        } else {
            printf("FAIL: \"x\" -> \"%s\" (expected \"x\")\n", s);
            fail++;
        }
    }

    /* Test 3: empty string */
    {
        char s[] = "";
        reverse_string(s);
        if (strcmp(s, "") == 0) {
            printf("PASS: \"\" -> \"%s\"\n", s);
            pass++;
        } else {
            printf("FAIL: \"\" -> \"%s\" (expected \"\")\n", s);
            fail++;
        }
    }

    /* Test 4: even-length string */
    {
        char s[] = "abcd";
        reverse_string(s);
        if (strcmp(s, "dcba") == 0) {
            printf("PASS: \"abcd\" -> \"%s\"\n", s);
            pass++;
        } else {
            printf("FAIL: \"abcd\" -> \"%s\" (expected \"dcba\")\n", s);
            fail++;
        }
    }

    /* Test 5: palindrome */
    {
        char s[] = "racecar";
        reverse_string(s);
        if (strcmp(s, "racecar") == 0) {
            printf("PASS: \"racecar\" -> \"%s\"\n", s);
            pass++;
        } else {
            printf("FAIL: \"racecar\" -> \"%s\" (expected \"racecar\")\n", s);
            fail++;
        }
    }

    printf("\n%d passed, %d failed\n", pass, fail);
    return fail ? 1 : 0;
}
