#include <stdio.h>
#include <stdlib.h>

/*
 * Q7 — Detect a Cycle in a Linked List
 *
 * Return 1 if the list contains a cycle, 0 otherwise.
 * O(1) extra space. (Floyd's tortoise and hare.)
 */
struct Node {
    int data;
    struct Node *next;
};

int has_cycle(struct Node *head)
{
    /* TODO: implement this */
    return 0;
}

/* Helper: allocate a node (used by tests only) */
static struct Node *make_node(int data)
{
    struct Node *n = malloc(sizeof(struct Node));
    n->data = data;
    n->next = NULL;
    return n;
}

int main(void)
{
    int pass = 0;
    int fail = 0;

    /* Test 1: NULL list — no cycle */
    {
        if (has_cycle(NULL) == 0) {
            printf("PASS: NULL list -> no cycle\n");
            pass++;
        } else {
            printf("FAIL: NULL list should have no cycle\n");
            fail++;
        }
    }

    /* Test 2: single node, no cycle */
    {
        struct Node *a = make_node(1);
        if (has_cycle(a) == 0) {
            printf("PASS: single node -> no cycle\n");
            pass++;
        } else {
            printf("FAIL: single node should have no cycle\n");
            fail++;
        }
        free(a);
    }

    /* Test 3: three nodes, no cycle */
    {
        struct Node *a = make_node(1);
        struct Node *b = make_node(2);
        struct Node *c = make_node(3);
        a->next = b;
        b->next = c;
        if (has_cycle(a) == 0) {
            printf("PASS: 1->2->3->NULL -> no cycle\n");
            pass++;
        } else {
            printf("FAIL: 1->2->3->NULL should have no cycle\n");
            fail++;
        }
        free(a); free(b); free(c);
    }

    /* Test 4: cycle back to head */
    {
        struct Node *a = make_node(1);
        struct Node *b = make_node(2);
        struct Node *c = make_node(3);
        a->next = b;
        b->next = c;
        c->next = a;  /* cycle */
        if (has_cycle(a) == 1) {
            printf("PASS: 1->2->3->1 -> cycle detected\n");
            pass++;
        } else {
            printf("FAIL: 1->2->3->1 should detect cycle\n");
            fail++;
        }
        /* don't free cyclic list nodes individually — OK for a test */
        c->next = NULL;
        free(a); free(b); free(c);
    }

    /* Test 5: cycle in the middle */
    {
        struct Node *a = make_node(1);
        struct Node *b = make_node(2);
        struct Node *c = make_node(3);
        struct Node *d = make_node(4);
        a->next = b;
        b->next = c;
        c->next = d;
        d->next = b;  /* cycle: d -> b */
        if (has_cycle(a) == 1) {
            printf("PASS: 1->2->3->4->2 -> cycle detected\n");
            pass++;
        } else {
            printf("FAIL: 1->2->3->4->2 should detect cycle\n");
            fail++;
        }
        d->next = NULL;
        free(a); free(b); free(c); free(d);
    }

    /* Test 6: single node pointing to itself */
    {
        struct Node *a = make_node(1);
        a->next = a;
        if (has_cycle(a) == 1) {
            printf("PASS: self-loop -> cycle detected\n");
            pass++;
        } else {
            printf("FAIL: self-loop should detect cycle\n");
            fail++;
        }
        a->next = NULL;
        free(a);
    }

    printf("\n%d passed, %d failed\n", pass, fail);
    return fail ? 1 : 0;
}
