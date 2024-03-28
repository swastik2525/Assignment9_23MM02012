#include <stdio.h>
struct company
{
    char name[50];
    char address[100];
    int phone_no;
    int no_of_members;
};
int main()
{

    struct company c;
    printf("enter the company name");
    scanf("%s", &c.name);
    printf("enter the address");
    scanf("%s", &c.address);
    printf("enter the phone number");
    scanf("%d", &c.phone_no);
    printf("enter the number of members");
    scanf("%d", &c.no_of_members);

    printf("\n comapny name:%c", c.name);
    printf("\n company address:%c", c.address);
    printf("\n phone no.:%d", c.phone_no);
    printf("\n number no of members:%d", c.no_of_members);
    return 0;
}