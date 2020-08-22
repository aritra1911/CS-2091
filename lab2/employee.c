#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define HR(basic) (0.25*basic)
#define DA(basic) (0.75*basic)

struct Employee {
    char name[32];
    char gender;
    char designation[32];
    char department[32];
    float basic_pay;
    float gross_pay;
};

int main() {
    struct Employee* employees;
    size_t n;

    printf("Enter no. of employees: ");
    scanf("%lu", &n);
    getchar();

    employees = malloc(n * sizeof *employees);

    for (size_t i=0; i<n; i++) {
        printf("\nEmployee #%d\n", i+1);
        printf("Enter name: ");
        scanf("%[^\n]", employees[i].name);
        getchar();
        printf("Enter gender (M/f): ");
        employees[i].gender = tolower(getchar());
        getchar();
        printf("Enter designation: ");
        scanf("%[^\n]", employees[i].designation);
        getchar();
        printf("Enter department: ");
        scanf("%[^\n]", employees[i].department);
        getchar();
        printf("Enter basic pay: ");
        scanf("%f", &employees[i].basic_pay);
        getchar();
    }

    for (size_t i=0; i<n; i++) {
        float basic_pay = employees[i].basic_pay;
        employees[i].gross_pay = basic_pay + HR(basic_pay) + DA(basic_pay);
    }

    printf("\n\n");

    for (size_t i=0; i<n; i++) {
        printf("Employee #%d\n", i+1);
        printf("Name : %s\n", employees[i].name);
        printf("Gender : %s\n", ((employees[i].gender == 'm') ? "Male" : "Female"));
        printf("Designation : %s\n", employees[i].designation);
        printf("Department : %s\n", employees[i].department);
        printf("Basic Pay : %f\n", employees[i].basic_pay);
        printf("Gross Pay : %f\n\n", employees[i].gross_pay);
    }

    free(employees);

    return 0;
}
