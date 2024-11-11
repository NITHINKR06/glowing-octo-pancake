#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 100

struct Stack {
    int top;
    int items[MAX];
};

void push(struct Stack *s, int ele) {
    s->items[++(s->top)] = ele;
}

int pop(struct Stack *s) {
    return s->items[(s->top)--];
}

int postfixEval(char postfix[]) {
    struct Stack s;
    s.top = -1;
    int i, operand1, operand2, result;
    char ch;

    for (i = 0; postfix[i] != '\0'; i++) {
        ch = postfix[i];
        if (isdigit(ch)) {
            push(&s, ch - '0');
        } else {
            operand2 = pop(&s);
            operand1 = pop(&s);
            switch (ch) {
                case '+':
                    result = operand1 + operand2;
                    break;
                case '-':
                    result = operand1 - operand2;
                    break;
                case '*':
                    result = operand1 * operand2;
                    break;
                case '/':
                    result = operand1 / operand2;
                    break;
                default:
                    printf("Invalid operator\n");
                    return -1;
            }
            push(&s, result);
        }
    }
    return pop(&s);
}

int main() {
    char postfix[MAX];
    int result;
    printf("Enter postfix expression: ");
    scanf("%s", postfix);
    result = postfixEval(postfix);
    printf("Result of postfix evaluation: %d\n", result);
    return 0;
}
