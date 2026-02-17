# C Programming Interview Practice — Rivian/VW Infotainment

**Format:** HackerRank, 1 hour, C language
**Domain:** Automotive infotainment / embedded systems team

These 10 questions are based on reported Rivian HackerRank interview patterns
(easy/medium difficulty, algorithmic + systems-level C), combined with common
embedded-C and automotive software interview topics. Time targets are included
so you can simulate the 60-minute constraint.

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

**Why they ask this:** Pointer arithmetic, null-terminator awareness, and no
hidden `malloc`. This is a warm-up question that confirms you can think in C.

---

## Q2 — Check if a Number is a Power of 2 (~3 min)

Write a function that returns `1` if `n` is a power of 2, `0` otherwise.
Do it **without loops or division** — bitwise only.

```c
int is_power_of_two(unsigned int n);
```

**Hint:** `n & (n - 1)`

**Why they ask this:** Bit manipulation is everyday work in embedded/infotainment
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

**Why they ask this:** Circular buffers are the #1 data structure in audio/video
streaming pipelines inside infotainment systems. Expect this or a variant.

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

**Why they ask this:** Classic HackerRank problem. Tests bitwise thinking and
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

**Why they ask this:** String parsing is real infotainment work (parsing serial
protocols, AT commands, metadata tags). Also a well-known HackerRank/LeetCode
medium.

---

## Q6 — Swap Two Variables Without a Temporary (~2 min)

Write a macro or function that swaps two integers without using a temp variable.

```c
void swap(int *a, int *b);
```

Provide **two** solutions: one with XOR, one with arithmetic.

**Why they ask this:** Quick embedded-C literacy check. They may also ask you to
explain the pitfalls (e.g., XOR swap fails when `a == b` points to the same
address).

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

**Why they ask this:** Pointer manipulation + classic algorithm. Linked lists
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

**Why they ask this:** Directly relevant to hardware register inspection in
automotive ECUs. Also a HackerRank staple.

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

**Why they ask this:** Infotainment systems parse semicolon/comma-delimited
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

**Why they ask this:** Array manipulation under tight memory constraints is a
recurring theme in embedded work. Also a common HackerRank medium.

---

## Study Tips for the 1-Hour HackerRank

| Strategy | Detail |
|---|---|
| **Read all questions first** | Spend 2-3 min scanning. Do the easiest ones first to bank points. |
| **Watch for edge cases** | Empty strings, `NULL` pointers, zero-length arrays, overflow. HackerRank auto-graders love these. |
| **Compile often** | HackerRank gives you a "Run" button. Use it after every function — don't write everything then debug. |
| **Know your `#include`s** | `<stdint.h>` for `uint32_t`, `<limits.h>` for `INT_MAX`/`INT_MIN`, `<string.h>` for `strlen`. |
| **Bit tricks** | Memorize: `n & (n-1)` clears lowest set bit, `n & (-n)` isolates lowest set bit, `x ^ x == 0`. |
| **No `malloc` unless needed** | Prefer stack arrays and in-place algorithms. Less to debug in 60 minutes. |

---

## How These Questions Map to Reported Rivian/RV Tech Interview Experiences

The following is compiled from Glassdoor, Jointaro, InterviewQuery, AlgoCademy,
Blind, and Prepfully reports for Rivian and the Rivian-VW joint venture
("Rivian and Volkswagen Group Technologies" / RV Tech).

### What candidates actually report

| Reported Topic | Source | Maps to |
| --- | --- | --- |
| "RTOS questions, then some coding questions in C" | Glassdoor — Embedded SW Engineer | Q3 (circular buffer), Q9 (reentrant tokenizer) |
| "Reversing an array" as a basic C coding question | Glassdoor — Embedded SW Engineer | **Q1** (reverse string) and **Q10** (rotate array) |
| LRU Cache (Medium) | Jointaro — Embedded SW Engineer, Aug 2025 | Q3 (similar struct + pointer bookkeeping) |
| Number of Islands (Medium, grid/graph) | Jointaro — Embedded SW Engineer | General graph/BFS — not in our 10 but worth studying |
| Rotate String (Easy) | Jointaro — Embedded SW Engineer | **Q10** (rotation concept) and **Q1** (string reversal) |
| "LeetCode Medium in a HackerRank environment" | Jointaro — Senior SW Engineer, Apr 2025 | Q5 (atoi), Q7 (cycle detection), Q10 (rotate) |
| String Palindromes (Easy) | InterviewQuery | Q1 variant (pointer walk from both ends) |
| Two-Sum / Target Indices (Medium) | InterviewQuery | Hash table or two-pointer — not in our 10 but common |
| Balanced Brackets (Easy) | InterviewQuery | Stack-based — good to know, simple in C |
| Fibonacci with recursion, iteration, memoization (Medium) | InterviewQuery | Tests recursion fundamentals (similar thinking to Q8 follow-up) |
| Matrix Multiplication (Medium) | InterviewQuery | Nested loops + pointer indexing — similar skills to Q10 |

