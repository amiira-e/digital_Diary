#ifndef ADDNOTE
#define ADDNOTE
void addNote()
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
        scanf("%s", date);
        printf("\nEnter the time (HH:MM):");
        scanf("%s", tim);
        printf("\nEnter the note: ");
        getchar();
        fgets(note, sizeof(note), stdin);
        fprintf(ptr,"%s              %s              %s", date, tim, note);
    }
    fclose(ptr);
}
#endif