#ifndef ADDNOTE
#define ADDNOTE
void addNote()
{
    FILE *ptr;
    int j=160, yr, count=1, exist;
    char id[10], note[1000], *ti, *day, *date, *m, *x, NID[1000];
    time_t t=time(NULL);
    struct tm tm=*localtime(&t);
    yr=tm.tm_year+1900;
    x=strtok(ctime(&t), " ");
    day=x;
    while(count<5)
    {
        count++;
        if(count==2)
        {
            x=strtok(NULL, " ");
            m=x;
        }
        if(count==3)
        {
            x=strtok(NULL, " ");
            date=x;
        }
        if(count==4)
        {
            x=strtok(NULL, " ");
            ti=x;
        }
    }
    ptr=fopen("personal_Diary.txt", "r");
    if(ptr==NULL)
    {
        printf("\nERROR!!!\nFile not found.");
    }
    else
    {
        do
        {
            exist=0;
            printf("\nEnter the note ID (in 3 digits): ");
            scanf("%s", id);
            while(!feof(ptr))
            {
                fgets(NID, sizeof(NID), ptr);
                strtok(NID, "             ");
                if(strcmp(NID, id)==0)
                {
                    exist=1;
                    printf("\nThis note ID already exists.\n");
                    break;
                }
            }
        } while(exist==1);
        fclose(ptr);
        printf("\nEnter the note: ");
        getchar();
        fgets(note, sizeof(note), stdin); 
        ptr=fopen("personal_Diary.txt", "a");
        fprintf(ptr,"%s             %s %s %s %d             %s           %s", id, day, date, m, yr, ti, note);
        fclose(ptr);
        ptr=fopen("personalDiary.txt","a");
        printf("\n\n\tINTERFACE OF THE DIARY AFTER ADDING A NEW NOTE :) \n\n");
        for(int i=0;i<175;i++)
        {
            printf("\xB2");
        }
        printf("\n\xB2\xB2\n\xB2\xB2\t%s %s %s %d\n\xB2\xB2\t",day, date, m, yr);
        printf("%s\n\xB2\xB2",ti);
        printf("\n\xB2\xB2\tDEAR DIARY,\n\xB2\xB2\n\xB2\xB2\t");
        for(int i=0;note[i]!='\0';i++)
        {
            printf("%c", note[i]);
            if(i>j && (note[i]==33 || note[i]==46 || note[i]==32))
            {  
                printf("\n\xB2\xB2\t");
                j=j+160;
            }
        }
        printf("\xB2\xB2\n");
        for(int i=0;i<175;i++)
        {
            printf("\xB2");
        }
        printf("\n");
        fclose(ptr);
    }
}
#endif