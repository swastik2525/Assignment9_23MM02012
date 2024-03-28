#include <stdio.h>

struct date
{
    int day, month, year;
};

int compareDates(struct date date1, struct date date2)
{
    if (date1.year > date2.year)
        return 1;
    if (date1.year < date2.year)
        return -1;

    if (date1.month > date2.month)
        return 1;
    if (date1.month < date2.month)
        return -1;

    if (date1.day > date2.day)
        return 1;
    if (date1.day < date2.day)
        return -1;

    return 0;
}

int main()
{
    struct date date1, date2;

    printf("Enter date1 (day month year): ");
    scanf("%d %d %d", &date1.day, &date1.month, &date1.year);

    printf("Enter date2 (day month year): ");
    scanf("%d %d %d", &date2.day, &date2.month, &date2.year);

    int result = compareDates(date1, date2);

    if (result == 1)
        printf("Date 1 is later than Date 2\n");
    else if (result == -1)
        printf("Date 2 is later than Date 1\n");
    else
        printf("Both dates are the same\n");

    return 0;
}
