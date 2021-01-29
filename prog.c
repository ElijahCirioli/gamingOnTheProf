/* Compile with gcc -Wall -ansi -o program prog.c */
/* I was too lazy to free memory but that's not the point */

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

#define TYPE int

struct Link {
    TYPE val;
    struct Link* next;
};

struct ListStack {
    struct Link* sentinel;
};

void initStack(struct ListStack* stk) {
    struct Link* sentinel = (struct Link*)malloc(sizeof(struct Link));
    assert(sentinel != NULL);

    sentinel->next = NULL;
    stk->sentinel = sentinel;
}

void pushStackPtr(struct ListStack* stk, TYPE val) {
    struct Link* new = (struct Link*)malloc(sizeof(struct Link));
    assert(new != NULL);

    new->val = val;
    new->next = stk->sentinel->next;
    stk->sentinel->next = new;
}

/* I would do it the other way but my prof was adamant this wouldn't work */
void pushStackVal(struct ListStack stk, TYPE val) {
    struct Link* new = (struct Link*)malloc(sizeof(struct Link));
    assert(new != NULL);

    new->val = val;
    new->next = stk.sentinel->next;
    stk.sentinel->next = new;
}

void printStack(struct ListStack* stk) {
    struct Link* link = stk->sentinel->next;

    do {
        printf("%d, ", link->val);
        link = link->next;
    } while (link != NULL);
    printf("\n");
}

int main() {
    struct ListStack stk;
    initStack(&stk);

    pushStackPtr(&stk, 4);
    pushStackPtr(&stk, 3);
    pushStackVal(stk, 2);
    pushStackVal(stk, 1);

    printStack(&stk);

    return 0;
}
