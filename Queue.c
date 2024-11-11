#include <stdio.h>
#include <stdlib.h>
#define MAX 4

struct Queue {
    int items[MAX];
    int front, rear;
};

int isQueuefull(struct Queue *p) {
    return p->rear == MAX - 1;
}

int isQueueempty(struct Queue *p) {
    return p->rear < p->front;
}

void insert(struct Queue *p, int ele) {

    p->items[++(p->rear)] = ele;
    printf("Pushed %d onto the Queue\n", ele);
}

int delete (struct Queue *p) {

    int ele = p->items[(p->front)++];
    printf("removed  %d from the Queue\n",ele);
    return ele; // Return the popped element
}

void Display(struct Queue *p) {

    printf("Queue items:\n");
    for (int i = p->front; i <= p->rear; i++) {
        printf("%d\n", p->items[i]);
    }
}

int main() {
    struct Queue p;
    p.rear = -1;
    p.front = 0;
    int choice, ele;
    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert Operation\n 2.delete operation \n 3. check overflow \n 4.check underflow \n 5.Display \n 6. Exit\n" );

        scanf("%d", &choice);
        switch (choice) {
            case 1:
                if (isQueuefull(&p)) {
        printf("Queue Overflow\n");
                }
        else{
                printf("Enter the item to be inserted :\n");
                scanf("%d", &ele);
                insert(&p, ele);
        }
                break;
            case 2:
                if (isQueueempty(&p)) {
        printf("Queue Underflow\n");
        }
        else
                delete  (&p);
                break;
            case 3:
                if (isQueuefull(&p))
                    printf("Queue is full\n");
                else
                    printf("Queue is not  full\n");
                break;
                case 4:
                if (isQueueempty(&p))
                    printf("Queue underflow\n");
                else
                    printf("Queue is not  empty \n");
break;
                case 5:
                Display(&p);
                break;
            case 6:
                printf("Exiting from the program\n");
                exit(0); // Exit the program
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
