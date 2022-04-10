#ifndef ADDNOTE
#define ADDNOTE
void addNote()
{
    FILE *ptr;
    int j=40, yr, count=1;
    char note[1000], *ti, *day, *date, *m, *x;
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
    ptr=fopen("personal_Diary.txt", "a");
    if(ptr==NULL)
    {
        printf("\nERROR!!!\nFile not found.");
    }
    else
    {
        printf("\nEnter the note: ");
        fgets(note, sizeof(note), stdin);
        fprintf(ptr,"%s %s %s %d             %s           %s", day, date, m, yr, ti, note);
    }
    fclose(ptr);
}
#endif