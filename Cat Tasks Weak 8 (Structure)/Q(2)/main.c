#include <stdio.h>
#include <stdlib.h>

struct STUDENTS
{
    float Programming_grades;
    float DataStructure_Grades;
    float DiscreteMath_Grades;
    float Algorithms_Grades;
};

int main()
{
    int id; //id of the student
    int choice; //editing grades
    int position; //Student or Admin?

    struct STUDENTS students[10];

    for (int i=0; i<10; i++)
    {
        students[i].Programming_grades = 10;
        students[i].DataStructure_Grades = 20;
        students[i].DiscreteMath_Grades = 30;
        students[i].Algorithms_Grades = 40;
    }

    printf("Enter 1 for Student And 2 for Admin\n");
    scanf("%d",&position);

    if (position == 1)
    {
        printf("Enter your ID from 0 to 9\n");
        scanf("%d",&id);

        if(id<0 || id>9)
            printf("wrong ID");
        else
        {
            printf("Programming_grades= %.2f \nDataStructure_Grades = %.2f \nDiscreteMath_Grades = %.2f \nAlgorithms_Grades = %.2f \n",students[id].Programming_grades, students[id].DataStructure_Grades, students[id].DiscreteMath_Grades,students[id].Algorithms_Grades);
        }
    }

    else if (position == 2)
    {
        printf("To edit grades enter 1\n");
        scanf("%d", &choice);

        if (choice == 1)
        {
            int id; //The one that will be Added by the Admin

            printf("Enter the id of the stdent from 0 to 9\n");
            scanf("%d",&id);

            if(id<0 || id>9)
                printf("wrong ID");
            else
            {
                printf("Enter Programming_grades\n");
                scanf ("%f", &students[id].Programming_grades);

                printf("Enter DataStructure_Grades\n");
                scanf ("%f", &students[id].DataStructure_Grades);

                printf("Enter DiscreteMath_Grades\n");
                scanf ("%f", &students[id].DiscreteMath_Grades);

                printf("Enter Algorithms_Grades\n");
                scanf ("%f", &students[id].Algorithms_Grades);

                printf("Programming_grades= %.2f \nDataStructure_Grades = %.2f \nDiscreteMath_Grades = %.2f \nAlgorithms_Grades = %.2f \n",students[id].Programming_grades, students[id].DataStructure_Grades, students[id].DiscreteMath_Grades,students[id].Algorithms_Grades);

            }

        }
    }

    return 0;
}

