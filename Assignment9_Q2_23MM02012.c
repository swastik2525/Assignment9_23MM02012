#include <stdio.h>

struct student
{
    int roll_no;
    char name[50]; 
    char address[100]; 
    int avg_marks;
    int age;
};

int main()
{
    struct student s[6]; 

    for (int i = 0; i < 6; i++)
    {
        printf("Enter the student %d Roll no.: ", i + 1);
        scanf("%d", &s[i].roll_no);
        
        printf("Enter the student %d name: ", i + 1);
        scanf("%s", s[i].name);
        
        printf("Enter the student %d address: ", i + 1);
        scanf("%s", s[i].address);
        
        printf("Enter the student %d age: ", i + 1);
        scanf("%d", &s[i].age);
        
        printf("Enter the student %d average marks: ", i + 1);
        scanf("%d", &s[i].avg_marks);
    }

    printf("\nEntered Student Details:\n");
    for (int i = 0; i < 6; i++)
    {
        printf("Student %d:\n", i + 1);
        printf("Roll no.: %d\n", s[i].roll_no);
        printf("Name: %s\n", s[i].name);
        printf("Address: %s\n", s[i].address);
        printf("Age: %d\n", s[i].age);
        printf("Average Marks: %d\n", s[i].avg_marks);
        printf("\n");
    }

    return 0;
}
