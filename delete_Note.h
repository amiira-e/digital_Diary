#ifndef DELETENOTE
#define DELETENOTE
void deleteNote()
{
    FILE *ptr1, *ptr2;
    char cur;
    int del, lineNum=0;
    printf("\n\nEnter the note to be deleted (for nth note, enter n): ");
    scanf("%d", &del);
    ptr1=fopen("personalDiary.txt","r");
    ptr2=fopen("temp.txt", "w");
    if(ptr1==NULL)
    {
        printf("\nERROR!!!\nFile not found.");
    }
    else
    {
        cur=getc(ptr1);
        if(cur!=EOF)
        {
            lineNum=1;
        }
        while(1)
        {
            if(del+1!=lineNum)
            {
                putc(cur, ptr2);
            }
            cur=getc(ptr1);
            if(cur=='\n')
            {
                lineNum++;
            } 
            if(cur==EOF)
            {
                break;
            }
        }
    }
    fclose(ptr1);
    fclose(ptr2);
    remove("personalDiary.txt");
    rename("temp.txt", "personalDiary.txt");
}
#endif