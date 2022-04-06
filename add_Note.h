#ifndef ADD_NOTE
#define ADD_NOTE
void add_Note()
{
    FILE *ptr;
    char note[1000], tim[20], date[20];
    ptr=fopen("personal_Diary.txt", "a");
    if(ptr==NULL)
    {
        printf("\nERROR!!!\nFile not found.");
    }
    else
    {
        printf("\nEnter the date (DD/MM/YY):");
        scantf("%s", date);
        printf("\nEnter the time (HH:MM):");
        scantf("%s", tim);
        printf("\nEnter the note: ");
        getchar();
        fgets(note, sizeof(note), stdin);
        fprintf(ptr,"%s              %s              %s", date, tim, note);
    }
    fclose(ptr);
}
#endif