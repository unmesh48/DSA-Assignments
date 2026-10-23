#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    int reg;
    char name[50];
    struct Node *next;
};

struct Node *head = NULL;

void add() {
    struct Node *p = malloc(sizeof(struct Node)), *t;
    if (!p) return;
    printf("Enter registration number and name: ");
    scanf("%d %49s", &p->reg, p->name);
    p->next = NULL;
    if (!head)
        head = p;
    else {
        for (t = head; t->next; t = t->next);
        t->next = p;
    }
    printf("Student added successfully.\n");
}

void removeStudent() {
    int reg;
    struct Node *t = head, *prev = NULL;
    printf("Enter registration number: ");
    scanf("%d", &reg);
    while (t && t->reg != reg) {
        prev = t;
        t = t->next;
    }
    if (!t) {
        printf("Student not found.\n");
        return;
    }
    if (prev) prev->next = t->next;
    else head = t->next;
    free(t);
    printf("Student removed successfully.\n");
}

void display() {
    struct Node *t = head;
    if (!t) {
        printf("No students registered.\n");
        return;
    }
    while (t) {
        printf("%d %s\n", t->reg, t->name);
        t = t->next;
    }
}

void count() {
    int n = 0;
    struct Node *t = head;
    while (t) {
        n++;
        t = t->next;
    }
    printf("Total participants: %d\n", n);
}

void sort() {
    struct Node *i, *j;
    int reg;
    char name[50];
    for (i = head; i; i = i->next)
        for (j = i->next; j; j = j->next)
            if (i->reg > j->reg) {
                reg = i->reg;
                i->reg = j->reg;
                j->reg = reg;
                strcpy(name, i->name);
                strcpy(i->name, j->name);
                strcpy(j->name, name);
            }
    printf("List sorted.\n");
}

void reverse() {
    struct Node *prev = NULL, *cur = head, *next;
    while (cur) {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    head = prev;
    printf("List reversed.\n");
}

int main() {
    int ch;
    do {
        printf("\n1.Add 2.Remove 3.Display 4.Count 5.Sort 6.Reverse 0.Exit\n");
        scanf("%d", &ch);
        switch (ch) {
            case 1: add(); break;
            case 2: removeStudent(); break;
            case 3: display(); break;
            case 4: count(); break;
            case 5: sort(); break;
            case 6: reverse(); break;
            case 0: break;
            default: printf("Invalid choice.\n");
        }
    } while (ch != 0);

    while (head) {
        struct Node *t = head;
        head = head->next;
        free(t);
    }
    return 0;
}