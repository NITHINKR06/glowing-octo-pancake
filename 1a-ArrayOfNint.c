#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100

void CreateArr(int a[], int *p) {
    int i;
    printf("Enter the size of array: ");
    scanf("%d", p);

    printf("Enter the array elements \n");
    for (i = 0; i < *p; i++) {
        scanf("%d", &a[i]);
    }
}

void insert(int a[], int ele, int pos, int *p) {
    int i;
    for (i = *p; i > pos; i--) {
        a[i] = a[i - 1];
    }
    a[pos] = ele;
    (*p)++;
}

int RemoveElePos(int a[], int pos, int *p) {
    int i, ele;
    ele = a[pos];
    for (i = pos; i < *p - 1; i++) {
        a[i] = a[i + 1];
    }
    (*p)--;
    return ele;
}

int isEleAvailable(int ele, int a[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        if (a[i] == ele)
            return i;
    }
    return -1;
}

void display(int a[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main() {
    int a[MAXSIZE], n = 0, choice, ele, pos;

    while (1) {
        printf("1. Create\n2. Insert\n3. Delete position\n4. Delete element\n5. Display\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                CreateArr(a, &n);
                printf("Array created!\n");
                break;
            case 2:
                printf("Enter the element and position: ");
                scanf("%d%d", &ele, &pos);

                if (pos > n || pos < 0) {
                    printf("Invalid position!\n");
                } else {
                    insert(a, ele, pos, &n);
                    printf("Element inserted!\n");
                }
                break;
            case 3:
                printf("Enter the position of the element to be removed: ");
                scanf("%d", &pos);
                if (pos >= n || pos < 0) {
                    printf("Invalid position!\n");
                } else {
                    ele = RemoveElePos(a, pos, &n);
                    printf("Element %d removed!\n", ele);
                }
                break;
            case 4:
                printf("Enter the element to be removed: ");
                scanf("%d", &ele);
                pos = isEleAvailable(ele, a, n);
                if (pos == -1) {
                    printf("Element not found!\n");
                } else {
                    ele = RemoveElePos(a, pos, &n);
                    printf("Element %d removed!\n", ele);
                }
                break;
            case 5:
                display(a, n);
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
