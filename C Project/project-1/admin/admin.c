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
                printf("Student total grade is: %d \n",arr[i].grade);
                printf("Student gender is: %c \n",arr[i].gender);

            }
             break;

        }
        //if it 's not valid Id print warning message
        if(flag==0)
            printf("Invalid ID,please try again \n");
    }

//view all records
 void Add_student (student *st,student *arr)
    {
        int flag=0;
        //check if there is student with the same id;

            printf("Please enter your ID ");
            scanf("%d",&st->id);
            for(int i=0; i<num_students; i++)
            {
                if(arr[i].id == st->id)
                {
                    flag=1;
                    printf("This ID is already exist,Try again");

                }
                break;
            }
            //if it's valid Id

            if(flag==0)
            {
                arr[num_students ++]= *st;
                 printf("Addition is done correctly \n");
            }
        }






 void EditStuGrade(student *arr,int id){
     int flag=0;
     /*char *pass_=(char *)malloc(10*sizeof(char));

      printf("Enter admin password\n");
      scanf("%s",pass_);  // in main
        if (strcmp(pass_, array[0].pass) == 0){*/

        int grade;

         for (int i = 0; i < num_students; i++)
        {
                if (arr[i].id == id)
                {
                    flag=1;
            printf("student grade=%d\n",arr[i].grade);
            printf("edit the grade");
            scanf("%d",&grade);
            arr[i].grade=grade;


        }
           }

                 if(flag==0 )
                 printf("student is not found\n");



        }






void viewAllrecords(student *arr){
for (int i = 0; i < num_students; i++)
    {

             printf("Student name is: %s \n",arr[i].name);
                printf("Student age is: %d \n",arr[i].age);
                printf("Student ID is: %d \n",arr[i].id);
                printf("Student total grade is: %d \n",arr[i].grade);
                printf("Student gender is: %c \n",arr[i].gender);
                printf("________________\n");

    }
}




void EditAdminPass(adminn *arr){
char *password = (char *)malloc(strlen(arr[0].pass) + 1);
    char *newpass = (char *)malloc(strlen(arr[0].pass) + 1);
    printf("Please enter admin password\n");
    scanf("%s",password);




    if(strcmp(password,arr[0].pass)==0){
        arr[0].pass=NULL;
         printf("Please enter new password :\n");
        scanf("%s", newpass);
        printf("admin Password %s\n", newpass);
        arr[0].pass = newpass;
        printf("admin Password %s\n", arr[0].pass);
    }
    else
    {
        printf("INCORRECT PASSWORD TRY AGAIN\n");
    }
    }

    void remove_student (int id, student* arr)
    {
        int flag=0;
        /* printf("Please enter Id of student you want to remove");
         scanf("%d",&id);*/ // in main.

        for(int i=0; i<num_students; i++) //check if it's valid Id
        {
            if(id== arr[i].id)
            {
                flag=1;
//                free (arr);
//                arr[i]=NULL;
                num_students--;
                break;
            }
        }
        printf("you removed the student successfully");
        if(flag==0)


        {
            printf("invalid Id,please try again");
        }


    }
