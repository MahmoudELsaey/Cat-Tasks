

#include <stdio.h>
#include <stdlib.h>
#define stringsize 30
#include"../student/student.c"
#include "../admin/admin.c"

//#include "../student/student.c"
 //static int num_students; //Size of the memory that will be Allocated.
    static int mode; // Admin OR User?.
    int uchoice; //to choose in User mode
    int achoice; //to choose in admin mode
    int id;
int main()
{
   /*int num_students; //Size of the memory that will be Allocated.
    int mode; // Admin OR User?.
    int uchoice; //to choose in User mode
    int achoice; //to choose in admin mode
    int id;*/


   // printf("Enter the number of the Students\n");
    //scanf("%d",&num_students);
student *arr = (student*)malloc(num_students*sizeof(student));
    adminn *aAdmin= malloc(sizeof(adminn));
    (aAdmin+0)->pass="1234";
     for(int i=0;i<num_students;i++){
        (arr+i)->age=20;
         (arr+i)->name="mariam ehab";
          (arr+i)->grade=99.5;
           (arr+i)->gender='F';
            (arr+i)->password="mariam2612";
             (arr+i)->id=i+1;
     }


    //Allocating Dynamic Memory for Objects and "student" is a pointer pointing to the first object.

    //Checking the Succession of Allocating Memory.
    if (arr == NULL)
        printf("Memory is not Available");
    if (arr != NULL)
        printf("Allocating Memory Succeeded\n");
    //End of Checking
while(1){
        printf("+++++++++++++++++++++++++++++++++++++++++++++++++++\n");
    printf("[1]Admin mode press \n[2] User mode press \n[3]EXIT\n ");
printf("+++++++++++++++++++++++++++++++++++++++++++++++++++\n");
  printf("choose from 1:3\n");
    scanf("%d",&mode);
    switch(mode){
case 1:
    ADMIN( aAdmin,arr);
    break;
case 2:
    USER(arr);
    break;
case 3:
    return 0;
    break;
 default:
 printf("Enter valid choice\n");
    }

    //After this: We will call the functions of Admin and User.
}
    return 0;
}

//Admin Function
void ADMIN(adminn *ad,student *arr)
{
    student st;
student *ptr =&st;
    int tries=0;
for( tries =0;tries<3;tries++){
    char *pass_=(char *)malloc(10*sizeof(char));

      printf("Enter admin password\n");
      scanf("%s",pass_);
        if (strcmp(pass_, (ad+0)->pass) == 0)
            break;
        else
            printf("TRY AGAIN\n");


        }
        if(tries==3)
            printf("You can't enter admin mode\n");
        else{


printf("+++++++++++++++++++++++++++++++++++++++++++++++++++\n");
        printf("[1]To Add Student Record \n");
        printf("[2]To Remove Student Record \n");
        printf("[3]To View Student Record \n");
        printf("[4]To View All Records \n");
        printf("[5]To Edit Admin Password \n");
        printf("[6]To Edit Student Grade \n");
printf("+++++++++++++++++++++++++++++++++++++++++++++++++++\n");
printf("choose from 1:6\n");
        scanf("%d", &achoice);


switch(achoice){
case 1:
    Add_student (ptr, &arr);

    break;
case 2:
     printf("Enter student ID\n");
        scanf("%d", &id);

    remove_student (id,arr);

    break;

case 3:
     printf("Enter student ID\n");
        scanf("%d", &id);

   viewStu(  id,arr);

    break;
   case 4:
        viewAllrecords(arr);
        break;
       case 5:
        EditAdminPass(ad);
        break;
      case 6:
         printf("Enter student ID\n");
        scanf("%d", &id);

          EditStuGrade(arr, id);
          break;
}
        }

        }



//User Function
void USER(student *arr){
  printf("Enter your ID\n");
        scanf("%d", &id);
        if (0<id && id<=num_students)
        {
            char *pass = (char *)malloc(strlen((arr+id-1)->password) + 1);
        printf("Enter password %s: \n",pass);
         scanf("%s", pass);
        if (strcmp(pass, (arr+id-1)->password) == 0){

printf("+++++++++++++++++++++++++++++++++++++++++++++++++++\n");
        printf("[1]To view Your Record \n");
        printf("[2]To Edit Your Password \n");
        printf("[3]To Edit Your Name \n");
        printf("choose from 1:3\n");
        scanf("%d", &uchoice);
printf("+++++++++++++++++++++++++++++++++++++++++++++++++++\n");

switch(uchoice){
        case 1:
           view_urecord(id-1, arr);
           break;
        case 2:
           edit_upass(id-1, arr);
           break;
        case 3:
            edit_uname(id-1, arr);
            break;
        default:
            printf("Enter valid choice\n");
            break;
}
        }
        else {
            printf("Wrong password\n");
        }

        }

        else
            printf("Wrong ID\n");

}


