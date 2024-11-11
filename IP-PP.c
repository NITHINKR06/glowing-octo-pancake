#include <stdio.h>
#include <stdlib.h>


#define MAX 100

struct Stack {
    int top;
    char items[MAX];
};

int precedence(char ch) {
    switch (ch) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
        case '%':
            return 2;
        case '^':
            return 3;
    }
    return -1;
}

void push(struct Stack *s, char ele) {

        s->items[++(s->top)] = ele;
}

char pop(struct Stack *s) {

        return s->items[(s->top)--];

}

int isOperator(char ch) {
    switch (ch) {
        case '+':
        case '-':
        case '*':
        case '/':
        case '%':
        case '^':
        case '(':
        case ')':
            return 1;
        default:
            return 0;
    }
}

int isOperand(char ch) {
    return isalnum(ch);
}

void infixToPostfix(char infix[], char postfix[]) {
    struct Stack s;
    s.top = -1;
    int i, j = 0;
    char ch;

    for (i = 0; infix[i] != '\0'; i++) {
        ch = infix[i];
        if (isOperand(ch)) {
            postfix[j++] = ch;
        } else if (ch == '(') {
            push(&s, ch);
        } else if (ch == ')') {
            while (s.top != -1 && s.items[s.top] != '(') {
                postfix[j++] = pop(&s);
            }
            pop(&s); // Remove '(' from stack
        } else {
            while (s.top != -1 && precedence(s.items[s.top]) >= precedence(ch)) {
                postfix[j++] = pop(&s);
            }
            push(&s, ch);
        }
    }

    while (s.top != -1) {
        postfix[j++] = pop(&s);
    }
    postfix[j] = '\0';
}

int main() {
    char infix[MAX], postfix[MAX];
    printf("Enter infix expression: ");
    gets(infix);
    infixToPostfix(infix, postfix);
    printf("Postfix expression: %s\n", postfix);
    return 0;
}