### Interview format (from multiple Glassdoor reports)

1. **Recruiter screen** — 30 min, behavioral + motivation
2. **Hiring manager call** — 30-45 min, background + domain fit
3. **Technical coding round** — 45-60 min on HackerRank
   - Typically 2-3 problems, easy-to-medium difficulty
   - C or C++ expected for embedded roles
   - RTOS concepts asked verbally alongside the coding
4. **Panel / onsite** — Presentation + deeper coding + system design

### Key takeaways for your prep

- **Difficulty is easy/medium.** Nobody reported hard DP or advanced graph
  problems for embedded roles. The emphasis is on writing correct, clean C
  under time pressure.
- **RTOS verbal questions appear alongside coding.** Be ready to explain
  mutexes vs. semaphores, priority inversion, and interrupt-safe ring buffers
  even if they're not coded on HackerRank.
- **Pointer fluency is the differentiator.** Multiple reports mention
  interviewers watching how comfortably you use `*`, `&`, and `->`. Our Q1,
  Q3, Q7, and Q9 all exercise this heavily.
- **The interviewer may hint early.** One Glassdoor report noted the
  interviewer "assumed I didn't know the solutions and immediately provided
  hints." Don't let this throw you — engage with the hints and show your
  thought process.
- **Pass rate is low.** Glassdoor/Jointaro data shows Rivian embedded roles
  are "extremely selective." Practicing all 10 questions here under timed
  conditions gives you a real edge.

---

## Sources

- [Rivian Software Engineer Interview Questions — Glassdoor](https://www.glassdoor.com/Interview/Rivian-Software-Engineer-Interview-Questions-EI_IE630579.0,6_KO7,24.htm)
- [Top 30 Rivian LeetCode Interview Questions — VerveCopilot](https://www.vervecopilot.com/hot-blogs/rivian-leetcode-interview-questions)
- [Rivian Technical Interview Prep — AlgoCademy](https://algocademy.com/blog/rivian-technical-interview-prep-a-comprehensive-guide-for-success/)
- [Top 50 C Coding Interview Questions — GeeksforGeeks](https://www.geeksforgeeks.org/c/c-coding-interview-questions/)
- [Embedded C Interview Questions — InterviewBit](https://www.interviewbit.com/embedded-c-interview-questions/)
- [C, Embedded & Automotive Interview Questions — Automotive Embedded Info](https://automotiveembeddedsite.wordpress.com/c-embedded-automotive-interview-questions/)
- [HackerRank C Programming Domain](https://www.hackerrank.com/domains/c)
- [HackerRank Interview Preparation Kit](https://www.hackerrank.com/interview/interview-preparation-kit)
- [Rivian Embedded Software Engineer Interview — Glassdoor](https://www.glassdoor.com/Interview/Rivian-Embedded-Software-Engineer-Interview-Questions-EI_IE630579.0,6_KO7,33.htm)
- [RV Tech Embedded Software Engineer Interview — Glassdoor](https://www.glassdoor.com/Interview/Rivian-and-Volkswagen-Group-Technologies-Embedded-Software-Engineer-Interview-Questions-EI_IE10545926.0,40_KO41,67.htm)
- [Rivian Embedded SW Engineer Interview Experience — Jointaro](https://www.jointaro.com/interviews/companies/rivian/experiences/embedded-software-engineer-united-states-august-1-2025-no-offer-negative-5161100b/)
- [Rivian Software Engineer Interview Guide — InterviewQuery](https://www.interviewquery.com/interview-guides/rivian-software-engineer)
- [Rivian Interview Question Bank 2026 — Prepfully](https://prepfully.com/interview-questions/rivian)
