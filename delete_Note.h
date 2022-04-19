#ifndef DELETENOTE
#define DELETENOTE
void deleteNote()
{
    FILE *ptr1, *ptr2;
    char note[1000], note1[1000], NID[10];
    ptr1=fopen("personal_Diary.txt","r");
    ptr2=fopen("temp.txt","a");
    printf("\n\nEnter the note ID you want to delete: ");
    scanf("%s", NID);
    while(!feof(ptr1))
    {
        fgets(note, sizeof(note), ptr1);
        strcpy(note1, note);
        strtok(note, "             ");
        if(strcmp(note, NID)!=0 && strlen(note1)>3)
        {
            fprintf(ptr2,"%s",note1);
        }
    }
    fclose(ptr2);
    fclose(ptr1);
    remove("personal_Diary.txt");
    rename("temp.txt", "personal_Diary.txt");
}
#endif