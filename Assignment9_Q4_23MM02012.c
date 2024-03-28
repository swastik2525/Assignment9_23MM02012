#include <stdio.h>

struct Address
{
    char street[100];
    char city[50];
    int zipCode[20];
};

struct Person
{
    char name[100];
    struct Address address;
};

int main()
{
    struct Person person;

    printf("Enter name: ");
    gets(person.name);
    printf("Enter street: ");
    gets(person.address.street);
    printf("Enter city: ");
    gets(person.address.city);
    printf("Enter zip code: ");
    scanf("%d",&person.address.zipCode);

    printf("\nDetails of the person:\n");
    printf("\nName: %s\n", person.name);
    printf("Address:\n");
    printf("Street: %s\n", person.address.street);
    printf("City: %s\n", person.address.city);
    printf("Zip code: %d", person.address.zipCode);

    return 0;
}
