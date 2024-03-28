#include <stdio.h>

struct CourseRecord
{
    char firstName[50];
    char lastName[50];
    int rollNumber;
    char department[50];
    char courseCode[20];
    int testMarks[3];
};

float Average(struct CourseRecord record)
{
    int totalMarks = 0;
    for (int i = 0; i < 3; i++)
    {
        totalMarks += record.testMarks[i];
    }
    return (float)totalMarks / 3;
}

int check(struct CourseRecord record)
{
    float averageMarks = Average(record);
    return (averageMarks >= 35) ? 1 : 0;
}

int main()
{
   
    struct CourseRecord record;

  
    printf("Enter student's first name: ");
    scanf("%s", record.firstName);
    printf("Enter student's last name: ");
    scanf("%s", record.lastName);
    printf("Enter student's roll number: ");
    scanf("%d", &record.rollNumber);
    printf("Enter department: ");
    scanf("%s", record.department);
    printf("Enter course code: ");
    scanf("%s", record.courseCode);
    printf("Enter three test marks: ");
    for (int i = 0; i < 3; i++)
    {
        scanf("%d", &record.testMarks[i]);
    }


    printf("\nAverage test marks: %.2f\n", Average(record));

    
    if (check(record))
    {
        printf("Student passed the test.\n");
    }
    else
    {
        printf("Student failed the test.\n");
    }

    return 0;
}
