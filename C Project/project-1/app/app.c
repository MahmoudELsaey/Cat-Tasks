#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int num_students; //Size of the memory that will be Allocated.

#include "../database/database.h"
#include "../student/student.c" // IS THIS TRUE?
//#include "../admin/admin.c"




int main()
{

    int mode; // Admin OR User?.
    int uchoice; //to choose in User mode
    int achoice; //to choose in admin mode
    int id;

    // Specifing size of memory will be Allocated.
    printf("Enter the number of the Students\n");
    scanf("%d",&num_students);

    //Allocating Dynamic Memory for Objects and "student" is a pointer pointing to the first object.
    student *arr = (student*)malloc(num_students*sizeof(student));
    adminn *aAdmin= malloc(sizeof(adminn));
    student s1;
    student *ptr = &s1;

    //Checking the Succession of Allocating Memory.
    if (arr == NULL)
        printf("Memory is not Available");
    if (arr != NULL)
        printf("Allocating Memory Succeeded\n");
    //End of Checking



    printf("For Admin mode press 1.\nFor User mode press 2.\n");
    scanf("%d",&mode);

//    After this: We will call the functions of Admin and User.
    if (mode ==1)
    {
        printf("To Add Student Record press 1\n");
        printf("To Remove Student Record press 2\n");
        printf("To View Student Record press 3\n");
        printf("To View All Records press 4\n");
        printf("To Edit Admin Password 5\n");
        printf("To Edit Student Grade 6\n");
        scanf("%d", &achoice);

        printf("Enter your ID\n");
        scanf("%d", &id);
//        switch (achoice)
//        {
//        case 1:
//            Add_student(ptr, arr);
//            break;
//        case 2:
//            remove_student(id, arr);
//            break;
//        case 3:
//            viewStu(id, arr);
//            break;
//        case 4:
//            viewAllrecords(arr);
//            break;
//        case 5:
//            EditAdminPass(aAdmin);
//            break;
//        case 6:
//            EditStuGrade(id, arr);
//            break;
//        default:
//            printf("Wrong Choice");
//        }

    }
    else if (mode ==2)
    {
        printf("To view Your Record press 1\n");
        printf("To Edit Your Password press 2\n");
        printf("To Edit Your Name press 3\n");
        scanf("%d", &uchoice);

        printf("Enter your ID\n");
        scanf("%d", &id);

        switch (uchoice)
        {
        case 1:
            view_urecord (id, arr);
            break;
        case 2:
            edit_upass (id, arr);
            break;
        case 3:
            edit_uname (id, arr);
            break;
        default:
            printf("Wrong Choice");
        }
    }

    return 0;
}
