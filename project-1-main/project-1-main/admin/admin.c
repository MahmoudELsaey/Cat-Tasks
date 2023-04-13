
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"admin.h"


    void Add_student (student *st,student **arr)
    {
        int flag=0;
        //check if there is student with the same id;

            printf("Please enter data of student: name,gender ,age,id , grades and password \n");
            st->name=(char *)malloc(stringsize*sizeof(char));
//             st->gender=(char *)malloc(stringsize*sizeof(char));
              st->password=(char *)malloc(stringsize*sizeof(char));
            scanf("%s %s %d %d %f %s",st->name,&st->gender,&st->age,&st->id,&st->grade,st->password);
            for(int i=0; i<num_students; i++)
            {
                if(arr[i]->id == st->id)
                {
                    flag=1;
                    printf("This ID is already exist,Try again \n");
                     break;

                }
            }
            //if it's valid Id
            if(flag==0)
            { int x=num_students +1;

           *arr =  realloc(*arr, x*sizeof(student));
            (*arr)[x - 1] = *st;
//           arr[x-1]=*st;

          printf("addition is done correctly \n");

            }


            }

void remove_student (int id, student* arr)
    {
        int flag=0;
        for(int i=0; i<num_students; i++) //check if it's valid Id
        {
            if(id== arr[i].id)
            {
                flag=1;
                //free(arr[i].name);
                arr[i].name=NULL;
                arr[i].age=0;
                //free(arr[i].gender);
                arr[i].gender=NULL;
                arr[i].grade=0;
                //free(arr[i].password);
                arr[i].password=NULL;
                arr[i].id=0;
printf("you removed the student successfully");
                num_students--;

                  break;
            }
        }

        if(flag==0)


        {
            printf("invalid Id,please try again");
        }


    }
//view all records






 void EditStuGrade(student *arr,int id){
     int flag=0;
     /*char *pass_=(char *)malloc(10*sizeof(char));
      printf("Enter admin password\n");
      scanf("%s",pass_);  // in main
        if (strcmp(pass_, array[0].pass) == 0){*/

        float grade;

         for (int i = 0; i < num_students; i++)
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
                printf("Student name is: %s \n",(arr+i)->name);
                printf("Student age is: %d \n",(arr+i)->age);
                printf("Student ID is: %d \n",arr[i].id);
                printf("Student total grade is: %f\n",arr[i].grade);
                printf("Student gender is: %c \n",arr[i].gender);
                printf("________________\n");
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
        for(int i=0; i<num_students; i++) //check if it's valid Id so we can show data.
        {
            if(id==arr[i].id)
            {
                flag=1;
                printf("Student name is: %s \n",arr[i].name);
                printf("Student age is: %d \n",arr[i].age);
                printf("Student ID is: %d \n",arr[i].id);
                printf("Student total grade is: %f \n",arr[i].grade);
                printf("Student gender is: %c \n",arr[i].gender);
               break;
            }


        }
        if (flag == 0)
            printf("Invalid Id\n");
    }
