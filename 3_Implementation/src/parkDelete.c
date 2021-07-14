#include "default_Libraries.h"
#include "parkdef.h"


/**
 * @brief This function is used to delete the individual who has exceeded the time limit.
 * It deletes the elements from the beginning of the linked list which is analogous with the FIFO queue.
 * @param head It is a pointer that holds the address of the linked list under consideration.
 * @return parkList* It returns the previously passed hesd pointer and with any changes as updated after deletion.
 */
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


/**
 * @brief This function is used to delete the individual whose token number is entered by the admin.
 * It deletes the elements from any position of the linked list.
 * @param head It is a pointer that holds the address of the linked list under consideration.
 * @param token The token number to be removed from the queue
 * @return parkList* It returns the previously passed hesd pointer and with any changes as updated after deletion.
 */
parkList* deleteIndividual(parkList *head, int token)
{
    if(head==NULL)
    {
        printf("Park is Empty\n");
        return head;
    }
    else if(head->token_number==token)
    {
        return NULL;
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
        if(temp->next==NULL && temp->token_number==token)
        {
            return prev;
        }
        else if(temp->next==NULL)
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