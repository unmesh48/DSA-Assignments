#include <stdio.h>
#include <ctype.h>
#include <string.h>

char stack[100], postfix[100];
int top = -1;

void push(char c) {
    stack[++top] = c;
}

char pop() {
    return stack[top--];
}

int priority(char c) {
    if (c == '^') return 3;
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return 0;
}

int main() {
    char infix[100], c;
    int i, j = 0;

    printf("Enter infix expression: ");
    scanf("%99s", infix);

    for (i = 0; infix[i]; i++) {
        c = infix[i];

        if (isalnum(c))
            postfix[j++] = c;
        else if (c == '(')
            push(c);
        else if (c == ')') {
            while (top != -1 && stack[top] != '(')
                postfix[j++] = pop();
            if (top != -1) pop();
        } else {
            while (top != -1 && stack[top] != '(' &&
                   (priority(stack[top]) > priority(c) ||
                   (priority(stack[top]) == priority(c) && c != '^')))
                postfix[j++] = pop();
            push(c);
        }
    }

    while (top != -1)
        postfix[j++] = pop();

    postfix[j] = '\0';
    printf("Postfix expression: %s\n", postfix);

    return 0;
}