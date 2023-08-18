#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100

struct Stack {
    char data[MAX_SIZE];
    int top;
};

void initialize(struct Stack *s) {
    s->top = -1;
}

int isEmpty(struct Stack *s) {
    return s->top == -1;
}

void push(struct Stack *s, char value) {
    if (s->top < MAX_SIZE - 1) {
        s->top++;
        s->data[s->top] = value;
    }
}

char pop(struct Stack *s) {
    if (!isEmpty(s)) {
        char value = s->data[s->top];
        s->top--;
        return value;
    }
    return '\0';
}

int precedence(char op) {
    switch (op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
    }
    return -1;
}

void infixToPostfix(char infix[], char postfix[]) {
    struct Stack stack;
    initialize(&stack);
    int i, j;
    j = 0;

    for (i = 0; infix[i] != '\0'; i++) {
        if (isalnum(infix[i])) {
            postfix[j] = infix[i];
            j++;
        } else if (infix[i] == '(') {
            push(&stack, '(');
        } else if (infix[i] == ')') {
            while (!isEmpty(&stack) && stack.data[stack.top] != '(') {
                postfix[j] = pop(&stack);
                j++;
            }
            pop(&stack);
        } else {
            while (!isEmpty(&stack) && precedence(infix[i]) <= precedence(stack.data[stack.top])) {
                postfix[j] = pop(&stack);
                j++;
            }
            push(&stack, infix[i]);
        }
    }

    while (!isEmpty(&stack)) {
        postfix[j] = pop(&stack);
        j++;
    }

    postfix[j] = '\0';
}

int main() {
    char infix[MAX_SIZE];
    char postfix[MAX_SIZE];

    printf("Enter the infix expression: ");
    fgets(infix, MAX_SIZE, stdin);
    infixToPostfix(infix, postfix);

    printf("Equivalent postfix expression: %s\n", postfix);

    return 0;
}
