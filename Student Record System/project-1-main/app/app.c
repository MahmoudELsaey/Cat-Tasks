
#include"../student/student.h"
#include "../admin/admin.h"
#include "app.h"


 static int mode; // Admin OR User?.
    int uchoice; //to choose in User mode
    int achoice; //to choose in admin mode
    int id;

    int MODE(){
student *arr = (student*)malloc(MAXSIZE*sizeof(student));
    adminn *aAdmin= malloc(sizeof(adminn));
    (aAdmin+0)->pass="1234";

while(1){
       printf("=-=-=-=-=-=-=-=\n");
    printf("[1]Admin mode  \n[2]User mode  \n[3]EXIT\n ");
printf("=-=-=-=-=-=-=-=\n");
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
    }
void ADMIN(adminn *ad,student *arr)

{
    student st;
student *ptr =&st;
    int tries=0;
for( tries =0;tries<3;tries++){
    char *pass_=(char *)malloc(stringsize*sizeof(char));
      printf("Enter admin password\n");
      scanf("%s",pass_);
        if (strcmp(pass_ ,(ad+0)->pass) == 0)
            break;
        else
            printf("TRY AGAIN\n");


        }
        if(tries==3)
            printf("You can't enter admin mode\n");
        else{


printf("=-=-=-=-=-=-=-=\n");
        printf("[1]To Add Student Record \n");
        printf("[2]To Remove Student Record \n");
        printf("[3]To View Student Record \n");
        printf("[4]To View All Records \n");
        printf("[5]To Edit Admin Password \n");
        printf("[6]To Edit Student Grade \n");
printf("=-=-=-=-=-=-=-=\n");
printf("choose from 1:6\n");
        scanf("%d", &achoice);


switch(achoice){
case 1:
    Add_student (ptr,arr);

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


void USER(student *arr){

    idagain:printf("Enter your ID\n");
    scanf("%d", &id);
    char *pass = (char *)malloc(stringsize*sizeof(char));

         for(int i=0; i<MAXSIZE; i++) //check if it's valid Id so we can show data.
        {


            if(id==arr[i].id)
            {
                goto PASS;
            }
             else{
             printf("\n\nXXXXXXX invalid Id XXXXXXX\n\n");
        goto idagain;
        }

  PASS:printf("Enter password : \n");
         scanf("%s", pass);
        if (strcmp(pass, arr[i].password) == 0){
                goto options;
        }
        else{
            printf("\n\nXXXXXX Wrong password try again XXXXXX\n\n");
            goto PASS;
        }
        }

  options:printf("=-=-=-=-=-=-=-=\n");
 printf("[1]To view Your Record \n");
        printf("[2]To Edit Your Password \n");
        printf("[3]To Edit Your Name \n");
         printf("choose from 1:3\n");
printf("=-=-=-=-=-=-=-=\n");
        scanf("%d", &uchoice);



switch(uchoice){
        case 1:


           view_urecord(id, arr);
           break;

       case 2:


           edit_upass(id, arr);
           break;

       case 3:


        edit_uname(id, arr);
        break;
       default:
        printf("Enter valid choice\n");
        break;

}


        }











