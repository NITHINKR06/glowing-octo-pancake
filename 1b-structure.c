#include <stdio.h>

struct Student {
    int roll;
    char name[50];
    int sem;
    int marks[3];
};

void readDetails(struct Student *s) {
    printf("Enter roll number: ");
    scanf("%d", &s->roll);
    printf("Enter name: ");
    scanf("%s", s->name);
    printf("Enter semester: ");
    scanf("%d", &s->sem);
    printf("Enter marks in 3 subjects: ");
    for (int i = 0; i < 3; i++) {
        scanf("%d", &s->marks[i]);
    }
}

void displayStudent(struct Student *s) {
    printf("\n\t%d \t %s\t %d\t %d\t %d\t %d\t", s->roll, s->name, s->sem, s->marks[0], s->marks[1], s->marks[2]);
}

void stdwise_marks(struct Student *s) {
    int totalmarks = s->marks[0] + s->marks[1] + s->marks[2];
    printf("\n\t%d \t %s\t %d\t %d\t %d\t %d\t %d\t", s->roll, s->name, s->sem, s->marks[0], s->marks[1], s->marks[2], totalmarks);
}

void subwiseStudent(struct Student *s) {
    int t1 = 0, t2 = 0, t3 = 0;
    for (int i = 0; i < 5; i++) {
        t1 += (s + i)->marks[0];
        t2 += (s + i)->marks[1];
        t3 += (s + i)->marks[2];
    }
    printf("\nTotal marks 1: %d\tTotal marks 2: %d\tTotal marks 3: %d\n", t1, t2, t3);
}

int main() {
    struct Student students[2];
    for (int i = 0; i < 2; i++) {
        printf("Enter details for student %d:\n", i + 1);
        readDetails(&students[i]);
    }

    printf("\nDisplaying student information:\n");
    printf("roll number\tName\tsem\tms1\tms2\tms3\n");
    for (int i = 0; i < 2; i++) {
        displayStudent(&students[i]);
    }

    printf("\n\nStudent wise marks:\n");
    printf("roll number\tName\tsem\tms1\tms2\tms3\ttotal marks\n");
    for (int i = 0; i < 2; i++) {
        stdwise_marks(&students[i]);
    }

    subwiseStudent(students);

    return 0;
}
