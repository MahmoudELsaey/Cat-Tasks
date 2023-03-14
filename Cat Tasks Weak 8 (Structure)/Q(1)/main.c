#include <stdio.h>
#include <stdlib.h>

struct employee {
float salary;
float bonus;
float deduction;
};

int main()
{
    // مش لازم محسن ماجد وميرم تحديدا بقى :)
    struct employee emp[3];

    for (int i=0; i<3; i++)
    {
    printf("Enter Employee %d salary\n", i+1);
    scanf ("%f", &emp[i].salary);

    printf("Enter Employee %d Bonus\n", i+1);
    scanf ("%f", &emp[i].bonus);

    printf("Enter Employee %d Deduction\n", i+1);
    scanf ("%f", &emp[i].deduction);

    printf("The Total Salary = %.2f \n", (emp[i].salary+emp[i].bonus-emp[i].deduction));
    }
    return 0;
}
