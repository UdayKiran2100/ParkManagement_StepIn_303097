#include "default_Libraries.h"
#include "parkdef.h"

parkList* deleteIndividual_beginning(parkList *head)
{
    if(head==NULL)
    {
        printf("The park is empty\n");
        return head;
    }
    else
    {
        parkList *temp=head;
        head=head->next;
        //free(temp);
    }
    return head;
}

parkList* deleteIndividual(parkList *head, int token)
{
    if(head==NULL)
    {
        printf("Park is Empty\n");
        return head;
    }
    else
    {
        parkList *temp=head;
        parkList *prev=head;
        while(temp->next!=NULL && temp->token_number!=token)
        {   
            prev=temp;
            temp=temp->next;
        }
        if(temp->next==NULL)
        {
            printf("The individual with given token number is not present in park\n");
        }
        else
        {
            prev->next=temp->next;
        }
    }
    return head;
}