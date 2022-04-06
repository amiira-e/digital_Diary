#ifndef VIEWDIARY
#define VIEWDIARY
void viewDiary()
{
    FILE *ptr;
    int c;
    ptr=fopen("personalDiary.txt", "r");
    printf("\n");
    if(ptr==NULL)
    {
        printf("\nERROR!!!\nFile not found.");
    }
    else
    { 
        while((c=fgetc(ptr))!=EOF)
        {
            system("COLOR 07");
            printf("%c", c);
        }
    }
    fclose(ptr);
}
#endif