# C Programming Practice

**Format:** 1 hour, C language
**Domain:** Automotive infotainment / embedded systems

These 10 questions cover easy/medium difficulty algorithmic + systems-level C,
combined with common embedded-C and automotive software topics. Time targets
are included so you can simulate the 60-minute constraint.

---

## Q1 — Reverse a String In-Place (~5 min)

Write a function that reverses a null-terminated string **in place** (no extra
buffer, no library calls).

```c
void reverse_string(char *str);
```

**Example:**
```
Input:  "rivian"
Output: "naivir"
```

**Why this matters:** Pointer arithmetic, null-terminator awareness, and no
hidden `malloc`. This is a warm-up question that confirms you can think in C.

---

## Q2 — Check if a Number is a Power of 2 (~3 min)

Write a function that returns `1` if `n` is a power of 2, `0` otherwise.
Do it **without loops or division** — bitwise only.

```c
int is_power_of_two(unsigned int n);
```

**Hint:** `n & (n - 1)`

**Why this matters:** Bit manipulation is everyday work in embedded/infotainment
register programming. This tests whether you reach for bitwise tools naturally.

---

## Q3 — Circular Buffer (Ring Buffer) (~12 min)

Implement a fixed-size circular buffer of integers with these operations:

```c
typedef struct {
    int *buffer;
    int head;
    int tail;
    int size;
    int count;
} CircularBuffer;

void cb_init(CircularBuffer *cb, int *backing_array, int size);
int  cb_push(CircularBuffer *cb, int value);   // returns 0 on success, -1 if full
int  cb_pop(CircularBuffer *cb, int *out);      // returns 0 on success, -1 if empty
```

**Why this matters:** Circular buffers are the #1 data structure in audio/video
streaming pipelines inside infotainment systems.

---

## Q4 — Find the Single Non-Duplicate in an Array (~5 min)

Given an array where every element appears **twice** except one, find the unique
element. You must run in O(n) time and O(1) space.

```c
int find_single(int *arr, int n);
```

**Example:**
```
Input:  [2, 3, 5, 3, 2]
Output: 5
```

**Hint:** XOR all elements.

**Why this matters:** Tests bitwise thinking and
the ability to avoid brute-force hash maps in C.

---

## Q5 — Implement `my_atoi` (~8 min)

Write a function that converts a string to an integer, handling:
- Leading whitespace
- Optional `+` or `-` sign
- Overflow (clamp to `INT_MAX` / `INT_MIN`)
- Stop at first non-digit character

```c
int my_atoi(const char *str);
```

**Example:**
```
"   -42abc"  →  -42
"2147483648" →  2147483647  (clamped to INT_MAX)
```

**Why this matters:** String parsing is real infotainment work (parsing serial
protocols, AT commands, metadata tags).

---

## Q6 — Swap Two Variables Without a Temporary (~2 min)

Write a macro or function that swaps two integers without using a temp variable.

```c
void swap(int *a, int *b);
```

Provide **two** solutions: one with XOR, one with arithmetic.

**Why this matters:** Quick embedded-C literacy check. Be aware of the
pitfalls (e.g., XOR swap fails when `a == b` points to the same address).

---

## Q7 — Detect a Cycle in a Linked List (~8 min)

Given a singly-linked list, return `1` if it contains a cycle, `0` otherwise.
Use O(1) extra space.

```c
struct Node {
    int data;
    struct Node *next;
};

int has_cycle(struct Node *head);
```

**Hint:** Floyd's tortoise and hare algorithm.

**Why this matters:** Pointer manipulation + classic algorithm. Linked lists
appear in event queues and message routers inside infotainment middleware.

---

## Q8 — Count Set Bits (Hamming Weight) (~5 min)

Write a function that returns the number of `1` bits in an unsigned 32-bit
integer. Then optimize it beyond the naive loop.

```c
int count_set_bits(uint32_t n);
```

**Follow-up:** How would you use Brian Kernighan's trick (`n & (n-1)`) to make
it proportional to the number of set bits rather than 32 iterations?

**Why this matters:** Directly relevant to hardware register inspection in
automotive ECUs.

---

## Q9 — Implement a Simple `malloc`-Free String Tokenizer (~10 min)

Write a function that splits a string by a delimiter character, similar to
`strtok`, but **reentrant** (no static state). Return a pointer to the next
token and update a save pointer.

```c
char *my_strtok_r(char *str, char delim, char **saveptr);
```

**Example:**
```c
char input[] = "vol:75;bass:10;treble:5";
char *saveptr;
char *token = my_strtok_r(input, ';', &saveptr);
// token → "vol:75"
token = my_strtok_r(NULL, ';', &saveptr);
// token → "bass:10"
```

**Why this matters:** Infotainment systems parse semicolon/comma-delimited
config strings and serial protocol frames constantly. Reentrancy matters because
multiple threads (audio, nav, Bluetooth) may tokenize concurrently.

---

## Q10 — Rotate an Array by K Positions (~8 min)

Rotate an integer array of size `n` to the right by `k` positions **in place**
with O(1) extra space.

```c
void rotate_array(int *arr, int n, int k);
```

**Example:**
```
Input:  [1, 2, 3, 4, 5], k = 2
Output: [4, 5, 1, 2, 3]
```

**Hint:** Three-reverse trick — reverse the whole array, then reverse the first
`k` elements, then reverse the rest.

**Why this matters:** Array manipulation under tight memory constraints is a
recurring theme in embedded work.

---

## Study Tips

| Strategy | Detail |
|---|---|
| **Read all questions first** | Spend 2-3 min scanning. Do the easiest ones first to bank points. |
| **Watch for edge cases** | Empty strings, `NULL` pointers, zero-length arrays, overflow. |
| **Compile often** | Use a "Run" button if available. Test after every function — don't write everything then debug. |
| **Know your `#include`s** | `<stdint.h>` for `uint32_t`, `<limits.h>` for `INT_MAX`/`INT_MIN`, `<string.h>` for `strlen`. |
| **Bit tricks** | Memorize: `n & (n-1)` clears lowest set bit, `n & (-n)` isolates lowest set bit, `x ^ x == 0`. |
| **No `malloc` unless needed** | Prefer stack arrays and in-place algorithms. Less to debug in 60 minutes. |

---

## Sources

- [Top 50 C Coding Questions — GeeksforGeeks](https://www.geeksforgeeks.org/c/c-coding-interview-questions/)
- [Embedded C Questions — InterviewBit](https://www.interviewbit.com/embedded-c-interview-questions/)
- [C, Embedded & Automotive Questions — Automotive Embedded Info](https://automotiveembeddedsite.wordpress.com/c-embedded-automotive-interview-questions/)
- [HackerRank C Programming Domain](https://www.hackerrank.com/domains/c)
