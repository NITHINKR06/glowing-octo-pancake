#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node *next;
};

void insertfront(struct node **list, int ele) {
    struct node *p = (struct node *)malloc(sizeof(struct node));
    p->info = ele;

    if (*list == NULL) {
        p->next = p;
        *list = p;
    } else {
        p->next = (*list)->next;
        (*list)->next = p;
    }
}

void insertrear(struct node **list, int ele) {
    struct node *p = (struct node *)malloc(sizeof(struct node));
    p->info = ele;

    if (*list == NULL) {
        p->next = p;
        *list = p;
    } else {
        p->next = (*list)->next;
        (*list)->next = p;
        *list = p;
    }
}

void insertafter(struct node **list, struct node *p, int ele) {
    struct node *q = (struct node *)malloc(sizeof(struct node));
    q->info = ele;
    q->next = p->next;
    p->next = q;
    if (p == *list) {
        *list = q;
    }
}

int removeafter(struct node **list, struct node *prev) {
    struct node *p = prev->next;
    int ele = p->info;
    prev->next = p->next;

    if (p == *list) {
        *list = prev;
    }
    free(p);

    return ele;
}

void Display(struct node **list) {
    if (*list == NULL) {
        printf("List is empty.\n");
        return;
    }
    
    struct node *p = (*list)->next;
    do {
        printf("%d\t", p->info);
        p = p->next;
    } while (p != (*list)->next);
    printf("\n");
}

int countnode(struct node **list) {
    if (*list == NULL) return 0;
    
    struct node *p = (*list)->next;
    int count = 0;
    do {
        count++;
        p = p->next;
    } while (p != (*list)->next);

    return count;
}

int main() {
    struct node *list = NULL;
    int choice, ele, pos, i;

    while (1) {
        printf("\n MENU\n");
        printf("1.INSERT front \n2.INSERT REAR \n3.INSERT AFTER A NODE \n4.REMOVE AFTER A NODE \n5.DISPLAY \n6.COUNT NODES \n7.EXIT\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element: ");
                scanf("%d", &ele);
                insertfront(&list, ele);
                break;
            case 2:
                printf("Enter element: ");
                scanf("%d", &ele);
                insertrear(&list, ele);
                break;
            case 3:
                printf("Enter the element to be inserted and the position: ");
                scanf("%d %d", &ele, &pos);
                if (pos == 1) {
                    insertfront(&list, ele);
                } else {
                    struct node *p;
                    for (i = 1, p = list->next; i < pos - 1 && p != list; i++, p = p->next);
                    if (p == NULL || p == list) {
                        printf("Position out of range\n");
                    } else {
                        insertafter(&list, p, ele);
                    }
                }
                break;
            case 4: {
                printf("Enter the element to be removed: ");
                scanf("%d", &ele);
                struct node *prev = NULL, *p = list->next;

                do {
                    if (p->info == ele) break;
                    prev = p;
                    p = p->next;
                } while (p != list->next);

                if (p == list->next && p->info != ele) {
                    printf("Element not found\n");
                } else {
                    ele = removeafter(&list, prev);
                    printf("%d is deleted\n", ele);
                }
                break;
            }
            case 5:
                Display(&list);
                break;
            case 6:
                printf("Node count: %d\n", countnode(&list));
                break;
            case 7:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
