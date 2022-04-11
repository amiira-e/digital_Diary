#ifndef ADDNOTE
#define ADDNOTE
void addNote()
{
    FILE *ptr, *ptr1;
    int j=40, yr, count=1, exist;
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
                    printf("\n\nThis note ID already exists.");
                    break;
                }
            }
        } while(exist==1);
        fclose(ptr);
        printf("\nEnter the note: ");
        getchar();
        fgets(note, sizeof(note), stdin); 
        ptr1=fopen("personal_Diary.txt", "a");
        fprintf(ptr1,"%s             %s %s %s %d             %s           %s", id, day, date, m, yr, ti, note);
        fclose(ptr1);
    }
}
#endif