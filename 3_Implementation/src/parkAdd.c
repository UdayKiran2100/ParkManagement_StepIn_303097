#include "default_Libraries.h"
#include "parkdef.h"

/**
 * @brief This function is used to add a member to the parklist.
 * This node will be created and then the passed values are asssigned to it.
 * @param head It is a pointer that holds the address of the linked list under consideration.
 * @param name The name of the individual entering the park
 * @param token The unique token number assigned to hiim
 * @param time The time at which he enters the park
 * @return parkList* It returns the previously passed hesd pointer and with any changes as updated.
 */
parkList* addIndividual( parkList *head, char *name, int token , int time )
{
    parkList* n;
    n =(parkList*)malloc(sizeof(parkList));
    strcpy(n->name,name);
    n->token_number=token;
    n->in_time=time;
    n->next=NULL;

    if(head==NULL)
    {
        head=n;
        return head;
    }
    else
    {
        parkList *temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=n;
    }
    return head;
}

