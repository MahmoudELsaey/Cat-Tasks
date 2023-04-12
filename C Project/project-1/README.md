# project-1
Students Record System 
I "Mahmoud" made the array of struct by dynamic memory and the way of accessing variables and members will be like this:
//This next commented part was just for checking, You will do this in the Admin folder.

for(int i=0; i<num_students; i++)
    {
        printf("Enter Student ID\n");
        scanf("%d", &((students+i)->id));
        printf("Enter Student Age\n");
        scanf("%d", &((students+i)->age));
        printf("Enter Student gender\n");
        scanf("%s", &((students+i)->gender));

    }

    for(int s=0; s<2; s++)
    {
        printf("%d\n", (students+s)->id);
        printf("%d\n", (students+s)->age);
        printf("%s\n", ((students+s)->gender));
    }





some notes about user func

// checking for first function (view your record)
//for (int id=0; id<4; id++)
//{
//    strcpy((students+id)->name, "Mahmoud");
//    (students+id)->id = id;
//    (students+id)->age = 15;
//    strcpy((students+id)->gender, "Male");
//}
//
//view_urecord(2, students);


//Checking for Second Function
//strcpy((students)->password, "Mahmoud");
//printf("%s\n", (students)->password);
//
//edit_pass (0, students);
//printf("%s", (students)->password);

//checking func 3 editting name
strcpy((students)->name, "Mahmoud");
printf("%s\n", (students)->name);

edit_name (0, students);
printf("%s", (students)->name);
