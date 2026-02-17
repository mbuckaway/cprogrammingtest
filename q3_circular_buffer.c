#include <stdio.h>

/*
 * Q3 — Circular Buffer (Ring Buffer)
 *
 * Implement a fixed-size circular buffer of integers.
 * cb_push returns 0 on success, -1 if full.
 * cb_pop  returns 0 on success, -1 if empty.
 * 
 * full is defined as head==tail and count = size
 * empty is defined as head==tail and count = 0
 * 
 * The buffer is circular. So, as data is pushed and popped, it may contain new data or not
 */
typedef struct {
    int *buffer;
    int head;
    int tail;
    int size;
    int count;
} CircularBuffer;

void cb_init(CircularBuffer *cb, int *backing_array, int size)
{
    /* TODO: implement this */
    cb->head = 0;
    cb->tail = 0;
    cb->size = size;
    cb->count = 0;
}

/**
 * Push an item onto the buffer checking for overruns
 * Returns 0 on success, -1 if full.
 * We increment the head and make sure it stays in bounds
 */
int cb_push(CircularBuffer *cb, int value)
{
    int isFull = 0;

    // Insert the data
    cb->buffer[cb->head] = value;
    // Adjust the head pointer
    cb->head++;

    // Check if the head pointer goes off the end, and reset it
    if (cb->head>=cb->size) {
            cb->head = 0;
    }

    /* Inc counter as we are adding one */
    cb->count++;

    /* Check if it now full, make sure count never exceeds size */
    if (cb->count > cb->size) {
        cb->count = cb->size;
    }

    if ((cb->head == cb->tail) && (cb->count = cb->size)) {
        isFull = -1;
    }

    return isFull;
}

int cb_pop(CircularBuffer *cb, int *out)
{
    /* TODO: implement this */
    return -1;
}

int main(void)
{
    int pass = 0;
    int fail = 0;
    int backing[4];
    CircularBuffer cb;
    int val;

    cb_init(&cb, backing, 4);

    /* Test 1: pop from empty buffer */
    if (cb_pop(&cb, &val) == -1) {
        printf("PASS: pop from empty returns -1\n");
        pass++;
    } else {
        printf("FAIL: pop from empty should return -1\n");
        fail++;
    }

    /* Test 2: push and pop single element */
    if (cb_push(&cb, 42) == 0) {
        printf("PASS: push 42 returns 0\n");
        pass++;
    } else {
        printf("FAIL: push 42 should return 0\n");
        fail++;
    }

    if (cb_pop(&cb, &val) == 0 && val == 42) {
        printf("PASS: pop returns 42\n");
        pass++;
    } else {
        printf("FAIL: pop should return 42 (got %d)\n", val);
        fail++;
    }

    /* Test 3: fill to capacity */
    cb_push(&cb, 10);
    cb_push(&cb, 20);
    cb_push(&cb, 30);
    cb_push(&cb, 40);
    if (cb_push(&cb, 50) == -1) {
        printf("PASS: push to full buffer returns -1\n");
        pass++;
    } else {
        printf("FAIL: push to full buffer should return -1\n");
        fail++;
    }

    /* Test 4: FIFO order */
    {
        int expected[] = { 10, 20, 30, 40 };
        int ok = 1;
        for (int i = 0; i < 4; i++) {
            cb_pop(&cb, &val);
            if (val != expected[i]) {
                printf("FAIL: expected %d, got %d at position %d\n",
                       expected[i], val, i);
                ok = 0;
                fail++;
                break;
            }
        }
        if (ok) {
            printf("PASS: FIFO order 10,20,30,40 correct\n");
            pass++;
        }
    }

    /* Test 5: wrap-around — push after partial pop */
    cb_init(&cb, backing, 4);
    cb_push(&cb, 1);
    cb_push(&cb, 2);
    cb_push(&cb, 3);
    cb_pop(&cb, &val);  /* pop 1 */
    cb_pop(&cb, &val);  /* pop 2 */
    cb_push(&cb, 4);
    cb_push(&cb, 5);
    /* buffer now has: 3, 4, 5 */
    {
        int expected[] = { 3, 4, 5 };
        int ok = 1;
        for (int i = 0; i < 3; i++) {
            cb_pop(&cb, &val);
            if (val != expected[i]) {
                printf("FAIL: wrap-around expected %d, got %d\n",
                       expected[i], val);
                ok = 0;
                fail++;
                break;
            }
        }
        if (ok) {
            printf("PASS: wrap-around order 3,4,5 correct\n");
            pass++;
        }
    }

    printf("\n%d passed, %d failed\n", pass, fail);
    return fail ? 1 : 0;
}
