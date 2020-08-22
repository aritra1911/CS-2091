#include <stdio.h>

#define STUDENTS 60

struct Student {
    unsigned int roll_no;
    char name[32];
    float marks;
};

int main(void) {
    struct Student studs[STUDENTS];

    for (int i=0; i<STUDENTS; i++) {
        printf("Student #%d\n", i+1);
        printf("Roll No.: ");
        scanf("%u", &studs[i].roll_no);
        getchar();
        printf("Name: ");
        scanf("%s", studs[i].name);
        printf("Marks: ");
        scanf("%f", &studs[i].marks);
        printf("\n");
    }

    float total_marks=0.0;

    for (int i=0; i<STUDENTS; i++)
        total_marks += studs[i].marks;

    printf("Average marks of the class is %f\n", total_marks/STUDENTS);

    return 0;
}
