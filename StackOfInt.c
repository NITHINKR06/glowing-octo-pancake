#include <stdlib.h>
#define MAXSIZE 3

// Define the stack structure
struct Stack {
    int items[MAXSIZE];
    int top;
};


// Check if the stack is empty
int isEmpty(struct Stack* s) {
    return s->top == -1;
}

// Check if the stack is full
int isFull(struct Stack* s) {
    return s->top == MAXSIZE - 1;
}

// Push an element onto the stack
void push(struct Stack* s, int ele) {

        s->items[++(s->top)] = ele;

}

// Pop an element from the stack
int pop(struct Stack* s) {
        return s->items[(s->top)--];
    }


// Display the stack elements
void display(struct Stack* s) {
    for (int i = s->top; i >=0; i--)
        printf("%d\t", s->items[i]);
}

int main() {
    struct Stack s;

 s.top = -1;
    int choice, ele;

while (1) {
        printf("\nMenu\n");
        printf("1. Push\n2. Pop\n3. Check Overflow\n4. Check Underflow\n5. Display\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (isFull(&s)) {
                 printf("Stack is full!\n");
                 }
                 else {
                printf("Enter the element to be pushed: ");
                scanf("%d", &ele);
                push(&s, ele);
                }
                break;
            case 2:
                    if (isEmpty(&s)) {
                    printf("Stack is empty!\n");

                    }
                    else{
                   ele = pop(&s);

                    printf("Popped element: %d\n", ele);
                    }
                break;
            case 3:
                if (isFull(&s))
                    printf("Stack overflow\n");
                else
                    printf("Stack is not full\n");
                break;
            case 4:
                if (isEmpty(&s))
                    printf("Stack underflow\n");
                else
                    printf("Stack is not empty\n");
                break;
            case 5:
                display(&s);
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
