#include <stdio.h>

struct Student
{
    char name[20];
    int age;
};

int main()
{
    struct Student studentArray[3] = {
        {"Alice", 33},
        {"Bob", 23},
        {"Michael", 49}
    };

    for (int i = 0; i < 3; i++)
    {
        printf("%s\t %d\n", studentArray[i].name, studentArray[i].age);
    }

    return 0;
}
