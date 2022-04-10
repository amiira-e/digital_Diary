#ifndef CHECKPW
#define CHECKPW
void checkPW()
{
    FILE *ptr;
    int c, k=0, i;
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
    i=0;
    printf("\nEnter the password: ");
    //scanf("%s", pass);
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
    }
    else
    {
        printf("\nACCESS DENIED!!!\nWrong password");
    }
    fclose(ptr);
}
#endif