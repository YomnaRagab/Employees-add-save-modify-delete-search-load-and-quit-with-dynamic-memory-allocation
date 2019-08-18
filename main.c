#include "proto.h"
#include "types.h"
#include <stdio.h>
extern tstrlist list;
void main(void)
{
    tstremp * temp;
    u32 i=0;
    u8 name1[30];
    printf("********************HELLO************************\n\t\tAuthor:Yomna Ragab\n");
    while(1)
    {
        printf("1)ADD\n2)LOAD\n3)DELETE\n4)SAVE\n5)SEARCH\n6)MODIFY\n7)QUIT\nYour choice:");
        scanf(" %d",&i);
        switch (i)
        {
        case 1:
            ADD();
            break;
        case 2:
            LOAD();
            break;
        case 3:
            DELETE();
            break;
        case 4:
            SAVE();
            break;
        case 5:
            printf("Please enter the name:");
            scanf(" %[^\n]%*c",name1);
            temp=SEARCH(name1);
            if (temp==NULL)
            {
                printf("There's a name such like that\n");
            }
            else{
                PRINITING(temp);
            }
            break;
        case 6:
            MODIFY();
            break;
        case 7:
            EXIT();
            break;
        default:
            printf("Error choice\n");
            break;

        }

    }
}
