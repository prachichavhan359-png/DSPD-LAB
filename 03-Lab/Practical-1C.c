#include <stdio.h>

struct Student {
    char name[50];
    int roll;
    int age;
    float avg;
};

int main() {
    struct Student s[100], temp;
    int n, i, j;

    printf("Enter number of students: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        printf("\nEnter details of student %d:\n", i + 1);
        printf("Name: ");
        scanf("%s", s[i].name);
        printf("Roll No: ");
        scanf("%d", &s[i].roll);
        printf("Age: ");
        scanf("%d", &s[i].age);
        printf("Average Marks: ");
        scanf("%f", &s[i].avg);
    }

    for(i = 0; i < n - 1; i++) {
        for(j = 0; j < n - i - 1; j++) {
            if(s[j].avg < s[j + 1].avg) {
                temp = s[j];
                s[j] = s[j + 1];
                s[j + 1] = temp;
            }
        }
    }

    printf("\nStudents sorted by Average Marks (Descending Order):\n");
    for(i = 0; i < n; i++) {
        printf("\nName: %s", s[i].name);
        printf("\nRoll No: %d", s[i].roll);
        printf("\nAge: %d", s[i].age);
        printf("\nAverage Marks: %.2f\n", s[i].avg);
    }

    return 0;
}
