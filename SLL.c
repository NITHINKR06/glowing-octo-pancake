#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node *next;
};
void insertfront(struct node **list, int ele) {
    struct node *p;
    p = (struct node *)malloc(sizeof(struct node));
    p->info = ele;
    p->next = *list;
    *list = p;
}
int removefront(struct node **list) {
    int ele;
    struct node *p;
    p = *list;
    ele = p->info;
    *list = p->next;
    free(p);
    return ele;
}
void insertrear(struct node **list, int ele) {
    struct node *p, *q;
    p = (struct node *)malloc(sizeof(struct node));
    p->info = ele;
    p->next = NULL;
    if (*list == NULL) {
        *list = p;
        return;
    }
    for (q = *list; q->next != NULL; q = q->next);
    q->next = p;
}


void Display(struct node **list) {
    struct node *p;
    for (p = *list; p != NULL; p = p->next) {
        printf("%d\t", p->info);
    }
    printf("\n");
}

int countnode(struct node **list) {
    struct node *p;
    int count = 0;
    for (p = *list; p != NULL; p = p->next) {
        count++;
    }
    return count;
}

int main() {
    struct node *list = NULL;
    int choice, ele, pos, i,key;

    while (1) {
        printf("\nMenu:\n");
        printf("\n 1. INSERT front \n 2. REMOVE FRONT \n 3. INSERT REAR \n 4. .DISPLAY \n 5. COUNT NODES \n 6. EXIT\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
            printf("Enter element: ");
                scanf("%d", &ele);
                insertfront(&list, ele);
                break;
                case 2:
                if (list == NULL) {
                    printf("List is empty\n");
                } else {
                    ele = removefront(&list);
                    printf("Removed %d element\n", ele);
                }
                break;
            case 3:
                printf("Enter element: ");
                scanf("%d", &ele);
                insertrear(&list, ele);
                break;

            
            case 4:
                Display(&list);
                break;
            case 5:
                printf("Node count: %d\n", countnode(&list));
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
