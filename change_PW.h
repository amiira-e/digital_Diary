#ifndef CHANGEPW
#define CHANGEPW
void changePW()
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
        scanf("%s", pass);
        printf("\n");
        fprintf(ptr, "%s", pass);
    }
    fclose(ptr);
}
#endif