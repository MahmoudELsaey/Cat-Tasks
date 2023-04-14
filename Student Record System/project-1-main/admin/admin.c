
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"admin.h"
static  int num_students =0;

    void Add_student (student *st,student *arr)
    {

        //check if there is student with the same id;


st->name=(char *)malloc(stringsize*sizeof(char));
st->password=(char *)malloc(stringsize*sizeof(char));

printf(" =-=-=-=-=-=-= Please enter data of student =-=-=-=-=-=-=\n");
printf("Enter name: ");
getchar();
gets(st->name);
printf("\n");
printf("Enter  password: ");
scanf("%s",st->password);
printf("\n");
printf("Enter age: ");
scanf("%d",&st->age);
printf("\n");
printf("Enter gender F or M: ");
getchar();
scanf("%c",&st->gender);
printf("\n");
 iid: printf("Enter id: ");
scanf("%d",&st->id);
 for(int i=0; i<MAXSIZE; i++)
            {
                if(arr[i].id == st->id)
                {

                    printf("\n\nXXXXX This ID is already exist,Try again XXXXX\n\n\n");

                     goto iid;

                }
            }
printf("\n");
aa: printf("enter grade: ");
scanf("%f",&st->grade);
if(st->grade>100||st->grade<0){
                printf("xxxxxxxxxxx Please enter grade between 0:100 xxxxxxxxxxx\n\n\n");
                goto aa;
            }
printf("\n");





          // arr =  realloc(arr, num_students*sizeof(student));
arr[num_students]=*st;
num_students++;



          printf("addition is done correctly \n");


            }

void remove_student (int id, student* arr)
    {
        int flag=0;
        for(int i=0; i<MAXSIZE; i++) //check if it's valid Id
        {
            if(id== arr[i].id)
            {
                flag=1;

                arr[i].name=NULL;
                arr[i].age=0;
                arr[i].gender=0;
                arr[i].grade=0;
                arr[i].password=NULL;
                arr[i].id=0;
printf("you removed the student successfully\n");

                  break;
            }
        }

        if(flag==0)


        {
            printf("invalid Id,please try again");
        }


    }






 void EditStuGrade(student *arr,int id){
     int flag=0;


        float grade;

         for (int i = 0; i < MAXSIZE; i++)
        {
                if (arr[i].id == id)
                {
                    flag=1;
            printf("student grade=%f\n",arr[i].grade);
            printf("edit the grade");
            scanf("%f",&grade);
            if(grade<=100&&grade>=0)
            arr[i].grade=grade;
            else
                printf("enter grade between 0 and 100\n");


        }
           }

                 if(flag==0 )
                 printf("student is not found\n");



        }






void viewAllrecords(student *arr){
for (int i = 0; i < num_students; i++)
    {
if((arr+i)->id!=0){
         printf("=-=-=-=-=-=-=-=\n");
                printf("Student name is: %s \n",(arr+i)->name);
                printf("Student age is: %d \n",(arr+i)->age);
                printf("Student ID is: %d \n",arr[i].id);
                printf("Student total grade is: %f\n",arr[i].grade);
                printf("Student gender is: %c \n",arr[i].gender);
                 printf("=-=-=-=-=-=-=-=\n");
}

    }
}




void EditAdminPass(adminn *arr){

         char *newpass = (char *)malloc(stringsize*sizeof(char));
        (arr+0)->pass=NULL;
         printf("Please enter new password :\n");
        scanf("%s", newpass);

        (arr+0)->pass = newpass;
        printf("The password changed \n");


    }

    void viewStu (int id, student *arr)
    {
         int flag=0;
        for(int i=0; i<MAXSIZE; i++) //check if it's valid Id so we can show data.
        {
            if(id==arr[i].id)
            {
                flag=1;
 printf("=-=-=-=-=-=-=-=\n");
                printf("Student name is: %s \n",arr[i].name);
                printf("Student age is: %d \n",arr[i].age);
                printf("Student ID is: %d \n",arr[i].id);
                printf("Student total grade is: %f \n",arr[i].grade);
                printf("Student gender is: %c \n",arr[i].gender);
                 printf("=-=-=-=-=-=-=-=\n");
               break;
            }


        }
        if (flag == 0)
            printf("Invalid Id\n");
    }
