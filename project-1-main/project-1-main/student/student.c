
#include "../database/database.h" // WE CAN DELETE IT
//#include "student.h"


// Fun of Viewing Records.
void view_urecord(int id, student *students)
{
    printf("Your name is %s\nYour id is %d\nYour age is %d\nYour gender is %c\n",(students+id)->name, (students+id)->id, (students+id)->age, (students+id)->gender);
}

// Fun Of Editting Password.
void edit_upass (int id, student *students)
{
    char *newPass = (char*)malloc(stringsize*sizeof(char));
    printf("Enter your new password\n");
    scanf("%s", newPass);
    (students+id)->password = newPass;
    printf("Password has been changed\n");
}

// Fun Of Editting Name.
void edit_uname (int id, student *students)
{
    char *newName = (char*)malloc(stringsize*sizeof(char));
    printf("Enter your new Name\n");
    getchar();
    gets(newName);
    (students+id)->name = newName;
    printf("Welcome %s\n",(students+id)->name);
}
