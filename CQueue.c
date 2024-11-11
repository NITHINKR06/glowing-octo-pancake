#include <stdio.h>
#include <stdlib.h>
#define MAX 4

struct CirQueue {
    int items[MAX];
    int front, rear;
};

int isCirQueuefull(struct CirQueue *p) {
    if (p-> front==(p->rear+1) % MAX)
        return 1;
return 0;
}

int isCirQueueempty(struct CirQueue *p) {
    if (p-> front==p->rear)
    return 1;
return 0;

}

void insert(struct CirQueue *p, int ele) {
    p->rear= (p->rear +1)%MAX;
    p->items[p->rear] = ele;
}

int delete (struct CirQueue *p) {

    int ele ;
     p->front= (p->front+1)%MAX;
   ele= p->items[p->front];
   return ele;
}

void Display(struct CirQueue *p) {
    printf("Queue items:\n");
int i= p->front;
do
{

    i=(i+1)% MAX;
    printf("%d \t", p->items[i]);

}while(i<(p->rear));


}

int main() {
    struct CirQueue p;
    p.rear = p.front = MAX-1;
    int choice, ele;
    while (1) {
        printf("\nMenu:\n");
        printf("\n 1. Insert Operation\n 2.delete operation \n 3. check overflow \n 4.check underflow \n 5.Display \n 6. Exit\n" );

        scanf("%d", &choice);
        switch (choice) {
            case 1: if (isCirQueuefull(&p))
                        printf("Queue is full\n");
                    else
                    {
                        printf("Enter the item to be inserted :\n");
                        scanf("%d", &ele);
                        insert(&p, ele);
                    }
                break;
            case 2:
                if (isCirQueueempty(&p))
        printf("Queue Underflow\n");
        else
                delete  (&p);

                break;
            case 3:
                if (isCirQueuefull(&p))
                    printf("Queue is full\n");
                else
                    printf("Queue is not  full\n");
                break;
                case 4:
                if (isCirQueueempty(&p))
                    printf("Queue underflow\n");
                else
                    printf("Queue is not  empty \n");
break;
                case 5:
                Display(&p);
                break;
            case 6:

                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
