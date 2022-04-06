#ifndef CHANGE_PW
#define CHANGE_PW
void change_PW()
{
    FILE *ptr;
    int c, i=0;
    char pass[100];
    ptr=fopen("password.txt", "w");
    printf("\n");
    if(ptr==NULL)
    {
        printf("\nERROR!!!\nFile not found.");
    }
    else
    {
        printf("\nEnter the new password: ");
        pass[0]=getch();
        while(pass[i]!='\r')
        {
            if(pass[i]=='\b')
            {
                i--;
                printf("\b \b");
                pass[i]=getch();
            }
            else
            {
                printf("*");
                i++;
                pass[i]=getch();
            }
        }
        pass[i]='\0';
        printf("\n");
        fprintf(ptr, "%s", pass);
    }
    fclose(ptr);
}
#endif