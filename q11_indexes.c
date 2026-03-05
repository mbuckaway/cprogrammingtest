#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline();



/*
 * Complete the 'getRemovableIndices' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. STRING str1
 *  2. STRING str2
 */

/**
 Let me help clarify the input format. For this problem, you'll be implementing a function `getRemovableIndices` that takes two parameters:

1.  `str1`: The first string (which is exactly one character longer than str2)
    
2.  `str2`: The second string
    

For example, if we have:

```markup

str1 = "aabbb"

str2 = "aabb"

```

The function should find which indices in str1 can be removed to make it equal to str2.
*/


/*
 * To return the integer array from the function, you should:
 *     - Store the size of the array to be returned in the result_count variable
 *     - Allocate the array statically or dynamically
 *
 * For example,
 * int* return_integer_array_using_static_allocation(int* result_count) {
 *     *result_count = 5;
 *
 *     static int a[5] = {1, 2, 3, 4, 5};
 *
 *     return a;
 * }
 *
 * int* return_integer_array_using_dynamic_allocation(int* result_count) {
 *     *result_count = 5;
 *
 *     int *a = malloc(5 * sizeof(int));
 *
 *     for (int i = 0; i < 5; i++) {
 *         *(a + i) = i + 1;
 *     }
 *
 *     return a;
 * }
 *
 * 3.  You need to handle the case when no valid indices are found (return \[-1\])
   4.  A better approach might be to:
*   Create a temporary string by copying str1
*   For each position i:
    *   Remove character at i (by shifting remaining characters)
    *   Compare with str2
    *   If equal, add i to result array
 */
int* getRemovableIndices(char* str1, char* str2, int* result_count) {
int* getRemovableIndices(char* str1, char* str2, int* result_count) {
    * result_count = 0;
    if ((str1 == NULL) && (str2 == NULL)) return NULL;
    if (result_count == NULL) return NULL;

    int str1len = strlen(str1);
    int str2len = strlen(str2);
    // str1 cannot be zero length
    if (str1len == 0) return NULL;
    // Covers if str2 is zero len because it must 1 longer than str1
    if (str1len != (str2len+1)) return NULL;

    int *resultarray = calloc(sizeof(int), str1len);

    // Scan the string to look for when the strings are not equal, and quit.
    char *str1cpy = NULL;
    strcpy(str1cpy, str1)
    for (int i = 1; i < str1len; i++) {
        // Check from 0 to i -1 and i+1 to strlen
        if ((strncmp(str1, str2, i) == 0) &&
            (strncmp(str1+(i+1), str2+i, str1len - (str1len - 1))))
        {
            resultarray[*result_count] = i;
            (*result_count) ++;
        }
    
    }
    return resultarray;
}

int main()
{
    char* str1 = readline();

    char* str2 = readline();

    int result_count;
    int* result = getRemovableIndices(str1, str2, &result_count);

    for (int i = 0; i < result_count; i++) {
        printf("%d", *(result + i));

        if (i != result_count - 1) {
            printf("\n");
        }
    }

    printf("\n");

    return 0;
}

char* readline() {
    size_t alloc_length = 1024;
    size_t data_length = 0;

    char* data = malloc(alloc_length);

    while (true) {
        char* cursor = data + data_length;
        char* line = fgets(cursor, alloc_length - data_length, stdin);

        if (!line) {
            break;
        }

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') {
            break;
        }

        alloc_length <<= 1;

        data = realloc(data, alloc_length);

        if (!data) {
            data = '\0';

            break;
        }
    }

    if (data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';

        data = realloc(data, data_length);

        if (!data) {
            data = '\0';
        }
    } else {
        data = realloc(data, data_length + 1);

        if (!data) {
            data = '\0';
        } else {
            data[data_length] = '\0';
        }
    }

    return data;
}
