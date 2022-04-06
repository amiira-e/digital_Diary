#ifndef CHECKPW
#define CHECKPW
void checkPW()
{
    FILE *ptr;
    int c, k=0;
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
    printf("\nEnter the password: ");
    pass[0]=getch();
    if(strcmp(pass, pw)==0)
    {
        printf("\nACCESS GRANTED!!!");
        break;
    }
        else
        {
            printf("\nACCESS DENIED!!!\nWrong password");
        }
    }
    fclose(ptr);
}
#endif