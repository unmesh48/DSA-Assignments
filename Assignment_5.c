#include <stdio.h>
#include <stdlib.h>

struct Node {
    int coeff, exp;
    struct Node *next;
};

struct Node *createNode(int c, int e) {
    struct Node *p = malloc(sizeof(struct Node));
    p->coeff = c;
    p->exp = e;
    p->next = p;
    return p;
}

void insert(struct Node **head, int c, int e) {
    if (c == 0) return;

    struct Node *p = *head, *prev = NULL;

    if (!p) {
        *head = createNode(c, e);
        return;
    }

    do {
        if (p->exp == e) {
            p->coeff += c;
            return;
        }
        if (p->exp < e) break;
        prev = p;
        p = p->next;
    } while (p != *head);

    struct Node *n = createNode(c, e);

    if (!prev) {
        struct Node *last = *head;
        while (last->next != *head) last = last->next;
        n->next = *head;
        last->next = n;
        *head = n;
    } else {
        n->next = p;
        prev->next = n;
    }
}

struct Node *createPolynomial() {
    struct Node *p = NULL;
    int n, c, e;

    printf("Enter number of terms: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter coefficient and exponent: ");
        scanf("%d%d", &c, &e);
        insert(&p, c, e);
    }
    return p;
}

void display(struct Node *p) {
    if (!p) {
        printf("0\n");
        return;
    }

    struct Node *start = p;
    do {
        printf("%+d", p->coeff);
        if (p->exp) printf("x");
        if (p->exp > 1) printf("^%d", p->exp);
        p = p->next;
    } while (p != start);

    printf("\n");
}

struct Node *add(struct Node *a, struct Node *b) {
    struct Node *r = NULL, *p;

    if (a) {
        p = a;
        do {
            insert(&r, p->coeff, p->exp);
            p = p->next;
        } while (p != a);
    }

    if (b) {
        p = b;
        do {
            insert(&r, p->coeff, p->exp);
            p = p->next;
        } while (p != b);
    }

    return r;
}

void freePolynomial(struct Node *p) {
    if (!p) return;

    struct Node *start = p, *next;
    p = p->next;

    while (p != start) {
        next = p->next;
        free(p);
        p = next;
    }
    free(start);
}

int main() {
    struct Node *a, *b, *c;

    printf("First polynomial:\n");
    a = createPolynomial();

    printf("Second polynomial:\n");
    b = createPolynomial();

    printf("Polynomial 1: ");
    display(a);

    printf("Polynomial 2: ");
    display(b);

    c = add(a, b);

    printf("Sum: ");
    display(c);

    freePolynomial(a);
    freePolynomial(b);
    freePolynomial(c);

    return 0;
}