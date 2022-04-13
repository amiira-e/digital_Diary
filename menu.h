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
    
    while(again==1)
    {
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
                addNote();
                break;
            }
            case 2:
            {
                if(checkPW()==1)
                {
                    viewDiary();
                }
                break;
            }
            case 3:
            {
                if(checkPW()==1)
                {
                    viewDiary();
                    deleteNote();
                }
                break;
            }
            case 4:
            {
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