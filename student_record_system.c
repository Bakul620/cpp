#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_STUDENTS 100
int total_student = 0;

struct student_record_system
{
    char name[50];
    char department[50];
    char id[10];
    double cgpa;
} student[MAX_STUDENTS];

void add_student()
{
    if (total_student >= MAX_STUDENTS)
    {
        printf("Cannot add more students. Maximum limit reached!\n");
        return;
    }

    printf("Enter the student's name: ");
    scanf(" %[^\n]", student[total_student].name);
    printf("Enter student's department: ");
    scanf("%s", student[total_student].department);
    printf("Enter student's ID: ");
    scanf("%s", student[total_student].id);
    printf("Enter student's CGPA: ");
    scanf("%lf", &student[total_student].cgpa);

    total_student++;
    printf("Student information added successfully!\n\n");
}

void find_by_ID()
{
    char Id[10];
    printf("Enter the Student ID: ");
    scanf("%s", Id);
    for (int j = 0; j < total_student; j++)
    {
        if (strcmp(Id, student[j].id) == 0)
        {
            printf("Student Name: %s\n", student[j].name);
            printf("Student Department: %s\n", student[j].department);
            printf("Student ID: %s\n", student[j].id);
            printf("Student CGPA: %.2lf\n", student[j].cgpa);
            return;
        }
    }
    printf("Student with ID %s not found.\n\n", Id);
}

void find_by_name()
{
    char name[50];
    printf("Enter the Student Name: ");
    scanf(" %[^\n]", name);
    for (int j = 0; j < total_student; j++)
    {
        if (strcmp(name, student[j].name) == 0)
        {
            printf("Student Name: %s\n", student[j].name);
            printf("Student Department: %s\n", student[j].department);
            printf("Student ID: %s\n", student[j].id);
            printf("Student CGPA: %.2lf\n", student[j].cgpa);
            return;
        }
    }
    printf("Student with name %s not found.\n\n", name);
}

void print_total_students()
{
    printf("Total number of students: %d\n\n", total_student);
}

void delete_student()
{
    char Id[10];
    printf("Enter the ID Number to delete: ");
    scanf("%s", Id);
    for (int j = 0; j < total_student; j++)
    {
        if (strcmp(Id, student[j].id) == 0)
        {
            for (int k = j; k < total_student - 1; k++)
            {
                student[k] = student[k + 1];
            }
            total_student--;
            printf("Student with ID %s removed successfully!\n", Id);
            return;
        }
    }
    printf("Student with ID %s not found.\n\n", Id);
}

void update_student()
{
    char Id[10];
    printf("Enter the ID Number to update the entry: ");
    scanf("%s", Id);
    for (int j = 0; j < total_student; j++)
    {
        if (strcmp(student[j].id, Id) == 0)
        {
            printf("1. Name\n2. ID\n3. CGPA\n4. Department\n");
            printf("Enter the field to update: ");
            int choice;
            scanf("%d", &choice);
            switch (choice)
            {
            case 1:
                printf("Enter the new Student Name: ");
                scanf(" %[^\n]", student[j].name);
                break;
            case 2:
                printf("Enter the new ID: ");
                scanf("%s", student[j].id);
                break;
            case 3:
                printf("Enter the new Student CGPA: ");
                scanf("%lf", &student[j].cgpa);
                break;
            case 4:
                printf("Enter the new Department: ");
                scanf("%s", student[j].department);
                break;
            default:
                printf("Invalid choice.\n");
                return;
            }
            printf("Student information updated successfully!\n");
            return;
        }
    }
    printf("Student with ID %s not found.\n\n", Id);
}

int main()
{
    int choice;
    printf("\n....Welcome to the Student Record System.....\n");
    while (1)
    {
        printf("\nThe Task that you want to perform --->>>\n");
        printf("1. Add Student Information\n");
        printf("2. Find Student Information by ID\n");
        printf("3. Find Student Information by Name\n");
        printf("4. Find Total Number of Students\n");
        printf("5. Delete Student Information by ID\n");
        printf("6. Update Student Information by ID\n");
        printf("7. Exit\n");
        printf("Enter your choice --> ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            add_student();
            break;
        case 2:
        find_by_ID();
            break;
        case 3:
        find_by_name();
            break;
        case 4:
            print_total_students();
            break;
        case 5:
            delete_student();
            break;
        case 6:
            update_student();
            break;
        case 7:
            printf("Exiting program...\n");
            exit(0);
        default:
            printf("Invalid choice. Please try again.\n\n");
        }
    }
}