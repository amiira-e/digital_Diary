#ifndef VIEWDIARY
#define VIEWDIARY
void viewDiary()
{
    FILE *ptr;
    int c;
    ptr=fopen("personal_Diary.txt", "r");
    printf("\n\n");
    if(ptr==NULL)
    {
        printf("\nERROR!!!\nFile not found.");
    }
    else
    {   
        for(int i=0;i<139;i++)
        {
           printf("\xB2");
        }
        printf("\n");
        
        while((c=fgetc(ptr))!=EOF)
        {
            system("");
            printf("%c", c);
        }
        for(int i=0;i<139;i++)
        {
            printf("\xB2");
        }
        printf("\n");
    }
    fclose(ptr);
}
#endif