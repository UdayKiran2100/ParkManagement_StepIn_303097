#include "default_Libraries.h"
#include "parkdef.h"


parkList* addIndividual( parkList *head, char *name, int token , int time )
{
    parkList* new;
    new =(parkList*)malloc(sizeof(parkList));
    strcpy(new->name,name);
    new->token_number=token;
    new->in_time=time;
    new->next=NULL;

    if(head==NULL)
    {
        head=new;
        return head;
    }
    else
    {
        parkList *temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=new;
    }
    return head;
}

