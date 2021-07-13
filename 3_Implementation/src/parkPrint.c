#include "default_Libraries.h"
#include "parkdef.h"

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