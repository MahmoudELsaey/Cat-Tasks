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