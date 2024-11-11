#include <stdio.h>
#include <stdlib.h>



struct node {
    int info;
    struct node *lc, *rc;
};

void insertbst(struct node **root, int ele) {
    struct node *parent, *current, *p;
    p = (struct node *)malloc(sizeof(struct node));
    p->info = ele;
    p->lc = p->rc = NULL;
    if (*root == NULL) {
        *root = p;
        return;
    }
    parent = NULL;
    current = *root;
    while (current != NULL && ele != current->info) {
        parent = current;
        if (ele < current->info) {
            current = current->lc;
        } else {
            current = current->rc;
        }
    }
    if (current != NULL) {
        free(p);
        printf("Duplicate \n");
        return;
    }
    if (ele > parent->info) {
        parent->rc = p;
    } else {
        parent->lc = p;
    }
}

int searchbst(struct node *root, int key) {
    struct node *current = root;
    while (current != NULL) {
        if (key > current->info) {
            current = current->rc;
        } else if (key < current->info) {
            current = current->lc;
        } else {
            return 1;
        }
    }
    return 0;
}

void preorder(struct node *root) {
    if (root != NULL) {
        printf("%d\t", root->info);
        preorder(root->lc);
        preorder(root->rc);
    }
}

void inorder(struct node *root) {
    if (root != NULL) {
        inorder(root->lc);
        printf("%d\t", root->info);
        inorder(root->rc);
    }
}

void postorder(struct node *root) {
    if (root != NULL) {
        postorder(root->lc);
        postorder(root->rc);
        printf("%d\t", root->info);
    }
}

int main() {
    struct node *root = NULL;
    int choice, ele, key, val;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert BST\n2. Search BST\n3. Display Inorder\n4. Display Preorder\n5. Display Postorder\n6. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter element: ");
                scanf("%d", &ele);
                insertbst(&root, ele);
                break;
            case 2:
                printf("Enter element to be searched: ");
                scanf("%d", &key);
                val = searchbst(root, key);
                if (val == 1)
                    printf("Key found \n");
                else
                    printf("Key not found \n");
                break;
            case 3:
                printf("Inorder traversal is: ");
                inorder(root);
                printf("\n");
                break;
            case 4:
                printf("Preorder traversal is: ");
                preorder(root);
                printf("\n");
                break;
            case 5:
                printf("Postorder traversal is: ");
                postorder(root);
                printf("\n");
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
