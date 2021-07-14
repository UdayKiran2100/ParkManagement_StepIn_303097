#include "default_Libraries.h"
#include "parkdef.h"


/**
 * @brief This Function is used to print the park details to a flie.
 * All the park details along with name, token assigned , time 
 * @param head It is a pointer that holds the address of the linked list under consideration.
 * @return int It returns 0 if pointer is null and returns 1 if not null. 
 */
int print_parkdetails_toFile(parkList *head)
{
    FILE *fptr=fopen("park_details.txt","w");
    parkList *temp=head;
    if(temp==NULL)
    {
        fclose(fptr);
        return 0;
    }
        
    while(temp!=NULL)
    {
        fprintf(fptr,"%s:%d:%d \n",temp->name,temp->token_number,temp->in_time);
        temp=temp->next;
    }
    fclose(fptr);
    return 1;
}

/**
 * @brief This Function is used to print the park details to a terminal.
 * All the park details along with name, token assigned , time 
 * 
 * @param head It is a pointer that holds the address of the linked list under consideration.
 * @return int It returns 0 if pointer is null and returns 1 if not null. 
 */
int print_parkdetails(parkList *head)
{
    
    if(head==NULL)
    {
        return 0;
    }
        
    
    parkList *temp=head;
    while(temp!=NULL)
    {
        printf("\n%s:%d:%d\n",temp->name,temp->token_number,temp->in_time);
        temp=temp->next;
    }
    return 1;
}