#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node *right, *left;
};

void insertfront(struct node **list, int ele) {
    struct node *p;
    p = (struct node *)malloc(sizeof(struct node));
    p->info = ele;
    p->left = NULL;
    p->right = *list;
    if (*list != NULL) {
        (*list)->left = p;
    }
    *list = p;
}

int removefront(struct node **list) {
    struct node *p;
    int ele;
    p = *list;
    ele = p->info;
    *list = p->right;

    if (*list != NULL) {
        (*list)->left = NULL;
    }
    free(p);
    return ele;
}

void insertrear(struct node **list, int ele) {
    struct node *p, *q;
    p = (struct node *)malloc(sizeof(struct node));
    p->info = ele;
    p->right = NULL;

    if (*list == NULL) {  // Case when list is empty
        p->left = NULL;
        *list = p;
    } else {
        for (q = *list; q->right != NULL; q = q->right) {
            ; // Traverse to the last node
        }
        q->right = p;
        p->left = q;
    }
}

int removerear(struct node **list ) {
    struct node *p,*prev;
int ele ;
    for (p = *list; p->right != NULL; p = p->right);
    prev=p->left;
    ele=p->info;
    prev->right=NULL;
    free(p);
    return ele;
}

void display(struct node **list) {
    struct node *p;
    for(p=*list;p->right!=NULL;p=p->right){
        printf("%d\t", p->info);
    }
    printf("\n");
}

int count(struct node **list) {
    struct node *p;
    int count = 0;
     for(p=*list;p->right!=NULL;p=p->right){
        count++;

    }
    return count;
}

int main() {
    struct node *list = NULL;
    int choice, ele;

    while (1) {
        printf("\nMenu:\n");
        printf("\n 1. INSERT front \n 2. REMOVE FRONT \n 3. INSERT REAR \n 4.  REMOVE REAR\n 5.DISPLAY \n 6. COUNT NODES \n 7. EXIT\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter element to insert at front: ");
                scanf("%d", &ele);
                insertfront(&list, ele);
                break;
            case 2:
                if (list != NULL) {
                    ele = removefront(&list);
                    printf("Removed element from front: %d\n", ele);
                } else {
                    printf("List is empty.\n");
                }
                break;
            case 3:
                printf("Enter element to insert at rear: ");
                scanf("%d", &ele);
                insertrear(&list, ele);
                break;
            case 4:
                if (list != NULL) {
                    ele = removerear(&list);
                    printf("Removed element from rear: %d\n", ele);
                } else {
                    printf("List is empty.\n");
                }
                break;
            case 5:
                display(&list);
                break;
            case 6:
                printf("Node count: %d\n", count(&list));
                break;
            case 7:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
}
