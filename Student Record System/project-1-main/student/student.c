
#include "../database/database.h" // WE CAN DELETE IT
#include"student.h"
#define stringsize 30
#include<string.h>
// Fun of Viewing Records.
void view_urecord(int id, student *students)
{ for(int i=0; i<MAXSIZE; i++) {
    if(id==students[i].id)
            {
 printf("=-=-=-=-=-=-=-=\n");
                printf("Student name is: %s \nStudent age is: %d \nStudent ID is: %d \nStudent total grade is: %f \nStudent gender is: %c \n",students[i].name,students[i].age,students[i].id,students[i].grade,students[i].gender);

                 printf("=-=-=-=-=-=-=-=\n");
                break;

            }
}

}

// Fun Of Editting Password.
void edit_upass (int id, student *students)
{
    char *newPass = (char*)malloc(stringsize*sizeof(char));
    printf("Enter your new password\n");
    scanf("%s", newPass);
    for(int i=0; i<MAXSIZE; i++) //check if it's valid Id so we can show data.
        {
            if(id==students[i].id)
            {
                 strcpy(students[i].password,newPass);
                printf("Password has been changed\n");
                break;
            }
        }


}

// Fun Of Editting Name.
void edit_uname (int id, student *students)
{
    char *newName = (char*)malloc(stringsize*sizeof(char));
    printf("Enter your new Name\n");
    getchar();
    gets(newName);
   for(int i=0; i<MAXSIZE; i++) //check if it's valid Id so we can show data.
        {
            if(id==students[i].id)
            {
                strcpy(students[i].name,newName);
                 printf("Welcome %s\n",students[i].name);
                break;
            }
        }

}
