#include <stdio.h>
#include <string.h>

/*
 * Q9 — Implement a Simple malloc-Free String Tokenizer
 *
 * Like strtok_r: split a string by a delimiter character.
 * Reentrant — no static state. Returns pointer to next token,
 * updates saveptr. Returns NULL when no more tokens.
 *
 * On first call, pass the string in str. On subsequent calls,
 * pass NULL for str and the same saveptr.
 */
char *my_strtok_r(char *str, char delim, char **saveptr)
{
    /* TODO: implement this */
    return NULL;
}

int main(void)
{
    int pass = 0;
    int fail = 0;

    /* Test 1: semicolon-delimited config string */
    {
        char input[] = "vol:75;bass:10;treble:5";
        char *saveptr;
        char *tok;

        tok = my_strtok_r(input, ';', &saveptr);
        if (tok && strcmp(tok, "vol:75") == 0) {
            printf("PASS: token 1 = \"%s\"\n", tok);
            pass++;
        } else {
            printf("FAIL: token 1 = \"%s\" (expected \"vol:75\")\n",
                   tok ? tok : "(null)");
            fail++;
        }

        tok = my_strtok_r(NULL, ';', &saveptr);
        if (tok && strcmp(tok, "bass:10") == 0) {
            printf("PASS: token 2 = \"%s\"\n", tok);
            pass++;
        } else {
            printf("FAIL: token 2 = \"%s\" (expected \"bass:10\")\n",
                   tok ? tok : "(null)");
            fail++;
        }

        tok = my_strtok_r(NULL, ';', &saveptr);
        if (tok && strcmp(tok, "treble:5") == 0) {
            printf("PASS: token 3 = \"%s\"\n", tok);
            pass++;
        } else {
            printf("FAIL: token 3 = \"%s\" (expected \"treble:5\")\n",
                   tok ? tok : "(null)");
            fail++;
        }

        tok = my_strtok_r(NULL, ';', &saveptr);
        if (tok == NULL) {
            printf("PASS: token 4 = NULL (end of tokens)\n");
            pass++;
        } else {
            printf("FAIL: token 4 = \"%s\" (expected NULL)\n", tok);
            fail++;
        }
    }

    /* Test 2: comma-delimited with single token */
    {
        char input[] = "hello";
        char *saveptr;
        char *tok;

        tok = my_strtok_r(input, ',', &saveptr);
        if (tok && strcmp(tok, "hello") == 0) {
            printf("PASS: single token = \"%s\"\n", tok);
            pass++;
        } else {
            printf("FAIL: single token = \"%s\" (expected \"hello\")\n",
                   tok ? tok : "(null)");
            fail++;
        }

        tok = my_strtok_r(NULL, ',', &saveptr);
        if (tok == NULL) {
            printf("PASS: no more tokens\n");
            pass++;
        } else {
            printf("FAIL: expected NULL, got \"%s\"\n", tok);
            fail++;
        }
    }

    /* Test 3: empty string */
    {
        char input[] = "";
        char *saveptr;
        char *tok;

        tok = my_strtok_r(input, ';', &saveptr);
        if (tok == NULL) {
            printf("PASS: empty string -> NULL\n");
            pass++;
        } else {
            printf("FAIL: empty string -> \"%s\" (expected NULL)\n", tok);
            fail++;
        }
    }

    /* Test 4: two independent tokenizers running concurrently */
    {
        char input1[] = "a;b;c";
        char input2[] = "x,y";
        char *save1, *save2;

        char *t1 = my_strtok_r(input1, ';', &save1);
        char *t2 = my_strtok_r(input2, ',', &save2);

        int ok = 1;
        if (!t1 || strcmp(t1, "a") != 0) ok = 0;
        if (!t2 || strcmp(t2, "x") != 0) ok = 0;

        t1 = my_strtok_r(NULL, ';', &save1);
        t2 = my_strtok_r(NULL, ',', &save2);
        if (!t1 || strcmp(t1, "b") != 0) ok = 0;
        if (!t2 || strcmp(t2, "y") != 0) ok = 0;

        if (ok) {
            printf("PASS: two concurrent tokenizers work independently\n");
            pass++;
        } else {
            printf("FAIL: concurrent tokenizers interfered\n");
            fail++;
        }
    }

    printf("\n%d passed, %d failed\n", pass, fail);
    return fail ? 1 : 0;
}
