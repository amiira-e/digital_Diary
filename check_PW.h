#ifndef CHECKPW
#define CHECKPW
int checkPW()
{
    FILE *ptr;
    int c, i, k=0, j, access=0;
    char pw[100], pass[100];
    ptr=fopen("password.txt", "r");
    printf("\n");
    if(ptr==NULL)
    {
        printf("\nERROR!!!\nFile not found.");
    }
    else
    {
        while((c=fgetc(ptr))!=EOF)
        {
            pw[k]=c;
            k++;
        }
    }
    pw[k]='\0';
    printf("\nYou have 3 trials to enter the correct password!");
    for(j=0;j<3;j++)
    {
        i=0;
        printf("\n\nTRIAL %d", j+1);
        printf("\nEnter the password: ");
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
        if(strcmp(pass, pw)==0)
        {
            printf("\nACCESS GRANTED!!!");
            access=1;
            break;
        }
        else
        {
            printf("\nACCESS DENIED!!!\nWrong password");
        }
    }
    if(j==3 && access==0)
    {
        printf("\n\nWRONG PASSWORD!!!\nYou have no access to the diary.");
    }
    fclose(ptr);
    return access;
}
#endif