#ifndef MENU
#define MENU
#include"check_PW.h"
#include"add_Note.h"
#include"view_Diary.h"
#include"delete_Note.h"
#include"change_PW.h"

void menu()
{
    int again=1, choice;
    char s[50]="~ ~ ~ ~ ~ WELCOME TO YOUR PERSONAL DIARY ~ ~ ~ ~ ~";
    printf("\n\t\t\t\t\t\033[0;33m");
    for(int i=0;i<50;i++)
    {
        system("");
        printf("%c", s[i]);
    }
    while(again==1)
    {
        printf("\033[0m\n");
        printf("\nChoose from the following:");
        printf("\n1: Add a note to the diary");
        printf("\n2: View the diary");
        printf("\n3: Delete a note from the diary");
        printf("\n4: Change password");
        printf("\n5: Exit");
        do
        {
            printf("\n\nEnter your choice: ");
            scanf("%d", &choice);
            if(choice<1 || choice>5)
            {
                printf("\nPlease, enter a valid choice (1-5): ");
                scanf("%d", &choice);
            }
        } while(choice<1 || choice>5);
        system("cls");
        switch (choice)
        {
            case 1:
            {
                printf("\033[0;31m");
                addNote();
                break;
            }
            case 2:
            {
                printf("\033[0;36m");
                if(checkPW()==1)
                {
                    viewDiary();
                }
                break;
            }
            case 3:
            {
                printf("\033[0;32m");
                if(checkPW()==1)
                {
                    viewDiary();
                    deleteNote();
                }
                break;
            }
            case 4:
            {
                printf("\033[0;35m");
                if(checkPW()==1)
                {
                    changePW();
                }
                break;
            }
            case 5:
            {
                again=0;
                break;
            }
        }
    }
}
#endif